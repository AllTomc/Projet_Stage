#pragma once
#include "XCSP3CoreParser.h"
#include "Rule.h"
#include "RuleIntension.h"
#include <iostream>
#include <ostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <regex>

using namespace std;
using namespace XCSP3Core;

struct CHRStruct {
    std::string header;
    std::string functions;
    std::string chrBlocks;
    std::string mainCode;
    bool onlyChrBlocks = true;

    void generateFullCode(std::ostream &out) const {
        if(onlyChrBlocks){
            out << chrBlocks << "\n";
        }else {
        out << header << "\n\n"
            << functions << "\n\n"
            << chrBlocks << "\n"
            << mainCode;
        }
    }
};

class CHRStructBuilder  {
public:
    std::string chrname = "defaultName";
    std::shared_ptr<int> global_id_val = std::make_shared<int>(0);
    std::string build_call;
    std::string build_init;
    std::string build_instantiation;
    bool dom = false;
    bool trace = false;
    bool print = false;
    CHRStruct chrCode;

    std::string prefixe_op = "CspOp";

    CHRStructBuilder() {} ;
    CHRStructBuilder(std::string filename) :chrname(filename){} ;


    void enableBuilder() {
        chrCode.onlyChrBlocks = false;
    }

    void init() {
        std::ostringstream head;
        head << "#include <iostream>\n";
        head << "#include <map>\n";
        head << "#include <string>\n";
        head << "#include <list>\n";
        head << "#include <regex>\n";
        head << "#include <chrpp.hh>\n";
        head << "#include <bt_interval.hh>\n";
        head << "#include <solvint.cpp>\n";
        head << "\nusing namespace chr;\n";
        head << "using interval = chr::Interval<int, false>;\n";
        head << "using string = std::string;\n";
        head << "using list_var = std::list<chr::Logical_var<int>>;\n";
        head << "using list_int = std::list<int>;\n";
        head << "int global_id = " << global_id() << ";\n";
        head << "std::map<int, std::string> id_name_map;\n";
        chrCode.header = head.str();
    }

    void setCHRBlock(const std::string &chrContent) {
        chrCode.chrBlocks = chrContent;
    }

