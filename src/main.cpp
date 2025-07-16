#include "CHRParser.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

std::string normalizeRuleName(const std::string& input) {
    std::string result;
    std::locale loc;
    for (char c : input) {
        if (!std::isspace(c, loc))
            result += std::tolower(c, loc);
    }
    return result;
}

std::vector<std::string> splitRules(const std::string& rules) {
    std::vector<std::string> result;
    std::stringstream ss(rules);
    std::string rule;
    while (std::getline(ss, rule, ',')) {
        result.push_back(normalizeRuleName(rule));
    }
    return result;
}

void printUsage(const string &execName) {
    cerr << "Usage: " << execName << " [options] <instance.xml>\n"
         << "Options disponibles :\n"
         << "  -b               Utiliser CHRStructBuilder\n"
         << "  -m               Mode minimal\n"
         << "  -s [r1,r2,...]   Sélectionner uniquement certaines règles\n"
         << "  -f               Utilisation d'un fichier de sortie [filename].chrpp \n"
         << "Exemple : ./parserXCSPtoCHR.sh -b -m -s [linear,allDifferent] instance.xml\n";
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printUsage(argv[0]);
        return 1;
    }

    bool useBuilder = false;
    bool minimalMode = false;
    bool useFile = false;
    vector<string> selectedRules;
    string filePath;

    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];
        if (arg == "-b") {
            useBuilder = true;
        } else if (arg == "-m") {
            minimalMode = true;
        } else if (arg == "-f") {
            useFile = true;
        } else if (arg == "-s") {
            if (i + 1 < argc) {
                selectedRules = splitRules(argv[++i]);
            } else {
                cerr << "Erreur: L'option -s nécessite une liste de règles.\n";
                return 1;
            }
        } else if (arg == "-help" ) {
            cerr << "Option inconnue : " << arg << "\n";
            printUsage(argv[0]);
            return 1;
        } else {
            filePath = arg;
        }
    }

    if (filePath.empty()) {
        cerr << "Erreur: Aucun fichier instance fourni.\n";
        printUsage(argv[0]);
        return 1;
    }

    CHRParser parser(filePath, selectedRules, useBuilder, useFile, minimalMode);

    return 0;
}
