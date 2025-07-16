#pragma once

#include <iostream>
#include <fstream>
#include <regex>
#include "CHRCallbacks.h"
#include "CHRStructBuilder.h"

using namespace std;
using namespace XCSP3Core;

class CHRParser : public XCSP3Core::XCSP3CoreParser {
private:
    CHRCallbacks parserCallbacks;
    std::unique_ptr<CHRStructBuilder> structBuilderPtr = nullptr;
    bool useBuilder;
    bool useFile;
    bool minimalMode;
    vector<string> selectedRules;

public:
    CHRParser(const std::string &filePath, vector<string> selectedRules, bool useBuilder = false, bool useFile = false, bool minimalMode = false)
    : XCSP3CoreParser(&parserCallbacks), useBuilder(useBuilder), useFile(useFile), minimalMode(minimalMode), selectedRules(selectedRules) {

        std::regex fileRegex(R"(([^/\\]+)(?=\.[^/\\]+$))");
        std::smatch match;
        std::string filename;
        std::string outputPath;

        if (std::regex_search(filePath, match, fileRegex)) {
            filename = match[1];
        } else {
            std::cerr << "Erreur format de l'instance" << std::endl;
            return;
        }
        std::ostream* outStream = nullptr;
        std::ofstream outFile;
        if (useFile) {
            std::string outputPath = "out/" + filename + ".chrpp";
            outFile.open(outputPath);
            if (!outFile.is_open()) {
                std::cerr << "Impossible d'ouvrir le fichier de sortie" << std::endl;
                return;
            }
            outStream = &outFile;
        } else {
            outStream = &std::cout;
        }

        structBuilderPtr = std::make_unique<CHRStructBuilder>(filename);
        if (useBuilder) {
        structBuilderPtr->enableBuilder();
        } 
        parserCallbacks = CHRCallbacks(structBuilderPtr.get(), *outStream, filename,minimalMode, selectedRules);
        this->parse(filePath.c_str());

        std::cout << "C++ généré "<< std::endl;
    }
    void setMinimalMode() {
        parserCallbacks.setMinimalMode();
    }

    void onlySelectedRules(std::vector<std::string> rules) {
        parserCallbacks.onlySelectedRules(rules);
    }
};


