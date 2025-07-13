#pragma once

#include "Rule.h"
#include <vector>
#include <map>
#include <string>
using namespace XCSP3Core;
class CHRCallbacks;

class RuleInstantiation : public Rule {
private:
    std::vector<XVariable*> vars;
    std::vector<int> values;
    CHRCallbacks* callback; 
    static bool eq_rules_defined ;

public:
    RuleInstantiation(const std::vector<XVariable*>& list,const std::vector<int>& vals,CHRCallbacks* cb); 
    void finalize() override;
    std::string toCHR() override;
};
