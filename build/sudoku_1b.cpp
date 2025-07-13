/*
From line 121 to 137
labelling<labelling( ( Id + 1 ) )> { CspVarIntDec<CspVarIntDec( Id, _, _, Dom )> } --> labelling<labelling( ( Id + 1 ) )>, built-in<begin(  )>
eq<eq( _, X, _, Y )> { CspVarInt<CspVarInt( _, X, XDom )> } --> built-in<Y>
neq<neq( Id1, X, Id2, Y )> { CspVarInt<CspVarInt( Id1, X, XDom )> } --> built-in<ne( XDom, YDom )>
CspTmpInt<CspTmpInt( I, X, Dom )> --> CspVarInt<CspVarInt( I, X, Dom )>
CspVarIntDec<CspVarIntDec( Id, _, X, Dom )> { labelling<labelling( Id )> } --> labelling<labelling( ( Id + 1 ) )>, built-in<begin(  )>, CspVarInt<CspVarInt( Id, X, Dom )>
put_alldiff<put_alldiff( L, Ids )> --> built-in<alldiff_fun( ( *this ), ( *L ), ( *Ids ) )>
CspVarInt<CspVarInt( _, X, XDom )> { eq<eq( _, X, _, Y )>, neq<neq( Id1, X, Id2, Y )>, CspVarInt<CspVarInt( Id2, Y, YDom )> } --> built-in<( ( *XDom ) . val(  ) )>

(constraint) CspVarIntDec( ( +int ), ( +string ), ( ?int ), ( -interval ) ), indexes: { <0> }
(constraint) CspVarInt( ( +int ), ( ?int ), ( -interval ) ), indexes: { <0,1>, <1> }
(constraint) CspTmpInt( ( +int ), ( ?int ), ( -interval ) )
(constraint) neq( ( +int ), ( ?int ), ( +int ), ( ?int ) ), indexes: { <0,1>, <2,3> }
(constraint) ##put_alldiff( ( ?list_var ), ( ?list_int ) )
(constraint) eq( ( +int ), ( ?int ), ( +int ), ( ?int ) ), indexes: { <1>, <3> }
(constraint) ##labelling( ( +int ) ), indexes: { <0> }
(rule) CspVarInt( _, _, Dom ) ==> ( ( *Dom ) . empty(  ) ) | failure ;;
(rule) CspVarInt( _, X, XDom ) ==> ( ( *XDom ) . singleton(  ) ) | X %= ( ( *XDom ) . val(  ) ) ;;
(rule) CspVarInt( _, Val, Dom ) ==> ( Val . ground(  ) ) | maj_dom( Dom, ( *Val ) ) ;;
(rule) CspVarIntDec( Id, _, X, Dom ) ==> CspVarInt( Id, X, Dom ) ;;
(rule) CspTmpInt( I, X, Dom ) ==> CspVarInt( I, X, Dom ) ;;
(rule) neq_var_var @ CspVarInt( Id1, X, XDom ), CspVarInt( Id2, Y, YDom ), neq( Id1, X, Id2, Y ) ==> ( Solvint :: ne( XDom, YDom ) ) ;;
(rule) neq_cste_var @ CspVarInt( Id, Y, YDom ), neq( _, X, Id, Y ) ==> ( X . ground(  ) ) | ( Solvint :: ne( YDom, ( *X ) ) ) ;;
(rule) neq_var_cste @ CspVarInt( Id, X, XDom ), neq( Id, X, _, Y ) ==> ( Y . ground(  ) ) | ( Solvint :: ne( XDom, ( *Y ) ) ) ;;
(rule) put_alldiff( L, Ids ) <=> ( ( *L ) . empty(  ) ) | success ;;
(rule) put_alldiff( L, Ids ) <=> alldiff_fun( ( *this ), ( *L ), ( *Ids ) ) ;;
(rule) eq_cste_cste @ eq( _, X, _, Y ) ==> X %= Y ;;
(rule) eq_var_var @ CspVarInt( _, X, XDom ), CspVarInt( _, Y, YDom ), eq( _, X, _, Y ) ==> XDom %= YDom ;;
(rule) CspVarIntDec( Id, _, _, Dom ) \ labelling( Id ) <=> ( __it_i = ( ( *Dom ) . begin(  ) ), __it_end_i = ( ( *Dom ) . end(  ) ), __local_success__3 = false, behavior( ( __local_success__3 || ( __it_i == __it_end_i ) ), __local_success__3 = true, ( ++__it_i ), __local_success__3, , , ( i = ( *__it_i ), set_eq( Dom, i ), labelling( ( Id + 1 ) ) )) ) ;;
(rule) labelling( Id ) <=> print_store( ( *this ) ) ;;
(occ rule) [+CspTmpInt( I, X, Dom )#0][] --> CspVarInt( I, X, Dom ) ;;
(occ rule) [+CspVarInt( _, _, Dom )#0][( ( *Dom ) . empty(  ) )] --> failure ;;
(occ rule) [+CspVarInt( _, X, XDom )#1][( ( *XDom ) . singleton(  ) )] --> X %= ( ( *XDom ) . val(  ) ) ;;
(occ rule) [+CspVarInt( _, Val, Dom )#2][( Val . ground(  ) )] --> maj_dom( Dom, ( *Val ) ) ;;
(occ rule) neq_var_var @ [+CspVarInt( Id1, X, XDom )#3][+neq( Id1, X, Id2, Y )<idx#0>, +CspVarInt( Id2, Y, YDom )<idx#0>] --> ( Solvint :: ne( XDom, YDom ) ) ;;
(occ rule) neq_var_var @ [+CspVarInt( Id2, Y, YDom )#4][+neq( Id1, X, Id2, Y )<idx#1>, +CspVarInt( Id1, X, XDom )<idx#0>] --> ( Solvint :: ne( XDom, YDom ) ) ;;
(occ rule) neq_cste_var @ [+CspVarInt( Id, Y, YDom )#5][+neq( _, X, Id, Y )<idx#1>, ( X . ground(  ) )] --> ( Solvint :: ne( YDom, ( *X ) ) ) ;;
(occ rule) neq_var_cste @ [+CspVarInt( Id, X, XDom )#6][+neq( Id, X, _, Y )<idx#0>, ( Y . ground(  ) )] --> ( Solvint :: ne( XDom, ( *Y ) ) ) ;;
(occ rule) eq_var_var @ [+CspVarInt( _, X, XDom )#7][+eq( _, X, _, Y )<idx#0>, +CspVarInt( _, Y, YDom )<idx#1>] --> XDom %= YDom ;;
(occ rule) eq_var_var @ [+CspVarInt( _, Y, YDom )#8][+eq( _, X, _, Y )<idx#1>, +CspVarInt( _, X, XDom )<idx#1>] --> XDom %= YDom ;;
(occ rule) [+CspVarIntDec( Id, _, X, Dom )#0][] --> CspVarInt( Id, X, Dom ) ;;
(occ rule) eq_cste_cste @ [+eq( _, X, _, Y )#0][] --> X %= Y ;;
(occ rule) eq_var_var @ [+eq( _, X, _, Y )#1][+CspVarInt( _, X, XDom )<idx#1>, +CspVarInt( _, Y, YDom )<idx#1>] --> XDom %= YDom ;;
(occ rule) [-labelling( Id )#0][+CspVarIntDec( Id, _, _, Dom )<idx#0>] --> ( __it_i = ( ( *Dom ) . begin(  ) ), __it_end_i = ( ( *Dom ) . end(  ) ), __local_success__3 = false, behavior( ( __local_success__3 || ( __it_i == __it_end_i ) ), __local_success__3 = true, ( ++__it_i ), __local_success__3, , , ( i = ( *__it_i ), set_eq( Dom, i ), labelling( ( Id + 1 ) ) )) ) ;;
(occ rule) [-labelling( Id )#1][] --> print_store( ( *this ) ) ;;
(occ rule) neq_var_var @ [+neq( Id1, X, Id2, Y )#0][+CspVarInt( Id1, X, XDom )<idx#0>, +CspVarInt( Id2, Y, YDom )<idx#0>] --> ( Solvint :: ne( XDom, YDom ) ) ;;
(occ rule) neq_cste_var @ [+neq( _, X, Id, Y )#1][( X . ground(  ) ), +CspVarInt( Id, Y, YDom )<idx#0>] --> ( Solvint :: ne( YDom, ( *X ) ) ) ;;
(occ rule) neq_var_cste @ [+neq( Id, X, _, Y )#2][( Y . ground(  ) ), +CspVarInt( Id, X, XDom )<idx#0>] --> ( Solvint :: ne( XDom, ( *Y ) ) ) ;;
(occ rule) [-put_alldiff( L, Ids )#0][( ( *L ) . empty(  ) )] --> success ;;
(occ rule) [-put_alldiff( L, Ids )#1][] --> alldiff_fun( ( *this ), ( *L ), ( *Ids ) ) ;;

(constraint store) CspVarIntDec( ( +int ), ( +string ), ( ?int ), ( -interval ) ), indexes: { <0> }
(constraint store) CspVarInt( ( +int ), ( ?int ), ( -interval ) ), indexes: { <0,1>, <1> }
(constraint store) CspTmpInt( ( +int ), ( ?int ), ( -interval ) )
(constraint store) neq( ( +int ), ( ?int ), ( +int ), ( ?int ) ), indexes: { <0,1>, <2,3> }
(constraint store) put_alldiff( ( ?list_var ), ( ?list_int ) )
(constraint store) eq( ( +int ), ( ?int ), ( +int ), ( ?int ) ), indexes: { <1>, <3> }
(constraint store) labelling( ( +int ) ), indexes: { <0> }
// Rule NO_NAME, active constraint CspTmpInt( I, X, Dom ), occurrence 0
Begin CspTmpInt_0
	If history <CspTmpInt( I, X, Dom )> Then
		store constraint CspTmpInt( I, X, Dom )
		CspVarInt( I, X, Dom )
		If not alived CspTmpInt( I, X, Dom ) Then goto next goal constraint
	End history
End
// Fail through
Begin CspTmpInt_store
	Store constraint CspTmpInt
	Schedule constraint CspTmpInt with variable index 1
	Schedule constraint CspTmpInt with variable index 2
Goto next goal constraint
// Rule NO_NAME, active constraint CspVarInt( _, _, Dom ), occurrence 0
Begin CspVarInt_0
	If guard
		( ( *Dom ) . empty(  ) )
	Then guard
		If history <CspVarInt( _, _, Dom )> Then
			store constraint CspVarInt( _, _, Dom )
			failure
			If not alived CspVarInt( _, _, Dom ) Then goto next goal constraint
		End history
	End guard
End
// Rule NO_NAME, active constraint CspVarInt( _, X, XDom ), occurrence 1
Begin CspVarInt_1
	If guard
		( ( *XDom ) . singleton(  ) )
	Then guard
		If history <CspVarInt( _, X, XDom )> Then
			store constraint CspVarInt( _, X, XDom )
			X %= ( ( *XDom ) . val(  ) )
			If not alived CspVarInt( _, X, XDom ) Then goto next goal constraint
		End history
	End guard
End
// Rule NO_NAME, active constraint CspVarInt( _, Val, Dom ), occurrence 2
Begin CspVarInt_2
	If guard
		( Val . ground(  ) )
	Then guard
		If history <CspVarInt( _, Val, Dom )> Then
			store constraint CspVarInt( _, Val, Dom )
			maj_dom( Dom, ( *Val ) )
			If not alived CspVarInt( _, Val, Dom ) Then goto next goal constraint
		End history
	End guard
End
// Rule neq_var_var, active constraint CspVarInt( Id1, X, XDom ), occurrence 3
Begin CspVarInt_3
If empty store neq( Id1, X, Id2, Y ) Then goto CspVarInt_4
If empty store CspVarInt( Id2, Y, YDom ) Then goto CspVarInt_4
	Matching partner neq( Id1, X, Id2, Y ) with idx#0<Id1,X>
		Matching partner CspVarInt( Id2, Y, YDom ) with idx#0<Id2,Y>
			If guard
				( CspVarInt( Id2, Y, YDom ) != CspVarInt( Id1, X, XDom ) )
			Then guard
				If history <CspVarInt( Id1, X, XDom ),neq( Id1, X, Id2, Y ),CspVarInt( Id2, Y, YDom )> Then
					store constraint CspVarInt( Id1, X, XDom )
					( Solvint :: ne( XDom, YDom ) )
					If not alived CspVarInt( Id1, X, XDom ) Then goto next goal constraint
					If not alived neq( Id1, X, Id2, Y ) Then goto next matching of neq( Id1, X, Id2, Y )
					goto next matching of CspVarInt( Id2, Y, YDom )
				End history
			End guard
		End matching partner CspVarInt( Id2, Y, YDom )
	End matching partner neq( Id1, X, Id2, Y )
End
// Rule neq_var_var, active constraint CspVarInt( Id2, Y, YDom ), occurrence 4
Begin CspVarInt_4
If empty store neq( Id1, X, Id2, Y ) Then goto CspVarInt_5
If empty store CspVarInt( Id1, X, XDom ) Then goto CspVarInt_5
	Matching partner neq( Id1, X, Id2, Y ) with idx#1<Id2,Y>
		Matching partner CspVarInt( Id1, X, XDom ) with idx#0<Id1,X>
			If guard
				( CspVarInt( Id1, X, XDom ) != CspVarInt( Id2, Y, YDom ) )
			Then guard
				If history <CspVarInt( Id2, Y, YDom ),neq( Id1, X, Id2, Y ),CspVarInt( Id1, X, XDom )> Then
					store constraint CspVarInt( Id2, Y, YDom )
					( Solvint :: ne( XDom, YDom ) )
					If not alived CspVarInt( Id2, Y, YDom ) Then goto next goal constraint
					If not alived neq( Id1, X, Id2, Y ) Then goto next matching of neq( Id1, X, Id2, Y )
					goto next matching of CspVarInt( Id1, X, XDom )
				End history
			End guard
		End matching partner CspVarInt( Id1, X, XDom )
	End matching partner neq( Id1, X, Id2, Y )
End
// Rule neq_cste_var, active constraint CspVarInt( Id, Y, YDom ), occurrence 5
Begin CspVarInt_5
If empty store neq( _, X, Id, Y ) Then goto CspVarInt_6
	Matching partner neq( _, X, Id, Y ) with idx#1<Id,Y>
		If guard
			( X . ground(  ) )
		Then guard
			If history <CspVarInt( Id, Y, YDom ),neq( _, X, Id, Y )> Then
				store constraint CspVarInt( Id, Y, YDom )
				( Solvint :: ne( YDom, ( *X ) ) )
				If not alived CspVarInt( Id, Y, YDom ) Then goto next goal constraint
				goto next matching of neq( _, X, Id, Y )
			End history
		End guard
	End matching partner neq( _, X, Id, Y )
End
// Rule neq_var_cste, active constraint CspVarInt( Id, X, XDom ), occurrence 6
Begin CspVarInt_6
If empty store neq( Id, X, _, Y ) Then goto CspVarInt_7
	Matching partner neq( Id, X, _, Y ) with idx#0<Id,X>
		If guard
			( Y . ground(  ) )
		Then guard
			If history <CspVarInt( Id, X, XDom ),neq( Id, X, _, Y )> Then
				store constraint CspVarInt( Id, X, XDom )
				( Solvint :: ne( XDom, ( *Y ) ) )
				If not alived CspVarInt( Id, X, XDom ) Then goto next goal constraint
				goto next matching of neq( Id, X, _, Y )
			End history
		End guard
	End matching partner neq( Id, X, _, Y )
End
// Rule eq_var_var, active constraint CspVarInt( _, X, XDom ), occurrence 7
Begin CspVarInt_7
If empty store eq( _, X, _, Y ) Then goto CspVarInt_8
If empty store CspVarInt( _, Y, YDom ) Then goto CspVarInt_8
	Matching partner eq( _, X, _, Y ) with idx#0<X>
		Matching partner CspVarInt( _, Y, YDom ) with idx#1<Y>
			If guard
				( CspVarInt( _, Y, YDom ) != CspVarInt( _, X, XDom ) )
			Then guard
				If history <CspVarInt( _, X, XDom ),eq( _, X, _, Y ),CspVarInt( _, Y, YDom )> Then
					store constraint CspVarInt( _, X, XDom )
					XDom %= YDom
					If not alived CspVarInt( _, X, XDom ) Then goto next goal constraint
					If not alived eq( _, X, _, Y ) Then goto next matching of eq( _, X, _, Y )
					goto next matching of CspVarInt( _, Y, YDom )
				End history
			End guard
		End matching partner CspVarInt( _, Y, YDom )
	End matching partner eq( _, X, _, Y )
End
// Rule eq_var_var, active constraint CspVarInt( _, Y, YDom ), occurrence 8
Begin CspVarInt_8
If empty store eq( _, X, _, Y ) Then goto CspVarInt_store
If empty store CspVarInt( _, X, XDom ) Then goto CspVarInt_store
	Matching partner eq( _, X, _, Y ) with idx#1<Y>
		Matching partner CspVarInt( _, X, XDom ) with idx#1<X>
			If guard
				( CspVarInt( _, X, XDom ) != CspVarInt( _, Y, YDom ) )
			Then guard
				If history <CspVarInt( _, Y, YDom ),eq( _, X, _, Y ),CspVarInt( _, X, XDom )> Then
					store constraint CspVarInt( _, Y, YDom )
					XDom %= YDom
					If not alived CspVarInt( _, Y, YDom ) Then goto next goal constraint
					If not alived eq( _, X, _, Y ) Then goto next matching of eq( _, X, _, Y )
					goto next matching of CspVarInt( _, X, XDom )
				End history
			End guard
		End matching partner CspVarInt( _, X, XDom )
	End matching partner eq( _, X, _, Y )
End
// Fail through
Begin CspVarInt_store
	Store constraint CspVarInt
	Schedule constraint CspVarInt with variable index 1
	Schedule constraint CspVarInt with variable index 2
Goto next goal constraint
// Rule NO_NAME, active constraint CspVarIntDec( Id, _, X, Dom ), occurrence 0
Begin CspVarIntDec_0
	If history <CspVarIntDec( Id, _, X, Dom )> Then
		store constraint CspVarIntDec( Id, _, X, Dom )
		CspVarInt( Id, X, Dom )
		If not alived CspVarIntDec( Id, _, X, Dom ) Then goto next goal constraint
	End history
End
// Fail through
Begin CspVarIntDec_store
	Store constraint CspVarIntDec
	Schedule constraint CspVarIntDec with variable index 2
	Schedule constraint CspVarIntDec with variable index 3
Goto next goal constraint
// Rule eq_cste_cste, active constraint eq( _, X, _, Y ), occurrence 0
Begin eq_0
	If history <eq( _, X, _, Y )> Then
		store constraint eq( _, X, _, Y )
		X %= Y
		If not alived eq( _, X, _, Y ) Then goto next goal constraint
	End history
End
// Rule eq_var_var, active constraint eq( _, X, _, Y ), occurrence 1
Begin eq_1
If empty store CspVarInt( _, X, XDom ) Then goto eq_store
If empty store CspVarInt( _, Y, YDom ) Then goto eq_store
	Matching partner CspVarInt( _, X, XDom ) with idx#1<X>
		Matching partner CspVarInt( _, Y, YDom ) with idx#1<Y>
			If guard
				( CspVarInt( _, Y, YDom ) != CspVarInt( _, X, XDom ) )
			Then guard
				If history <eq( _, X, _, Y ),CspVarInt( _, X, XDom ),CspVarInt( _, Y, YDom )> Then
					store constraint eq( _, X, _, Y )
					XDom %= YDom
					If not alived eq( _, X, _, Y ) Then goto next goal constraint
					If not alived CspVarInt( _, X, XDom ) Then goto next matching of CspVarInt( _, X, XDom )
					goto next matching of CspVarInt( _, Y, YDom )
				End history
			End guard
		End matching partner CspVarInt( _, Y, YDom )
	End matching partner CspVarInt( _, X, XDom )
End
// Fail through
Begin eq_store
	Store constraint eq
	Schedule constraint eq with variable index 1
	Schedule constraint eq with variable index 3
Goto next goal constraint
// Rule NO_NAME, active constraint labelling( Id ), occurrence 0
Begin labelling_0
If empty store CspVarIntDec( Id, _, _, Dom ) Then goto labelling_1
	Matching partner CspVarIntDec( Id, _, _, Dom ) with idx#0<Id>
		remove constraint labelling( Id )
		__it_i = ( ( *Dom ) . begin(  ) )
		__it_end_i = ( ( *Dom ) . end(  ) )
		__local_success__3 = false
		Behavior
			While (( __local_success__3 || ( __it_i == __it_end_i ) ))
				_ret_beha_ <-- Try
					i = ( *__it_i )
					set_eq( Dom, i )
					labelling( ( Id + 1 ) )
				End try
				If _ret_beha_ is success
					__local_success__3 = true
				Else
					( ++__it_i )
				End if
			End while
			If (__local_success__3)

			Else

			End if
		End behavior
		goto next goal constraint
	End matching partner CspVarIntDec( Id, _, _, Dom )
End
// Rule NO_NAME, active constraint labelling( Id ), occurrence 1
Begin labelling_1
	remove constraint labelling( Id )
	print_store( ( *this ) )
	goto next goal constraint
End
// Fail through
Begin labelling_store
	Store constraint labelling
Goto next goal constraint
// Rule neq_var_var, active constraint neq( Id1, X, Id2, Y ), occurrence 0
Begin neq_0
If empty store CspVarInt( Id1, X, XDom ) Then goto neq_1
If empty store CspVarInt( Id2, Y, YDom ) Then goto neq_1
	Matching partner CspVarInt( Id1, X, XDom ) with idx#0<Id1,X>
		Matching partner CspVarInt( Id2, Y, YDom ) with idx#0<Id2,Y>
			If guard
				( CspVarInt( Id2, Y, YDom ) != CspVarInt( Id1, X, XDom ) )
			Then guard
				If history <neq( Id1, X, Id2, Y ),CspVarInt( Id1, X, XDom ),CspVarInt( Id2, Y, YDom )> Then
					store constraint neq( Id1, X, Id2, Y )
					( Solvint :: ne( XDom, YDom ) )
					If not alived neq( Id1, X, Id2, Y ) Then goto next goal constraint
					If not alived CspVarInt( Id1, X, XDom ) Then goto next matching of CspVarInt( Id1, X, XDom )
					goto next matching of CspVarInt( Id2, Y, YDom )
				End history
			End guard
		End matching partner CspVarInt( Id2, Y, YDom )
	End matching partner CspVarInt( Id1, X, XDom )
End
// Rule neq_cste_var, active constraint neq( _, X, Id, Y ), occurrence 1
Begin neq_1
If empty store CspVarInt( Id, Y, YDom ) Then goto neq_2
	If guard
		( X . ground(  ) )
	Then guard
		Matching partner CspVarInt( Id, Y, YDom ) with idx#0<Id,Y>
			If history <neq( _, X, Id, Y ),CspVarInt( Id, Y, YDom )> Then
				store constraint neq( _, X, Id, Y )
				( Solvint :: ne( YDom, ( *X ) ) )
				If not alived neq( _, X, Id, Y ) Then goto next goal constraint
				goto next matching of CspVarInt( Id, Y, YDom )
			End history
		End matching partner CspVarInt( Id, Y, YDom )
	End guard
End
// Rule neq_var_cste, active constraint neq( Id, X, _, Y ), occurrence 2
Begin neq_2
If empty store CspVarInt( Id, X, XDom ) Then goto neq_store
	If guard
		( Y . ground(  ) )
	Then guard
		Matching partner CspVarInt( Id, X, XDom ) with idx#0<Id,X>
			If history <neq( Id, X, _, Y ),CspVarInt( Id, X, XDom )> Then
				store constraint neq( Id, X, _, Y )
				( Solvint :: ne( XDom, ( *Y ) ) )
				If not alived neq( Id, X, _, Y ) Then goto next goal constraint
				goto next matching of CspVarInt( Id, X, XDom )
			End history
		End matching partner CspVarInt( Id, X, XDom )
	End guard
End
// Fail through
Begin neq_store
	Store constraint neq
	Schedule constraint neq with variable index 1
	Schedule constraint neq with variable index 3
Goto next goal constraint
// Rule NO_NAME, active constraint put_alldiff( L, Ids ), occurrence 0
Begin put_alldiff_0
	If guard
		( ( *L ) . empty(  ) )
	Then guard
		remove constraint put_alldiff( L, Ids )
		success
		goto next goal constraint
	End guard
End
// Rule NO_NAME, active constraint put_alldiff( L, Ids ), occurrence 1
Begin put_alldiff_1
	remove constraint put_alldiff( L, Ids )
	alldiff_fun( ( *this ), ( *L ), ( *Ids ) )
	goto next goal constraint
End
// Fail through
Begin put_alldiff_store
	Store constraint put_alldiff
Goto next goal constraint
*/
//----------------------- START INCLUDE HEADER ---------------------
#include <iostream>
#include <map>
#include <string>
#include <list>
#include <regex>
#include <chrpp.hh>
#include <bt_interval.hh>
#include <solvint.cpp>