    int global_id() const {
        return *global_id_val;
    }
    void add_default_functions() {
        std::ostringstream f;
        f << "template <typename T>\n"
          << "void print_store(T& pb) {\n"
          << "    auto it = pb.chr_store_begin();\n"
          << "    while (!it.at_end()) {\n"
          << "        std::cout << it.to_string() << std::endl;\n"
          << "        ++it;\n"
          << "    }\n"
          << "}\n\n";

        //f << "template<typename... Args>\n"
        //  << "list_var make_list_var(Args... args) {\n"
        //  << "    return list_var{args...};\n"
        //  << "}\n\n";
        //
        //f << "template<typename... Ints>\n"
        //  << "list_int make_list_int(Ints... ints) {\n"
        //  << "    return list_int{ints...};\n"
        //  << "}\n\n";

        f << "inline chr::ES_CHR maj_dom(chr::Logical_var_mutable<interval> &i, int val) {\n"
          << "    bool modified = false;\n"
          << "    return i.update_mutable(modified, [&modified, val](auto& intvl) {\n"
          << "        modified = intvl.eq(val);\n"
          << "    });\n"
          << "}\n\n";

        f << "inline chr::ES_CHR set_eq(chr::Logical_var_mutable<interval> &x, int v) {\n"
          << "    bool modified = false;\n"
          << "    return x.update_mutable(modified, [&modified, v](auto& intvl1){\n"
          << "        modified = intvl1.eq(v);\n"
          << "    });\n"
          << "}\n\n";

        f << "template <typename T> \n"
          << "void print_matrix(T& pb) {\n"
          << "    std::regex re(R\"(x\\[(\\d+)\\]\\[(\\d+)\\],\\s*(\\d+),)\");\n"
          << "    std::vector<std::tuple<int, int, int>> assignments;\n"
          << "\n"
          << "    int count = 0;\n"
          << "    auto it = pb.chr_store_begin();\n"
          << "\n"
          << "    // Collecte des faits CspVarIntDec\n"
          << "    while (!it.at_end()) {\n"
          << "        std::string fact = it.to_string();\n"
          << "        if (fact.find(\"CspVarIntDec\") != std::string::npos) {\n"
          << "            std::smatch match;\n"
          << "            if (std::regex_search(fact, match, re)) {\n"
          << "                int i = std::stoi(match[1].str());\n"
          << "                int j = std::stoi(match[2].str());\n"
          << "                int val = std::stoi(match[3].str());\n"
          << "                assignments.emplace_back(i, j, val);\n"
          << "                ++count;\n"
          << "            }\n"
          << "        }\n"
          << "        ++it;\n"
          << "    }\n"
          << "\n"
          << "    if (count == 0) {\n"
          << "        std::cout << \"Aucune variable CspVarIntDec trouvée.\"; \n"
          << "        return;\n"
          << "    }\n"
          << "\n"
          << "    // Calcul de la dimension d\n"
          << "    int d = std::sqrt(count);\n"
          << "    if (d * d != count) {\n"
          << "        std::cerr << \"Erreur : le nombre de variables (\" << count << \") n'est pas un carré parfait.\";\n"
          << "        return;\n"
          << "    }\n"
          << "\n"
          << "    // Initialisation de la grille\n"
          << "    std::vector<std::vector<int>> grid(d, std::vector<int>(d, 0));\n"
          << "    for (const auto& [i, j, val] : assignments) {\n"
          << "        if (i >= 0 && i < d && j >= 0 && j < d)\n"
          << "            grid[i][j] = val;\n"
          << "    }\n"
          << "\n"
          << "    // Affichage uniforme de la grille\n"
          << "    std::cout << \"======= Matrice \" << d << \"x\" << d << \" =======\" << std::endl;\n"
          << "    for (int i = 0; i < d; ++i) {\n"
          << "        for (int j = 0; j < d; ++j) {\n"
          << "            std::cout << std::setw(4) << (grid[i][j] ? std::to_string(grid[i][j]) : \".\");\n"
          << "        }\n"
          << "        std::cout << \"\\n\";\n"
          << "    }\n"
          << "    std::cout << \"=============================\";\n"
          << "}\n";


        chrCode.functions = f.str() + chrCode.functions ;

    }

    void add_linear_functions(){

        std::ostringstream f;
          f << "template<class T>\n"
          << "bool linear_post(T& space, const list_var& vars, const list_int& ids, int target) {\n"
          << "    if (vars.size() < 2 || vars.size() != ids.size()) return false;\n"
          << "    auto it = vars.begin();\n"
          << "    auto id_it = ids.begin();\n"
          << "    auto prev = *it++;\n"
          << "    int id_prev = *id_it++;\n"
          << "    for (; it != vars.end(); ++it, ++id_it) {\n"
          << "        int tmp_id = global_id++;\n"
          << "        Logical_var<int> tmpVar;\n"
          << "        Logical_var_mutable<interval> tmpDom = interval(0, 1000);\n"
          << "        CHECK_ES(space.CspTmpInt(\n"
          << "            Logical_var_ground<int>(tmp_id), tmpVar, tmpDom));\n"
          << "        CHECK_ES(space." << prefixe_op << "plus(\n"
          << "            Logical_var_ground<int>(id_prev), prev,\n"
          << "            Logical_var_ground<int>(*id_it), *it,\n"
          << "            Logical_var_ground<int>(tmp_id), tmpVar));\n"
          << "        prev = tmpVar;\n"
          << "        id_prev = tmp_id;\n"
          << "    }\n"
          << "    int final_id = global_id++;\n"
          << "    Logical_var<int> finalVar;\n"
          << "    Logical_var_mutable<interval> finalDom = interval(target, target);\n"
          << "    CHECK_ES(space.CspTmpInt(\n"
          << "        Logical_var_ground<int>(final_id), finalVar, finalDom));\n"
          << "    CHECK_ES(space." << prefixe_op << "eq(\n"
          << "        Logical_var_ground<int>(id_prev), prev,\n"
          << "        Logical_var_ground<int>(final_id), finalVar));\n"
          << "    CHECK_ES(set_eq(finalDom, target));\n"
          << "    return true;\n"
          << "}\n";

        chrCode.functions += f.str();
    }

