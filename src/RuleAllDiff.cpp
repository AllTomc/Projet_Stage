#include "RuleAllDiff.h"
#include "CHRCallbacks.h"  

RuleAllDiff::RuleAllDiff(std::string id,
                         const std::vector<XVariable*>& list, CHRCallbacks* cb)
    : vars(list) { Rule::setCHRCallbacks(cb);
    toCHR();
}
bool RuleAllDiff::neq_rules_defined = false;

void RuleAllDiff::finalize() {
    if (!neq_rules_defined) {
        callback->add_constraint(Predicate::cspOp("neq"));
        callback->addRule(RuleRaw::neqRule());
        neq_rules_defined = true;

        callback->getBuilder()->add_alldiferrent_functions();
    } else {
        //std::cout << "Les règles neq ont déjà été ajoutées." << std::endl;
    }
}

std::string RuleAllDiff::toCHR() {
    std::vector<std::string> logicalVars;
    std::vector<int> ids;

    for (auto* var : vars) {
        const auto& name_id_map = Rule::getCHRCallbacks()->getNameIdMap();
        auto it = name_id_map.find(var->id);
        if (it != name_id_map.end()) {
            int id = it->second;
            logicalVars.push_back("X[" + std::to_string(id)+"]");
            ids.push_back(id);
        }
    }

    if (!logicalVars.empty() && callback->getBuilder()) {
        std::ostringstream oss;
        oss << "alldiff_post(*space, {";
        for (size_t i = 0; i < logicalVars.size(); ++i) {
            oss << logicalVars[i];
            if (i < logicalVars.size() - 1)
                oss << ", ";
        }
        oss << "}, {";
        for (size_t i = 0; i < ids.size(); ++i) {
            oss << ids[i];
            if (i < ids.size() - 1)
                oss << ", ";
        }
        oss << "})";

        callback->getBuilder()->addPredicateCallToMain(oss.str());
    }

    return "";  
}

