#include "CHRCallbacks.h"
#include "RuleAllDiff.h"
#include "RuleInstantiation.h"
#include "RuleLinear.h" 


CHRCallbacks::CHRCallbacks(CHRStructBuilder* v, std::ostream& outputStream, std::string name, bool minimalMode, std::vector<std::string> selectedRules)
    : builder(v), out(&outputStream), chrname(name), minimalMode(minimalMode), selectedRules(selectedRules) 
    {
        global_id_val = builder->global_id_val;
        //On nomme le préfixe de la variable static de Rule pour les opérateurs, principe réutilisable pour les autres préfixes.
        Rule::setprefix_op("CspOp");
        if(minimalMode) {
            Rule::enable_minimalMode();
        }
    }
CHRCallbacks::CHRCallbacks()
    : builder(nullptr), out(&std::cout) {}
    
CHRCallbacks::~CHRCallbacks() = default;


void CHRCallbacks::setMinimalMode() {
    minimalMode = true;
}

void CHRCallbacks::onlySelectedRules(std::vector<std::string> rules){
    selectedRules = rules;
}

void CHRCallbacks::beginInstance(XCSP3Core::InstanceType type) {
    std::cout << "Début de l'instance" << std::endl;
}

void CHRCallbacks::endInstance() {
    std::cout << "Fin de l'instance." << std::endl;
    std::string rulesStream;
    close(rulesStream);
}


// Fonctions de gestions variables et domaines 
void CHRCallbacks::buildVariableInteger(std::string id, int minValue, int maxValue) {
    std::cout << "Variable entière : " << id << " avec domaine [" << minValue << ", " << maxValue << "]" << std::endl;
    if (!var_declaration_rule_added) {
        addDomainPropagationRules();
        add_constraint(Predicate::varIntDec());
        add_constraint(Predicate::varInt());
        add_constraint(Predicate::tmpInt());
        
        rules.emplace_back(RuleRaw::declarationRules());
        var_declaration_rule_added = true;
    }

    vars_set.insert(VarDecl{global_id(), id, minValue, maxValue});
    addIdNamePair(global_id(), id);
    getBuilder()->addInitialisationVar(id,minValue,maxValue);
    inc_global_id();
}



void CHRCallbacks::buildVariableInteger(std::string id, std::vector<int>& values) {
    std::cout << "Variable entière : " << id << " avec valeurs NI";
}

void CHRCallbacks::buildTmpVariableInteger(std::string id, int minValue, int maxValue) {
    //std::cout << "Variable entière temporaire : " << id << " avec domaine [" << minValue << ", " << maxValue << "]" << std::endl;
    vars_set.insert(VarDecl{global_id(), id, minValue, maxValue});
    addIdNamePair(global_id(), id);
    builder->addInitialisationTmpVar(id,minValue,maxValue);
    inc_global_id();
}

void CHRCallbacks::buildCstInteger(std::string id, int value) {
    //std::cout << "Constante  de valeur :  " << value <<  std::endl;
    vars_set.insert(VarDecl{global_id(), id, value, value});
    addIdNamePair(global_id(), id);
    builder->addInitialisationTmpVar(id,value,value);
    inc_global_id();
}
//


// Fonctions de gestions des règles 

void CHRCallbacks::buildConstraintIntension(std::string id, Tree* tree) {
    if(isRuleSelected("intension")) {
    std::cout << "Intension (Tree)" << std::endl;
    auto rule = factory.createIntensionRule(tree, this);
    rules.emplace_back(rule);
    rule->finalize();
    }
}


void CHRCallbacks::buildConstraintAlldifferent(std::string id, std::vector<XVariable *> &list) {
    if(isRuleSelected("alldiff")) {
    std::cout << "AlldifferentRule" << std::endl;
    auto rule = factory.createAllDiffRule(id, list, this);
    rules.push_back(rule);
    rule->finalize();
}
}
    
void CHRCallbacks::buildConstraintInstantiation(string id, vector<XVariable *> &list, vector<int> &values) {
    if(isRuleSelected("instantiation")) {
    std::cout << "InstantiationRule" << std::endl;
    auto rule = factory.createInstantiation(list, values, this);
    rules.push_back(rule);
   rule->finalize();
}
}

void CHRCallbacks::buildConstraintSum(string id, vector<XVariable *> &list, XCondition &cond) {
    if(isRuleSelected("linear")) {
    std::cout << "LinearRule" << std::endl;
    auto ruleUS = factory.createLinear(list, cond, this);
    rules.emplace_back(ruleUS);
    ruleUS->finalize();
}
}


void CHRCallbacks::buildConstraintSum(string id, vector<XVariable*> &list, vector<int> &coeffs, XCondition &cond) {
    if(isRuleSelected("linear")) {
    std::cout << "LinearRule_coeffs" << std::endl;
    auto rule = factory.createLinear(list, coeffs, cond, this);
    rules.emplace_back(rule);
    rule->finalize();
}
}

void CHRCallbacks::buildConstraintSum(string id, vector<XVariable*> &list, vector<XVariable*> &coeffs, XCondition &cond) {
    if(isRuleSelected("linear")) {
    std::cout << "LinearRule_coeffs_var" << std::endl;
    auto rule = factory.createLinear(list, coeffs, cond, this);
    rules.emplace_back(rule);
    rule->finalize();
}
}

