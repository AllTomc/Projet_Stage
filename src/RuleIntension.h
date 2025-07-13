#pragma once

#include "Rule.h"
#include "RuleRaw.h"
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <limits>
#include <sstream>

class CHRCallbacks;

using namespace std;
using namespace XCSP3Core;

class RuleIntension : public Rule {
private:
    Tree* tree;
    CHRCallbacks* callbacks;
    
    struct TempVar {
        std::string name;
        std::string interval;
        int id;
    };
public:
    RuleIntension(Tree* t,CHRCallbacks* cb);

    std::string toCHR() override;  
    void finalize() override;

private:

    TempVar translate_expression(Node* n);
    std::pair<int, int> getInterval(int id);
    bool isBuiltin(const std::string& name) const;
    std::shared_ptr<RuleRaw> getBuiltinRule(const Predicate& pred);
};
