/*
From line 241 to 259
labelling<labelling( ( Id + 1 ) )> { CspVarIntDec<CspVarIntDec( Id, _, _, Dom )> } --> labelling<labelling( ( Id + 1 ) )>, built-in<begin(  )>
put_usum<put_usum( L, Ids, Target )> --> built-in<sum_fun( ( *this ), ( *L ), ( *Ids ), Target )>
plus<plus( Id1, X, Id2, Y, Id3, Z )> { CspVarInt<CspVarInt( Id1, X, XDom )> } --> built-in<plus_boundConsistency( XDom, YDom, ZDom )>
eq<eq( Id1, X, Id2, Y )> { CspVarInt<CspVarInt( Id1, X, XDom )> } --> built-in<YDom>
neq<neq( Id1, X, Id2, Y )> { CspVarInt<CspVarInt( Id1, X, XDom )> } --> built-in<ne( XDom, YDom )>
CspTmpInt<CspTmpInt( I, X, Dom )> --> CspVarInt<CspVarInt( I, X, Dom )>
CspVarIntDec<CspVarIntDec( Id, _, X, Dom )> { labelling<labelling( Id )> } --> labelling<labelling( ( Id + 1 ) )>, built-in<begin(  )>, CspVarInt<CspVarInt( Id, X, Dom )>
put_alldiff<put_alldiff( L, Ids )> --> built-in<alldiff_fun( ( *this ), ( *L ), ( *Ids ) )>
CspVarInt<CspVarInt( _, X, XDom )> { plus<plus( Id1, X, Id2, Y, Id3, Z )>, eq<eq( Id1, X, Id2, Y )>, neq<neq( Id1, X, Id2, Y )>, CspVarInt<CspVarInt( Id2, Y, YDom )> } --> built-in<( ( *XDom ) . val(  ) )>

(constraint) CspVarIntDec( ( +int ), ( +string ), ( ?int ), ( -interval ) ), indexes: { <0> }
(constraint) CspVarInt( ( +int ), ( ?int ), ( -interval ) ), indexes: { <0,1> }
(constraint) CspTmpInt( ( +int ), ( ?int ), ( -interval ) )
(constraint) neq( ( +int ), ( ?int ), ( +int ), ( ?int ) ), indexes: { <0,1>, <2,3> }
(constraint) ##put_alldiff( ( ?list_var ), ( ?list_int ) )
(constraint) plus( ( +int ), ( ?int ), ( +int ), ( ?int ), ( +int ), ( ?int ) ), indexes: { <0,1>, <2,3>, <4,5> }
(constraint) eq( ( +int ), ( ?int ), ( +int ), ( ?int ) ), indexes: { <0,1>, <2,3> }
(constraint) ##put_usum( ( ?list_var ), ( ?list_int ), ( +int ) )
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
(rule) plus @ CspVarInt( Id1, X, XDom ), CspVarInt( Id2, Y, YDom ), CspVarInt( Id3, Z, ZDom ), plus( Id1, X, Id2, Y, Id3, Z ) =>> ( Solvint :: plus_boundConsistency( XDom, YDom, ZDom ) ) ;;
(rule) eq_var_var @ CspVarInt( Id1, X, XDom ), CspVarInt( Id2, Y, YDom ), eq( Id1, X, Id2, Y ) ==> XDom %= YDom ;;
(rule) put_usum( L, Ids, Target ) <=> ( ( *L ) . empty(  ) ) | ( Target == 0 ) ;;
(rule) put_usum( L, Ids, Target ) <=> sum_fun( ( *this ), ( *L ), ( *Ids ), Target ) ;;
(rule) CspVarIntDec( Id, _, _, Dom ) \ labelling( Id ) <=> ( __it_i = ( ( *Dom ) . begin(  ) ), __it_end_i = ( ( *Dom ) . end(  ) ), __local_success__3 = false, behavior( ( __local_success__3 || ( __it_i == __it_end_i ) ), __local_success__3 = true, ( ++__it_i ), __local_success__3, , , ( i = ( *__it_i ), set_eq( Dom, i ), labelling( ( Id + 1 ) ) )) ) ;;
(rule) labelling( Id ) <=> print_matrix( ( *this ) ) ;;
(occ rule) [+CspTmpInt( I, X, Dom )#0][] --> CspVarInt( I, X, Dom ) ;;
(occ rule) [+CspVarInt( _, _, Dom )#0][( ( *Dom ) . empty(  ) )] --> failure ;;
(occ rule) [+CspVarInt( _, X, XDom )#1][( ( *XDom ) . singleton(  ) )] --> X %= ( ( *XDom ) . val(  ) ) ;;
(occ rule) [+CspVarInt( _, Val, Dom )#2][( Val . ground(  ) )] --> maj_dom( Dom, ( *Val ) ) ;;
(occ rule) neq_var_var @ [+CspVarInt( Id1, X, XDom )#3][+neq( Id1, X, Id2, Y )<idx#0>, +CspVarInt( Id2, Y, YDom )<idx#0>] --> ( Solvint :: ne( XDom, YDom ) ) ;;
(occ rule) neq_var_var @ [+CspVarInt( Id2, Y, YDom )#4][+neq( Id1, X, Id2, Y )<idx#1>, +CspVarInt( Id1, X, XDom )<idx#0>] --> ( Solvint :: ne( XDom, YDom ) ) ;;
(occ rule) neq_cste_var @ [+CspVarInt( Id, Y, YDom )#5][+neq( _, X, Id, Y )<idx#1>, ( X . ground(  ) )] --> ( Solvint :: ne( YDom, ( *X ) ) ) ;;
(occ rule) neq_var_cste @ [+CspVarInt( Id, X, XDom )#6][+neq( Id, X, _, Y )<idx#0>, ( Y . ground(  ) )] --> ( Solvint :: ne( XDom, ( *Y ) ) ) ;;
(occ rule) plus @ [+CspVarInt( Id1, X, XDom )#7#no_history][+plus( Id1, X, Id2, Y, Id3, Z )<idx#0>#no_history, +CspVarInt( Id3, Z, ZDom )<idx#0>#no_history, +CspVarInt( Id2, Y, YDom )<idx#0>#no_history] --> ( Solvint :: plus_boundConsistency( XDom, YDom, ZDom ) ) ;;
(occ rule) plus @ [+CspVarInt( Id2, Y, YDom )#8#no_history][+plus( Id1, X, Id2, Y, Id3, Z )<idx#1>#no_history, +CspVarInt( Id3, Z, ZDom )<idx#0>#no_history, +CspVarInt( Id1, X, XDom )<idx#0>#no_history] --> ( Solvint :: plus_boundConsistency( XDom, YDom, ZDom ) ) ;;
(occ rule) plus @ [+CspVarInt( Id3, Z, ZDom )#9#no_history][+plus( Id1, X, Id2, Y, Id3, Z )<idx#2>#no_history, +CspVarInt( Id2, Y, YDom )<idx#0>#no_history, +CspVarInt( Id1, X, XDom )<idx#0>#no_history] --> ( Solvint :: plus_boundConsistency( XDom, YDom, ZDom ) ) ;;
(occ rule) eq_var_var @ [+CspVarInt( Id1, X, XDom )#10][+eq( Id1, X, Id2, Y )<idx#0>, +CspVarInt( Id2, Y, YDom )<idx#0>] --> XDom %= YDom ;;
(occ rule) eq_var_var @ [+CspVarInt( Id2, Y, YDom )#11][+eq( Id1, X, Id2, Y )<idx#1>, +CspVarInt( Id1, X, XDom )<idx#0>] --> XDom %= YDom ;;
(occ rule) [+CspVarIntDec( Id, _, X, Dom )#0][] --> CspVarInt( Id, X, Dom ) ;;
(occ rule) eq_var_var @ [+eq( Id1, X, Id2, Y )#0][+CspVarInt( Id1, X, XDom )<idx#0>, +CspVarInt( Id2, Y, YDom )<idx#0>] --> XDom %= YDom ;;
(occ rule) [-labelling( Id )#0][+CspVarIntDec( Id, _, _, Dom )<idx#0>] --> ( __it_i = ( ( *Dom ) . begin(  ) ), __it_end_i = ( ( *Dom ) . end(  ) ), __local_success__3 = false, behavior( ( __local_success__3 || ( __it_i == __it_end_i ) ), __local_success__3 = true, ( ++__it_i ), __local_success__3, , , ( i = ( *__it_i ), set_eq( Dom, i ), labelling( ( Id + 1 ) ) )) ) ;;
(occ rule) [-labelling( Id )#1][] --> print_matrix( ( *this ) ) ;;
(occ rule) neq_var_var @ [+neq( Id1, X, Id2, Y )#0][+CspVarInt( Id1, X, XDom )<idx#0>, +CspVarInt( Id2, Y, YDom )<idx#0>] --> ( Solvint :: ne( XDom, YDom ) ) ;;
(occ rule) neq_cste_var @ [+neq( _, X, Id, Y )#1][( X . ground(  ) ), +CspVarInt( Id, Y, YDom )<idx#0>] --> ( Solvint :: ne( YDom, ( *X ) ) ) ;;
(occ rule) neq_var_cste @ [+neq( Id, X, _, Y )#2][( Y . ground(  ) ), +CspVarInt( Id, X, XDom )<idx#0>] --> ( Solvint :: ne( XDom, ( *Y ) ) ) ;;
(occ rule) plus @ [+plus( Id1, X, Id2, Y, Id3, Z )#0#no_history][+CspVarInt( Id1, X, XDom )<idx#0>#no_history, +CspVarInt( Id2, Y, YDom )<idx#0>#no_history, +CspVarInt( Id3, Z, ZDom )<idx#0>#no_history] --> ( Solvint :: plus_boundConsistency( XDom, YDom, ZDom ) ) ;;
(occ rule) [-put_alldiff( L, Ids )#0][( ( *L ) . empty(  ) )] --> success ;;
(occ rule) [-put_alldiff( L, Ids )#1][] --> alldiff_fun( ( *this ), ( *L ), ( *Ids ) ) ;;
(occ rule) [-put_usum( L, Ids, Target )#0][( ( *L ) . empty(  ) )] --> ( Target == 0 ) ;;
(occ rule) [-put_usum( L, Ids, Target )#1][] --> sum_fun( ( *this ), ( *L ), ( *Ids ), Target ) ;;

(constraint store) CspVarIntDec( ( +int ), ( +string ), ( ?int ), ( -interval ) ), indexes: { <0> }
(constraint store) CspVarInt( ( +int ), ( ?int ), ( -interval ) ), indexes: { <0,1> }
(constraint store) CspTmpInt( ( +int ), ( ?int ), ( -interval ) )
(constraint store) neq( ( +int ), ( ?int ), ( +int ), ( ?int ) ), indexes: { <0,1>, <2,3> }
(constraint store) put_alldiff( ( ?list_var ), ( ?list_int ) )
(constraint store) plus( ( +int ), ( ?int ), ( +int ), ( ?int ), ( +int ), ( ?int ) ), indexes: { <0,1>, <2,3>, <4,5> }
(constraint store) eq( ( +int ), ( ?int ), ( +int ), ( ?int ) ), indexes: { <0,1>, <2,3> }
(constraint store) put_usum( ( ?list_var ), ( ?list_int ), ( +int ) )
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
// Rule plus, active constraint CspVarInt( Id1, X, XDom ), occurrence 7
Begin CspVarInt_7
If empty store plus( Id1, X, Id2, Y, Id3, Z ) Then goto CspVarInt_8
If empty store CspVarInt( Id3, Z, ZDom ) Then goto CspVarInt_8
If empty store CspVarInt( Id2, Y, YDom ) Then goto CspVarInt_8
	Matching partner plus( Id1, X, Id2, Y, Id3, Z ) with idx#0<Id1,X>
		Matching partner CspVarInt( Id3, Z, ZDom ) with idx#0<Id3,Z>
			If guard
				( CspVarInt( Id3, Z, ZDom ) != CspVarInt( Id1, X, XDom ) )
			Then guard
				Matching partner CspVarInt( Id2, Y, YDom ) with idx#0<Id2,Y>
					If guard
						( CspVarInt( Id2, Y, YDom ) != CspVarInt( Id3, Z, ZDom ) )
						&& ( CspVarInt( Id2, Y, YDom ) != CspVarInt( Id1, X, XDom ) )
					Then guard
						store constraint CspVarInt( Id1, X, XDom )
						( Solvint :: plus_boundConsistency( XDom, YDom, ZDom ) )
						If not alived CspVarInt( Id1, X, XDom ) Then goto next goal constraint
						If not alived plus( Id1, X, Id2, Y, Id3, Z ) Then goto next matching of plus( Id1, X, Id2, Y, Id3, Z )
						If not alived CspVarInt( Id3, Z, ZDom ) Then goto next matching of CspVarInt( Id3, Z, ZDom )
						goto next matching of CspVarInt( Id2, Y, YDom )
					End guard
				End matching partner CspVarInt( Id2, Y, YDom )
			End guard
		End matching partner CspVarInt( Id3, Z, ZDom )
	End matching partner plus( Id1, X, Id2, Y, Id3, Z )
End
// Rule plus, active constraint CspVarInt( Id2, Y, YDom ), occurrence 8
Begin CspVarInt_8
If empty store plus( Id1, X, Id2, Y, Id3, Z ) Then goto CspVarInt_9
If empty store CspVarInt( Id3, Z, ZDom ) Then goto CspVarInt_9
If empty store CspVarInt( Id1, X, XDom ) Then goto CspVarInt_9
	Matching partner plus( Id1, X, Id2, Y, Id3, Z ) with idx#1<Id2,Y>
		Matching partner CspVarInt( Id3, Z, ZDom ) with idx#0<Id3,Z>
			If guard
				( CspVarInt( Id3, Z, ZDom ) != CspVarInt( Id2, Y, YDom ) )
			Then guard
				Matching partner CspVarInt( Id1, X, XDom ) with idx#0<Id1,X>
					If guard
						( CspVarInt( Id1, X, XDom ) != CspVarInt( Id3, Z, ZDom ) )
						&& ( CspVarInt( Id1, X, XDom ) != CspVarInt( Id2, Y, YDom ) )
					Then guard
						store constraint CspVarInt( Id2, Y, YDom )
						( Solvint :: plus_boundConsistency( XDom, YDom, ZDom ) )
						If not alived CspVarInt( Id2, Y, YDom ) Then goto next goal constraint
						If not alived plus( Id1, X, Id2, Y, Id3, Z ) Then goto next matching of plus( Id1, X, Id2, Y, Id3, Z )
						If not alived CspVarInt( Id3, Z, ZDom ) Then goto next matching of CspVarInt( Id3, Z, ZDom )
						goto next matching of CspVarInt( Id1, X, XDom )
					End guard
				End matching partner CspVarInt( Id1, X, XDom )
			End guard
		End matching partner CspVarInt( Id3, Z, ZDom )
	End matching partner plus( Id1, X, Id2, Y, Id3, Z )
End
// Rule plus, active constraint CspVarInt( Id3, Z, ZDom ), occurrence 9
Begin CspVarInt_9
If empty store plus( Id1, X, Id2, Y, Id3, Z ) Then goto CspVarInt_10
If empty store CspVarInt( Id2, Y, YDom ) Then goto CspVarInt_10
If empty store CspVarInt( Id1, X, XDom ) Then goto CspVarInt_10
	Matching partner plus( Id1, X, Id2, Y, Id3, Z ) with idx#2<Id3,Z>
		Matching partner CspVarInt( Id2, Y, YDom ) with idx#0<Id2,Y>
			If guard
				( CspVarInt( Id2, Y, YDom ) != CspVarInt( Id3, Z, ZDom ) )
			Then guard
				Matching partner CspVarInt( Id1, X, XDom ) with idx#0<Id1,X>
					If guard
						( CspVarInt( Id1, X, XDom ) != CspVarInt( Id2, Y, YDom ) )
						&& ( CspVarInt( Id1, X, XDom ) != CspVarInt( Id3, Z, ZDom ) )
					Then guard
						store constraint CspVarInt( Id3, Z, ZDom )
						( Solvint :: plus_boundConsistency( XDom, YDom, ZDom ) )
						If not alived CspVarInt( Id3, Z, ZDom ) Then goto next goal constraint
						If not alived plus( Id1, X, Id2, Y, Id3, Z ) Then goto next matching of plus( Id1, X, Id2, Y, Id3, Z )
						If not alived CspVarInt( Id2, Y, YDom ) Then goto next matching of CspVarInt( Id2, Y, YDom )
						goto next matching of CspVarInt( Id1, X, XDom )
					End guard
				End matching partner CspVarInt( Id1, X, XDom )
			End guard
		End matching partner CspVarInt( Id2, Y, YDom )
	End matching partner plus( Id1, X, Id2, Y, Id3, Z )
End
// Rule eq_var_var, active constraint CspVarInt( Id1, X, XDom ), occurrence 10
Begin CspVarInt_10
If empty store eq( Id1, X, Id2, Y ) Then goto CspVarInt_11
If empty store CspVarInt( Id2, Y, YDom ) Then goto CspVarInt_11
	Matching partner eq( Id1, X, Id2, Y ) with idx#0<Id1,X>
		Matching partner CspVarInt( Id2, Y, YDom ) with idx#0<Id2,Y>
			If guard
				( CspVarInt( Id2, Y, YDom ) != CspVarInt( Id1, X, XDom ) )
			Then guard
				If history <CspVarInt( Id1, X, XDom ),eq( Id1, X, Id2, Y ),CspVarInt( Id2, Y, YDom )> Then
					store constraint CspVarInt( Id1, X, XDom )
					XDom %= YDom
					If not alived CspVarInt( Id1, X, XDom ) Then goto next goal constraint
					If not alived eq( Id1, X, Id2, Y ) Then goto next matching of eq( Id1, X, Id2, Y )
					goto next matching of CspVarInt( Id2, Y, YDom )
				End history
			End guard
		End matching partner CspVarInt( Id2, Y, YDom )
	End matching partner eq( Id1, X, Id2, Y )
End
// Rule eq_var_var, active constraint CspVarInt( Id2, Y, YDom ), occurrence 11
Begin CspVarInt_11
If empty store eq( Id1, X, Id2, Y ) Then goto CspVarInt_store
If empty store CspVarInt( Id1, X, XDom ) Then goto CspVarInt_store
	Matching partner eq( Id1, X, Id2, Y ) with idx#1<Id2,Y>
		Matching partner CspVarInt( Id1, X, XDom ) with idx#0<Id1,X>
			If guard
				( CspVarInt( Id1, X, XDom ) != CspVarInt( Id2, Y, YDom ) )
			Then guard
				If history <CspVarInt( Id2, Y, YDom ),eq( Id1, X, Id2, Y ),CspVarInt( Id1, X, XDom )> Then
					store constraint CspVarInt( Id2, Y, YDom )
					XDom %= YDom
					If not alived CspVarInt( Id2, Y, YDom ) Then goto next goal constraint
					If not alived eq( Id1, X, Id2, Y ) Then goto next matching of eq( Id1, X, Id2, Y )
					goto next matching of CspVarInt( Id1, X, XDom )
				End history
			End guard
		End matching partner CspVarInt( Id1, X, XDom )
	End matching partner eq( Id1, X, Id2, Y )
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
// Rule eq_var_var, active constraint eq( Id1, X, Id2, Y ), occurrence 0
Begin eq_0
If empty store CspVarInt( Id1, X, XDom ) Then goto eq_store
If empty store CspVarInt( Id2, Y, YDom ) Then goto eq_store
	Matching partner CspVarInt( Id1, X, XDom ) with idx#0<Id1,X>
		Matching partner CspVarInt( Id2, Y, YDom ) with idx#0<Id2,Y>
			If guard
				( CspVarInt( Id2, Y, YDom ) != CspVarInt( Id1, X, XDom ) )
			Then guard
				If history <eq( Id1, X, Id2, Y ),CspVarInt( Id1, X, XDom ),CspVarInt( Id2, Y, YDom )> Then
					store constraint eq( Id1, X, Id2, Y )
					XDom %= YDom
					If not alived eq( Id1, X, Id2, Y ) Then goto next goal constraint
					If not alived CspVarInt( Id1, X, XDom ) Then goto next matching of CspVarInt( Id1, X, XDom )
					goto next matching of CspVarInt( Id2, Y, YDom )
				End history
			End guard
		End matching partner CspVarInt( Id2, Y, YDom )
	End matching partner CspVarInt( Id1, X, XDom )
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
	print_matrix( ( *this ) )
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
// Rule plus, active constraint plus( Id1, X, Id2, Y, Id3, Z ), occurrence 0
Begin plus_0
If empty store CspVarInt( Id1, X, XDom ) Then goto plus_store
If empty store CspVarInt( Id2, Y, YDom ) Then goto plus_store
If empty store CspVarInt( Id3, Z, ZDom ) Then goto plus_store
	Matching partner CspVarInt( Id1, X, XDom ) with idx#0<Id1,X>
		Matching partner CspVarInt( Id2, Y, YDom ) with idx#0<Id2,Y>
			If guard
				( CspVarInt( Id2, Y, YDom ) != CspVarInt( Id1, X, XDom ) )
			Then guard
				Matching partner CspVarInt( Id3, Z, ZDom ) with idx#0<Id3,Z>
					If guard
						( CspVarInt( Id3, Z, ZDom ) != CspVarInt( Id2, Y, YDom ) )
						&& ( CspVarInt( Id3, Z, ZDom ) != CspVarInt( Id1, X, XDom ) )
					Then guard
						store constraint plus( Id1, X, Id2, Y, Id3, Z )
						( Solvint :: plus_boundConsistency( XDom, YDom, ZDom ) )
						If not alived plus( Id1, X, Id2, Y, Id3, Z ) Then goto next goal constraint
						If not alived CspVarInt( Id1, X, XDom ) Then goto next matching of CspVarInt( Id1, X, XDom )
						If not alived CspVarInt( Id2, Y, YDom ) Then goto next matching of CspVarInt( Id2, Y, YDom )
						goto next matching of CspVarInt( Id3, Z, ZDom )
					End guard
				End matching partner CspVarInt( Id3, Z, ZDom )
			End guard
		End matching partner CspVarInt( Id2, Y, YDom )
	End matching partner CspVarInt( Id1, X, XDom )
End
// Fail through
Begin plus_store
	Store constraint plus
	Schedule constraint plus with variable index 1
	Schedule constraint plus with variable index 3
	Schedule constraint plus with variable index 5
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
// Rule NO_NAME, active constraint put_usum( L, Ids, Target ), occurrence 0
Begin put_usum_0
	If guard
		( ( *L ) . empty(  ) )
	Then guard
		remove constraint put_usum( L, Ids, Target )
		( Target == 0 )
		goto next goal constraint
	End guard
End
// Rule NO_NAME, active constraint put_usum( L, Ids, Target ), occurrence 1
Begin put_usum_1
	remove constraint put_usum( L, Ids, Target )
	sum_fun( ( *this ), ( *L ), ( *Ids ), Target )
	goto next goal constraint
End
// Fail through
Begin put_usum_store
	Store constraint put_usum
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
int global_id = 16;
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

#include <cmath>
#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <tuple>
#include <iomanip>

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
        std::cout << "Aucune variable CspVarIntDec trouvée.\n";
        return;
    }

    // Calcul de la dimension d
    int d = std::sqrt(count);
    if (d * d != count) {
        std::cerr << "Erreur : le nombre de variables (" << count << ") n'est pas un carré parfait.\n";
        return;
    }

    // Initialisation de la grille
    std::vector<std::vector<int>> grid(d, std::vector<int>(d, 0));
    for (const auto& [i, j, val] : assignments) {
        if (i >= 0 && i < d && j >= 0 && j < d)
            grid[i][j] = val;
    }

    // Affichage uniforme de la grille
    std::cout << "\n======= Matrice " << d << "x" << d << " =======\n";
    for (int i = 0; i < d; ++i) {
        for (int j = 0; j < d; ++j) {
            std::cout << std::setw(4) << (grid[i][j] ? std::to_string(grid[i][j]) : ".");
        }
        std::cout << "\n";
    }
    std::cout << "=============================\n";
}

template<class T>
bool sum_fun(T& space, const list_var& vars, const list_int& ids, int target) {
    if (vars.size() < 2 || vars.size() != ids.size()) return false;

    auto it = vars.begin();
    auto id_it = ids.begin();

    auto prev = *it++;
    int id_prev = *id_it++;

    for (; it != vars.end(); ++it, ++id_it) {
        int tmp_id = global_id++;
        Logical_var<int> tmpVar;
        Logical_var_mutable<interval> tmpDom = interval(0, 1000);

        CHECK_ES(space.CspTmpInt(
            Logical_var_ground<int>(tmp_id), tmpVar, tmpDom));

        CHECK_ES(space.plus(
            Logical_var_ground<int>(id_prev), prev,
            Logical_var_ground<int>(*id_it), *it,
            Logical_var_ground<int>(tmp_id), tmpVar));

        prev = tmpVar;
        id_prev = tmp_id;
    }

    int final_id = global_id++;
    Logical_var<int> finalVar;
    Logical_var_mutable<interval> finalDom = interval(target, target);

    CHECK_ES(space.CspTmpInt(
        Logical_var_ground<int>(final_id), finalVar, finalDom));

    CHECK_ES(space.eq(
        Logical_var_ground<int>(id_prev), prev,
        Logical_var_ground<int>(final_id), finalVar));

    CHECK_ES(set_eq(finalDom, target));

    return true;
}


template <typename T>
void print_magic_square_grid(T& pb) {
    int grid[4][4] = {0};  

    auto it = pb.chr_store_begin();
    std::regex re(R"(x\[(\d+)\]\[(\d+)\],\s*(\d+),)");

    while (!it.at_end()) {
        std::string fact = it.to_string();

        if (fact.find("CspVarIntDec") == std::string::npos) {
            ++it;
            continue;
        }

        std::smatch match;
        if (std::regex_search(fact, match, re)) {
            int i = std::stoi(match[1].str());
            int j = std::stoi(match[2].str());
            int val = std::stoi(match[3].str());
            if (i >= 0 && i < 4 && j >= 0 && j < 4) {
                grid[i][j] = val;
            }
        }

        ++it;
    }

    std::cout << "\n======================\n";
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << (grid[i][j] < 17 ? "  " : " ") << grid[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << "======================\n";
}


template <typename T>
void print_sudoku_grid(T& pb) {
    int grid[9][9] = {0};
    auto it = pb.chr_store_begin();
    std::regex re(R"(x\[(\d+)\]\[(\d+)\],\s*(\d+),)");
    while (!it.at_end()) {
        std::string fact = it.to_string();
        if (fact.find("CspVarIntDec") == std::string::npos) { ++it; continue; }
        std::smatch match;
        if (std::regex_search(fact, match, re)) {
            int i = std::stoi(match[1].str());
            int j = std::stoi(match[2].str());
            int val = std::stoi(match[3].str());
            if (i >= 0 && i < 9 && j >= 0 && j < 9) grid[i][j] = val;
        }
        ++it;
    }
    for (int i = 0; i < 9; ++i) {
        if (i % 3 == 0) std::cout << "-------------------------\n";
        for (int j = 0; j < 9; ++j) {
            if (j % 3 == 0) std::cout << "| ";
            std::cout << (grid[i][j] ? std::to_string(grid[i][j]) : ".") << ' ';
        }
        std::cout << "|\n";
    }
    std::cout << "-------------------------\n";
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
class MagicSquare_04 {
	unsigned long int next_free_constraint_id = 1;
	//(constraint store) CspVarIntDec( ( +int ), ( +string ), ( ?int ), ( -interval ) ), indexes: { <0> }
public:
	struct CspVarIntDec {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var_ground< int >, chr::Logical_var_ground< string >, chr::Logical_var< int >, chr::Logical_var_mutable< interval > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0> >, true >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(MagicSquare_04* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
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
			chr::Weak_obj< MagicSquare_04 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename CspVarIntDec::Constraint_store_t > CspVarIntDec_constraint_store{ chr::make_shared< typename CspVarIntDec::Constraint_store_t >("CspVarIntDec") };
	//(constraint store) CspVarInt( ( +int ), ( ?int ), ( -interval ) ), indexes: { <0,1> }
public:
	struct CspVarInt {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var_ground< int >, chr::Logical_var< int >, chr::Logical_var_mutable< interval > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,1> >, true >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(MagicSquare_04* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
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
			chr::Weak_obj< MagicSquare_04 > _space;
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
			Constraint_callback(MagicSquare_04* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
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
			chr::Weak_obj< MagicSquare_04 > _space;
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
			Constraint_callback(MagicSquare_04* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
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
			chr::Weak_obj< MagicSquare_04 > _space;
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
	//(constraint store) plus( ( +int ), ( ?int ), ( +int ), ( ?int ), ( +int ), ( ?int ) ), indexes: { <0,1>, <2,3>, <4,5> }
public:
	struct plus {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var_ground< int >, chr::Logical_var< int >, chr::Logical_var_ground< int >, chr::Logical_var< int >, chr::Logical_var_ground< int >, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,1>, chr::LNS::Index<2,3>, chr::LNS::Index<4,5> >, true >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(MagicSquare_04* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->plus_constraint_store && _space->plus_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_plus(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< MagicSquare_04 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename plus::Constraint_store_t > plus_constraint_store{ chr::make_shared< typename plus::Constraint_store_t >("plus") };
	//(constraint store) eq( ( +int ), ( ?int ), ( +int ), ( ?int ) ), indexes: { <0,1>, <2,3> }
public:
	struct eq {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var_ground< int >, chr::Logical_var< int >, chr::Logical_var_ground< int >, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,1>, chr::LNS::Index<2,3> >, true >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(MagicSquare_04* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
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
			chr::Weak_obj< MagicSquare_04 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename eq::Constraint_store_t > eq_constraint_store{ chr::make_shared< typename eq::Constraint_store_t >("eq") };
	//(constraint store) put_usum( ( ?list_var ), ( ?list_int ), ( +int ) )
public:
	struct put_usum {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< list_var >, chr::Logical_var< list_int >, chr::Logical_var_ground< int > >;
	};
	//(constraint store) labelling( ( +int ) ), indexes: { <0> }
public:
	struct labelling {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var_ground< int > >;
	};
public:
	unsigned int _ref_use_count  = 0;///< Count of shared references
	unsigned int _ref_weak_count = 0;///< Count of weak references + (#shared != 0)
	MagicSquare_04() { }
	~MagicSquare_04() {
		CspVarIntDec_constraint_store.release();
		CspVarInt_constraint_store.release();
		CspTmpInt_constraint_store.release();
		neq_constraint_store.release();
		plus_constraint_store.release();
		eq_constraint_store.release();
	}
	static chr::Shared_obj<MagicSquare_04> create() { return chr::make_shared<MagicSquare_04>(); }
	chr::Constraint_stores_iterator<chr::Shared_obj<typename CspVarIntDec::Constraint_store_t>,chr::Shared_obj<typename CspVarInt::Constraint_store_t>,chr::Shared_obj<typename CspTmpInt::Constraint_store_t>,chr::Shared_obj<typename neq::Constraint_store_t>,chr::Shared_obj<typename plus::Constraint_store_t>,chr::Shared_obj<typename eq::Constraint_store_t>> chr_store_begin() { return chr::Constraint_stores_iterator(CspVarIntDec_constraint_store,CspVarInt_constraint_store,CspTmpInt_constraint_store,neq_constraint_store,plus_constraint_store,eq_constraint_store); }
	typename CspVarIntDec::Constraint_store_t& get_CspVarIntDec_store() { return *CspVarIntDec_constraint_store; }
	typename CspVarInt::Constraint_store_t& get_CspVarInt_store() { return *CspVarInt_constraint_store; }
	typename CspTmpInt::Constraint_store_t& get_CspTmpInt_store() { return *CspTmpInt_constraint_store; }
	typename neq::Constraint_store_t& get_neq_store() { return *neq_constraint_store; }
	typename plus::Constraint_store_t& get_plus_store() { return *plus_constraint_store; }
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
	chr::ES_CHR do_plus(typename plus::Type c_args, typename plus::Constraint_store_t::iterator c_it);
	chr::ES_CHR plus( chr::Logical_var_ground< int > arg0, chr::Logical_var< int > arg1, chr::Logical_var_ground< int > arg2, chr::Logical_var< int > arg3, chr::Logical_var_ground< int > arg4, chr::Logical_var< int > arg5) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1, arg2, arg3, arg4, arg5);
		return do_plus(std::move(c_args), plus_constraint_store->end());
	}
	chr::ES_CHR do_eq(typename eq::Type c_args, typename eq::Constraint_store_t::iterator c_it);
	chr::ES_CHR eq( chr::Logical_var_ground< int > arg0, chr::Logical_var< int > arg1, chr::Logical_var_ground< int > arg2, chr::Logical_var< int > arg3) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1, arg2, arg3);
		return do_eq(std::move(c_args), eq_constraint_store->end());
	}
	chr::ES_CHR do_put_usum(typename put_usum::Type c_args);
	chr::ES_CHR put_usum( chr::Logical_var< list_var > arg0, chr::Logical_var< list_int > arg1, chr::Logical_var_ground< int > arg2) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1, arg2);
		return do_put_usum(std::move(c_args));
	}
	chr::ES_CHR do_labelling(typename labelling::Type c_args);
	chr::ES_CHR labelling( chr::Logical_var_ground< int > arg0) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0);
		return do_labelling(std::move(c_args));
	}
};
chr::ES_CHR MagicSquare_04::do_CspTmpInt(typename CspTmpInt::Type c_args, typename CspTmpInt::Constraint_store_t::iterator c_it) {
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
chr::ES_CHR MagicSquare_04::do_CspVarInt(typename CspVarInt::Type c_args, typename CspVarInt::Constraint_store_t::iterator c_it) {
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
	// CspVarInt_7 <=> Rule plus, active constraint CspVarInt( Id1, X, XDom ), occurrence 8
	[[maybe_unused]] CspVarInt_7:
	{
		if (plus_constraint_store->empty()) goto CspVarInt_8;
		if (CspVarInt_constraint_store->empty()) goto CspVarInt_8;
		if (CspVarInt_constraint_store->empty()) goto CspVarInt_8;
		auto& Id1 = std::get<1>(c_args);
		auto& X = std::get<2>(c_args);
		auto& XDom = std::get<3>(c_args);
		auto it7_0 = plus_constraint_store->template begin<0>(Id1,X);
		while ( !it7_0.at_end() ) {
			auto Id2(std::get<3>(*it7_0));
			auto Y(std::get<4>(*it7_0));
			auto Id3(std::get<5>(*it7_0));
			auto Z(std::get<6>(*it7_0));
			auto it7_1 = CspVarInt_constraint_store->template begin<0>(Id3,Z);
			while ( !it7_1.at_end() ) {
				auto ZDom(std::get<3>(*it7_1));
				// Begin guard
				if (
					( std::get<0>(*it7_1) != std::get<0>(c_args) )
				) {
					auto it7_2 = CspVarInt_constraint_store->template begin<0>(Id2,Y);
					while ( !it7_2.at_end() ) {
						auto YDom(std::get<3>(*it7_2));
						// Begin guard
						if (
							( std::get<0>(*it7_2) != std::get<0>(c_args) )
							&& ( std::get<0>(*it7_2) != std::get<0>(*it7_1) )
						) {
							it7_0.lock();
							it7_1.lock();
							it7_2.lock();
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
							CHECK_ES( ( Solvint :: plus_boundConsistency( XDom, YDom, ZDom ) ) );
							assert(c_stored_before);
							if (!c_it.alive()) {
								c_it.unlock();
								it7_0.unlock();
								it7_1.unlock();
								it7_2.unlock();
								return chr::ES_CHR::SUCCESS;
							}
							c_it.unlock();
							if (!it7_0.alive()) {
								it7_1.unlock();
								it7_2.unlock();
								it7_0.next_and_unlock();
								goto it7_0_next;
							}
							it7_0.unlock();
							if (!it7_1.alive()) {
								it7_2.unlock();
								it7_1.next_and_unlock();
								goto it7_1_next;
							}
							it7_1.unlock();
							it7_2.next_and_unlock();
							goto it7_2_next;
						} // End guard
						++it7_2;
						it7_2_next:;
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
	// CspVarInt_8 <=> Rule plus, active constraint CspVarInt( Id2, Y, YDom ), occurrence 9
	[[maybe_unused]] CspVarInt_8:
	{
		if (plus_constraint_store->empty()) goto CspVarInt_9;
		if (CspVarInt_constraint_store->empty()) goto CspVarInt_9;
		if (CspVarInt_constraint_store->empty()) goto CspVarInt_9;
		auto& Id2 = std::get<1>(c_args);
		auto& Y = std::get<2>(c_args);
		auto& YDom = std::get<3>(c_args);
		auto it8_0 = plus_constraint_store->template begin<1>(Id2,Y);
		while ( !it8_0.at_end() ) {
			auto Id1(std::get<1>(*it8_0));
			auto X(std::get<2>(*it8_0));
			auto Id3(std::get<5>(*it8_0));
			auto Z(std::get<6>(*it8_0));
			auto it8_1 = CspVarInt_constraint_store->template begin<0>(Id3,Z);
			while ( !it8_1.at_end() ) {
				auto ZDom(std::get<3>(*it8_1));
				// Begin guard
				if (
					( std::get<0>(*it8_1) != std::get<0>(c_args) )
				) {
					auto it8_2 = CspVarInt_constraint_store->template begin<0>(Id1,X);
					while ( !it8_2.at_end() ) {
						auto XDom(std::get<3>(*it8_2));
						// Begin guard
						if (
							( std::get<0>(*it8_2) != std::get<0>(c_args) )
							&& ( std::get<0>(*it8_2) != std::get<0>(*it8_1) )
						) {
							it8_0.lock();
							it8_1.lock();
							it8_2.lock();
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
							CHECK_ES( ( Solvint :: plus_boundConsistency( XDom, YDom, ZDom ) ) );
							assert(c_stored_before);
							if (!c_it.alive()) {
								c_it.unlock();
								it8_0.unlock();
								it8_1.unlock();
								it8_2.unlock();
								return chr::ES_CHR::SUCCESS;
							}
							c_it.unlock();
							if (!it8_0.alive()) {
								it8_1.unlock();
								it8_2.unlock();
								it8_0.next_and_unlock();
								goto it8_0_next;
							}
							it8_0.unlock();
							if (!it8_1.alive()) {
								it8_2.unlock();
								it8_1.next_and_unlock();
								goto it8_1_next;
							}
							it8_1.unlock();
							it8_2.next_and_unlock();
							goto it8_2_next;
						} // End guard
						++it8_2;
						it8_2_next:;
					}
				} // End guard
				++it8_1;
				it8_1_next:;
			}
			++it8_0;
			it8_0_next:;
		}
	}
	// ***************************************************
	// CspVarInt_9 <=> Rule plus, active constraint CspVarInt( Id3, Z, ZDom ), occurrence 10
	[[maybe_unused]] CspVarInt_9:
	{
		if (plus_constraint_store->empty()) goto CspVarInt_10;
		if (CspVarInt_constraint_store->empty()) goto CspVarInt_10;
		if (CspVarInt_constraint_store->empty()) goto CspVarInt_10;
		auto& Id3 = std::get<1>(c_args);
		auto& Z = std::get<2>(c_args);
		auto& ZDom = std::get<3>(c_args);
		auto it9_0 = plus_constraint_store->template begin<2>(Id3,Z);
		while ( !it9_0.at_end() ) {
			auto Id1(std::get<1>(*it9_0));
			auto X(std::get<2>(*it9_0));
			auto Id2(std::get<3>(*it9_0));
			auto Y(std::get<4>(*it9_0));
			auto it9_1 = CspVarInt_constraint_store->template begin<0>(Id2,Y);
			while ( !it9_1.at_end() ) {
				auto YDom(std::get<3>(*it9_1));
				// Begin guard
				if (
					( std::get<0>(*it9_1) != std::get<0>(c_args) )
				) {
					auto it9_2 = CspVarInt_constraint_store->template begin<0>(Id1,X);
					while ( !it9_2.at_end() ) {
						auto XDom(std::get<3>(*it9_2));
						// Begin guard
						if (
							( std::get<0>(*it9_2) != std::get<0>(c_args) )
							&& ( std::get<0>(*it9_2) != std::get<0>(*it9_1) )
						) {
							it9_0.lock();
							it9_1.lock();
							it9_2.lock();
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
							CHECK_ES( ( Solvint :: plus_boundConsistency( XDom, YDom, ZDom ) ) );
							assert(c_stored_before);
							if (!c_it.alive()) {
								c_it.unlock();
								it9_0.unlock();
								it9_1.unlock();
								it9_2.unlock();
								return chr::ES_CHR::SUCCESS;
							}
							c_it.unlock();
							if (!it9_0.alive()) {
								it9_1.unlock();
								it9_2.unlock();
								it9_0.next_and_unlock();
								goto it9_0_next;
							}
							it9_0.unlock();
							if (!it9_1.alive()) {
								it9_2.unlock();
								it9_1.next_and_unlock();
								goto it9_1_next;
							}
							it9_1.unlock();
							it9_2.next_and_unlock();
							goto it9_2_next;
						} // End guard
						++it9_2;
						it9_2_next:;
					}
				} // End guard
				++it9_1;
				it9_1_next:;
			}
			++it9_0;
			it9_0_next:;
		}
	}
	// ***************************************************
	// CspVarInt_10 <=> Rule eq_var_var, active constraint CspVarInt( Id1, X, XDom ), occurrence 11
	[[maybe_unused]] CspVarInt_10:
	{
		if (eq_constraint_store->empty()) goto CspVarInt_11;
		if (CspVarInt_constraint_store->empty()) goto CspVarInt_11;
		auto& Id1 = std::get<1>(c_args);
		auto& X = std::get<2>(c_args);
		auto& XDom = std::get<3>(c_args);
		auto it10_0 = eq_constraint_store->template begin<0>(Id1,X);
		while ( !it10_0.at_end() ) {
			auto Id2(std::get<3>(*it10_0));
			auto Y(std::get<4>(*it10_0));
			auto it10_1 = CspVarInt_constraint_store->template begin<0>(Id2,Y);
			while ( !it10_1.at_end() ) {
				auto YDom(std::get<3>(*it10_1));
				// Begin guard
				if (
					( std::get<0>(*it10_1) != std::get<0>(c_args) )
				) {
					// Check history
					if (_history.rule_11->check( {{std::get<0>(c_args),std::get<0>(*it10_0),std::get<0>(*it10_1)}} )) {
						it10_0.lock();
						it10_1.lock();
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
							it10_0.unlock();
							it10_1.unlock();
							return chr::ES_CHR::SUCCESS;
						}
						c_it.unlock();
						if (!it10_0.alive()) {
							it10_1.unlock();
							it10_0.next_and_unlock();
							goto it10_0_next;
						}
						it10_0.unlock();
						it10_1.next_and_unlock();
						goto it10_1_next;
					} // End history
					else {
						++it10_1;
						goto it10_1_next;
					}
				} // End guard
				++it10_1;
				it10_1_next:;
			}
			++it10_0;
			it10_0_next:;
		}
	}
	// ***************************************************
	// CspVarInt_11 <=> Rule eq_var_var, active constraint CspVarInt( Id2, Y, YDom ), occurrence 12
	[[maybe_unused]] CspVarInt_11:
	{
		if (eq_constraint_store->empty()) goto CspVarInt_store;
		if (CspVarInt_constraint_store->empty()) goto CspVarInt_store;
		auto& Id2 = std::get<1>(c_args);
		auto& Y = std::get<2>(c_args);
		auto& YDom = std::get<3>(c_args);
		auto it11_0 = eq_constraint_store->template begin<1>(Id2,Y);
		while ( !it11_0.at_end() ) {
			auto Id1(std::get<1>(*it11_0));
			auto X(std::get<2>(*it11_0));
			auto it11_1 = CspVarInt_constraint_store->template begin<0>(Id1,X);
			while ( !it11_1.at_end() ) {
				auto XDom(std::get<3>(*it11_1));
				// Begin guard
				if (
					( std::get<0>(*it11_1) != std::get<0>(c_args) )
				) {
					// Check history
					if (_history.rule_11->check( {{std::get<0>(c_args),std::get<0>(*it11_0),std::get<0>(*it11_1)}} )) {
						it11_0.lock();
						it11_1.lock();
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
							it11_0.unlock();
							it11_1.unlock();
							return chr::ES_CHR::SUCCESS;
						}
						c_it.unlock();
						if (!it11_0.alive()) {
							it11_1.unlock();
							it11_0.next_and_unlock();
							goto it11_0_next;
						}
						it11_0.unlock();
						it11_1.next_and_unlock();
						goto it11_1_next;
					} // End history
					else {
						++it11_1;
						goto it11_1_next;
					}
				} // End guard
				++it11_1;
				it11_1_next:;
			}
			++it11_0;
			it11_0_next:;
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
chr::ES_CHR MagicSquare_04::do_CspVarIntDec(typename CspVarIntDec::Type c_args, typename CspVarIntDec::Constraint_store_t::iterator c_it) {
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
chr::ES_CHR MagicSquare_04::do_eq(typename eq::Type c_args, typename eq::Constraint_store_t::iterator c_it) {
	bool c_stored_before = !c_it.at_end();
	chr::Statistics::update_call_stack();
	[[maybe_unused]] eq_call:
	// ***************************************************
	// eq_0 <=> Rule eq_var_var, active constraint eq( Id1, X, Id2, Y ), occurrence 1
	[[maybe_unused]] eq_0:
	{
		if (CspVarInt_constraint_store->empty()) goto eq_store;
		if (CspVarInt_constraint_store->empty()) goto eq_store;
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
					if (_history.rule_11->check( {{std::get<0>(c_args),std::get<0>(*it0_0),std::get<0>(*it0_1)}} )) {
						it0_0.lock();
						it0_1.lock();
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
chr::ES_CHR MagicSquare_04::do_labelling(typename labelling::Type c_args) {
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
		CHECK_ES( print_matrix( (*this ) ) );
		return chr::ES_CHR::SUCCESS;
	}
	// Store constraint
	[[maybe_unused]] labelling_store:
	return chr::ES_CHR::SUCCESS;
}
chr::ES_CHR MagicSquare_04::do_neq(typename neq::Type c_args, typename neq::Constraint_store_t::iterator c_it) {
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
chr::ES_CHR MagicSquare_04::do_plus(typename plus::Type c_args, typename plus::Constraint_store_t::iterator c_it) {
	bool c_stored_before = !c_it.at_end();
	chr::Statistics::update_call_stack();
	[[maybe_unused]] plus_call:
	// ***************************************************
	// plus_0 <=> Rule plus, active constraint plus( Id1, X, Id2, Y, Id3, Z ), occurrence 1
	[[maybe_unused]] plus_0:
	{
		if (CspVarInt_constraint_store->empty()) goto plus_store;
		if (CspVarInt_constraint_store->empty()) goto plus_store;
		if (CspVarInt_constraint_store->empty()) goto plus_store;
		auto& Id1 = std::get<1>(c_args);
		auto& X = std::get<2>(c_args);
		auto& Id2 = std::get<3>(c_args);
		auto& Y = std::get<4>(c_args);
		auto& Id3 = std::get<5>(c_args);
		auto& Z = std::get<6>(c_args);
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
					auto it0_2 = CspVarInt_constraint_store->template begin<0>(Id3,Z);
					while ( !it0_2.at_end() ) {
						auto ZDom(std::get<3>(*it0_2));
						// Begin guard
						if (
							( std::get<0>(*it0_2) != std::get<0>(*it0_0) )
							&& ( std::get<0>(*it0_2) != std::get<0>(*it0_1) )
						) {
							it0_0.lock();
							it0_1.lock();
							it0_2.lock();
							if (!c_stored_before) {
								c_it = plus_constraint_store->add(c_args);
								auto ccb = chr::Shared_x_obj< chr::Logical_var_imp_observer_constraint >(new typename plus::Constraint_callback(this,c_it));
								chr::schedule_constraint_callback(std::get<2>(c_args), ccb);
								chr::schedule_constraint_callback(std::get<4>(c_args), ccb);
								chr::schedule_constraint_callback(std::get<6>(c_args), ccb);
								c_stored_before = true;
							}
							c_it.lock();
							// Body
							chr::Statistics::inc_nb_rules();
							CHECK_ES( ( Solvint :: plus_boundConsistency( XDom, YDom, ZDom ) ) );
							assert(c_stored_before);
							if (!c_it.alive()) {
								c_it.unlock();
								it0_0.unlock();
								it0_1.unlock();
								it0_2.unlock();
								return chr::ES_CHR::SUCCESS;
							}
							c_it.unlock();
							if (!it0_0.alive()) {
								it0_1.unlock();
								it0_2.unlock();
								it0_0.next_and_unlock();
								goto it0_0_next;
							}
							it0_0.unlock();
							if (!it0_1.alive()) {
								it0_2.unlock();
								it0_1.next_and_unlock();
								goto it0_1_next;
							}
							it0_1.unlock();
							it0_2.next_and_unlock();
							goto it0_2_next;
						} // End guard
						++it0_2;
						it0_2_next:;
					}
				} // End guard
				++it0_1;
				it0_1_next:;
			}
			++it0_0;
			it0_0_next:;
		}
	}
	// Store constraint
	[[maybe_unused]] plus_store:
		if (!c_stored_before) {
			c_it = plus_constraint_store->add( c_args );
			auto ccb = chr::Shared_x_obj< chr::Logical_var_imp_observer_constraint >(new typename plus::Constraint_callback(this,c_it));
			chr::schedule_constraint_callback(std::get<2>(c_args), ccb);
			chr::schedule_constraint_callback(std::get<4>(c_args), ccb);
			chr::schedule_constraint_callback(std::get<6>(c_args), ccb);
		}
	return chr::ES_CHR::SUCCESS;
}
chr::ES_CHR MagicSquare_04::do_put_alldiff(typename put_alldiff::Type c_args) {
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
chr::ES_CHR MagicSquare_04::do_put_usum(typename put_usum::Type c_args) {
	chr::Statistics::update_call_stack();
	[[maybe_unused]] put_usum_call:
	// ***************************************************
	// put_usum_0 <=> Rule NO_NAME, active constraint put_usum( L, Ids, Target ), occurrence 1
	[[maybe_unused]] put_usum_0:
	{
		auto& L = std::get<1>(c_args);
		auto& Ids = std::get<2>(c_args);
		auto& Target = std::get<3>(c_args);
		// Begin guard
		if (
			( ( *L ) . empty(  ) )
		) {
			// Body
			chr::Statistics::inc_nb_rules();
			CHECK_ES( ( Target == 0 ) );
			return chr::ES_CHR::SUCCESS;
		} // End guard
	}
	// ***************************************************
	// put_usum_1 <=> Rule NO_NAME, active constraint put_usum( L, Ids, Target ), occurrence 2
	[[maybe_unused]] put_usum_1:
	{
		auto& L = std::get<1>(c_args);
		auto& Ids = std::get<2>(c_args);
		auto& Target = std::get<3>(c_args);
		// Body
		chr::Statistics::inc_nb_rules();
		CHECK_ES( sum_fun( (*this ), (*L ), (*Ids ), Target ) );
		return chr::ES_CHR::SUCCESS;
	}
	// Store constraint
	[[maybe_unused]] put_usum_store:
	return chr::ES_CHR::SUCCESS;
}
//----------------------- START INCLUDE HEADER ---------------------

int main(int argc, const char *argv[]) {
    auto space = MagicSquare_04::create();
    chr::Logical_var<int> X[16];
    chr::Logical_var_mutable<interval> Dom[16];

    for (int i = 0; i < 16; ++i) {
        Dom[i] = interval(1, 16);
        space->CspVarIntDec(i, "x[" + std::to_string(i / 4) + "][" + std::to_string(i % 4) + "]", X[i], Dom[i]);
    }


CHR_RUN(    space->put_alldiff(make_list_var(X[0], X[1], X[2], X[3], X[4], X[5], X[6], X[7], X[8], X[9], X[10], X[11], X[12], X[13], X[14], X[15]), make_list_int(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15));
    space->put_usum(make_list_var(X[0], X[1], X[2], X[3]), make_list_int(0, 1, 2, 3), 34);
    space->put_usum(make_list_var(X[4], X[5], X[6], X[7]), make_list_int(4, 5, 6, 7), 34);
    space->put_usum(make_list_var(X[8], X[9], X[10], X[11]), make_list_int(8, 9, 10, 11), 34);
    space->put_usum(make_list_var(X[12], X[13], X[14], X[15]), make_list_int(12, 13, 14, 15), 34);
    space->put_usum(make_list_var(X[0], X[4], X[8], X[12]), make_list_int(0, 4, 8, 12), 34);
    space->put_usum(make_list_var(X[1], X[5], X[9], X[13]), make_list_int(1, 5, 9, 13), 34);
    space->put_usum(make_list_var(X[2], X[6], X[10], X[14]), make_list_int(2, 6, 10, 14), 34);
    space->put_usum(make_list_var(X[3], X[7], X[11], X[15]), make_list_int(3, 7, 11, 15), 34);
    space->put_usum(make_list_var(X[0], X[5], X[10], X[15]), make_list_int(0, 5, 10, 15), 34);
    space->put_usum(make_list_var(X[3], X[6], X[9], X[12]), make_list_int(3, 6, 9, 12), 34);
); 
CHR_RUN(space->labelling(0);); 
chr::Statistics::print(std::cout);
return 0;
}
//----------------------- END INCLUDE HEADER ---------------------
