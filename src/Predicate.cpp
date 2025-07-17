#include "Predicate.h"

std::string Predicate::prefix_op = "";

std::shared_ptr<Predicate> Predicate::varIntDec() {
    return std::make_shared<Predicate>("CspVarIntDec", std::vector<std::string>{"+int", "+string", "?int", "-interval"});
}

std::shared_ptr<Predicate> Predicate::varInt() {
    return std::make_shared<Predicate>("CspVarInt", std::vector<std::string>{"+int", "?int", "-interval"});
}

std::shared_ptr<Predicate> Predicate::tmpInt() {
    return std::make_shared<Predicate>("CspTmpInt", std::vector<std::string>{"+int", "?int", "-interval"});
}

std::shared_ptr<Predicate> Predicate::labelling() {
    return std::make_shared<Predicate>("labelling", std::vector<std::string>{"+int"});
}

// Opérateurs arithmétiques
std::shared_ptr<Predicate> Predicate::cspOp(const std::string& opName) {
if (opName == "lt" || opName == "le" || opName == "gt" || opName == "ge" || opName == "eq" || opName == "neq") {
    return std::make_shared<Predicate>(prefix_op + opName, std::vector<std::string>{"+int", "?int","+int","?int"});
}
if ((opName == "plus" || opName == "sub" || opName == "mul" || opName == "div") ){
    return std::make_shared<Predicate>(prefix_op + opName, std::vector<std::string>{"+int", "?int","+int", "?int","+int", "?int"});
}
else return nullptr;
}

std::string Predicate::toStringElement() const {
    std::ostringstream oss;
    oss << name << "(";
    for (size_t i = 0; i < elements.size(); ++i) {
        oss << elements[i];
        if (i + 1 < elements.size()) oss << ",";
    }
    oss << ")";
    return oss.str();
}
std::string Predicate::toStringType() const {
    std::ostringstream oss;
    oss << name << "(";
    for (size_t i = 0; i < types.size(); ++i) {
        oss << types[i];
        if (i + 1 < types.size()) oss << ",";
    }
    oss << ")";
    return oss.str();
}
