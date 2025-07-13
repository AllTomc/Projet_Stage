#pragma once
#include <string>
#include <vector>
#include <sstream>

class Predicate {
private:
    std::string name;
    std::vector<std::string> types;
    std::vector<std::string> elements;

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

    Predicate() {
    }

    std::string toString() const {
        return toStringElement();
    }

    std::string toStringElement() const {
        std::ostringstream oss;
        oss << name << "(";
        for (size_t i = 0; i < elements.size(); ++i) {
            oss << elements[i];
            if (i + 1 < elements.size()) oss << ",";
        }
        oss << ")";
        return oss.str();
    }

    std::string toStringType() const {
        std::ostringstream oss;
        oss << name << "(";
        for (size_t i = 0; i < types.size(); ++i) {
            oss << types[i];
            if (i + 1 < types.size()) oss << ",";
        }
        oss << ")";
        return oss.str();
    }

    bool operator==(const Predicate& other) const {
    return name == other.name && types == other.types && elements == other.elements ;
}
};
