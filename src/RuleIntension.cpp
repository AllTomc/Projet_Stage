#include "RuleIntension.h"
#include "CHRCallbacks.h"

RuleIntension::RuleIntension(Tree* t, CHRCallbacks* cb)
    : Rule("intension", cb), tree(t), callbacks(cb) {
    toCHR();
}

void RuleIntension::finalize() {
    for (const Predicate& pred : this->getTail()) {
        std::string name = pred.getName().substr(prefix_op.length());
        if (isBuiltin(name)) {
            auto rule = getBuiltinRule(pred);
            if (rule && !callbacks->hasRule(rule->toString())) {
                callbacks->addRule(rule);
                callbacks->add_constraint(std::make_shared<Predicate>(pred));
            }
        }
    }
}

using RuleF = std::function<std::shared_ptr<RuleRaw>()>;
static const std::map<std::string, RuleF> rule_dispatch = {
    {"eq",   []() { return RuleRaw::eqRule(); }},
    {"neq",  []() { return RuleRaw::neqRule(); }},
    {"lt",   []() { return RuleRaw::ltRule(); }},
    {"le",   []() { return RuleRaw::leRule(); }},
    {"gt",   []() { return RuleRaw::gtRule(); }},
    {"ge",   []() { return RuleRaw::geRule(); }},
    {"plus", []() { return RuleRaw::plusRule(); }},
    {"div",  []() { return RuleRaw::divRule(); }}
};


std::shared_ptr<RuleRaw> RuleIntension::getBuiltinRule(const Predicate& pred) {
    std::string name = pred.getName().substr(prefix_op.length());
    auto it = rule_dispatch.find(name);
    if (it != rule_dispatch.end()) {
        return it->second();
    }
    return nullptr;
}



std::string RuleIntension::toCHR() {
    TempVar result = translate_expression(tree->root);
    return Rule::toCHR();
}

RuleIntension::TempVar RuleIntension::translate_expression(Node* n) {
    if (auto var = dynamic_cast<NodeVariable*>(n)) {
        std::string v = var->var;
        v.erase(remove_if(v.begin(), v.end(), ::isspace), v.end());
        int id = callbacks->getNameIdMap()[v];
        return {"X[" + std::to_string(id)+ "]", "Interval_" + std::to_string(id), id};
    }

    if (auto cst = dynamic_cast<NodeConstant*>(n)) {
        int val = cst->val;
        std::string s = "C" + std::to_string(val) ;
        callbacks->buildCstInteger(s,val);
        int idC = callbacks->getNameIdMap()[s];
        return {"X[" + std::to_string(idC)+ "]", "Interval_" + std::to_string(idC), idC};
    }

    if (auto op = dynamic_cast<NodeOperator*>(n)) {
        std::string opname = op->op;
        std::vector<TempVar> args;
        for (Node* p : op->parameters)
            args.push_back(translate_expression(p));


        if ((opname == "lt" || opname == "le" || opname == "gt" || opname == "ge" || opname == "eq" || opname == "neq")) {
            Predicate pred = *Predicate::cspOp(opname);
            pred.setElements({
                std::to_string(args[0].id), args[0].name,
                std::to_string(args[1].id), args[1].name
            });
            addTail(pred);
            callbacks->getBuilder()->addPredicateCallToSpace(pred.toString());
            return {"", "", -1};
        }

        if ((opname == "add" || opname == "sub" || opname == "mul" || opname == "div") ) {
            int tmp_id = callbacks->global_id();
            std::string xname = "X[" + std::to_string(tmp_id) + "]";
            std::string interval_name = "IntervalTmp_" + std::to_string(tmp_id);

            std::pair<int, int> i1 = (args[0].id >= 0) ? getInterval(args[0].id) : std::make_pair(std::stoi(args[0].name), std::stoi(args[0].name));
            std::pair<int, int> i2 = (args[1].id >= 0) ? getInterval(args[1].id) : std::make_pair(std::stoi(args[1].name), std::stoi(args[1].name));
            std::pair<int, int> result_interval;

            if (opname == "add")
                result_interval = {i1.first + i2.first, i1.second + i2.second};
            else if (opname == "sub")
                result_interval = {i1.first - i2.second, i1.second - i2.first};
            else if (opname == "mul") {
                std::vector<int> values = {i1.first * i2.first, i1.first * i2.second, i1.second * i2.first, i1.second * i2.second};
                result_interval = {*min_element(values.begin(), values.end()), *max_element(values.begin(), values.end())};
            } else if (opname == "div") {
                if (i2.first <= 0 && i2.second >= 0)
                    result_interval = {std::numeric_limits<int>::min(), std::numeric_limits<int>::max()};
                else {
                    std::vector<int> values = {i1.first / i2.first, i1.first / i2.second, i1.second / i2.first, i1.second / i2.second};
                    result_interval = {*min_element(values.begin(), values.end()), *max_element(values.begin(), values.end())};
                }
            }


            callbacks->buildTmpVariableInteger(xname, result_interval.first, result_interval.second);
            std::string chr_op = (opname == "add") ? ("plus") : (opname);
            Predicate pred = *Predicate::cspOp(chr_op);
            pred.setElements({
                std::to_string(args[0].id), args[0].name,
                std::to_string(args[1].id), args[1].name,
                std::to_string(tmp_id), xname
            });
            addTail(pred);
            callbacks->getBuilder()->addPredicateCallToSpace(pred.toString());
            return {xname, interval_name, tmp_id};
        }
    }

    return {"", "", -1};
}

std::pair<int, int> RuleIntension::getInterval(int id) {
    auto it = std::find_if(callbacks->getVars().begin(), callbacks->getVars().end(), [&](const VarDecl& v) { return v.id == id; });
    if (it != callbacks->getVars().end()) return {it->min, it->max};
    std::cerr << "Erreur : intervalle introuvable pour l'ID " << id << std::endl;
    return {0, 0};
}

bool RuleIntension::isBuiltin(const std::string& name) const {
    static const std::set<std::string> builtin_names = {
        "eq", "neq", "lt", "le", "gt", "ge", "plus", "div"
    };
    return builtin_names.count(name) > 0;
}