//


void CHRCallbacks::close(std::string rulesText) {
    // Ajouter labelling
    add_constraint(Predicate::labelling());

    rules.emplace_back(RuleRaw::labellingRules());
    

    std::string chr;
    chr += "<CHR name=\"" + chrname + "\">\n<chr_constraint> ";
    for (size_t i = 0; i < chr_constraints_define.size(); ++i) {
        chr += chr_constraints_define[i]->toStringType();
        if (i != chr_constraints_define.size() - 1)
            chr += ", ";
    }
    chr += "\n";

    std::vector<std::shared_ptr<Rule>> rawRules;
    for (const auto& rule : rules) {
        if (std::dynamic_pointer_cast<RuleRaw>(rule)) {
            chr += rule->toString() + "\n";
        } 
    }

    chr += "</CHR>\n";

    if (builder != nullptr) {
        builder->setCHRBlock(chr);

        builder->addInitialisationBlock(global_id());
        std::map<int, int> instanciations;
        for (const auto& pred : predicates_init_element) {
            if (pred.getName() == "set_eq" && pred.getElements().size() == 2) {
                const std::string& var = pred.getElements()[0];
                int value = std::stoi(pred.getElements()[1]);

                if (name_id_map.count(var)) {
                    int varId = name_id_map[var];
                    instanciations[varId] = value;
                }
            }
        }
        builder->addInstantiations(instanciations);

        // Génére le reste du code (main, print, etc.)
        builder->build_file();
        builder->chrCode.generateFullCode(*out);
    } else {
        *out << chr;
    }
}




 


/* Fonctions auxiliaires
*
* 
*/


bool CHRCallbacks::isRuleSelected(const std::string& ruleName) const {
    if (selectedRules.empty()) return true;

    return std::find(selectedRules.begin(), selectedRules.end(), ruleName) != selectedRules.end();
}

bool CHRCallbacks::addIdNamePair(int id, const std::string& name) {
    if (id_name_map.count(id) || name_id_map.count(name))
        return false; 
    id_name_map[id] = name;
    name_id_map[name] = id;
    return true;
}

const std::string& CHRCallbacks::getNameById(int id) const {
    return id_name_map.at(id); 
}

int CHRCallbacks::getIdByName(const std::string& name) const {
    return name_id_map.at(name); 
}

int CHRCallbacks::global_id() const {
    return *global_id_val;
}

void CHRCallbacks::inc_global_id()  {
     {(*global_id_val)++;}
}

int CHRCallbacks::getNextId() {
    inc_global_id();
    return global_id();
}

std::map<int, std::string>& CHRCallbacks::getIdNameMap() {
    return id_name_map;
}

std::map<std::string, int>& CHRCallbacks::getNameIdMap() {
    return name_id_map;
}

void CHRCallbacks::setOut(std::ostream &outputStream) {
    out = &outputStream;
}

bool CHRCallbacks::add_constraint(std::shared_ptr<Predicate> predicate) {
    for (auto &existing : chr_constraints_define) {
        if (*existing == *predicate) { 
            return false;
    }
}
    chr_constraints_define.push_back(predicate);
    
    return true ;
}

void CHRCallbacks::addDomainPropagationRules() {
    rules.emplace_back(RuleRaw::domainPropagationRules());
    //std::cout << "Ajout règle de propagation ! " << std::endl ;
}   

void CHRCallbacks::addRule(std::shared_ptr<Rule> rule) {
    rules.emplace_back(std::move(rule));
}

bool CHRCallbacks::hasRule(const std::string& ruleStr) const {
    return std::any_of(rules.begin(), rules.end(),
                       [&ruleStr](const std::shared_ptr<Rule>& r) {
                           return r->toString() == ruleStr;
                       });
}

void CHRCallbacks::addToInit(const Predicate& pred) {
    predicates_init_element.push_back(pred);
}

const std::set<VarDecl>& CHRCallbacks::getVars() const {
    return vars_set;
}

CHRStructBuilder*  CHRCallbacks::getBuilder() {
    return builder;
}






/* À définir 
*
*
*/
void CHRCallbacks::buildConstraintAlldifferent(std::string id, std::vector<Tree *> &list)  {
    std::cout << "AllDifferent (expressions) (NI) " << std::endl;
}
void CHRCallbacks::buildConstraintAlldifferentExcept(std::string id, std::vector<XVariable *> &list, std::vector<int> &except)  {
    std::cout << "AllDifferent (avec exceptions) (NI) " << std::endl;
}
void CHRCallbacks::buildConstraintAlldifferentList(std::string id, std::vector<std::vector<XVariable *>> &lists)  {
    std::cout << "AllDifferent (listes) (NI)"  << std::endl;
}
// AllDifferent - matrice
void CHRCallbacks::buildConstraintAlldifferentMatrix(std::string id, std::vector<std::vector<XVariable *>> &matrix)  {
    std::cout << "AllDifferent (matrice) (NI)" << std::endl;
}
/*
void buildConstraintSum(string id, vector<Tree *> &list, vector<int> &coeffs, XCondition &cond) override;
void buildConstraintSum(string id, vector<Tree *> &list, XCondition &cond) override;
*/
void CHRCallbacks::buildConstraintIntension(std::string id, std::string expr) {
    std::cout << "Intension (NI)" << std::endl;
}
    