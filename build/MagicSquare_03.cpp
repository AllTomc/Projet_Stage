/*
From line 142 to 156
labelling<labelling( ( Id + 1 ) )> { CspVarIntDec<CspVarIntDec( Id, _, _, Dom )> } --> labelling<labelling( ( Id + 1 ) )>, built-in<begin(  )>
CspOpeq<CspOpeq( IdX, X, IdY, Y )> { CspVarInt<CspVarInt( IdX, X, XDom )> } --> built-in<YDom>
CspOpplus<CspOpplus( Id1, X, Id2, Y, Id3, Z )> { CspVarInt<CspVarInt( Id1, X, XDom )> } --> built-in<plus_boundConsistency( XDom, YDom, ZDom )>
CspOpneq<CspOpneq( Id1, X, Id2, Y )> { CspVarInt<CspVarInt( Id1, X, XDom )> } --> built-in<ne( XDom, YDom )>
CspTmpInt<CspTmpInt( I, X, Dom )> --> CspVarInt<CspVarInt( I, X, Dom )>
CspVarIntDec<CspVarIntDec( Id, _, X, Dom )> { labelling<labelling( Id )> } --> labelling<labelling( ( Id + 1 ) )>, built-in<begin(  )>, CspVarInt<CspVarInt( Id, X, Dom )>
CspVarInt<CspVarInt( _, X, XDom )> { CspOpeq<CspOpeq( IdX, X, IdY, Y )>, CspOpplus<CspOpplus( Id1, X, Id2, Y, Id3, Z )>, CspOpneq<CspOpneq( Id1, X, Id2, Y )>, CspVarInt<CspVarInt( Id2, Y, YDom )> } --> built-in<( ( *XDom ) . val(  ) )>

(constraint) CspVarIntDec( ( +int ), ( +string ), ( ?int ), ( -interval ) ), indexes: { <0> }
(constraint) CspVarInt( ( +int ), ( ?int ), ( -interval ) ), indexes: { <0,1> }
(constraint) CspTmpInt( ( +int ), ( ?int ), ( -interval ) )
(constraint) CspOpneq( ( +int ), ( ?int ), ( +int ), ( ?int ) ), indexes: { <0,1>, <2,3> }
(constraint) CspOpplus( ( +int ), ( ?int ), ( +int ), ( ?int ), ( +int ), ( ?int ) ), indexes: { <0,1>, <2,3>, <4,5> }
(constraint) CspOpeq( ( +int ), ( ?int ), ( +int ), ( ?int ) ), indexes: { <0,1>, <2,3> }
(constraint) ##labelling( ( +int ) ), indexes: { <0> }
(rule) CspVarInt( _, _, Dom ) ==> ( ( *Dom ) . empty(  ) ) | failure ;;
(rule) CspVarInt( _, X, XDom ) ==> ( ( *XDom ) . singleton(  ) ) | X %= ( ( *XDom ) . val(  ) ) ;;
(rule) CspVarInt( _, Val, Dom ) ==> ( Val . ground(  ) ) | maj_dom( Dom, ( *Val ) ) ;;
(rule) CspVarIntDec( Id, _, X, Dom ) ==> CspVarInt( Id, X, Dom ) ;;
(rule) CspTmpInt( I, X, Dom ) ==> CspVarInt( I, X, Dom ) ;;
(rule) neq_var_var @ CspVarInt( Id1, X, XDom ), CspVarInt( Id2, Y, YDom ), CspOpneq( Id1, X, Id2, Y ) ==> ( Solvint :: ne( XDom, YDom ) ) ;;
(rule) neq_cste_var @ CspVarInt( Id, Y, YDom ), CspOpneq( _, X, Id, Y ) ==> ( X . ground(  ) ) | ( Solvint :: ne( YDom, ( *X ) ) ) ;;
(rule) neq_var_cste @ CspVarInt( Id, X, XDom ), CspOpneq( Id, X, _, Y ) ==> ( Y . ground(  ) ) | ( Solvint :: ne( XDom, ( *Y ) ) ) ;;
(rule) plus @ CspVarInt( Id1, X, XDom ), CspVarInt( Id2, Y, YDom ), CspVarInt( Id3, Z, ZDom ), CspOpplus( Id1, X, Id2, Y, Id3, Z ) =>> ( Solvint :: plus_boundConsistency( XDom, YDom, ZDom ) ) ;;
(rule) eq_var_var @ CspVarInt( IdX, X, XDom ), CspVarInt( IdY, Y, YDom ), CspOpeq( IdX, X, IdY, Y ) ==> ( XDom %= YDom, X %= Y ) ;;
(rule) CspVarIntDec( Id, _, _, Dom ) \ labelling( Id ) <=> ( __it_i = ( ( *Dom ) . begin(  ) ), __it_end_i = ( ( *Dom ) . end(  ) ), __local_success__3 = false, behavior( ( __local_success__3 || ( __it_i == __it_end_i ) ), __local_success__3 = true, ( ++__it_i ), __local_success__3, , , ( i = ( *__it_i ), set_eq( Dom, i ), labelling( ( Id + 1 ) ) )) ) ;;
(rule) labelling( Id ) <=> print_store( ( *this ) ) ;;
(occ rule) eq_var_var @ [+CspOpeq( IdX, X, IdY, Y )#0][+CspVarInt( IdX, X, XDom )<idx#0>, +CspVarInt( IdY, Y, YDom )<idx#0>] --> ( XDom %= YDom, X %= Y ) ;;
(occ rule) neq_var_var @ [+CspOpneq( Id1, X, Id2, Y )#0][+CspVarInt( Id1, X, XDom )<idx#0>, +CspVarInt( Id2, Y, YDom )<idx#0>] --> ( Solvint :: ne( XDom, YDom ) ) ;;
(occ rule) neq_cste_var @ [+CspOpneq( _, X, Id, Y )#1][( X . ground(  ) ), +CspVarInt( Id, Y, YDom )<idx#0>] --> ( Solvint :: ne( YDom, ( *X ) ) ) ;;
(occ rule) neq_var_cste @ [+CspOpneq( Id, X, _, Y )#2][( Y . ground(  ) ), +CspVarInt( Id, X, XDom )<idx#0>] --> ( Solvint :: ne( XDom, ( *Y ) ) ) ;;
(occ rule) plus @ [+CspOpplus( Id1, X, Id2, Y, Id3, Z )#0#no_history][+CspVarInt( Id1, X, XDom )<idx#0>#no_history, +CspVarInt( Id2, Y, YDom )<idx#0>#no_history, +CspVarInt( Id3, Z, ZDom )<idx#0>#no_history] --> ( Solvint :: plus_boundConsistency( XDom, YDom, ZDom ) ) ;;
(occ rule) [+CspTmpInt( I, X, Dom )#0][] --> CspVarInt( I, X, Dom ) ;;
(occ rule) [+CspVarInt( _, _, Dom )#0][( ( *Dom ) . empty(  ) )] --> failure ;;
(occ rule) [+CspVarInt( _, X, XDom )#1][( ( *XDom ) . singleton(  ) )] --> X %= ( ( *XDom ) . val(  ) ) ;;
(occ rule) [+CspVarInt( _, Val, Dom )#2][( Val . ground(  ) )] --> maj_dom( Dom, ( *Val ) ) ;;
(occ rule) neq_var_var @ [+CspVarInt( Id1, X, XDom )#3][+CspOpneq( Id1, X, Id2, Y )<idx#0>, +CspVarInt( Id2, Y, YDom )<idx#0>] --> ( Solvint :: ne( XDom, YDom ) ) ;;
(occ rule) neq_var_var @ [+CspVarInt( Id2, Y, YDom )#4][+CspOpneq( Id1, X, Id2, Y )<idx#1>, +CspVarInt( Id1, X, XDom )<idx#0>] --> ( Solvint :: ne( XDom, YDom ) ) ;;
(occ rule) neq_cste_var @ [+CspVarInt( Id, Y, YDom )#5][+CspOpneq( _, X, Id, Y )<idx#1>, ( X . ground(  ) )] --> ( Solvint :: ne( YDom, ( *X ) ) ) ;;
(occ rule) neq_var_cste @ [+CspVarInt( Id, X, XDom )#6][+CspOpneq( Id, X, _, Y )<idx#0>, ( Y . ground(  ) )] --> ( Solvint :: ne( XDom, ( *Y ) ) ) ;;
(occ rule) plus @ [+CspVarInt( Id1, X, XDom )#7#no_history][+CspOpplus( Id1, X, Id2, Y, Id3, Z )<idx#0>#no_history, +CspVarInt( Id3, Z, ZDom )<idx#0>#no_history, +CspVarInt( Id2, Y, YDom )<idx#0>#no_history] --> ( Solvint :: plus_boundConsistency( XDom, YDom, ZDom ) ) ;;
(occ rule) plus @ [+CspVarInt( Id2, Y, YDom )#8#no_history][+CspOpplus( Id1, X, Id2, Y, Id3, Z )<idx#1>#no_history, +CspVarInt( Id3, Z, ZDom )<idx#0>#no_history, +CspVarInt( Id1, X, XDom )<idx#0>#no_history] --> ( Solvint :: plus_boundConsistency( XDom, YDom, ZDom ) ) ;;
(occ rule) plus @ [+CspVarInt( Id3, Z, ZDom )#9#no_history][+CspOpplus( Id1, X, Id2, Y, Id3, Z )<idx#2>#no_history, +CspVarInt( Id2, Y, YDom )<idx#0>#no_history, +CspVarInt( Id1, X, XDom )<idx#0>#no_history] --> ( Solvint :: plus_boundConsistency( XDom, YDom, ZDom ) ) ;;
(occ rule) eq_var_var @ [+CspVarInt( IdX, X, XDom )#10][+CspOpeq( IdX, X, IdY, Y )<idx#0>, +CspVarInt( IdY, Y, YDom )<idx#0>] --> ( XDom %= YDom, X %= Y ) ;;
(occ rule) eq_var_var @ [+CspVarInt( IdY, Y, YDom )#11][+CspOpeq( IdX, X, IdY, Y )<idx#1>, +CspVarInt( IdX, X, XDom )<idx#0>] --> ( XDom %= YDom, X %= Y ) ;;
(occ rule) [+CspVarIntDec( Id, _, X, Dom )#0][] --> CspVarInt( Id, X, Dom ) ;;
(occ rule) [-labelling( Id )#0][+CspVarIntDec( Id, _, _, Dom )<idx#0>] --> ( __it_i = ( ( *Dom ) . begin(  ) ), __it_end_i = ( ( *Dom ) . end(  ) ), __local_success__3 = false, behavior( ( __local_success__3 || ( __it_i == __it_end_i ) ), __local_success__3 = true, ( ++__it_i ), __local_success__3, , , ( i = ( *__it_i ), set_eq( Dom, i ), labelling( ( Id + 1 ) ) )) ) ;;
(occ rule) [-labelling( Id )#1][] --> print_store( ( *this ) ) ;;

(constraint store) CspVarIntDec( ( +int ), ( +string ), ( ?int ), ( -interval ) ), indexes: { <0> }
(constraint store) CspVarInt( ( +int ), ( ?int ), ( -interval ) ), indexes: { <0,1> }
(constraint store) CspTmpInt( ( +int ), ( ?int ), ( -interval ) )
(constraint store) CspOpneq( ( +int ), ( ?int ), ( +int ), ( ?int ) ), indexes: { <0,1>, <2,3> }
(constraint store) CspOpplus( ( +int ), ( ?int ), ( +int ), ( ?int ), ( +int ), ( ?int ) ), indexes: { <0,1>, <2,3>, <4,5> }
(constraint store) CspOpeq( ( +int ), ( ?int ), ( +int ), ( ?int ) ), indexes: { <0,1>, <2,3> }
(constraint store) labelling( ( +int ) ), indexes: { <0> }
// Rule eq_var_var, active constraint CspOpeq( IdX, X, IdY, Y ), occurrence 0
Begin CspOpeq_0
If empty store CspVarInt( IdX, X, XDom ) Then goto CspOpeq_store
If empty store CspVarInt( IdY, Y, YDom ) Then goto CspOpeq_store
	Matching partner CspVarInt( IdX, X, XDom ) with idx#0<IdX,X>
		Matching partner CspVarInt( IdY, Y, YDom ) with idx#0<IdY,Y>
			If guard
				( CspVarInt( IdY, Y, YDom ) != CspVarInt( IdX, X, XDom ) )
			Then guard
				If history <CspOpeq( IdX, X, IdY, Y ),CspVarInt( IdX, X, XDom ),CspVarInt( IdY, Y, YDom )> Then
					store constraint CspOpeq( IdX, X, IdY, Y )
					XDom %= YDom
					X %= Y
					If not alived CspOpeq( IdX, X, IdY, Y ) Then goto next goal constraint
					If not alived CspVarInt( IdX, X, XDom ) Then goto next matching of CspVarInt( IdX, X, XDom )
					goto next matching of CspVarInt( IdY, Y, YDom )
				End history
			End guard
		End matching partner CspVarInt( IdY, Y, YDom )
	End matching partner CspVarInt( IdX, X, XDom )
End
// Fail through
Begin CspOpeq_store
	Store constraint CspOpeq
	Schedule constraint CspOpeq with variable index 1
	Schedule constraint CspOpeq with variable index 3
Goto next goal constraint
// Rule neq_var_var, active constraint CspOpneq( Id1, X, Id2, Y ), occurrence 0
Begin CspOpneq_0
If empty store CspVarInt( Id1, X, XDom ) Then goto CspOpneq_1
If empty store CspVarInt( Id2, Y, YDom ) Then goto CspOpneq_1
	Matching partner CspVarInt( Id1, X, XDom ) with idx#0<Id1,X>
		Matching partner CspVarInt( Id2, Y, YDom ) with idx#0<Id2,Y>
			If guard
				( CspVarInt( Id2, Y, YDom ) != CspVarInt( Id1, X, XDom ) )
			Then guard
				If history <CspOpneq( Id1, X, Id2, Y ),CspVarInt( Id1, X, XDom ),CspVarInt( Id2, Y, YDom )> Then
					store constraint CspOpneq( Id1, X, Id2, Y )
					( Solvint :: ne( XDom, YDom ) )
					If not alived CspOpneq( Id1, X, Id2, Y ) Then goto next goal constraint
					If not alived CspVarInt( Id1, X, XDom ) Then goto next matching of CspVarInt( Id1, X, XDom )
					goto next matching of CspVarInt( Id2, Y, YDom )
				End history
			End guard
		End matching partner CspVarInt( Id2, Y, YDom )
	End matching partner CspVarInt( Id1, X, XDom )
End
// Rule neq_cste_var, active constraint CspOpneq( _, X, Id, Y ), occurrence 1
Begin CspOpneq_1
If empty store CspVarInt( Id, Y, YDom ) Then goto CspOpneq_2
	If guard
		( X . ground(  ) )
	Then guard
		Matching partner CspVarInt( Id, Y, YDom ) with idx#0<Id,Y>
			If history <CspOpneq( _, X, Id, Y ),CspVarInt( Id, Y, YDom )> Then
				store constraint CspOpneq( _, X, Id, Y )
				( Solvint :: ne( YDom, ( *X ) ) )
				If not alived CspOpneq( _, X, Id, Y ) Then goto next goal constraint
				goto next matching of CspVarInt( Id, Y, YDom )
			End history
		End matching partner CspVarInt( Id, Y, YDom )
	End guard
End
// Rule neq_var_cste, active constraint CspOpneq( Id, X, _, Y ), occurrence 2
Begin CspOpneq_2
If empty store CspVarInt( Id, X, XDom ) Then goto CspOpneq_store
	If guard
		( Y . ground(  ) )
	Then guard
		Matching partner CspVarInt( Id, X, XDom ) with idx#0<Id,X>
			If history <CspOpneq( Id, X, _, Y ),CspVarInt( Id, X, XDom )> Then
				store constraint CspOpneq( Id, X, _, Y )
				( Solvint :: ne( XDom, ( *Y ) ) )
				If not alived CspOpneq( Id, X, _, Y ) Then goto next goal constraint
				goto next matching of CspVarInt( Id, X, XDom )
			End history
		End matching partner CspVarInt( Id, X, XDom )
	End guard
End
// Fail through
Begin CspOpneq_store
	Store constraint CspOpneq
	Schedule constraint CspOpneq with variable index 1
	Schedule constraint CspOpneq with variable index 3
Goto next goal constraint
// Rule plus, active constraint CspOpplus( Id1, X, Id2, Y, Id3, Z ), occurrence 0
Begin CspOpplus_0
If empty store CspVarInt( Id1, X, XDom ) Then goto CspOpplus_store
If empty store CspVarInt( Id2, Y, YDom ) Then goto CspOpplus_store
If empty store CspVarInt( Id3, Z, ZDom ) Then goto CspOpplus_store
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
						store constraint CspOpplus( Id1, X, Id2, Y, Id3, Z )
						( Solvint :: plus_boundConsistency( XDom, YDom, ZDom ) )
						If not alived CspOpplus( Id1, X, Id2, Y, Id3, Z ) Then goto next goal constraint
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
Begin CspOpplus_store
	Store constraint CspOpplus
	Schedule constraint CspOpplus with variable index 1
	Schedule constraint CspOpplus with variable index 3
	Schedule constraint CspOpplus with variable index 5
Goto next goal constraint
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
If empty store CspOpneq( Id1, X, Id2, Y ) Then goto CspVarInt_4
If empty store CspVarInt( Id2, Y, YDom ) Then goto CspVarInt_4
	Matching partner CspOpneq( Id1, X, Id2, Y ) with idx#0<Id1,X>
		Matching partner CspVarInt( Id2, Y, YDom ) with idx#0<Id2,Y>
			If guard
				( CspVarInt( Id2, Y, YDom ) != CspVarInt( Id1, X, XDom ) )
			Then guard
				If history <CspVarInt( Id1, X, XDom ),CspOpneq( Id1, X, Id2, Y ),CspVarInt( Id2, Y, YDom )> Then
					store constraint CspVarInt( Id1, X, XDom )
					( Solvint :: ne( XDom, YDom ) )
					If not alived CspVarInt( Id1, X, XDom ) Then goto next goal constraint
					If not alived CspOpneq( Id1, X, Id2, Y ) Then goto next matching of CspOpneq( Id1, X, Id2, Y )
					goto next matching of CspVarInt( Id2, Y, YDom )
				End history
			End guard
		End matching partner CspVarInt( Id2, Y, YDom )
	End matching partner CspOpneq( Id1, X, Id2, Y )
End
// Rule neq_var_var, active constraint CspVarInt( Id2, Y, YDom ), occurrence 4
Begin CspVarInt_4
If empty store CspOpneq( Id1, X, Id2, Y ) Then goto CspVarInt_5
If empty store CspVarInt( Id1, X, XDom ) Then goto CspVarInt_5
	Matching partner CspOpneq( Id1, X, Id2, Y ) with idx#1<Id2,Y>
		Matching partner CspVarInt( Id1, X, XDom ) with idx#0<Id1,X>
			If guard
				( CspVarInt( Id1, X, XDom ) != CspVarInt( Id2, Y, YDom ) )
			Then guard
				If history <CspVarInt( Id2, Y, YDom ),CspOpneq( Id1, X, Id2, Y ),CspVarInt( Id1, X, XDom )> Then
					store constraint CspVarInt( Id2, Y, YDom )
					( Solvint :: ne( XDom, YDom ) )
					If not alived CspVarInt( Id2, Y, YDom ) Then goto next goal constraint
					If not alived CspOpneq( Id1, X, Id2, Y ) Then goto next matching of CspOpneq( Id1, X, Id2, Y )
					goto next matching of CspVarInt( Id1, X, XDom )
				End history
			End guard
		End matching partner CspVarInt( Id1, X, XDom )
	End matching partner CspOpneq( Id1, X, Id2, Y )
End
// Rule neq_cste_var, active constraint CspVarInt( Id, Y, YDom ), occurrence 5
Begin CspVarInt_5
If empty store CspOpneq( _, X, Id, Y ) Then goto CspVarInt_6
	Matching partner CspOpneq( _, X, Id, Y ) with idx#1<Id,Y>
		If guard
			( X . ground(  ) )
		Then guard
			If history <CspVarInt( Id, Y, YDom ),CspOpneq( _, X, Id, Y )> Then
				store constraint CspVarInt( Id, Y, YDom )
				( Solvint :: ne( YDom, ( *X ) ) )
				If not alived CspVarInt( Id, Y, YDom ) Then goto next goal constraint
				goto next matching of CspOpneq( _, X, Id, Y )
			End history
		End guard
	End matching partner CspOpneq( _, X, Id, Y )
End
// Rule neq_var_cste, active constraint CspVarInt( Id, X, XDom ), occurrence 6
Begin CspVarInt_6
If empty store CspOpneq( Id, X, _, Y ) Then goto CspVarInt_7
	Matching partner CspOpneq( Id, X, _, Y ) with idx#0<Id,X>
		If guard
			( Y . ground(  ) )
		Then guard
			If history <CspVarInt( Id, X, XDom ),CspOpneq( Id, X, _, Y )> Then
				store constraint CspVarInt( Id, X, XDom )
				( Solvint :: ne( XDom, ( *Y ) ) )
				If not alived CspVarInt( Id, X, XDom ) Then goto next goal constraint
				goto next matching of CspOpneq( Id, X, _, Y )
			End history
		End guard
	End matching partner CspOpneq( Id, X, _, Y )
End
// Rule plus, active constraint CspVarInt( Id1, X, XDom ), occurrence 7
Begin CspVarInt_7
If empty store CspOpplus( Id1, X, Id2, Y, Id3, Z ) Then goto CspVarInt_8
If empty store CspVarInt( Id3, Z, ZDom ) Then goto CspVarInt_8
If empty store CspVarInt( Id2, Y, YDom ) Then goto CspVarInt_8
	Matching partner CspOpplus( Id1, X, Id2, Y, Id3, Z ) with idx#0<Id1,X>
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
						If not alived CspOpplus( Id1, X, Id2, Y, Id3, Z ) Then goto next matching of CspOpplus( Id1, X, Id2, Y, Id3, Z )
						If not alived CspVarInt( Id3, Z, ZDom ) Then goto next matching of CspVarInt( Id3, Z, ZDom )
						goto next matching of CspVarInt( Id2, Y, YDom )
					End guard
				End matching partner CspVarInt( Id2, Y, YDom )
			End guard
		End matching partner CspVarInt( Id3, Z, ZDom )
	End matching partner CspOpplus( Id1, X, Id2, Y, Id3, Z )
End
// Rule plus, active constraint CspVarInt( Id2, Y, YDom ), occurrence 8
Begin CspVarInt_8
If empty store CspOpplus( Id1, X, Id2, Y, Id3, Z ) Then goto CspVarInt_9
If empty store CspVarInt( Id3, Z, ZDom ) Then goto CspVarInt_9
If empty store CspVarInt( Id1, X, XDom ) Then goto CspVarInt_9
	Matching partner CspOpplus( Id1, X, Id2, Y, Id3, Z ) with idx#1<Id2,Y>
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
						If not alived CspOpplus( Id1, X, Id2, Y, Id3, Z ) Then goto next matching of CspOpplus( Id1, X, Id2, Y, Id3, Z )
						If not alived CspVarInt( Id3, Z, ZDom ) Then goto next matching of CspVarInt( Id3, Z, ZDom )
						goto next matching of CspVarInt( Id1, X, XDom )
					End guard
				End matching partner CspVarInt( Id1, X, XDom )
			End guard
		End matching partner CspVarInt( Id3, Z, ZDom )
	End matching partner CspOpplus( Id1, X, Id2, Y, Id3, Z )
End
// Rule plus, active constraint CspVarInt( Id3, Z, ZDom ), occurrence 9
Begin CspVarInt_9
If empty store CspOpplus( Id1, X, Id2, Y, Id3, Z ) Then goto CspVarInt_10
If empty store CspVarInt( Id2, Y, YDom ) Then goto CspVarInt_10
If empty store CspVarInt( Id1, X, XDom ) Then goto CspVarInt_10
	Matching partner CspOpplus( Id1, X, Id2, Y, Id3, Z ) with idx#2<Id3,Z>
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
						If not alived CspOpplus( Id1, X, Id2, Y, Id3, Z ) Then goto next matching of CspOpplus( Id1, X, Id2, Y, Id3, Z )
						If not alived CspVarInt( Id2, Y, YDom ) Then goto next matching of CspVarInt( Id2, Y, YDom )
						goto next matching of CspVarInt( Id1, X, XDom )
					End guard
				End matching partner CspVarInt( Id1, X, XDom )
			End guard
		End matching partner CspVarInt( Id2, Y, YDom )
	End matching partner CspOpplus( Id1, X, Id2, Y, Id3, Z )
End
// Rule eq_var_var, active constraint CspVarInt( IdX, X, XDom ), occurrence 10
Begin CspVarInt_10
If empty store CspOpeq( IdX, X, IdY, Y ) Then goto CspVarInt_11
If empty store CspVarInt( IdY, Y, YDom ) Then goto CspVarInt_11
	Matching partner CspOpeq( IdX, X, IdY, Y ) with idx#0<IdX,X>
		Matching partner CspVarInt( IdY, Y, YDom ) with idx#0<IdY,Y>
			If guard
				( CspVarInt( IdY, Y, YDom ) != CspVarInt( IdX, X, XDom ) )
			Then guard
				If history <CspVarInt( IdX, X, XDom ),CspOpeq( IdX, X, IdY, Y ),CspVarInt( IdY, Y, YDom )> Then
					store constraint CspVarInt( IdX, X, XDom )
					XDom %= YDom
					X %= Y
					If not alived CspVarInt( IdX, X, XDom ) Then goto next goal constraint
					If not alived CspOpeq( IdX, X, IdY, Y ) Then goto next matching of CspOpeq( IdX, X, IdY, Y )
					goto next matching of CspVarInt( IdY, Y, YDom )
				End history
			End guard
		End matching partner CspVarInt( IdY, Y, YDom )
	End matching partner CspOpeq( IdX, X, IdY, Y )
End
// Rule eq_var_var, active constraint CspVarInt( IdY, Y, YDom ), occurrence 11
Begin CspVarInt_11
If empty store CspOpeq( IdX, X, IdY, Y ) Then goto CspVarInt_store
If empty store CspVarInt( IdX, X, XDom ) Then goto CspVarInt_store
	Matching partner CspOpeq( IdX, X, IdY, Y ) with idx#1<IdY,Y>
		Matching partner CspVarInt( IdX, X, XDom ) with idx#0<IdX,X>
			If guard
				( CspVarInt( IdX, X, XDom ) != CspVarInt( IdY, Y, YDom ) )
			Then guard
				If history <CspVarInt( IdY, Y, YDom ),CspOpeq( IdX, X, IdY, Y ),CspVarInt( IdX, X, XDom )> Then
					store constraint CspVarInt( IdY, Y, YDom )
					XDom %= YDom
					X %= Y
					If not alived CspVarInt( IdY, Y, YDom ) Then goto next goal constraint
					If not alived CspOpeq( IdX, X, IdY, Y ) Then goto next matching of CspOpeq( IdX, X, IdY, Y )
					goto next matching of CspVarInt( IdX, X, XDom )
				End history
			End guard
		End matching partner CspVarInt( IdX, X, XDom )
	End matching partner CspOpeq( IdX, X, IdY, Y )
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
int global_id = 9;
std::map<int, std::string> id_name_map;


template <typename T>
void print_store(T& pb) {
    auto it = pb.chr_store_begin();
    while (!it.at_end()) {
        std::cout << it.to_string() << std::endl;
        ++it;
    }
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
bool alldiff_post(T& space, const list_var& vars, const list_int& ids) {
    auto it1 = vars.begin();
    auto id1 = ids.begin();
    for (; it1 != vars.end(); ++it1, ++id1) {
        auto it2 = it1;
        auto id2 = id1;
        ++it2; ++id2;
        for (; it2 != vars.end(); ++it2, ++id2) {
            CHECK_ES(space.CspOpneq(chr::Logical_var_ground<int>(*id1), *it1, chr::Logical_var_ground<int>(*id2), *it2));
        }
    }
    return true;
}
template<class T>
bool linear_post(T& space, const list_var& vars, const list_int& ids, int target) {
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
        CHECK_ES(space.CspOpplus(
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
    CHECK_ES(space.CspOpeq(
        Logical_var_ground<int>(id_prev), prev,
        Logical_var_ground<int>(final_id), finalVar));
    CHECK_ES(set_eq(finalDom, target));
    return true;
}


//----------------------- END INCLUDE HEADER ---------------------
#include <chrpp.hh>
class MagicSquare_03 {
	unsigned long int next_free_constraint_id = 1;
	//(constraint store) CspVarIntDec( ( +int ), ( +string ), ( ?int ), ( -interval ) ), indexes: { <0> }
public:
	struct CspVarIntDec {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var_ground< int >, chr::Logical_var_ground< string >, chr::Logical_var< int >, chr::Logical_var_mutable< interval > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0> >, true >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(MagicSquare_03* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
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
			chr::Weak_obj< MagicSquare_03 > _space;
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
			Constraint_callback(MagicSquare_03* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
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
			chr::Weak_obj< MagicSquare_03 > _space;
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
			Constraint_callback(MagicSquare_03* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
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
			chr::Weak_obj< MagicSquare_03 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename CspTmpInt::Constraint_store_t > CspTmpInt_constraint_store{ chr::make_shared< typename CspTmpInt::Constraint_store_t >("CspTmpInt") };
	//(constraint store) CspOpneq( ( +int ), ( ?int ), ( +int ), ( ?int ) ), indexes: { <0,1>, <2,3> }
public:
	struct CspOpneq {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var_ground< int >, chr::Logical_var< int >, chr::Logical_var_ground< int >, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,1>, chr::LNS::Index<2,3> >, true >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(MagicSquare_03* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->CspOpneq_constraint_store && _space->CspOpneq_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_CspOpneq(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< MagicSquare_03 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename CspOpneq::Constraint_store_t > CspOpneq_constraint_store{ chr::make_shared< typename CspOpneq::Constraint_store_t >("CspOpneq") };
	//(constraint store) CspOpplus( ( +int ), ( ?int ), ( +int ), ( ?int ), ( +int ), ( ?int ) ), indexes: { <0,1>, <2,3>, <4,5> }
public:
	struct CspOpplus {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var_ground< int >, chr::Logical_var< int >, chr::Logical_var_ground< int >, chr::Logical_var< int >, chr::Logical_var_ground< int >, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,1>, chr::LNS::Index<2,3>, chr::LNS::Index<4,5> >, true >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(MagicSquare_03* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->CspOpplus_constraint_store && _space->CspOpplus_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_CspOpplus(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< MagicSquare_03 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename CspOpplus::Constraint_store_t > CspOpplus_constraint_store{ chr::make_shared< typename CspOpplus::Constraint_store_t >("CspOpplus") };
	//(constraint store) CspOpeq( ( +int ), ( ?int ), ( +int ), ( ?int ) ), indexes: { <0,1>, <2,3> }
public:
	struct CspOpeq {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var_ground< int >, chr::Logical_var< int >, chr::Logical_var_ground< int >, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,1>, chr::LNS::Index<2,3> >, true >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(MagicSquare_03* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->CspOpeq_constraint_store && _space->CspOpeq_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_CspOpeq(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< MagicSquare_03 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename CspOpeq::Constraint_store_t > CspOpeq_constraint_store{ chr::make_shared< typename CspOpeq::Constraint_store_t >("CspOpeq") };
	//(constraint store) labelling( ( +int ) ), indexes: { <0> }
public:
	struct labelling {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var_ground< int > >;
	};
public:
	unsigned int _ref_use_count  = 0;///< Count of shared references
	unsigned int _ref_weak_count = 0;///< Count of weak references + (#shared != 0)
	MagicSquare_03() { }
	~MagicSquare_03() {
		CspVarIntDec_constraint_store.release();
		CspVarInt_constraint_store.release();
		CspTmpInt_constraint_store.release();
		CspOpneq_constraint_store.release();
		CspOpplus_constraint_store.release();
		CspOpeq_constraint_store.release();
	}
	static chr::Shared_obj<MagicSquare_03> create() { return chr::make_shared<MagicSquare_03>(); }
	chr::Constraint_stores_iterator<chr::Shared_obj<typename CspVarIntDec::Constraint_store_t>,chr::Shared_obj<typename CspVarInt::Constraint_store_t>,chr::Shared_obj<typename CspTmpInt::Constraint_store_t>,chr::Shared_obj<typename CspOpneq::Constraint_store_t>,chr::Shared_obj<typename CspOpplus::Constraint_store_t>,chr::Shared_obj<typename CspOpeq::Constraint_store_t>> chr_store_begin() { return chr::Constraint_stores_iterator(CspVarIntDec_constraint_store,CspVarInt_constraint_store,CspTmpInt_constraint_store,CspOpneq_constraint_store,CspOpplus_constraint_store,CspOpeq_constraint_store); }
	typename CspVarIntDec::Constraint_store_t& get_CspVarIntDec_store() { return *CspVarIntDec_constraint_store; }
	typename CspVarInt::Constraint_store_t& get_CspVarInt_store() { return *CspVarInt_constraint_store; }
	typename CspTmpInt::Constraint_store_t& get_CspTmpInt_store() { return *CspTmpInt_constraint_store; }
	typename CspOpneq::Constraint_store_t& get_CspOpneq_store() { return *CspOpneq_constraint_store; }
	typename CspOpplus::Constraint_store_t& get_CspOpplus_store() { return *CspOpplus_constraint_store; }
	typename CspOpeq::Constraint_store_t& get_CspOpeq_store() { return *CspOpeq_constraint_store; }
	struct History {
		typename chr::Shared_obj< chr::History_dyn< 1 > > rule_0{ chr::make_shared< typename chr::History_dyn< 1 > >() };
		typename chr::Shared_obj< chr::History_dyn< 1 > > rule_1{ chr::make_shared< typename chr::History_dyn< 1 > >() };
		typename chr::Shared_obj< chr::History_dyn< 1 > > rule_2{ chr::make_shared< typename chr::History_dyn< 1 > >() };
		typename chr::Shared_obj< chr::History_dyn< 1 > > rule_3{ chr::make_shared< typename chr::History_dyn< 1 > >() };
		typename chr::Shared_obj< chr::History_dyn< 1 > > rule_4{ chr::make_shared< typename chr::History_dyn< 1 > >() };
		typename chr::Shared_obj< chr::History_dyn< 3 > > rule_5{ chr::make_shared< typename chr::History_dyn< 3 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_6{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_7{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 3 > > rule_9{ chr::make_shared< typename chr::History_dyn< 3 > >() };
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
	chr::ES_CHR do_CspOpneq(typename CspOpneq::Type c_args, typename CspOpneq::Constraint_store_t::iterator c_it);
	chr::ES_CHR CspOpneq( chr::Logical_var_ground< int > arg0, chr::Logical_var< int > arg1, chr::Logical_var_ground< int > arg2, chr::Logical_var< int > arg3) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1, arg2, arg3);
		return do_CspOpneq(std::move(c_args), CspOpneq_constraint_store->end());
	}
	chr::ES_CHR do_CspOpplus(typename CspOpplus::Type c_args, typename CspOpplus::Constraint_store_t::iterator c_it);
	chr::ES_CHR CspOpplus( chr::Logical_var_ground< int > arg0, chr::Logical_var< int > arg1, chr::Logical_var_ground< int > arg2, chr::Logical_var< int > arg3, chr::Logical_var_ground< int > arg4, chr::Logical_var< int > arg5) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1, arg2, arg3, arg4, arg5);
		return do_CspOpplus(std::move(c_args), CspOpplus_constraint_store->end());
	}
	chr::ES_CHR do_CspOpeq(typename CspOpeq::Type c_args, typename CspOpeq::Constraint_store_t::iterator c_it);
	chr::ES_CHR CspOpeq( chr::Logical_var_ground< int > arg0, chr::Logical_var< int > arg1, chr::Logical_var_ground< int > arg2, chr::Logical_var< int > arg3) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1, arg2, arg3);
		return do_CspOpeq(std::move(c_args), CspOpeq_constraint_store->end());
	}
	chr::ES_CHR do_labelling(typename labelling::Type c_args);
	chr::ES_CHR labelling( chr::Logical_var_ground< int > arg0) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0);
		return do_labelling(std::move(c_args));
	}
};
chr::ES_CHR MagicSquare_03::do_CspOpeq(typename CspOpeq::Type c_args, typename CspOpeq::Constraint_store_t::iterator c_it) {
	bool c_stored_before = !c_it.at_end();
	chr::Statistics::update_call_stack();
	[[maybe_unused]] CspOpeq_call:
	// ***************************************************
	// CspOpeq_0 <=> Rule eq_var_var, active constraint CspOpeq( IdX, X, IdY, Y ), occurrence 1
	[[maybe_unused]] CspOpeq_0:
	{
		if (CspVarInt_constraint_store->empty()) goto CspOpeq_store;
		if (CspVarInt_constraint_store->empty()) goto CspOpeq_store;
		auto& IdX = std::get<1>(c_args);
		auto& X = std::get<2>(c_args);
		auto& IdY = std::get<3>(c_args);
		auto& Y = std::get<4>(c_args);
		auto it0_0 = CspVarInt_constraint_store->template begin<0>(IdX,X);
		while ( !it0_0.at_end() ) {
			auto XDom(std::get<3>(*it0_0));
			auto it0_1 = CspVarInt_constraint_store->template begin<0>(IdY,Y);
			while ( !it0_1.at_end() ) {
				auto YDom(std::get<3>(*it0_1));
				// Begin guard
				if (
					( std::get<0>(*it0_1) != std::get<0>(*it0_0) )
				) {
					// Check history
					if (_history.rule_9->check( {{std::get<0>(c_args),std::get<0>(*it0_0),std::get<0>(*it0_1)}} )) {
						it0_0.lock();
						it0_1.lock();
						if (!c_stored_before) {
							c_it = CspOpeq_constraint_store->add(c_args);
							auto ccb = chr::Shared_x_obj< chr::Logical_var_imp_observer_constraint >(new typename CspOpeq::Constraint_callback(this,c_it));
							chr::schedule_constraint_callback(std::get<2>(c_args), ccb);
							chr::schedule_constraint_callback(std::get<4>(c_args), ccb);
							c_stored_before = true;
						}
						c_it.lock();
						// Body
						chr::Statistics::inc_nb_rules();
						if ((XDom %= YDom) == chr::ES_CHR::FAILURE) return chr::ES_CHR::FAILURE;
						if ((X %= Y) == chr::ES_CHR::FAILURE) return chr::ES_CHR::FAILURE;
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
	[[maybe_unused]] CspOpeq_store:
		if (!c_stored_before) {
			c_it = CspOpeq_constraint_store->add( c_args );
			auto ccb = chr::Shared_x_obj< chr::Logical_var_imp_observer_constraint >(new typename CspOpeq::Constraint_callback(this,c_it));
			chr::schedule_constraint_callback(std::get<2>(c_args), ccb);
			chr::schedule_constraint_callback(std::get<4>(c_args), ccb);
		}
	return chr::ES_CHR::SUCCESS;
}
chr::ES_CHR MagicSquare_03::do_CspOpneq(typename CspOpneq::Type c_args, typename CspOpneq::Constraint_store_t::iterator c_it) {
	bool c_stored_before = !c_it.at_end();
	chr::Statistics::update_call_stack();
	[[maybe_unused]] CspOpneq_call:
	// ***************************************************
	// CspOpneq_0 <=> Rule neq_var_var, active constraint CspOpneq( Id1, X, Id2, Y ), occurrence 1
	[[maybe_unused]] CspOpneq_0:
	{
		if (CspVarInt_constraint_store->empty()) goto CspOpneq_1;
		if (CspVarInt_constraint_store->empty()) goto CspOpneq_1;
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
							c_it = CspOpneq_constraint_store->add(c_args);
							auto ccb = chr::Shared_x_obj< chr::Logical_var_imp_observer_constraint >(new typename CspOpneq::Constraint_callback(this,c_it));
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
	// CspOpneq_1 <=> Rule neq_cste_var, active constraint CspOpneq( _, X, Id, Y ), occurrence 2
	[[maybe_unused]] CspOpneq_1:
	{
		if (CspVarInt_constraint_store->empty()) goto CspOpneq_2;
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
						c_it = CspOpneq_constraint_store->add(c_args);
						auto ccb = chr::Shared_x_obj< chr::Logical_var_imp_observer_constraint >(new typename CspOpneq::Constraint_callback(this,c_it));
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
	// CspOpneq_2 <=> Rule neq_var_cste, active constraint CspOpneq( Id, X, _, Y ), occurrence 3
	[[maybe_unused]] CspOpneq_2:
	{
		if (CspVarInt_constraint_store->empty()) goto CspOpneq_store;
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
						c_it = CspOpneq_constraint_store->add(c_args);
						auto ccb = chr::Shared_x_obj< chr::Logical_var_imp_observer_constraint >(new typename CspOpneq::Constraint_callback(this,c_it));
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
	[[maybe_unused]] CspOpneq_store:
		if (!c_stored_before) {
			c_it = CspOpneq_constraint_store->add( c_args );
			auto ccb = chr::Shared_x_obj< chr::Logical_var_imp_observer_constraint >(new typename CspOpneq::Constraint_callback(this,c_it));
			chr::schedule_constraint_callback(std::get<2>(c_args), ccb);
			chr::schedule_constraint_callback(std::get<4>(c_args), ccb);
		}
	return chr::ES_CHR::SUCCESS;
}
chr::ES_CHR MagicSquare_03::do_CspOpplus(typename CspOpplus::Type c_args, typename CspOpplus::Constraint_store_t::iterator c_it) {
	bool c_stored_before = !c_it.at_end();
	chr::Statistics::update_call_stack();
	[[maybe_unused]] CspOpplus_call:
	// ***************************************************
	// CspOpplus_0 <=> Rule plus, active constraint CspOpplus( Id1, X, Id2, Y, Id3, Z ), occurrence 1
	[[maybe_unused]] CspOpplus_0:
	{
		if (CspVarInt_constraint_store->empty()) goto CspOpplus_store;
		if (CspVarInt_constraint_store->empty()) goto CspOpplus_store;
		if (CspVarInt_constraint_store->empty()) goto CspOpplus_store;
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
								c_it = CspOpplus_constraint_store->add(c_args);
								auto ccb = chr::Shared_x_obj< chr::Logical_var_imp_observer_constraint >(new typename CspOpplus::Constraint_callback(this,c_it));
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
	[[maybe_unused]] CspOpplus_store:
		if (!c_stored_before) {
			c_it = CspOpplus_constraint_store->add( c_args );
			auto ccb = chr::Shared_x_obj< chr::Logical_var_imp_observer_constraint >(new typename CspOpplus::Constraint_callback(this,c_it));
			chr::schedule_constraint_callback(std::get<2>(c_args), ccb);
			chr::schedule_constraint_callback(std::get<4>(c_args), ccb);
			chr::schedule_constraint_callback(std::get<6>(c_args), ccb);
		}
	return chr::ES_CHR::SUCCESS;
}
chr::ES_CHR MagicSquare_03::do_CspTmpInt(typename CspTmpInt::Type c_args, typename CspTmpInt::Constraint_store_t::iterator c_it) {
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
chr::ES_CHR MagicSquare_03::do_CspVarInt(typename CspVarInt::Type c_args, typename CspVarInt::Constraint_store_t::iterator c_it) {
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
		if (CspOpneq_constraint_store->empty()) goto CspVarInt_4;
		if (CspVarInt_constraint_store->empty()) goto CspVarInt_4;
		auto& Id1 = std::get<1>(c_args);
		auto& X = std::get<2>(c_args);
		auto& XDom = std::get<3>(c_args);
		auto it3_0 = CspOpneq_constraint_store->template begin<0>(Id1,X);
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
		if (CspOpneq_constraint_store->empty()) goto CspVarInt_5;
		if (CspVarInt_constraint_store->empty()) goto CspVarInt_5;
		auto& Id2 = std::get<1>(c_args);
		auto& Y = std::get<2>(c_args);
		auto& YDom = std::get<3>(c_args);
		auto it4_0 = CspOpneq_constraint_store->template begin<1>(Id2,Y);
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
		if (CspOpneq_constraint_store->empty()) goto CspVarInt_6;
		auto& Id = std::get<1>(c_args);
		auto& Y = std::get<2>(c_args);
		auto& YDom = std::get<3>(c_args);
		auto it5_0 = CspOpneq_constraint_store->template begin<1>(Id,Y);
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
		if (CspOpneq_constraint_store->empty()) goto CspVarInt_7;
		auto& Id = std::get<1>(c_args);
		auto& X = std::get<2>(c_args);
		auto& XDom = std::get<3>(c_args);
		auto it6_0 = CspOpneq_constraint_store->template begin<0>(Id,X);
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
		if (CspOpplus_constraint_store->empty()) goto CspVarInt_8;
		if (CspVarInt_constraint_store->empty()) goto CspVarInt_8;
		if (CspVarInt_constraint_store->empty()) goto CspVarInt_8;
		auto& Id1 = std::get<1>(c_args);
		auto& X = std::get<2>(c_args);
		auto& XDom = std::get<3>(c_args);
		auto it7_0 = CspOpplus_constraint_store->template begin<0>(Id1,X);
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
		if (CspOpplus_constraint_store->empty()) goto CspVarInt_9;
		if (CspVarInt_constraint_store->empty()) goto CspVarInt_9;
		if (CspVarInt_constraint_store->empty()) goto CspVarInt_9;
		auto& Id2 = std::get<1>(c_args);
		auto& Y = std::get<2>(c_args);
		auto& YDom = std::get<3>(c_args);
		auto it8_0 = CspOpplus_constraint_store->template begin<1>(Id2,Y);
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
		if (CspOpplus_constraint_store->empty()) goto CspVarInt_10;
		if (CspVarInt_constraint_store->empty()) goto CspVarInt_10;
		if (CspVarInt_constraint_store->empty()) goto CspVarInt_10;
		auto& Id3 = std::get<1>(c_args);
		auto& Z = std::get<2>(c_args);
		auto& ZDom = std::get<3>(c_args);
		auto it9_0 = CspOpplus_constraint_store->template begin<2>(Id3,Z);
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
	// CspVarInt_10 <=> Rule eq_var_var, active constraint CspVarInt( IdX, X, XDom ), occurrence 11
	[[maybe_unused]] CspVarInt_10:
	{
		if (CspOpeq_constraint_store->empty()) goto CspVarInt_11;
		if (CspVarInt_constraint_store->empty()) goto CspVarInt_11;
		auto& IdX = std::get<1>(c_args);
		auto& X = std::get<2>(c_args);
		auto& XDom = std::get<3>(c_args);
		auto it10_0 = CspOpeq_constraint_store->template begin<0>(IdX,X);
		while ( !it10_0.at_end() ) {
			auto IdY(std::get<3>(*it10_0));
			auto Y(std::get<4>(*it10_0));
			auto it10_1 = CspVarInt_constraint_store->template begin<0>(IdY,Y);
			while ( !it10_1.at_end() ) {
				auto YDom(std::get<3>(*it10_1));
				// Begin guard
				if (
					( std::get<0>(*it10_1) != std::get<0>(c_args) )
				) {
					// Check history
					if (_history.rule_9->check( {{std::get<0>(c_args),std::get<0>(*it10_0),std::get<0>(*it10_1)}} )) {
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
						if ((X %= Y) == chr::ES_CHR::FAILURE) return chr::ES_CHR::FAILURE;
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
	// CspVarInt_11 <=> Rule eq_var_var, active constraint CspVarInt( IdY, Y, YDom ), occurrence 12
	[[maybe_unused]] CspVarInt_11:
	{
		if (CspOpeq_constraint_store->empty()) goto CspVarInt_store;
		if (CspVarInt_constraint_store->empty()) goto CspVarInt_store;
		auto& IdY = std::get<1>(c_args);
		auto& Y = std::get<2>(c_args);
		auto& YDom = std::get<3>(c_args);
		auto it11_0 = CspOpeq_constraint_store->template begin<1>(IdY,Y);
		while ( !it11_0.at_end() ) {
			auto IdX(std::get<1>(*it11_0));
			auto X(std::get<2>(*it11_0));
			auto it11_1 = CspVarInt_constraint_store->template begin<0>(IdX,X);
			while ( !it11_1.at_end() ) {
				auto XDom(std::get<3>(*it11_1));
				// Begin guard
				if (
					( std::get<0>(*it11_1) != std::get<0>(c_args) )
				) {
					// Check history
					if (_history.rule_9->check( {{std::get<0>(c_args),std::get<0>(*it11_0),std::get<0>(*it11_1)}} )) {
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
						if ((X %= Y) == chr::ES_CHR::FAILURE) return chr::ES_CHR::FAILURE;
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
chr::ES_CHR MagicSquare_03::do_CspVarIntDec(typename CspVarIntDec::Type c_args, typename CspVarIntDec::Constraint_store_t::iterator c_it) {
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
chr::ES_CHR MagicSquare_03::do_labelling(typename labelling::Type c_args) {
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
//----------------------- START INCLUDE HEADER ---------------------

int main(int argc, const char *argv[]) {
    auto space = MagicSquare_03::create();
chr::Logical_var<int> X[9];
chr::Logical_var_mutable<interval> Dom[9];

Dom[0] = interval(1,9);
space->CspVarIntDec(0, string("x[0][0]"), X[0], Dom[0]);
Dom[1] = interval(1,9);
space->CspVarIntDec(1, string("x[0][1]"), X[1], Dom[1]);
Dom[2] = interval(1,9);
space->CspVarIntDec(2, string("x[0][2]"), X[2], Dom[2]);
Dom[3] = interval(1,9);
space->CspVarIntDec(3, string("x[1][0]"), X[3], Dom[3]);
Dom[4] = interval(1,9);
space->CspVarIntDec(4, string("x[1][1]"), X[4], Dom[4]);
Dom[5] = interval(1,9);
space->CspVarIntDec(5, string("x[1][2]"), X[5], Dom[5]);
Dom[6] = interval(1,9);
space->CspVarIntDec(6, string("x[2][0]"), X[6], Dom[6]);
Dom[7] = interval(1,9);
space->CspVarIntDec(7, string("x[2][1]"), X[7], Dom[7]);
Dom[8] = interval(1,9);
space->CspVarIntDec(8, string("x[2][2]"), X[8], Dom[8]);

CHR_RUN(alldiff_post(*space, {X[0], X[1], X[2], X[3], X[4], X[5], X[6], X[7], X[8]}, {0, 1, 2, 3, 4, 5, 6, 7, 8});
linear_post(*space, {X[0], X[1], X[2]}, {0, 1, 2}, 15);
linear_post(*space, {X[3], X[4], X[5]}, {3, 4, 5}, 15);
linear_post(*space, {X[6], X[7], X[8]}, {6, 7, 8}, 15);
linear_post(*space, {X[0], X[3], X[6]}, {0, 3, 6}, 15);
linear_post(*space, {X[1], X[4], X[7]}, {1, 4, 7}, 15);
linear_post(*space, {X[2], X[5], X[8]}, {2, 5, 8}, 15);
linear_post(*space, {X[0], X[4], X[8]}, {0, 4, 8}, 15);
linear_post(*space, {X[2], X[4], X[6]}, {2, 4, 6}, 15);
); 
CHR_RUN(space->labelling(0);); 
chr::Statistics::print(std::cout);
return 0;
}
//----------------------- END INCLUDE HEADER ---------------------
