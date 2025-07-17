#include "RuleLinear.h"
#include "CHRCallbacks.h"
#include <iostream>
#include <algorithm>

RuleLinear::RuleLinear(const std::vector<XVariable*>& list, const XCondition& cond, CHRCallbacks* cb)
    : vars(list), condition(cond), callback(cb) {
    toCHR();
}

RuleLinear::RuleLinear(const std::vector<XVariable*>& list, const std::vector<int>& coeffs, const XCondition& cond, CHRCallbacks* cb)
    : vars(list), const_coeffs(coeffs), condition(cond), callback(cb) {
    coeff_type = CoeffType::CONST_INT;
    toCHR();
}

RuleLinear::RuleLinear(const std::vector<XVariable*>& list, const std::vector<XVariable*>& coeffs, const XCondition& cond, CHRCallbacks* cb)
    : vars(list), var_coeffs(coeffs), condition(cond), callback(cb) {
    coeff_type = CoeffType::VAR;    
    toCHR();
}

bool RuleLinear::linear_rules_defined = false;

void RuleLinear::finalize() {
    if (!linear_rules_defined) {
        callback->add_constraint(Predicate::cspOp("plus"));
        callback->add_constraint(Predicate::cspOp("eq"));

        callback->addRule(RuleRaw::plusRule());
        callback->addRule(RuleRaw::eqRule());
        
        callback->getBuilder()->add_linear_functions();
        linear_rules_defined = true;
    }
}

std::string RuleLinear::toCHR() {
    if (vars.empty()) return "";

    auto name_id_map = callback->getNameIdMap();
    std::vector<std::string> logicalVars;
    std::vector<int> ids;
    std::ostringstream var_list, id_list, coeff_list;

    for (auto* var : vars) {
        std::string name = var->id;
        auto it = name_id_map.find(name);
        if (it == name_id_map.end()) continue;

        int id = it->second;
        std::string logic = "X[" + std::to_string(id) + "]";
        std::string inter = "Interval_" + std::to_string(id);

        Predicate pVar("CspVarInt", {"+int", "?int", "-interval"});
        pVar.setElements({logic, inter});
        addHead(pVar);

        logicalVars.push_back(logic);
        ids.push_back(id);
    }

    if (logicalVars.empty() || condition.op != OrderType::EQ) return "";

    // Création des listes CHR++
    for (size_t i = 0; i < logicalVars.size(); ++i) {
        var_list << logicalVars[i];
        id_list << ids[i];
        if (i < logicalVars.size() - 1) {
            var_list << ", ";
            id_list << ", ";
        }
    }

    if (coeff_type == CoeffType::CONST_INT) {
        for (size_t i = 0; i < const_coeffs.size(); ++i) {
            coeff_list << const_coeffs[i];
            if (i < const_coeffs.size() - 1)
                coeff_list << ", ";
        }
    } else if (coeff_type == CoeffType::VAR) {
        for (size_t i = 0; i < var_coeffs.size(); ++i) {
            auto it = name_id_map.find(var_coeffs[i]->id);
            if (it == name_id_map.end()) continue;
            coeff_list << "X[" << it->second << "]";
            if (i < var_coeffs.size() - 1)
                coeff_list << ", ";
        }
    }

    // Ajout à la section main()
    std::ostringstream oss;
    oss << "linear_post(*space, {" << var_list.str() << "}, "
        << "{" << id_list.str() << "}, ";

    oss << condition.val << ")";

    callback->getBuilder()->addPredicateCallToMain(oss.str());

    return Rule::toCHR();
}