    void add_alldiferrent_functions(){
        std::ostringstream f;
          f << "template<class T>\n"
          << "bool alldiff_post(T& space, const list_var& vars, const list_int& ids) {\n"
          << "    auto it1 = vars.begin();\n"
          << "    auto id1 = ids.begin();\n"
          << "    for (; it1 != vars.end(); ++it1, ++id1) {\n"
          << "        auto it2 = it1;\n"
          << "        auto id2 = id1;\n"
          << "        ++it2; ++id2;\n"
          << "        for (; it2 != vars.end(); ++it2, ++id2) {\n"
          << "            CHECK_ES(space." << prefixe_op << "neq(chr::Logical_var_ground<int>(*id1), *it1, chr::Logical_var_ground<int>(*id2), *it2));\n"
          << "        }\n"
          << "    }\n"
          << "    return true;\n"
          << "}\n";
        chrCode.functions += f.str();
    }

    void generateMainFunction(const std::string& chrName) {
        std::ostringstream main;
        main << "int main(int argc, const char *argv[]) {\n";
        if (trace)
            main << "    TRACE(chr::Log::register_flags(chr::Log::ALL);)\n\n";
        main << "    auto space = " << chrName << "::create();\n";
        main << build_init;
        main << build_instantiation;
        main << "CHR_RUN(";
        main << build_call;
        main << "); \n";
        if (print) {
            main << "    std::cout << \" Contenu du store :\";\n";
            main << "    print_store(*space);\n";
            main << "    std::cout << \" Table des ids :\" << std::endl;\n";
            main << "    for (const auto& [id, name] : id_name_map) {\n";
            main << "        std::cout << \"  id=\" << id << \" : \" << name << \"\\n\";\n";
            main << "    }\n";
        }
        main << "CHR_RUN(space->labelling(0);); \n";
        main << "chr::Statistics::print(std::cout);\n";
        main << "return 0;\n";
        main << "}\n";
        chrCode.mainCode = main.str();
    }

    void build_file() {
        init();
        add_default_functions();
        generateMainFunction(chrname);
    }

    void addPredicateCallToSpace(const std::string& predicateCall) {
        build_call += "space->" + predicateCall + ";\n";
    }

    void addPredicateCallToMain(const std::string& predicateCall) {
        build_call +=  predicateCall + ";\n";
    }

    void addInitialisationVar(std::string id, int minValue, int maxValue) {
        std::ostringstream init;
        init << "Dom[" << global_id() << "] = interval(" << minValue << "," << maxValue <<  ");\n";
        init << "space->CspVarIntDec(" << global_id() << ", string(\""<< id << "\"), X[" << global_id() << "], Dom[" << global_id() << "]);\n";
        build_init += init.str();
    }

    void addInitialisationTmpVar(std::string id, int minValue, int maxValue) {
        std::ostringstream init;
        init << "Dom[" << global_id() << "] = interval(" << minValue << "," << maxValue <<  ");\n";
        init << "space->CspTmpInt(" << global_id() << ", X[" << global_id() << "], Dom[" << global_id() << "]);\n";
        build_init += init.str();
    }

     void addInitialisationBlock(int n) {
        std::ostringstream initB;
        initB << "chr::Logical_var<int> X[" << n << "];\n";
        initB << "chr::Logical_var_mutable<interval> Dom[" << n << "];\n\n";
        build_init = initB.str() + build_init ;
    }


    void addInstantiations(const std::map<int, int>& instanciations) {
        for (const auto& [index, value] : instanciations) {
                 build_instantiation += "set_eq(Dom[" + std::to_string(index) + "], " + std::to_string(value) + ");\n";
             }
             build_instantiation += "\n";
        }
};
