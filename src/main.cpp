#include "CHRParser.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> splitRules(const string &rules) {
    vector<string> result;
    stringstream ss(rules);
    string rule;
    while (getline(ss, rule, ',')) {
        result.push_back(rule);
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
        } else if (arg[0] == '-' || arg[0] == '-help') {
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

    // TODO minimalMode / selectedRules 
    CHRParser parser(filePath, useBuilder, useFile);

    return 0;
}
