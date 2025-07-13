#pragma once
#include <iostream>
#include <tuple>

struct VarDecl {
        int id;
        std::string name;
        int min;
        int max;
        bool operator<(const VarDecl& other) const {
            return std::tie(id, name, min, max) < std::tie(other.id, other.name, other.min, other.max);
        }
};