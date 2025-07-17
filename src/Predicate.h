#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <memory>

class Predicate {
private:
    std::string name;
    std::vector<std::string> types;
    std::vector<std::string> elements;
    static std::string prefix_op ;

public:
    Predicate(const std::string& name) : name(name) {}

    Predicate(const std::string& name, const std::vector<std::string> types) : name(name), types(types) {}
    const std::string& getName() const { return name; }
    const std::vector<std::string>& getTypes() const { return types; }
    const std::vector<std::string>& getElements() const { return elements; }
    void setTypes(const std::vector<std::string>& t) { types = t; }
    void setElements(const std::vector<std::string>& e) { elements = e; }
    void addType(const std::string& t) { types.push_back(t); }
    void addElement(const std::string& e) { elements.push_back(e); }
    void setName(const std::string& s) {name = s;}
    static void setprefix_op(const std::string & s) {prefix_op = s;}

    Predicate() {
    }

    std::string toString() const {
        return toStringElement();
    }
    std::string toStringElement() const ;
    std::string toStringType() const ;

    bool operator==(const Predicate& other) const {
        return name == other.name && types == other.types && elements == other.elements ;
    }

    // ===============================
    // Static Rule Factories
    // ===============================

    static std::shared_ptr<Predicate> varIntDec() ;
    static std::shared_ptr<Predicate> varInt() ;
    static std::shared_ptr<Predicate> tmpInt() ;
    static std::shared_ptr<Predicate> labelling() ;
    
    // Opérateurs arithmétiques
    static std::shared_ptr<Predicate> cspOp(const std::string& opName) ;
};