using namespace chr;
using interval = chr::Interval<int, false>;
using string = std::string;
using list_var = std::list<chr::Logical_var<int>>;
using list_int = std::list<int>;
int global_id = 0;
std::map<int, std::string> id_name_map;


template <typename T>
void print_store(T& pb) {
    auto it = pb.chr_store_begin();
    while (!it.at_end()) {
        std::cout << it.to_string() << std::endl;
        ++it;
    }
}

template<typename... Args>
list_var make_list_var(Args... args) {
    return list_var{args...};
}

template<typename... Ints>
list_int make_list_int(Ints... ints) {
    return list_int{ints...};
}

inline chr::ES_CHR maj_dom(chr::Logical_var_mutable<interval> &i, int val) {
    bool modified = false;
    return i.update_mutable(modified, [&modified, val](auto& intvl) {
        modified = intvl.eq(val);
    });
}

inline chr::ES_CHR set_eq(chr::Logical_var_mutable<interval> &x, int v) {
    bool modified = false;
    return x.update_mutable(modified, [&modified, v](auto& intvl1){
        modified = intvl1.eq(v);
    });
}

template <typename T> 
void print_matrix(T& pb) {
    std::regex re(R"(x\[(\d+)\]\[(\d+)\],\s*(\d+),)");
    std::vector<std::tuple<int, int, int>> assignments;

    int count = 0;
    auto it = pb.chr_store_begin();

    // Collecte des faits CspVarIntDec
    while (!it.at_end()) {
        std::string fact = it.to_string();
        if (fact.find("CspVarIntDec") != std::string::npos) {
            std::smatch match;
            if (std::regex_search(fact, match, re)) {
                int i = std::stoi(match[1].str());
                int j = std::stoi(match[2].str());
                int val = std::stoi(match[3].str());
                assignments.emplace_back(i, j, val);
                ++count;
            }
        }
        ++it;
    }

    if (count == 0) {
        std::cout << "Aucune variable CspVarIntDec trouvée."; 
        return;
    }

    // Calcul de la dimension d
    int d = std::sqrt(count);
    if (d * d != count) {
        std::cerr << "Erreur : le nombre de variables (" << count << ") n'est pas un carré parfait.";
        return;
    }

    // Initialisation de la grille
    std::vector<std::vector<int>> grid(d, std::vector<int>(d, 0));
    for (const auto& [i, j, val] : assignments) {
        if (i >= 0 && i < d && j >= 0 && j < d)
            grid[i][j] = val;
    }

    // Affichage uniforme de la grille
    std::cout << "======= Matrice " << d << "x" << d << " =======" << std::endl;
    for (int i = 0; i < d; ++i) {
        for (int j = 0; j < d; ++j) {
            std::cout << std::setw(4) << (grid[i][j] ? std::to_string(grid[i][j]) : ".");
        }
        std::cout << "\n";
    }
    std::cout << "=============================";
}
template<class T>
bool alldiff_fun(T& space, const list_var& vars, const list_int& ids) {
    auto it1 = vars.begin();
    auto id1 = ids.begin();
    for (; it1 != vars.end(); ++it1, ++id1) {
        auto it2 = it1;
        auto id2 = id1;
        ++it2; ++id2;
        for (; it2 != vars.end(); ++it2, ++id2) {
            CHECK_ES(space.neq(chr::Logical_var_ground<int>(*id1), *it1, chr::Logical_var_ground<int>(*id2), *it2));
        }
    }
    return true;
}


