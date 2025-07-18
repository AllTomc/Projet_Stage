#ifndef SOLVINT_H
#define SOLVINT_H

#include "solvint_global.h"

#include <chrpp.hh>
#include <bt_interval.hh>

class SOLVINT_EXPORT Solvint
{
public:
    Solvint() = delete;

    static chr::ES_CHR narrow(chr::Logical_var_mutable< chr::Interval<int, false> > &i1, chr::Logical_var_mutable< chr::Interval<int, false> > &i2);
    static chr::ES_CHR eq(chr::Logical_var_mutable< chr::Interval<int, false> > &i1, chr::Logical_var_mutable< chr::Interval<int, false> > &i2);
    static chr::ES_CHR eq(chr::Logical_var_mutable< chr::Interval<int, false> > &i1, int v2);
    static chr::ES_CHR eq(int v1, int v2);
    static chr::ES_CHR ne(chr::Logical_var_mutable< chr::Interval<int, false> > &i1, chr::Logical_var_mutable< chr::Interval<int, false> > &i2);
    static chr::ES_CHR ne(chr::Logical_var_mutable< chr::Interval<int, false> > &i1, int v2);
    static chr::ES_CHR ne(int v1, int v2);
    static chr::ES_CHR ne(chr::Logical_var_mutable< chr::Interval<int, false> > &i1, int removeFrom, int removeTo);
    static chr::ES_CHR lt(chr::Logical_var_mutable< chr::Interval<int, false> > &i1, chr::Logical_var_mutable< chr::Interval<int, false> > &i2);
    static chr::ES_CHR lt(chr::Logical_var_mutable< chr::Interval<int, false> > &i1, int v2);
    static chr::ES_CHR lt(int v1, chr::Logical_var_mutable< chr::Interval<int, false> > &i2);
    static chr::ES_CHR lt(int v1, int v2);
    static chr::ES_CHR le(chr::Logical_var_mutable< chr::Interval<int, false> > &i1, chr::Logical_var_mutable< chr::Interval<int, false> > &i2);
    static chr::ES_CHR le(chr::Logical_var_mutable< chr::Interval<int, false> > &i1, int v2);
    static chr::ES_CHR le(int v1, chr::Logical_var_mutable< chr::Interval<int, false> > &i2);
    static chr::ES_CHR le(int v1, int v2);
    static chr::ES_CHR gt(chr::Logical_var_mutable< chr::Interval<int, false> > &i1, chr::Logical_var_mutable< chr::Interval<int, false> > &i2);
    static chr::ES_CHR gt(chr::Logical_var_mutable< chr::Interval<int, false> > &i1, int v2);
    static chr::ES_CHR gt(int v1, chr::Logical_var_mutable< chr::Interval<int, false> > &i2);
    static chr::ES_CHR gt(int v1, int v2);
    static chr::ES_CHR ge(chr::Logical_var_mutable< chr::Interval<int, false> > &i1, chr::Logical_var_mutable< chr::Interval<int, false> > &i2);
    static chr::ES_CHR ge(chr::Logical_var_mutable< chr::Interval<int, false> > &i1, int v2);
    static chr::ES_CHR ge(int v1, chr::Logical_var_mutable< chr::Interval<int, false> > &i2);
    static chr::ES_CHR ge(int v1, int v2);
    static chr::ES_CHR plus(chr::Logical_var_mutable< chr::Interval<int, false> > &i1, int v2, chr::Logical_var_mutable< chr::Interval<int, false> > &i3);
    static chr::ES_CHR plus_boundConsistency(chr::Logical_var_mutable< chr::Interval<int, false> > &i1, chr::Logical_var_mutable< chr::Interval<int, false> > &i2, chr::Logical_var_mutable< chr::Interval<int, false> > &i3);
    static chr::ES_CHR modulo(chr::Logical_var_mutable< chr::Interval<int, false> > &i1, int v2, chr::Logical_var_mutable< chr::Interval<int, false> > &i3);
    static chr::ES_CHR modulo_boundConsistency(chr::Logical_var_mutable< chr::Interval<int, false> > &i1, int v2, chr::Logical_var_mutable< chr::Interval<int, false> > &i3);
    static chr::ES_CHR div_boundConsistency(chr::Logical_var_mutable< chr::Interval<int, false> > &i1, int v2, chr::Logical_var_mutable< chr::Interval<int, false> > &i3);
    static chr::ES_CHR mult_boundConsistency(chr::Logical_var_mutable< chr::Interval<int, false> > &i1, chr::Logical_var_mutable< chr::Interval<int, false> > &i2, chr::Logical_var_mutable< chr::Interval<int, false> > &i3);
    static chr::ES_CHR mult_boundConsistency(chr::Logical_var_mutable< chr::Interval<int, false> > &i1, int v2, chr::Logical_var_mutable< chr::Interval<int, false> > &i3);
    static chr::ES_CHR notin_range(chr::Logical_var_mutable< chr::Interval<int, false> > &i1, int rangeMin, int rangeMax);
    static chr::ES_CHR shift_boundConsistency(chr::Logical_var_mutable< chr::Interval<int, false> > &i1, chr::Logical_var_mutable< chr::Interval<int, false> > &i2, int offset);
};

#endif // SOLVINT_H
