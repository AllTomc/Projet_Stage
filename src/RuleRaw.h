#pragma once
#include "Rule.h"
#include <memory>

class RuleRaw : public Rule {
protected:
    std::string rule;

public:
    RuleRaw() = default;
    RuleRaw(const std::string& content) : rule(content) {}

    void finalize() override {}
    std::string toCHR() override { return rule; }
    std::string toString() override { return rule; }

    const std::string& getText() const {
        return rule;
    }

    // ===============================
    // Static Rule Factories
    // ===============================

    static std::shared_ptr<RuleRaw> declarationRules() {
        auto r = std::make_shared<RuleRaw>();
        r->rule = "CspVarIntDec(Id,_,X,Dom) ==> CspVarInt(Id,X,Dom);;\n"
                  "CspTmpInt(I,X,Dom) ==> CspVarInt(I,X,Dom);;";
        return r;
    }

    static std::shared_ptr<RuleRaw> domainPropagationRules() {
        auto r = std::make_shared<RuleRaw>();
        r->rule = "CspVarInt(_,_, Dom) ==> (*Dom).empty() | failure();;\n"
                  "CspVarInt(_,X, XDom) ==> (*XDom).singleton() | X %= (*XDom).val();;\n"
                  "CspVarInt(_,Val, Dom) ==> Val.ground() | maj_dom(Dom, *Val);;";
        return r;
    }

    static std::shared_ptr<RuleRaw> labellingRules() {
        auto r = std::make_shared<RuleRaw>();
        r->rule = "CspVarIntDec(Id, _, _, Dom) \\ labelling(Id) <=> exists_it(i, *Dom, ( set_eq(Dom,i) , labelling(Id+1)));;\n"
                  "labelling(Id) <=> print_store(*this);;";
        return r;
    }

    static std::shared_ptr<RuleRaw> eqRule() {
        auto r = std::make_shared<RuleRaw>();
        r->rule = "eq_var_var @ CspVarInt(IdX,X, XDom), CspVarInt(IdY,Y, YDom), CspOpeq(IdX, X, IdY, Y) ==> XDom %= YDom, X %= Y ;;";
        return r;
    }

    static std::shared_ptr<RuleRaw> neqRule() {
        auto r = std::make_shared<RuleRaw>();
        r->rule = "neq_var_var @ CspVarInt(Id1, X, XDom), CspVarInt(Id2, Y, YDom), CspOpneq(Id1, X, Id2, Y) ==> Solvint::ne(XDom, YDom);;\n"
                  "neq_cste_var @ CspVarInt(Id, Y, YDom), CspOpneq(_,X,Id,Y) ==> X.ground() | Solvint::ne(YDom, *X) ;;\n"
                  "neq_var_cste @ CspVarInt(Id, X, XDom), CspOpneq(Id,X,_,Y) ==> Y.ground() | Solvint::ne(XDom, *Y) ;;";
        return r;
    }

    static std::shared_ptr<RuleRaw> ltRule() {
        auto r = std::make_shared<RuleRaw>();
        r->rule = "lt_var_var @ CspVarInt(IdX,X, XDom), CspVarInt(IdY,Y, YDom), CspOplt(IdX, X, IdY, Y) =>> Solvint::lt(XDom, YDom) ;;";
        return r;
    }

    static std::shared_ptr<RuleRaw> leRule() {
        auto r = std::make_shared<RuleRaw>();
        r->rule = "le_var_var @ CspVarInt(IdX,X, XDom), CspVarInt(IdY,Y, YDom), CspOple(IdX, X, IdY, Y) =>> Solvint::le(XDom, YDom) ;;";
        return r;
    }

    static std::shared_ptr<RuleRaw> gtRule() {
        auto r = std::make_shared<RuleRaw>();
        r->rule = "gt_var_var @ CspVarInt(IdX,X, XDom), CspVarInt(IdY,Y, YDom), CspOpgt(IdX, X, IdY, Y) =>> Solvint::gt(XDom, YDom) ;;";
        return r;
    }

    static std::shared_ptr<RuleRaw> geRule() {
        auto r = std::make_shared<RuleRaw>();
        r->rule = "ge_var_var @ CspVarInt(IdX,X, XDom), CspVarInt(IdY,Y, YDom), CspOpge(IdX, X, IdY, Y) =>> Solvint::ge(XDom, YDom) ;;";
        return r;
    }

    static std::shared_ptr<RuleRaw> plusRule() {
        auto r = std::make_shared<RuleRaw>();
        r->rule = "plus @ CspVarInt(Id1,X,XDom), CspVarInt(Id2,Y,YDom), CspVarInt(Id3,Z,ZDom), CspOpplus(Id1,X,Id2,Y,Id3,Z) =>> Solvint::plus_boundConsistency(XDom, YDom, ZDom) ;;";
        return r;
    }

    static std::shared_ptr<RuleRaw> divRule() {
        auto r = std::make_shared<RuleRaw>();
        r->rule = "div @ CspVarInt(IdX,X, XDom), CspVarInt(IdY,Y, YDom), CspVarInt(IdZ,Z, ZDom), CspOpdiv(IdX, X, IdY, Y, IdZ, Z) =>> Solvint::div_boundConsistency(XDom, Y, ZDom) ;;";
        return r;
    }
};
