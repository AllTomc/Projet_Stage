#include "RuleInstantiation.h"

#include "CHRCallbacks.h"  
#include <iostream>


bool RuleInstantiation::eq_rules_defined = false;

RuleInstantiation::RuleInstantiation(const std::vector<XVariable*>& list,const std::vector<int>& vals,CHRCallbacks* cb)
    : vars(list), values(vals),  callback(cb) {
    toCHR();
}


void RuleInstantiation::finalize() {

    if (!eq_rules_defined) {
        callback->  add_constraint(std::make_shared<Predicate>(prefix_op + "eq", std::vector<std::string>{"+int", "?int", "+int", "?int"}));
        callback->addRule(RuleRaw::eqRule());
        eq_rules_defined = true;
    }
}


std::string RuleInstantiation::toCHR() {
    if (vars.size() != values.size()) {
        std::cerr << "Erreur : tailles différentes entre vars et values.\n";
        return "";
    }

    std::map<int, int> instantiations;

    for (size_t i = 0; i < vars.size(); ++i) {
        std::string name = vars[i]->id;
        int value = values[i];

        const auto& name_id_map = callback->getNameIdMap();
        auto it = name_id_map.find(name);
        if (it == name_id_map.end()) {
            std::cerr << "Erreur : variable '" << name << "' inconnue dans name_id_map.\n";
            continue;
        }

        int id = it->second;
        instantiations[id] = value;
    }

    if (callback->getBuilder()) {
        callback->getBuilder()->addInstantiations(instantiations);
    }

    return ""; 
}

