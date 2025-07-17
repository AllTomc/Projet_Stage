#include "Rule.h"


std::string Rule::prefix_op = "";
void Rule::setprefix_op(const std::string & s) {prefix_op = s; Predicate::setprefix_op(s);}

bool Rule::minimalMode = false;
void Rule::enable_minimalMode() {minimalMode = true;}