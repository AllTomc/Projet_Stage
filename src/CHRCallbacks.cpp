    #include "CHRCallbacks.h"
    #include "RuleAllDiff.h"
    #include "RuleInstantiation.h"
    #include "RuleLinear.h"



    CHRCallbacks::CHRCallbacks(CHRStructBuilder* v, std::ostream& outputStream, std::string name)
        : builder(v), out(&outputStream), chrname(name) {global_id_val = builder->global_id_val;}

    CHRCallbacks::CHRCallbacks(std::ostream& outputStream)
        : builder(nullptr), out(&outputStream)  {}

    CHRCallbacks::CHRCallbacks(std::ostream& outputStream, std::string name)
        : chrname(name), builder(nullptr), out(&outputStream) {}

    CHRCallbacks::CHRCallbacks()
        : builder(nullptr), out(&std::cout) {}

    CHRCallbacks::~CHRCallbacks() = default;

    void CHRCallbacks::beginInstance(XCSP3Core::InstanceType type) {
        std::cout << "Début de l'instance" << std::endl;
    }

    void CHRCallbacks::endInstance() {
        std::cout << "Fin de l'instance." << std::endl;
        std::string rulesStream;
        close(rulesStream);
    }

    void CHRCallbacks::buildVariableInteger(std::string id, int minValue, int maxValue) {
        std::cout << "Variable entière : " << id << " avec domaine [" << minValue << ", " << maxValue << "]" << std::endl;

        if (!var_declaration_rule_added) {
            addDomainPropagationRules();

            add_constraint(std::make_shared<Predicate>("CspVarIntDec", std::vector<std::string>{"+int", "+string", "?int", "-interval"}));
            add_constraint(std::make_shared<Predicate>("CspVarInt", std::vector<std::string>{"+int","?int", "-interval"}));
            add_constraint(std::make_shared<Predicate>("CspTmpInt", std::vector<std::string>{"+int", "?int", "-interval"}));
            
            rules.emplace_back(RuleRaw::declarationRules());
            var_declaration_rule_added = true;

        }

  

        vars_set.insert(VarDecl{global_id(), id, minValue, maxValue});
        addIdNamePair(global_id(), id);
        getBuilder()->addInitialisationVar(id,minValue,maxValue);
        inc_global_id();
    }



    void CHRCallbacks::buildVariableInteger(std::string id, std::vector<int>& values) {
        std::cout << "Variable entière : " << id << " avec valeurs Non utilisé";
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

    void CHRCallbacks::buildConstraintIntension(std::string id, Tree* tree) {
        std::cout << "Intension (Tree)" << std::endl;
        auto rule = factory.createIntensionRule(tree, this);
        rules.emplace_back(rule);
        rule->finalize();
    }

    void CHRCallbacks::buildConstraintIntension(std::string id, std::string expr) {
        std::cout << "Intension (NI)" << std::endl;
    }

    void CHRCallbacks::buildConstraintAlldifferent(std::string id, std::vector<XVariable *> &list) {
        std::cout << "AlldifferentRule" << std::endl;
        auto rule = factory.createAllDiffRule(id, list, this);
        rules.push_back(rule);
        rule->finalize();
    }
    
    void CHRCallbacks::buildConstraintInstantiation(string id, vector<XVariable *> &list, vector<int> &values) {
        std::cout << "InstantiationRule" << std::endl;
        auto rule = factory.createInstantiation(list, values, this);
        rules.push_back(rule);
       rule->finalize();
    }

    void CHRCallbacks::buildConstraintSum(string id, vector<XVariable *> &list, XCondition &cond) {
        std::cout << "LinearRule" << std::endl;
        auto ruleUS = factory.createLinear(list, cond, this);
        rules.emplace_back(ruleUS);
        ruleUS->finalize();
    }
    
    void CHRCallbacks::buildConstraintSum(string id, vector<XVariable*> &list, vector<int> &coeffs, XCondition &cond) {
        std::cout << "LinearRule_coeffs" << std::endl;
        auto rule = factory.createLinear(list, coeffs, cond, this);
        rules.emplace_back(rule);
        rule->finalize();
    }

    void CHRCallbacks::buildConstraintSum(string id, vector<XVariable*> &list, vector<XVariable*> &coeffs, XCondition &cond) {
        std::cout << "LinearRule_coeffs_var" << std::endl;
        auto rule = factory.createLinear(list, coeffs, cond, this);
        rules.emplace_back(rule);
        rule->finalize();
    }
    /*
    void buildConstraintSum(string id, vector<Tree *> &list, vector<int> &coeffs, XCondition &cond) override;
    void buildConstraintSum(string id, vector<Tree *> &list, XCondition &cond) override;
    */
void CHRCallbacks::close(std::string rulesText) {
    // Ajouter labelling
    auto labellingPred = std::make_shared<Predicate>("labelling", std::vector<std::string>{"+int"});
    add_constraint(labellingPred);

    std::vector<std::string> labellingRules = {
        "CspVarIntDec(Id, _, _, Dom) \\ labelling(Id) <=> exists_it(i, *Dom, ( set_eq(Dom,i) , labelling(Id+1)));;",
        "labelling(Id) <=> print_store(*this);;"
        //"labelling(Id) <=> print_matrix(*this);;"
    };

    for (const auto& ruleText : labellingRules) {
        rules.emplace_back(std::make_shared<RuleRaw>(ruleText));
    }

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
        //TOCHECK
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
                //std::cout << "doublon" << std::endl;
                return false;
        }
    }
        //std::cout << "ajout" << std::endl;
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
        std::cout << "AllDifferent (expressions) [" << id << "] : NI ";

    }

    void CHRCallbacks::buildConstraintAlldifferentExcept(std::string id, std::vector<XVariable *> &list, std::vector<int> &except)  {
        std::cout << "AllDifferent (avec exceptions) [" << id << "] : ";
        for (auto *var : list)
            std::cout << var->id << " ";
        std::cout << "| Exceptés : ";
        for (int val : except)
            std::cout << val << " ";
        std::cout << std::endl;

        /*
        if (builder)
            builder->buildAllDifferentExcept(id, list, except);
        */
    }

    void CHRCallbacks::buildConstraintAlldifferentList(std::string id, std::vector<std::vector<XVariable *>> &lists)  {
        std::cout << "AllDifferent (listes) [" << id << "] :" << std::endl;
        int idx = 1;
        for (const auto &list : lists) {
            std::cout << "  Liste " << idx++ << " : ";
            for (auto *var : list)
                std::cout << var->id << " ";
            std::cout << std::endl;
        }

        /*
        if (builder)
            builder->buildAllDifferentList(id, lists);
        */
    }

    // AllDifferent - matrice
    void CHRCallbacks::buildConstraintAlldifferentMatrix(std::string id, std::vector<std::vector<XVariable *>> &matrix)  {
        std::cout << "AllDifferent (matrice) [" << id << "] :" << std::endl;
        for (size_t row = 0; row < matrix.size(); ++row) {
            std::cout << "  Ligne " << row + 1 << " : ";
            for (auto *var : matrix[row])
                std::cout << var->id << " ";
            std::cout << std::endl;
        }

        /*
        if (builder)
            builder->buildAllDifferentMatrix(id, matrix);
        */
    }


