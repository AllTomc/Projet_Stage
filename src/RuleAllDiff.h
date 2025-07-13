#pragma once

#include "Rule.h"
#include <vector>
#include <map>
#include <string>

using namespace XCSP3Core;

class CHRCallbacks;  
class RuleAllDiff : public Rule {
private:
    std::vector<XVariable*> vars;
    static bool neq_rules_defined;
    std::vector<std::vector<std::string>> allDiffLogicalVarsGroups;

public:
    RuleAllDiff(std::string id,
                const std::vector<XVariable*>& list,CHRCallbacks* cb);

    void finalize() override;
    std::string toCHR() override;
};
