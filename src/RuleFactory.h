#pragma once
#include <memory>
#include <string>
#include <map>
#include "Rule.h"
#include "RuleRaw.h"
#include "RuleIntension.h"
#include "RuleAllDiff.h"
#include "RuleInstantiation.h"
#include "RuleLinear.h"

class RuleFactory {

public:
    RuleFactory() {}

    static std::shared_ptr<Rule> createRawRule(const std::string& content) {
        return std::make_shared<RuleRaw>(content);
    }

    std::shared_ptr<Rule> createIntensionRule(Tree* tree, CHRCallbacks* callbacks) const {
        return std::make_shared<RuleIntension>(tree, callbacks);
    }

    std::shared_ptr<Rule> createAllDiffRule(const std::string& id, std::vector<XVariable*>& list, CHRCallbacks* callbacks) const {
        return std::make_shared<RuleAllDiff>(id, list, callbacks);
    }

    std::shared_ptr<Rule> createInstantiation(const std::vector<XVariable*>& list, const std::vector<int>& vals,CHRCallbacks* callbacks) const {
        return std::make_shared<RuleInstantiation>(list, vals, callbacks);
    }
    std::shared_ptr<Rule> createLinear(vector<XVariable *> &list, XCondition &cond,CHRCallbacks* callbacks) const {
        return std::make_shared<RuleLinear>(list, cond, callbacks);

    }

    std::shared_ptr<Rule> createLinear(std::vector<XVariable*> &list, std::vector<int> &coeffs, XCondition &cond, CHRCallbacks* callbacks) const {
        return std::make_shared<RuleLinear>(list, coeffs, cond, callbacks);
    }

    std::shared_ptr<Rule> createLinear(std::vector<XVariable*> &list, std::vector<XVariable*> &coeffs, XCondition &cond, CHRCallbacks* callbacks) const {
        return std::make_shared<RuleLinear>(list, coeffs, cond, callbacks);
    }
};
