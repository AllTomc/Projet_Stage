#pragma once
#include "XCSP3CoreParser.h"
#include "CHRStructBuilder.h"
#include "Predicate.h"
#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include "RuleFactory.h"
#include "RuleRaw.h"

class Rule;
class CHRCallbacks : public XCSP3Core::XCSP3CoreCallbacks {
protected:
    std::string chrname = "defaultName";
    CHRStructBuilder* builder;
    std::ostream* out;

    std::vector<std::shared_ptr<Predicate>> chr_constraints_define;
    std::vector<std::shared_ptr<Rule>> rules;
    std::map<int, std::string> id_name_map;
    std::map<std::string, int> name_id_map;
    std::shared_ptr<int> global_id_val = std::make_shared<int>(0);
    bool var_declaration_rule_added = false;
    std::vector<Predicate> predicates_init_element;
    std::set<VarDecl> vars_set;
    RuleFactory factory;
public:
    CHRCallbacks(CHRStructBuilder* v, std::ostream& outputStream, std::string name);
    CHRCallbacks(std::ostream& out);
    CHRCallbacks(std::ostream& out, std::string name);
    CHRCallbacks();
    ~CHRCallbacks();
    void beginInstance(XCSP3Core::InstanceType type) override;
    void endInstance() override;
    void close(std::string rulesText);
    
    void buildTmpVariableInteger(std::string id, int minValue, int maxValue);
    void buildCstInteger(std::string id, int value);
    // Build 
    void buildVariableInteger(std::string id, int minValue, int maxValue) override;
    void buildVariableInteger(std::string id, std::vector<int>& values) override;
    void buildConstraintIntension(std::string id, Tree* tree) override;
    void buildConstraintIntension(std::string id, std::string expr) override;
    void buildConstraintInstantiation(std::string id, std::vector<XCSP3Core::XVariable*>& list, std::vector<int>& values) override;
    void buildConstraintAlldifferent(std::string id, std::vector<XCSP3Core::XVariable*>& list) override;
    void buildConstraintSum(string id, vector<XVariable *> &list, XCondition &cond) override;
    void buildConstraintSum(string id, vector<XVariable *> &list, vector<int> &coeffs, XCondition &cond) override;
    void buildConstraintSum(string id, vector<XVariable *> &list, vector<XVariable *> &coeffs, XCondition &cond) override;
    
    
    /*
    TODO
    void buildConstraintSum(string id, vector<Tree *> &list, vector<int> &coeffs, XCondition &cond) override;
    void buildConstraintSum(string id, vector<Tree *> &list, XCondition &cond) override;
    */
    // Getters 
    std::map<int, std::string>& getIdNameMap();
    std::map<std::string, int>& getNameIdMap();
    int getNextId();
    const std::string& getNameById(int id) const;
    int getIdByName(const std::string& name) const;
    const std::map<std::string, int>& getNameIdMap() const;
    const std::set<VarDecl>& getVars() const;
    std::string getCHRBlock() const;
    CHRStructBuilder* getBuilder();
    int global_id() const;
    void inc_global_id();
    // Setters 
    void setOut(std::ostream& outputStream);
    // Rule Tools
    bool add_constraint(std::shared_ptr<Predicate> predicate); 
    void addDomainPropagationRules();
    void addRule(std::shared_ptr<Rule> rule);
    bool hasRule(const std::string& ruleStr) const ; 
    bool addIdNamePair(int id, const std::string& name);
    void addToInit(const Predicate& pred);
    // Build TODO
    void buildConstraintAlldifferent(std::string id, std::vector<Tree*>& list) override;
    void buildConstraintAlldifferentExcept(std::string id, std::vector<XCSP3Core::XVariable*>& list, std::vector<int>& except) override;
    void buildConstraintAlldifferentList(std::string id, std::vector<std::vector<XCSP3Core::XVariable*>>& lists) override;
    void buildConstraintAlldifferentMatrix(std::string id, std::vector<std::vector<XCSP3Core::XVariable*>>& matrix) override;
};