//----------------------- END INCLUDE HEADER ---------------------
#include <chrpp.hh>
class sudoku_1b {
	unsigned long int next_free_constraint_id = 1;
	//(constraint store) CspVarIntDec( ( +int ), ( +string ), ( ?int ), ( -interval ) ), indexes: { <0> }
public:
	struct CspVarIntDec {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var_ground< int >, chr::Logical_var_ground< string >, chr::Logical_var< int >, chr::Logical_var_mutable< interval > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0> >, true >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(sudoku_1b* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->CspVarIntDec_constraint_store && _space->CspVarIntDec_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_CspVarIntDec(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< sudoku_1b > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename CspVarIntDec::Constraint_store_t > CspVarIntDec_constraint_store{ chr::make_shared< typename CspVarIntDec::Constraint_store_t >("CspVarIntDec") };
	//(constraint store) CspVarInt( ( +int ), ( ?int ), ( -interval ) ), indexes: { <0,1>, <1> }
public:
	struct CspVarInt {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var_ground< int >, chr::Logical_var< int >, chr::Logical_var_mutable< interval > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,1>, chr::LNS::Index<1> >, true >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(sudoku_1b* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->CspVarInt_constraint_store && _space->CspVarInt_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_CspVarInt(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< sudoku_1b > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename CspVarInt::Constraint_store_t > CspVarInt_constraint_store{ chr::make_shared< typename CspVarInt::Constraint_store_t >("CspVarInt") };
	//(constraint store) CspTmpInt( ( +int ), ( ?int ), ( -interval ) )
public:
	struct CspTmpInt {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var_ground< int >, chr::Logical_var< int >, chr::Logical_var_mutable< interval > >;
		using Constraint_store_t = typename chr::Constraint_store_simple< Type, true >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(sudoku_1b* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->CspTmpInt_constraint_store && _space->CspTmpInt_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_CspTmpInt(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< sudoku_1b > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename CspTmpInt::Constraint_store_t > CspTmpInt_constraint_store{ chr::make_shared< typename CspTmpInt::Constraint_store_t >("CspTmpInt") };
	//(constraint store) neq( ( +int ), ( ?int ), ( +int ), ( ?int ) ), indexes: { <0,1>, <2,3> }
public:
	struct neq {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var_ground< int >, chr::Logical_var< int >, chr::Logical_var_ground< int >, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,1>, chr::LNS::Index<2,3> >, true >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(sudoku_1b* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->neq_constraint_store && _space->neq_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_neq(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< sudoku_1b > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename neq::Constraint_store_t > neq_constraint_store{ chr::make_shared< typename neq::Constraint_store_t >("neq") };
	//(constraint store) put_alldiff( ( ?list_var ), ( ?list_int ) )
public:
	struct put_alldiff {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< list_var >, chr::Logical_var< list_int > >;
	};
	//(constraint store) eq( ( +int ), ( ?int ), ( +int ), ( ?int ) ), indexes: { <1>, <3> }
public:
	struct eq {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var_ground< int >, chr::Logical_var< int >, chr::Logical_var_ground< int >, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<1>, chr::LNS::Index<3> >, true >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(sudoku_1b* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->eq_constraint_store && _space->eq_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_eq(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< sudoku_1b > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename eq::Constraint_store_t > eq_constraint_store{ chr::make_shared< typename eq::Constraint_store_t >("eq") };
	//(constraint store) labelling( ( +int ) ), indexes: { <0> }
public:
	struct labelling {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var_ground< int > >;
	};
public:
	unsigned int _ref_use_count  = 0;///< Count of shared references
	unsigned int _ref_weak_count = 0;///< Count of weak references + (#shared != 0)
	sudoku_1b() { }
	~sudoku_1b() {
		CspVarIntDec_constraint_store.release();
		CspVarInt_constraint_store.release();
		CspTmpInt_constraint_store.release();
		neq_constraint_store.release();
		eq_constraint_store.release();
	}
	static chr::Shared_obj<sudoku_1b> create() { return chr::make_shared<sudoku_1b>(); }
	chr::Constraint_stores_iterator<chr::Shared_obj<typename CspVarIntDec::Constraint_store_t>,chr::Shared_obj<typename CspVarInt::Constraint_store_t>,chr::Shared_obj<typename CspTmpInt::Constraint_store_t>,chr::Shared_obj<typename neq::Constraint_store_t>,chr::Shared_obj<typename eq::Constraint_store_t>> chr_store_begin() { return chr::Constraint_stores_iterator(CspVarIntDec_constraint_store,CspVarInt_constraint_store,CspTmpInt_constraint_store,neq_constraint_store,eq_constraint_store); }
	typename CspVarIntDec::Constraint_store_t& get_CspVarIntDec_store() { return *CspVarIntDec_constraint_store; }
	typename CspVarInt::Constraint_store_t& get_CspVarInt_store() { return *CspVarInt_constraint_store; }
	typename CspTmpInt::Constraint_store_t& get_CspTmpInt_store() { return *CspTmpInt_constraint_store; }
	typename neq::Constraint_store_t& get_neq_store() { return *neq_constraint_store; }
	typename eq::Constraint_store_t& get_eq_store() { return *eq_constraint_store; }
	struct History {
		typename chr::Shared_obj< chr::History_dyn< 1 > > rule_0{ chr::make_shared< typename chr::History_dyn< 1 > >() };
		typename chr::Shared_obj< chr::History_dyn< 1 > > rule_1{ chr::make_shared< typename chr::History_dyn< 1 > >() };
		typename chr::Shared_obj< chr::History_dyn< 1 > > rule_2{ chr::make_shared< typename chr::History_dyn< 1 > >() };
		typename chr::Shared_obj< chr::History_dyn< 1 > > rule_3{ chr::make_shared< typename chr::History_dyn< 1 > >() };
		typename chr::Shared_obj< chr::History_dyn< 1 > > rule_4{ chr::make_shared< typename chr::History_dyn< 1 > >() };
		typename chr::Shared_obj< chr::History_dyn< 3 > > rule_5{ chr::make_shared< typename chr::History_dyn< 3 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_6{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_7{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 1 > > rule_10{ chr::make_shared< typename chr::History_dyn< 1 > >() };
		typename chr::Shared_obj< chr::History_dyn< 3 > > rule_11{ chr::make_shared< typename chr::History_dyn< 3 > >() };
	};
	History _history;
	chr::ES_CHR do_CspVarIntDec(typename CspVarIntDec::Type c_args, typename CspVarIntDec::Constraint_store_t::iterator c_it);
	chr::ES_CHR CspVarIntDec( chr::Logical_var_ground< int > arg0, chr::Logical_var_ground< string > arg1, chr::Logical_var< int > arg2, chr::Logical_var_mutable< interval > arg3) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1, arg2, arg3);
		return do_CspVarIntDec(std::move(c_args), CspVarIntDec_constraint_store->end());
	}
	chr::ES_CHR do_CspVarInt(typename CspVarInt::Type c_args, typename CspVarInt::Constraint_store_t::iterator c_it);
	chr::ES_CHR CspVarInt( chr::Logical_var_ground< int > arg0, chr::Logical_var< int > arg1, chr::Logical_var_mutable< interval > arg2) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1, arg2);
		return do_CspVarInt(std::move(c_args), CspVarInt_constraint_store->end());
	}
	chr::ES_CHR do_CspTmpInt(typename CspTmpInt::Type c_args, typename CspTmpInt::Constraint_store_t::iterator c_it);
	chr::ES_CHR CspTmpInt( chr::Logical_var_ground< int > arg0, chr::Logical_var< int > arg1, chr::Logical_var_mutable< interval > arg2) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1, arg2);
		return do_CspTmpInt(std::move(c_args), CspTmpInt_constraint_store->end());
	}
	chr::ES_CHR do_neq(typename neq::Type c_args, typename neq::Constraint_store_t::iterator c_it);
	chr::ES_CHR neq( chr::Logical_var_ground< int > arg0, chr::Logical_var< int > arg1, chr::Logical_var_ground< int > arg2, chr::Logical_var< int > arg3) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1, arg2, arg3);
		return do_neq(std::move(c_args), neq_constraint_store->end());
	}
	chr::ES_CHR do_put_alldiff(typename put_alldiff::Type c_args);
	chr::ES_CHR put_alldiff( chr::Logical_var< list_var > arg0, chr::Logical_var< list_int > arg1) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1);
		return do_put_alldiff(std::move(c_args));
	}
	chr::ES_CHR do_eq(typename eq::Type c_args, typename eq::Constraint_store_t::iterator c_it);
	chr::ES_CHR eq( chr::Logical_var_ground< int > arg0, chr::Logical_var< int > arg1, chr::Logical_var_ground< int > arg2, chr::Logical_var< int > arg3) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1, arg2, arg3);
		return do_eq(std::move(c_args), eq_constraint_store->end());
	}
	chr::ES_CHR do_labelling(typename labelling::Type c_args);
	chr::ES_CHR labelling( chr::Logical_var_ground< int > arg0) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0);
		return do_labelling(std::move(c_args));
	}
};
chr::ES_CHR sudoku_1b::do_CspTmpInt(typename CspTmpInt::Type c_args, typename CspTmpInt::Constraint_store_t::iterator c_it) {
	bool c_stored_before = !c_it.at_end();
	chr::Statistics::update_call_stack();
	[[maybe_unused]] CspTmpInt_call:
	// ***************************************************
	// CspTmpInt_0 <=> Rule NO_NAME, active constraint CspTmpInt( I, X, Dom ), occurrence 1
	[[maybe_unused]] CspTmpInt_0:
	{
		auto& I = std::get<1>(c_args);
		auto& X = std::get<2>(c_args);
		auto& Dom = std::get<3>(c_args);
		// Check history
		if (_history.rule_4->check( {{std::get<0>(c_args)}} )) {
			if (!c_stored_before) {
				c_it = CspTmpInt_constraint_store->add(c_args);
				auto ccb = chr::Shared_x_obj< chr::Logical_var_imp_observer_constraint >(new typename CspTmpInt::Constraint_callback(this,c_it));
				chr::schedule_constraint_callback(std::get<2>(c_args), ccb);
				chr::schedule_constraint_callback(std::get<3>(c_args), ccb);
				c_stored_before = true;
			}
			c_it.lock();
			// Body
			chr::Statistics::inc_nb_rules();
			if (chr::ES_CHR::FAILURE == CspVarInt( I, X, Dom )) return chr::ES_CHR::FAILURE;
			assert(c_stored_before);
			if (!c_it.alive()) {
				c_it.unlock();
				return chr::ES_CHR::SUCCESS;
			}
			c_it.unlock();
		} // End history
	}
	// Store constraint
	[[maybe_unused]] CspTmpInt_store:
		if (!c_stored_before) {
			c_it = CspTmpInt_constraint_store->add( c_args );
			auto ccb = chr::Shared_x_obj< chr::Logical_var_imp_observer_constraint >(new typename CspTmpInt::Constraint_callback(this,c_it));
			chr::schedule_constraint_callback(std::get<2>(c_args), ccb);
			chr::schedule_constraint_callback(std::get<3>(c_args), ccb);
		}
	return chr::ES_CHR::SUCCESS;
}
chr::ES_CHR sudoku_1b::do_CspVarInt(typename CspVarInt::Type c_args, typename CspVarInt::Constraint_store_t::iterator c_it) {
	bool c_stored_before = !c_it.at_end();
	chr::Statistics::update_call_stack();
	[[maybe_unused]] CspVarInt_call:
	// ***************************************************
	// CspVarInt_0 <=> Rule NO_NAME, active constraint CspVarInt( _, _, Dom ), occurrence 1
	[[maybe_unused]] CspVarInt_0:
	{
		auto& Dom = std::get<3>(c_args);
		// Begin guard
		if (
			( ( *Dom ) . empty(  ) )
		) {
			// Check history
			if (_history.rule_0->check( {{std::get<0>(c_args)}} )) {
				if (!c_stored_before) {
					c_it = CspVarInt_constraint_store->add(c_args);
					auto ccb = chr::Shared_x_obj< chr::Logical_var_imp_observer_constraint >(new typename CspVarInt::Constraint_callback(this,c_it));
					chr::schedule_constraint_callback(std::get<2>(c_args), ccb);
					chr::schedule_constraint_callback(std::get<3>(c_args), ccb);
					c_stored_before = true;
				}
				c_it.lock();
				// Body
				chr::Statistics::inc_nb_rules();
				return chr::failure();
				assert(c_stored_before);
				if (!c_it.alive()) {
					c_it.unlock();
					return chr::ES_CHR::SUCCESS;
				}
				c_it.unlock();
			} // End history
		} // End guard
	}
	// ***************************************************
	// CspVarInt_1 <=> Rule NO_NAME, active constraint CspVarInt( _, X, XDom ), occurrence 2
	[[maybe_unused]] CspVarInt_1:
	{
		auto& X = std::get<2>(c_args);
		auto& XDom = std::get<3>(c_args);
		// Begin guard
		if (
			( ( *XDom ) . singleton(  ) )
		) {
			// Check history
			if (_history.rule_1->check( {{std::get<0>(c_args)}} )) {
				if (!c_stored_before) {
					c_it = CspVarInt_constraint_store->add(c_args);
					auto ccb = chr::Shared_x_obj< chr::Logical_var_imp_observer_constraint >(new typename CspVarInt::Constraint_callback(this,c_it));
					chr::schedule_constraint_callback(std::get<2>(c_args), ccb);
					chr::schedule_constraint_callback(std::get<3>(c_args), ccb);
					c_stored_before = true;
				}
				c_it.lock();
				// Body
				chr::Statistics::inc_nb_rules();
				if ((X %= (*XDom ) . val(  )) == chr::ES_CHR::FAILURE) return chr::ES_CHR::FAILURE;
				assert(c_stored_before);
				if (!c_it.alive()) {
					c_it.unlock();
					return chr::ES_CHR::SUCCESS;
				}
				c_it.unlock();
			} // End history
		} // End guard
	}
	// ***************************************************
	// CspVarInt_2 <=> Rule NO_NAME, active constraint CspVarInt( _, Val, Dom ), occurrence 3
	[[maybe_unused]] CspVarInt_2:
	{
		auto& Val = std::get<2>(c_args);
		auto& Dom = std::get<3>(c_args);
		// Begin guard
		if (
			( Val . ground(  ) )
		) {
			// Check history
			if (_history.rule_2->check( {{std::get<0>(c_args)}} )) {
				if (!c_stored_before) {
					c_it = CspVarInt_constraint_store->add(c_args);
					auto ccb = chr::Shared_x_obj< chr::Logical_var_imp_observer_constraint >(new typename CspVarInt::Constraint_callback(this,c_it));
					chr::schedule_constraint_callback(std::get<2>(c_args), ccb);
					chr::schedule_constraint_callback(std::get<3>(c_args), ccb);
					c_stored_before = true;
				}
				c_it.lock();
				// Body
				chr::Statistics::inc_nb_rules();
				CHECK_ES( maj_dom( Dom, (*Val ) ) );
				assert(c_stored_before);
				if (!c_it.alive()) {
					c_it.unlock();
					return chr::ES_CHR::SUCCESS;
				}
				c_it.unlock();
			} // End history
		} // End guard
	}
	// ***************************************************
	// CspVarInt_3 <=> Rule neq_var_var, active constraint CspVarInt( Id1, X, XDom ), occurrence 4
	[[maybe_unused]] CspVarInt_3:
	{
		if (neq_constraint_store->empty()) goto CspVarInt_4;
		if (CspVarInt_constraint_store->empty()) goto CspVarInt_4;
		auto& Id1 = std::get<1>(c_args);
		auto& X = std::get<2>(c_args);
		auto& XDom = std::get<3>(c_args);
		auto it3_0 = neq_constraint_store->template begin<0>(Id1,X);
		while ( !it3_0.at_end() ) {
			auto Id2(std::get<3>(*it3_0));
			auto Y(std::get<4>(*it3_0));
			auto it3_1 = CspVarInt_constraint_store->template begin<0>(Id2,Y);
			while ( !it3_1.at_end() ) {
				auto YDom(std::get<3>(*it3_1));
				// Begin guard
				if (
					( std::get<0>(*it3_1) != std::get<0>(c_args) )
				) {
					// Check history
					if (_history.rule_5->check( {{std::get<0>(c_args),std::get<0>(*it3_0),std::get<0>(*it3_1)}} )) {
						it3_0.lock();
						it3_1.lock();
						if (!c_stored_before) {
							c_it = CspVarInt_constraint_store->add(c_args);
							auto ccb = chr::Shared_x_obj< chr::Logical_var_imp_observer_constraint >(new typename CspVarInt::Constraint_callback(this,c_it));
							chr::schedule_constraint_callback(std::get<2>(c_args), ccb);
							chr::schedule_constraint_callback(std::get<3>(c_args), ccb);
							c_stored_before = true;
						}
						c_it.lock();
						// Body
						chr::Statistics::inc_nb_rules();
						CHECK_ES( ( Solvint :: ne( XDom, YDom ) ) );
						assert(c_stored_before);
						if (!c_it.alive()) {
							c_it.unlock();
							it3_0.unlock();
							it3_1.unlock();
							return chr::ES_CHR::SUCCESS;
						}
						c_it.unlock();
						if (!it3_0.alive()) {
							it3_1.unlock();
							it3_0.next_and_unlock();
							goto it3_0_next;
						}
						it3_0.unlock();
						it3_1.next_and_unlock();
						goto it3_1_next;
					} // End history
					else {
						++it3_1;
						goto it3_1_next;
					}
				} // End guard
				++it3_1;
				it3_1_next:;
			}
			++it3_0;
			it3_0_next:;
		}
	}
	// ***************************************************
	// CspVarInt_4 <=> Rule neq_var_var, active constraint CspVarInt( Id2, Y, YDom ), occurrence 5
	[[maybe_unused]] CspVarInt_4:
	{
		if (neq_constraint_store->empty()) goto CspVarInt_5;
		if (CspVarInt_constraint_store->empty()) goto CspVarInt_5;
		auto& Id2 = std::get<1>(c_args);
		auto& Y = std::get<2>(c_args);
		auto& YDom = std::get<3>(c_args);
		auto it4_0 = neq_constraint_store->template begin<1>(Id2,Y);
		while ( !it4_0.at_end() ) {
			auto Id1(std::get<1>(*it4_0));
			auto X(std::get<2>(*it4_0));
			auto it4_1 = CspVarInt_constraint_store->template begin<0>(Id1,X);
			while ( !it4_1.at_end() ) {
				auto XDom(std::get<3>(*it4_1));
				// Begin guard
				if (
					( std::get<0>(*it4_1) != std::get<0>(c_args) )
				) {
					// Check history
					if (_history.rule_5->check( {{std::get<0>(c_args),std::get<0>(*it4_0),std::get<0>(*it4_1)}} )) {
						it4_0.lock();
						it4_1.lock();
						if (!c_stored_before) {
							c_it = CspVarInt_constraint_store->add(c_args);
							auto ccb = chr::Shared_x_obj< chr::Logical_var_imp_observer_constraint >(new typename CspVarInt::Constraint_callback(this,c_it));
							chr::schedule_constraint_callback(std::get<2>(c_args), ccb);
							chr::schedule_constraint_callback(std::get<3>(c_args), ccb);
							c_stored_before = true;
						}
						c_it.lock();
						// Body
						chr::Statistics::inc_nb_rules();
						CHECK_ES( ( Solvint :: ne( XDom, YDom ) ) );
						assert(c_stored_before);
						if (!c_it.alive()) {
							c_it.unlock();
							it4_0.unlock();
							it4_1.unlock();
							return chr::ES_CHR::SUCCESS;
						}
						c_it.unlock();
						if (!it4_0.alive()) {
							it4_1.unlock();
							it4_0.next_and_unlock();
							goto it4_0_next;
						}
						it4_0.unlock();
						it4_1.next_and_unlock();
						goto it4_1_next;
					} // End history
					else {
						++it4_1;
						goto it4_1_next;
					}
				} // End guard
				++it4_1;
				it4_1_next:;
			}
			++it4_0;
			it4_0_next:;
		}
	}
	// ***************************************************
	// CspVarInt_5 <=> Rule neq_cste_var, active constraint CspVarInt( Id, Y, YDom ), occurrence 6
	[[maybe_unused]] CspVarInt_5:
	{
		if (neq_constraint_store->empty()) goto CspVarInt_6;
		auto& Id = std::get<1>(c_args);
		auto& Y = std::get<2>(c_args);
		auto& YDom = std::get<3>(c_args);
		auto it5_0 = neq_constraint_store->template begin<1>(Id,Y);
		while ( !it5_0.at_end() ) {
			auto X(std::get<2>(*it5_0));
			// Begin guard
			if (
				( X . ground(  ) )
			) {
				// Check history
				if (_history.rule_6->check( {{std::get<0>(c_args),std::get<0>(*it5_0)}} )) {
					it5_0.lock();
					if (!c_stored_before) {
						c_it = CspVarInt_constraint_store->add(c_args);
						auto ccb = chr::Shared_x_obj< chr::Logical_var_imp_observer_constraint >(new typename CspVarInt::Constraint_callback(this,c_it));
						chr::schedule_constraint_callback(std::get<2>(c_args), ccb);
						chr::schedule_constraint_callback(std::get<3>(c_args), ccb);
						c_stored_before = true;
					}
					c_it.lock();
					// Body
					chr::Statistics::inc_nb_rules();
					CHECK_ES( ( Solvint :: ne( YDom, (*X ) ) ) );
					assert(c_stored_before);
					if (!c_it.alive()) {
						c_it.unlock();
						it5_0.unlock();
						return chr::ES_CHR::SUCCESS;
					}
					c_it.unlock();
					it5_0.next_and_unlock();
					goto it5_0_next;
				} // End history
				else {
					++it5_0;
					goto it5_0_next;
				}
			} // End guard
			++it5_0;
			it5_0_next:;
		}
	}
	// ***************************************************
	// CspVarInt_6 <=> Rule neq_var_cste, active constraint CspVarInt( Id, X, XDom ), occurrence 7
	[[maybe_unused]] CspVarInt_6:
	{
		if (neq_constraint_store->empty()) goto CspVarInt_7;
		auto& Id = std::get<1>(c_args);
		auto& X = std::get<2>(c_args);
		auto& XDom = std::get<3>(c_args);
		auto it6_0 = neq_constraint_store->template begin<0>(Id,X);
		while ( !it6_0.at_end() ) {
			auto Y(std::get<4>(*it6_0));
			// Begin guard
			if (
				( Y . ground(  ) )
			) {
				// Check history
				if (_history.rule_7->check( {{std::get<0>(c_args),std::get<0>(*it6_0)}} )) {
					it6_0.lock();
					if (!c_stored_before) {
						c_it = CspVarInt_constraint_store->add(c_args);
						auto ccb = chr::Shared_x_obj< chr::Logical_var_imp_observer_constraint >(new typename CspVarInt::Constraint_callback(this,c_it));
						chr::schedule_constraint_callback(std::get<2>(c_args), ccb);
						chr::schedule_constraint_callback(std::get<3>(c_args), ccb);
						c_stored_before = true;
					}
					c_it.lock();
					// Body
					chr::Statistics::inc_nb_rules();
					CHECK_ES( ( Solvint :: ne( XDom, (*Y ) ) ) );
					assert(c_stored_before);
					if (!c_it.alive()) {
						c_it.unlock();
						it6_0.unlock();
						return chr::ES_CHR::SUCCESS;
					}
					c_it.unlock();
					it6_0.next_and_unlock();
					goto it6_0_next;
				} // End history
				else {
					++it6_0;
					goto it6_0_next;
				}
			} // End guard
			++it6_0;
			it6_0_next:;
		}
	}
	// ***************************************************
	// CspVarInt_7 <=> Rule eq_var_var, active constraint CspVarInt( _, X, XDom ), occurrence 8
	[[maybe_unused]] CspVarInt_7:
	{
		if (eq_constraint_store->empty()) goto CspVarInt_8;
		if (CspVarInt_constraint_store->empty()) goto CspVarInt_8;
		auto& X = std::get<2>(c_args);
		auto& XDom = std::get<3>(c_args);
		auto it7_0 = eq_constraint_store->template begin<0>(X);
		while ( !it7_0.at_end() ) {
			auto Y(std::get<4>(*it7_0));
			auto it7_1 = CspVarInt_constraint_store->template begin<1>(Y);
			while ( !it7_1.at_end() ) {
				auto YDom(std::get<3>(*it7_1));
				// Begin guard
				if (
					( std::get<0>(*it7_1) != std::get<0>(c_args) )
				) {
					// Check history
					if (_history.rule_11->check( {{std::get<0>(c_args),std::get<0>(*it7_0),std::get<0>(*it7_1)}} )) {
						it7_0.lock();
						it7_1.lock();
						if (!c_stored_before) {
							c_it = CspVarInt_constraint_store->add(c_args);
							auto ccb = chr::Shared_x_obj< chr::Logical_var_imp_observer_constraint >(new typename CspVarInt::Constraint_callback(this,c_it));
							chr::schedule_constraint_callback(std::get<2>(c_args), ccb);
							chr::schedule_constraint_callback(std::get<3>(c_args), ccb);
							c_stored_before = true;
						}
						c_it.lock();
						// Body
						chr::Statistics::inc_nb_rules();
						if ((XDom %= YDom) == chr::ES_CHR::FAILURE) return chr::ES_CHR::FAILURE;
						assert(c_stored_before);
						if (!c_it.alive()) {
							c_it.unlock();
							it7_0.unlock();
							it7_1.unlock();
							return chr::ES_CHR::SUCCESS;
						}
						c_it.unlock();
						if (!it7_0.alive()) {
							it7_1.unlock();
							it7_0.next_and_unlock();
							goto it7_0_next;
						}
						it7_0.unlock();
						it7_1.next_and_unlock();
						goto it7_1_next;
					} // End history
					else {
						++it7_1;
						goto it7_1_next;
					}
				} // End guard
				++it7_1;
				it7_1_next:;
			}
			++it7_0;
			it7_0_next:;
		}
	}
	// ***************************************************
	// CspVarInt_8 <=> Rule eq_var_var, active constraint CspVarInt( _, Y, YDom ), occurrence 9
	[[maybe_unused]] CspVarInt_8:
	{
		if (eq_constraint_store->empty()) goto CspVarInt_store;
		if (CspVarInt_constraint_store->empty()) goto CspVarInt_store;
		auto& Y = std::get<2>(c_args);
		auto& YDom = std::get<3>(c_args);
		auto it8_0 = eq_constraint_store->template begin<1>(Y);
		while ( !it8_0.at_end() ) {
			auto X(std::get<2>(*it8_0));
			auto it8_1 = CspVarInt_constraint_store->template begin<1>(X);
			while ( !it8_1.at_end() ) {
				auto XDom(std::get<3>(*it8_1));
				// Begin guard
				if (
					( std::get<0>(*it8_1) != std::get<0>(c_args) )
				) {
					// Check history
					if (_history.rule_11->check( {{std::get<0>(c_args),std::get<0>(*it8_0),std::get<0>(*it8_1)}} )) {
						it8_0.lock();
						it8_1.lock();
						if (!c_stored_before) {
							c_it = CspVarInt_constraint_store->add(c_args);
							auto ccb = chr::Shared_x_obj< chr::Logical_var_imp_observer_constraint >(new typename CspVarInt::Constraint_callback(this,c_it));
							chr::schedule_constraint_callback(std::get<2>(c_args), ccb);
							chr::schedule_constraint_callback(std::get<3>(c_args), ccb);
							c_stored_before = true;
						}
						c_it.lock();
						// Body
						chr::Statistics::inc_nb_rules();
						if ((XDom %= YDom) == chr::ES_CHR::FAILURE) return chr::ES_CHR::FAILURE;
						assert(c_stored_before);
						if (!c_it.alive()) {
							c_it.unlock();
							it8_0.unlock();
							it8_1.unlock();
							return chr::ES_CHR::SUCCESS;
						}
						c_it.unlock();
						if (!it8_0.alive()) {
							it8_1.unlock();
							it8_0.next_and_unlock();
							goto it8_0_next;
						}
						it8_0.unlock();
						it8_1.next_and_unlock();
						goto it8_1_next;
					} // End history
					else {
						++it8_1;
						goto it8_1_next;
					}
				} // End guard
				++it8_1;
				it8_1_next:;
			}
			++it8_0;
			it8_0_next:;
		}
	}
	// Store constraint
	[[maybe_unused]] CspVarInt_store:
		if (!c_stored_before) {
			c_it = CspVarInt_constraint_store->add( c_args );
			auto ccb = chr::Shared_x_obj< chr::Logical_var_imp_observer_constraint >(new typename CspVarInt::Constraint_callback(this,c_it));
			chr::schedule_constraint_callback(std::get<2>(c_args), ccb);
			chr::schedule_constraint_callback(std::get<3>(c_args), ccb);
		}
	return chr::ES_CHR::SUCCESS;
}
chr::ES_CHR sudoku_1b::do_CspVarIntDec(typename CspVarIntDec::Type c_args, typename CspVarIntDec::Constraint_store_t::iterator c_it) {
	bool c_stored_before = !c_it.at_end();
	chr::Statistics::update_call_stack();
	[[maybe_unused]] CspVarIntDec_call:
	// ***************************************************
	// CspVarIntDec_0 <=> Rule NO_NAME, active constraint CspVarIntDec( Id, _, X, Dom ), occurrence 1
	[[maybe_unused]] CspVarIntDec_0:
	{
		auto& Id = std::get<1>(c_args);
		auto& X = std::get<3>(c_args);
		auto& Dom = std::get<4>(c_args);
		// Check history
		if (_history.rule_3->check( {{std::get<0>(c_args)}} )) {
			if (!c_stored_before) {
				c_it = CspVarIntDec_constraint_store->add(c_args);
				auto ccb = chr::Shared_x_obj< chr::Logical_var_imp_observer_constraint >(new typename CspVarIntDec::Constraint_callback(this,c_it));
				chr::schedule_constraint_callback(std::get<3>(c_args), ccb);
				chr::schedule_constraint_callback(std::get<4>(c_args), ccb);
				c_stored_before = true;
			}
			c_it.lock();
			// Body
			chr::Statistics::inc_nb_rules();
			if (chr::ES_CHR::FAILURE == CspVarInt( Id, X, Dom )) return chr::ES_CHR::FAILURE;
			assert(c_stored_before);
			if (!c_it.alive()) {
				c_it.unlock();
				return chr::ES_CHR::SUCCESS;
			}
			c_it.unlock();
		} // End history
	}
	// Store constraint
	[[maybe_unused]] CspVarIntDec_store:
		if (!c_stored_before) {
			c_it = CspVarIntDec_constraint_store->add( c_args );
			auto ccb = chr::Shared_x_obj< chr::Logical_var_imp_observer_constraint >(new typename CspVarIntDec::Constraint_callback(this,c_it));
			chr::schedule_constraint_callback(std::get<3>(c_args), ccb);
			chr::schedule_constraint_callback(std::get<4>(c_args), ccb);
		}
	return chr::ES_CHR::SUCCESS;
}
chr::ES_CHR sudoku_1b::do_eq(typename eq::Type c_args, typename eq::Constraint_store_t::iterator c_it) {
	bool c_stored_before = !c_it.at_end();
	chr::Statistics::update_call_stack();
	[[maybe_unused]] eq_call:
	// ***************************************************
	// eq_0 <=> Rule eq_cste_cste, active constraint eq( _, X, _, Y ), occurrence 1
	[[maybe_unused]] eq_0:
	{
		auto& X = std::get<2>(c_args);
		auto& Y = std::get<4>(c_args);
		// Check history
		if (_history.rule_10->check( {{std::get<0>(c_args)}} )) {
			if (!c_stored_before) {
				c_it = eq_constraint_store->add(c_args);
				auto ccb = chr::Shared_x_obj< chr::Logical_var_imp_observer_constraint >(new typename eq::Constraint_callback(this,c_it));
				chr::schedule_constraint_callback(std::get<2>(c_args), ccb);
				chr::schedule_constraint_callback(std::get<4>(c_args), ccb);
				c_stored_before = true;
			}
			c_it.lock();
			// Body
			chr::Statistics::inc_nb_rules();
			if ((X %= Y) == chr::ES_CHR::FAILURE) return chr::ES_CHR::FAILURE;
			assert(c_stored_before);
			if (!c_it.alive()) {
				c_it.unlock();
				return chr::ES_CHR::SUCCESS;
			}
			c_it.unlock();
		} // End history
	}
	// ***************************************************
	// eq_1 <=> Rule eq_var_var, active constraint eq( _, X, _, Y ), occurrence 2
	[[maybe_unused]] eq_1:
	{
		if (CspVarInt_constraint_store->empty()) goto eq_store;
		if (CspVarInt_constraint_store->empty()) goto eq_store;
		auto& X = std::get<2>(c_args);
		auto& Y = std::get<4>(c_args);
		auto it1_0 = CspVarInt_constraint_store->template begin<1>(X);
		while ( !it1_0.at_end() ) {
			auto XDom(std::get<3>(*it1_0));
			auto it1_1 = CspVarInt_constraint_store->template begin<1>(Y);
			while ( !it1_1.at_end() ) {
				auto YDom(std::get<3>(*it1_1));
				// Begin guard
				if (
					( std::get<0>(*it1_1) != std::get<0>(*it1_0) )
				) {
					// Check history
					if (_history.rule_11->check( {{std::get<0>(c_args),std::get<0>(*it1_0),std::get<0>(*it1_1)}} )) {
						it1_0.lock();
						it1_1.lock();
						if (!c_stored_before) {
							c_it = eq_constraint_store->add(c_args);
							auto ccb = chr::Shared_x_obj< chr::Logical_var_imp_observer_constraint >(new typename eq::Constraint_callback(this,c_it));
							chr::schedule_constraint_callback(std::get<2>(c_args), ccb);
							chr::schedule_constraint_callback(std::get<4>(c_args), ccb);
							c_stored_before = true;
						}
						c_it.lock();
						// Body
						chr::Statistics::inc_nb_rules();
						if ((XDom %= YDom) == chr::ES_CHR::FAILURE) return chr::ES_CHR::FAILURE;
						assert(c_stored_before);
						if (!c_it.alive()) {
							c_it.unlock();
							it1_0.unlock();
							it1_1.unlock();
							return chr::ES_CHR::SUCCESS;
						}
						c_it.unlock();
						if (!it1_0.alive()) {
							it1_1.unlock();
							it1_0.next_and_unlock();
							goto it1_0_next;
						}
						it1_0.unlock();
						it1_1.next_and_unlock();
						goto it1_1_next;
					} // End history
					else {
						++it1_1;
						goto it1_1_next;
					}
				} // End guard
				++it1_1;
				it1_1_next:;
			}
			++it1_0;
			it1_0_next:;
		}
	}
	// Store constraint
	[[maybe_unused]] eq_store:
		if (!c_stored_before) {
			c_it = eq_constraint_store->add( c_args );
			auto ccb = chr::Shared_x_obj< chr::Logical_var_imp_observer_constraint >(new typename eq::Constraint_callback(this,c_it));
			chr::schedule_constraint_callback(std::get<2>(c_args), ccb);
			chr::schedule_constraint_callback(std::get<4>(c_args), ccb);
		}
	return chr::ES_CHR::SUCCESS;
}
chr::ES_CHR sudoku_1b::do_labelling(typename labelling::Type c_args) {
	chr::Statistics::update_call_stack();
	[[maybe_unused]] labelling_call:
	// ***************************************************
	// labelling_0 <=> Rule NO_NAME, active constraint labelling( Id ), occurrence 1
	[[maybe_unused]] labelling_0:
	{
		if (CspVarIntDec_constraint_store->empty()) goto labelling_1;
		auto& Id = std::get<1>(c_args);
		auto it0_0 = CspVarIntDec_constraint_store->template begin<0>(Id);
		if ( !it0_0.at_end() ) {
			auto Dom(std::get<4>(*it0_0));
			// Body
			chr::Statistics::inc_nb_rules();
			auto __it_i = (*Dom ) . begin(  );
			auto __it_end_i = (*Dom ) . end(  );
			auto __local_success__3 = false;
			{
				unsigned int depth0 = chr::Backtrack::depth();
				chr::Statistics::open_choice();
				while (!( __local_success__3 || ( __it_i == __it_end_i ) )) {
					chr::reset();
					if (depth0 != chr::Backtrack::depth()) chr::Backtrack::back_to(depth0);
					chr::Backtrack::inc_backtrack_depth();
					auto _try_beha_0_ = [&]() {
						auto i = (*__it_i );
						CHECK_ES( set_eq( Dom, i ) );
						if (chr::ES_CHR::FAILURE == labelling( ( Id + 1 ) )) return chr::ES_CHR::FAILURE;
						return chr::ES_CHR::SUCCESS;
					};
					if (_try_beha_0_() == chr::ES_CHR::SUCCESS) {
						__local_success__3 = true;
					} else {
						CHECK_ES( (++__it_i ) );
					}
				}
				chr::Statistics::close_choice();
				chr::reset();
				if (__local_success__3) {
					if (depth0 != chr::Backtrack::depth()) chr::Backtrack::back_to(depth0);
				} else {
					return (chr::failed()?chr::ES_CHR::FAILURE:chr::failure());
				}
			}

			return chr::ES_CHR::SUCCESS;
		}
	}
	// ***************************************************
	// labelling_1 <=> Rule NO_NAME, active constraint labelling( Id ), occurrence 2
	[[maybe_unused]] labelling_1:
	{
		auto& Id = std::get<1>(c_args);
		// Body
		chr::Statistics::inc_nb_rules();
		CHECK_ES( print_store( (*this ) ) );
		return chr::ES_CHR::SUCCESS;
	}
	// Store constraint
	[[maybe_unused]] labelling_store:
	return chr::ES_CHR::SUCCESS;
}
chr::ES_CHR sudoku_1b::do_neq(typename neq::Type c_args, typename neq::Constraint_store_t::iterator c_it) {
	bool c_stored_before = !c_it.at_end();
	chr::Statistics::update_call_stack();
	[[maybe_unused]] neq_call:
	// ***************************************************
	// neq_0 <=> Rule neq_var_var, active constraint neq( Id1, X, Id2, Y ), occurrence 1
	[[maybe_unused]] neq_0:
	{
		if (CspVarInt_constraint_store->empty()) goto neq_1;
		if (CspVarInt_constraint_store->empty()) goto neq_1;
		auto& Id1 = std::get<1>(c_args);
		auto& X = std::get<2>(c_args);
		auto& Id2 = std::get<3>(c_args);
		auto& Y = std::get<4>(c_args);
		auto it0_0 = CspVarInt_constraint_store->template begin<0>(Id1,X);
		while ( !it0_0.at_end() ) {
			auto XDom(std::get<3>(*it0_0));
			auto it0_1 = CspVarInt_constraint_store->template begin<0>(Id2,Y);
			while ( !it0_1.at_end() ) {
				auto YDom(std::get<3>(*it0_1));
				// Begin guard
				if (
					( std::get<0>(*it0_1) != std::get<0>(*it0_0) )
				) {
					// Check history
					if (_history.rule_5->check( {{std::get<0>(c_args),std::get<0>(*it0_0),std::get<0>(*it0_1)}} )) {
						it0_0.lock();
						it0_1.lock();
						if (!c_stored_before) {
							c_it = neq_constraint_store->add(c_args);
							auto ccb = chr::Shared_x_obj< chr::Logical_var_imp_observer_constraint >(new typename neq::Constraint_callback(this,c_it));
							chr::schedule_constraint_callback(std::get<2>(c_args), ccb);
							chr::schedule_constraint_callback(std::get<4>(c_args), ccb);
							c_stored_before = true;
						}
						c_it.lock();
						// Body
						chr::Statistics::inc_nb_rules();
						CHECK_ES( ( Solvint :: ne( XDom, YDom ) ) );
						assert(c_stored_before);
						if (!c_it.alive()) {
							c_it.unlock();
							it0_0.unlock();
							it0_1.unlock();
							return chr::ES_CHR::SUCCESS;
						}
						c_it.unlock();
						if (!it0_0.alive()) {
							it0_1.unlock();
							it0_0.next_and_unlock();
							goto it0_0_next;
						}
						it0_0.unlock();
						it0_1.next_and_unlock();
						goto it0_1_next;
					} // End history
					else {
						++it0_1;
						goto it0_1_next;
					}
				} // End guard
				++it0_1;
				it0_1_next:;
			}
			++it0_0;
			it0_0_next:;
		}
	}
	// ***************************************************
	// neq_1 <=> Rule neq_cste_var, active constraint neq( _, X, Id, Y ), occurrence 2
	[[maybe_unused]] neq_1:
	{
		if (CspVarInt_constraint_store->empty()) goto neq_2;
		auto& X = std::get<2>(c_args);
		auto& Id = std::get<3>(c_args);
		auto& Y = std::get<4>(c_args);
		// Begin guard
		if (
			( X . ground(  ) )
		) {
			auto it1_0 = CspVarInt_constraint_store->template begin<0>(Id,Y);
			while ( !it1_0.at_end() ) {
				auto YDom(std::get<3>(*it1_0));
				// Check history
				if (_history.rule_6->check( {{std::get<0>(c_args),std::get<0>(*it1_0)}} )) {
					it1_0.lock();
					if (!c_stored_before) {
						c_it = neq_constraint_store->add(c_args);
						auto ccb = chr::Shared_x_obj< chr::Logical_var_imp_observer_constraint >(new typename neq::Constraint_callback(this,c_it));
						chr::schedule_constraint_callback(std::get<2>(c_args), ccb);
						chr::schedule_constraint_callback(std::get<4>(c_args), ccb);
						c_stored_before = true;
					}
					c_it.lock();
					// Body
					chr::Statistics::inc_nb_rules();
					CHECK_ES( ( Solvint :: ne( YDom, (*X ) ) ) );
					assert(c_stored_before);
					if (!c_it.alive()) {
						c_it.unlock();
						it1_0.unlock();
						return chr::ES_CHR::SUCCESS;
					}
					c_it.unlock();
					it1_0.next_and_unlock();
				} // End history
				else {
					++it1_0;
				}
			}
		} // End guard
	}
	// ***************************************************
	// neq_2 <=> Rule neq_var_cste, active constraint neq( Id, X, _, Y ), occurrence 3
	[[maybe_unused]] neq_2:
	{
		if (CspVarInt_constraint_store->empty()) goto neq_store;
		auto& Id = std::get<1>(c_args);
		auto& X = std::get<2>(c_args);
		auto& Y = std::get<4>(c_args);
		// Begin guard
		if (
			( Y . ground(  ) )
		) {
			auto it2_0 = CspVarInt_constraint_store->template begin<0>(Id,X);
			while ( !it2_0.at_end() ) {
				auto XDom(std::get<3>(*it2_0));
				// Check history
				if (_history.rule_7->check( {{std::get<0>(c_args),std::get<0>(*it2_0)}} )) {
					it2_0.lock();
					if (!c_stored_before) {
						c_it = neq_constraint_store->add(c_args);
						auto ccb = chr::Shared_x_obj< chr::Logical_var_imp_observer_constraint >(new typename neq::Constraint_callback(this,c_it));
						chr::schedule_constraint_callback(std::get<2>(c_args), ccb);
						chr::schedule_constraint_callback(std::get<4>(c_args), ccb);
						c_stored_before = true;
					}
					c_it.lock();
					// Body
					chr::Statistics::inc_nb_rules();
					CHECK_ES( ( Solvint :: ne( XDom, (*Y ) ) ) );
					assert(c_stored_before);
					if (!c_it.alive()) {
						c_it.unlock();
						it2_0.unlock();
						return chr::ES_CHR::SUCCESS;
					}
					c_it.unlock();
					it2_0.next_and_unlock();
				} // End history
				else {
					++it2_0;
				}
			}
		} // End guard
	}
	// Store constraint
	[[maybe_unused]] neq_store:
		if (!c_stored_before) {
			c_it = neq_constraint_store->add( c_args );
			auto ccb = chr::Shared_x_obj< chr::Logical_var_imp_observer_constraint >(new typename neq::Constraint_callback(this,c_it));
			chr::schedule_constraint_callback(std::get<2>(c_args), ccb);
			chr::schedule_constraint_callback(std::get<4>(c_args), ccb);
		}
	return chr::ES_CHR::SUCCESS;
}
chr::ES_CHR sudoku_1b::do_put_alldiff(typename put_alldiff::Type c_args) {
	chr::Statistics::update_call_stack();
	[[maybe_unused]] put_alldiff_call:
	// ***************************************************
	// put_alldiff_0 <=> Rule NO_NAME, active constraint put_alldiff( L, Ids ), occurrence 1
	[[maybe_unused]] put_alldiff_0:
	{
		auto& L = std::get<1>(c_args);
		auto& Ids = std::get<2>(c_args);
		// Begin guard
		if (
			( ( *L ) . empty(  ) )
		) {
			// Body
			chr::Statistics::inc_nb_rules();

			return chr::ES_CHR::SUCCESS;
		} // End guard
	}
	// ***************************************************
	// put_alldiff_1 <=> Rule NO_NAME, active constraint put_alldiff( L, Ids ), occurrence 2
	[[maybe_unused]] put_alldiff_1:
	{
		auto& L = std::get<1>(c_args);
		auto& Ids = std::get<2>(c_args);
		// Body
		chr::Statistics::inc_nb_rules();
		CHECK_ES( alldiff_fun( (*this ), (*L ), (*Ids ) ) );
		return chr::ES_CHR::SUCCESS;
	}
	// Store constraint
	[[maybe_unused]] put_alldiff_store:
	return chr::ES_CHR::SUCCESS;
}
//----------------------- START INCLUDE HEADER ---------------------

int main(int argc, const char *argv[]) {
    auto space = sudoku_1b::create();
    chr::Logical_var<int> X[81];
    chr::Logical_var_mutable<interval> Dom[81];

Dom[0] = interval(1,9);
space->CspVarIntDec(0, string("x[0][0]"), X[0], Dom[0]);
Dom[1] = interval(1,9);
space->CspVarIntDec(1, string("x[0][1]"), X[1], Dom[1]);
Dom[2] = interval(1,9);
space->CspVarIntDec(2, string("x[0][2]"), X[2], Dom[2]);
Dom[3] = interval(1,9);
space->CspVarIntDec(3, string("x[0][3]"), X[3], Dom[3]);
Dom[4] = interval(1,9);
space->CspVarIntDec(4, string("x[0][4]"), X[4], Dom[4]);
Dom[5] = interval(1,9);
space->CspVarIntDec(5, string("x[0][5]"), X[5], Dom[5]);
Dom[6] = interval(1,9);
space->CspVarIntDec(6, string("x[0][6]"), X[6], Dom[6]);
Dom[7] = interval(1,9);
space->CspVarIntDec(7, string("x[0][7]"), X[7], Dom[7]);
Dom[8] = interval(1,9);
space->CspVarIntDec(8, string("x[0][8]"), X[8], Dom[8]);
Dom[9] = interval(1,9);
space->CspVarIntDec(9, string("x[1][0]"), X[9], Dom[9]);
Dom[10] = interval(1,9);
space->CspVarIntDec(10, string("x[1][1]"), X[10], Dom[10]);
Dom[11] = interval(1,9);
space->CspVarIntDec(11, string("x[1][2]"), X[11], Dom[11]);
Dom[12] = interval(1,9);
space->CspVarIntDec(12, string("x[1][3]"), X[12], Dom[12]);
Dom[13] = interval(1,9);
space->CspVarIntDec(13, string("x[1][4]"), X[13], Dom[13]);
Dom[14] = interval(1,9);
space->CspVarIntDec(14, string("x[1][5]"), X[14], Dom[14]);
Dom[15] = interval(1,9);
space->CspVarIntDec(15, string("x[1][6]"), X[15], Dom[15]);
Dom[16] = interval(1,9);
space->CspVarIntDec(16, string("x[1][7]"), X[16], Dom[16]);
Dom[17] = interval(1,9);
space->CspVarIntDec(17, string("x[1][8]"), X[17], Dom[17]);
Dom[18] = interval(1,9);
space->CspVarIntDec(18, string("x[2][0]"), X[18], Dom[18]);
Dom[19] = interval(1,9);
space->CspVarIntDec(19, string("x[2][1]"), X[19], Dom[19]);
Dom[20] = interval(1,9);
space->CspVarIntDec(20, string("x[2][2]"), X[20], Dom[20]);
Dom[21] = interval(1,9);
space->CspVarIntDec(21, string("x[2][3]"), X[21], Dom[21]);
Dom[22] = interval(1,9);
space->CspVarIntDec(22, string("x[2][4]"), X[22], Dom[22]);
Dom[23] = interval(1,9);
space->CspVarIntDec(23, string("x[2][5]"), X[23], Dom[23]);
Dom[24] = interval(1,9);
space->CspVarIntDec(24, string("x[2][6]"), X[24], Dom[24]);
Dom[25] = interval(1,9);
space->CspVarIntDec(25, string("x[2][7]"), X[25], Dom[25]);
Dom[26] = interval(1,9);
space->CspVarIntDec(26, string("x[2][8]"), X[26], Dom[26]);
Dom[27] = interval(1,9);
space->CspVarIntDec(27, string("x[3][0]"), X[27], Dom[27]);
Dom[28] = interval(1,9);
space->CspVarIntDec(28, string("x[3][1]"), X[28], Dom[28]);
Dom[29] = interval(1,9);
space->CspVarIntDec(29, string("x[3][2]"), X[29], Dom[29]);
Dom[30] = interval(1,9);
space->CspVarIntDec(30, string("x[3][3]"), X[30], Dom[30]);
Dom[31] = interval(1,9);
space->CspVarIntDec(31, string("x[3][4]"), X[31], Dom[31]);
Dom[32] = interval(1,9);
space->CspVarIntDec(32, string("x[3][5]"), X[32], Dom[32]);
Dom[33] = interval(1,9);
space->CspVarIntDec(33, string("x[3][6]"), X[33], Dom[33]);
Dom[34] = interval(1,9);
space->CspVarIntDec(34, string("x[3][7]"), X[34], Dom[34]);
Dom[35] = interval(1,9);
space->CspVarIntDec(35, string("x[3][8]"), X[35], Dom[35]);
Dom[36] = interval(1,9);
space->CspVarIntDec(36, string("x[4][0]"), X[36], Dom[36]);
Dom[37] = interval(1,9);
space->CspVarIntDec(37, string("x[4][1]"), X[37], Dom[37]);
Dom[38] = interval(1,9);
space->CspVarIntDec(38, string("x[4][2]"), X[38], Dom[38]);
Dom[39] = interval(1,9);
space->CspVarIntDec(39, string("x[4][3]"), X[39], Dom[39]);
Dom[40] = interval(1,9);
space->CspVarIntDec(40, string("x[4][4]"), X[40], Dom[40]);
Dom[41] = interval(1,9);
space->CspVarIntDec(41, string("x[4][5]"), X[41], Dom[41]);
Dom[42] = interval(1,9);
space->CspVarIntDec(42, string("x[4][6]"), X[42], Dom[42]);
Dom[43] = interval(1,9);
space->CspVarIntDec(43, string("x[4][7]"), X[43], Dom[43]);
Dom[44] = interval(1,9);
space->CspVarIntDec(44, string("x[4][8]"), X[44], Dom[44]);
Dom[45] = interval(1,9);
space->CspVarIntDec(45, string("x[5][0]"), X[45], Dom[45]);
Dom[46] = interval(1,9);
space->CspVarIntDec(46, string("x[5][1]"), X[46], Dom[46]);
Dom[47] = interval(1,9);
space->CspVarIntDec(47, string("x[5][2]"), X[47], Dom[47]);
Dom[48] = interval(1,9);
space->CspVarIntDec(48, string("x[5][3]"), X[48], Dom[48]);
Dom[49] = interval(1,9);
space->CspVarIntDec(49, string("x[5][4]"), X[49], Dom[49]);
Dom[50] = interval(1,9);
space->CspVarIntDec(50, string("x[5][5]"), X[50], Dom[50]);
Dom[51] = interval(1,9);
space->CspVarIntDec(51, string("x[5][6]"), X[51], Dom[51]);
Dom[52] = interval(1,9);
space->CspVarIntDec(52, string("x[5][7]"), X[52], Dom[52]);
Dom[53] = interval(1,9);
space->CspVarIntDec(53, string("x[5][8]"), X[53], Dom[53]);
Dom[54] = interval(1,9);
space->CspVarIntDec(54, string("x[6][0]"), X[54], Dom[54]);
Dom[55] = interval(1,9);
space->CspVarIntDec(55, string("x[6][1]"), X[55], Dom[55]);
Dom[56] = interval(1,9);
space->CspVarIntDec(56, string("x[6][2]"), X[56], Dom[56]);
Dom[57] = interval(1,9);
space->CspVarIntDec(57, string("x[6][3]"), X[57], Dom[57]);
Dom[58] = interval(1,9);
space->CspVarIntDec(58, string("x[6][4]"), X[58], Dom[58]);
Dom[59] = interval(1,9);
space->CspVarIntDec(59, string("x[6][5]"), X[59], Dom[59]);
Dom[60] = interval(1,9);
space->CspVarIntDec(60, string("x[6][6]"), X[60], Dom[60]);
Dom[61] = interval(1,9);
space->CspVarIntDec(61, string("x[6][7]"), X[61], Dom[61]);
Dom[62] = interval(1,9);
space->CspVarIntDec(62, string("x[6][8]"), X[62], Dom[62]);
Dom[63] = interval(1,9);
space->CspVarIntDec(63, string("x[7][0]"), X[63], Dom[63]);
Dom[64] = interval(1,9);
space->CspVarIntDec(64, string("x[7][1]"), X[64], Dom[64]);
Dom[65] = interval(1,9);
space->CspVarIntDec(65, string("x[7][2]"), X[65], Dom[65]);
Dom[66] = interval(1,9);
space->CspVarIntDec(66, string("x[7][3]"), X[66], Dom[66]);
Dom[67] = interval(1,9);
space->CspVarIntDec(67, string("x[7][4]"), X[67], Dom[67]);
Dom[68] = interval(1,9);
space->CspVarIntDec(68, string("x[7][5]"), X[68], Dom[68]);
Dom[69] = interval(1,9);
space->CspVarIntDec(69, string("x[7][6]"), X[69], Dom[69]);
Dom[70] = interval(1,9);
space->CspVarIntDec(70, string("x[7][7]"), X[70], Dom[70]);
Dom[71] = interval(1,9);
space->CspVarIntDec(71, string("x[7][8]"), X[71], Dom[71]);
Dom[72] = interval(1,9);
space->CspVarIntDec(72, string("x[8][0]"), X[72], Dom[72]);
Dom[73] = interval(1,9);
space->CspVarIntDec(73, string("x[8][1]"), X[73], Dom[73]);
Dom[74] = interval(1,9);
space->CspVarIntDec(74, string("x[8][2]"), X[74], Dom[74]);
Dom[75] = interval(1,9);
space->CspVarIntDec(75, string("x[8][3]"), X[75], Dom[75]);
Dom[76] = interval(1,9);
space->CspVarIntDec(76, string("x[8][4]"), X[76], Dom[76]);
Dom[77] = interval(1,9);
space->CspVarIntDec(77, string("x[8][5]"), X[77], Dom[77]);
Dom[78] = interval(1,9);
space->CspVarIntDec(78, string("x[8][6]"), X[78], Dom[78]);
Dom[79] = interval(1,9);
space->CspVarIntDec(79, string("x[8][7]"), X[79], Dom[79]);
Dom[80] = interval(1,9);
space->CspVarIntDec(80, string("x[8][8]"), X[80], Dom[80]);
    set_eq(Dom[0], 8);
    set_eq(Dom[2], 2);
    set_eq(Dom[4], 5);
    set_eq(Dom[6], 7);
    set_eq(Dom[8], 1);
    set_eq(Dom[11], 7);
    set_eq(Dom[13], 8);
    set_eq(Dom[14], 2);
    set_eq(Dom[15], 4);
    set_eq(Dom[16], 6);
    set_eq(Dom[19], 1);
    set_eq(Dom[21], 9);
    set_eq(Dom[27], 6);
    set_eq(Dom[32], 1);
    set_eq(Dom[33], 8);
    set_eq(Dom[34], 3);
    set_eq(Dom[35], 2);
    set_eq(Dom[36], 5);
    set_eq(Dom[44], 9);
    set_eq(Dom[45], 1);
    set_eq(Dom[46], 8);
    set_eq(Dom[47], 4);
    set_eq(Dom[48], 3);
    set_eq(Dom[53], 6);
    set_eq(Dom[59], 4);
    set_eq(Dom[61], 2);
    set_eq(Dom[64], 9);
    set_eq(Dom[65], 5);
    set_eq(Dom[66], 6);
    set_eq(Dom[67], 1);
    set_eq(Dom[69], 3);
    set_eq(Dom[72], 3);
    set_eq(Dom[74], 8);
    set_eq(Dom[76], 9);
    set_eq(Dom[78], 6);
    set_eq(Dom[80], 7);


CHR_RUN(    space->put_alldiff(make_list_var(X[0], X[1], X[2], X[3], X[4], X[5], X[6], X[7], X[8]), make_list_int(0, 1, 2, 3, 4, 5, 6, 7, 8));
    space->put_alldiff(make_list_var(X[9], X[10], X[11], X[12], X[13], X[14], X[15], X[16], X[17]), make_list_int(9, 10, 11, 12, 13, 14, 15, 16, 17));
    space->put_alldiff(make_list_var(X[18], X[19], X[20], X[21], X[22], X[23], X[24], X[25], X[26]), make_list_int(18, 19, 20, 21, 22, 23, 24, 25, 26));
    space->put_alldiff(make_list_var(X[27], X[28], X[29], X[30], X[31], X[32], X[33], X[34], X[35]), make_list_int(27, 28, 29, 30, 31, 32, 33, 34, 35));
    space->put_alldiff(make_list_var(X[36], X[37], X[38], X[39], X[40], X[41], X[42], X[43], X[44]), make_list_int(36, 37, 38, 39, 40, 41, 42, 43, 44));
    space->put_alldiff(make_list_var(X[45], X[46], X[47], X[48], X[49], X[50], X[51], X[52], X[53]), make_list_int(45, 46, 47, 48, 49, 50, 51, 52, 53));
    space->put_alldiff(make_list_var(X[54], X[55], X[56], X[57], X[58], X[59], X[60], X[61], X[62]), make_list_int(54, 55, 56, 57, 58, 59, 60, 61, 62));
    space->put_alldiff(make_list_var(X[63], X[64], X[65], X[66], X[67], X[68], X[69], X[70], X[71]), make_list_int(63, 64, 65, 66, 67, 68, 69, 70, 71));
    space->put_alldiff(make_list_var(X[72], X[73], X[74], X[75], X[76], X[77], X[78], X[79], X[80]), make_list_int(72, 73, 74, 75, 76, 77, 78, 79, 80));
    space->put_alldiff(make_list_var(X[0], X[9], X[18], X[27], X[36], X[45], X[54], X[63], X[72]), make_list_int(0, 9, 18, 27, 36, 45, 54, 63, 72));
    space->put_alldiff(make_list_var(X[1], X[10], X[19], X[28], X[37], X[46], X[55], X[64], X[73]), make_list_int(1, 10, 19, 28, 37, 46, 55, 64, 73));
    space->put_alldiff(make_list_var(X[2], X[11], X[20], X[29], X[38], X[47], X[56], X[65], X[74]), make_list_int(2, 11, 20, 29, 38, 47, 56, 65, 74));
    space->put_alldiff(make_list_var(X[3], X[12], X[21], X[30], X[39], X[48], X[57], X[66], X[75]), make_list_int(3, 12, 21, 30, 39, 48, 57, 66, 75));
    space->put_alldiff(make_list_var(X[4], X[13], X[22], X[31], X[40], X[49], X[58], X[67], X[76]), make_list_int(4, 13, 22, 31, 40, 49, 58, 67, 76));
    space->put_alldiff(make_list_var(X[5], X[14], X[23], X[32], X[41], X[50], X[59], X[68], X[77]), make_list_int(5, 14, 23, 32, 41, 50, 59, 68, 77));
    space->put_alldiff(make_list_var(X[6], X[15], X[24], X[33], X[42], X[51], X[60], X[69], X[78]), make_list_int(6, 15, 24, 33, 42, 51, 60, 69, 78));
    space->put_alldiff(make_list_var(X[7], X[16], X[25], X[34], X[43], X[52], X[61], X[70], X[79]), make_list_int(7, 16, 25, 34, 43, 52, 61, 70, 79));
    space->put_alldiff(make_list_var(X[8], X[17], X[26], X[35], X[44], X[53], X[62], X[71], X[80]), make_list_int(8, 17, 26, 35, 44, 53, 62, 71, 80));
    space->put_alldiff(make_list_var(X[0], X[1], X[2], X[9], X[10], X[11], X[18], X[19], X[20]), make_list_int(0, 1, 2, 9, 10, 11, 18, 19, 20));
    space->put_alldiff(make_list_var(X[3], X[4], X[5], X[12], X[13], X[14], X[21], X[22], X[23]), make_list_int(3, 4, 5, 12, 13, 14, 21, 22, 23));
    space->put_alldiff(make_list_var(X[6], X[7], X[8], X[15], X[16], X[17], X[24], X[25], X[26]), make_list_int(6, 7, 8, 15, 16, 17, 24, 25, 26));
    space->put_alldiff(make_list_var(X[27], X[28], X[29], X[36], X[37], X[38], X[45], X[46], X[47]), make_list_int(27, 28, 29, 36, 37, 38, 45, 46, 47));
    space->put_alldiff(make_list_var(X[30], X[31], X[32], X[39], X[40], X[41], X[48], X[49], X[50]), make_list_int(30, 31, 32, 39, 40, 41, 48, 49, 50));
    space->put_alldiff(make_list_var(X[33], X[34], X[35], X[42], X[43], X[44], X[51], X[52], X[53]), make_list_int(33, 34, 35, 42, 43, 44, 51, 52, 53));
    space->put_alldiff(make_list_var(X[54], X[55], X[56], X[63], X[64], X[65], X[72], X[73], X[74]), make_list_int(54, 55, 56, 63, 64, 65, 72, 73, 74));
    space->put_alldiff(make_list_var(X[57], X[58], X[59], X[66], X[67], X[68], X[75], X[76], X[77]), make_list_int(57, 58, 59, 66, 67, 68, 75, 76, 77));
    space->put_alldiff(make_list_var(X[60], X[61], X[62], X[69], X[70], X[71], X[78], X[79], X[80]), make_list_int(60, 61, 62, 69, 70, 71, 78, 79, 80));
); 
CHR_RUN(space->labelling(0);); 
chr::Statistics::print(std::cout);
return 0;
}
//----------------------- END INCLUDE HEADER ---------------------
