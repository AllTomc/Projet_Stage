#pragma once
#include "Rule.h"
#include <vector>
#include <string>

class CHRCallbacks;
using namespace std;
using namespace XCSP3Core;


class RuleLinear : public Rule {
public:
    RuleLinear(const std::vector<XVariable*>& list, const XCondition& condition, CHRCallbacks* callback);
    RuleLinear(const std::vector<XVariable*>& list, const std::vector<int>& coeffs, const XCondition& cond, CHRCallbacks* cb);
    RuleLinear(const std::vector<XVariable*>& list, const std::vector<XVariable*>& coeffs, const XCondition& cond, CHRCallbacks* cb);

    void finalize() override;
    std::string toCHR() override;

private:
    enum class CoeffType { NONE, CONST_INT, VAR };
    CoeffType coeff_type = CoeffType::NONE;
    std::vector<int> const_coeffs;
    std::vector<XVariable*> var_coeffs;
    std::vector<XVariable*> vars;
    XCondition condition;
    static bool linear_rules_defined ;
    CHRCallbacks* callback;
};
