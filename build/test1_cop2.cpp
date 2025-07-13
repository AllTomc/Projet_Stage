/*
From line 107 to 119
labelling<labelling( ( Id + 1 ) )> { CspVarIntDec<CspVarIntDec( Id, _, _, Dom )> } --> labelling<labelling( ( Id + 1 ) )>, built-in<begin(  )>
CspOple<CspOple( IdX, X, IdY, Y )> { CspVarInt<CspVarInt( IdY, Y, YDom )> } --> built-in<le( X, YDom )>
CspOpeq<CspOpeq( IdX, X, IdY, Y )> { CspVarInt<CspVarInt( IdX, X, XDom )> } --> built-in<YDom>
CspOpplus<CspOpplus( IdX, X, IdY, Y, IdZ, Z )> { CspVarInt<CspVarInt( IdX, X, XDom )> } --> built-in<plus_boundConsistency( XDom, YDom, ZDom )>
CspTmpInt<CspTmpInt( I, X, Dom )> --> CspVarInt<CspVarInt( I, X, Dom )>
CspVarIntDec<CspVarIntDec( Id, _, X, Dom )> { labelling<labelling( Id )> } --> labelling<labelling( ( Id + 1 ) )>, built-in<begin(  )>, CspVarInt<CspVarInt( Id, X, Dom )>
CspVarInt<CspVarInt( _, X, XDom )> { CspOple<CspOple( IdX, X, IdY, Y )>, CspOpeq<CspOpeq( IdX, X, IdY, Y )>, CspOpplus<CspOpplus( IdX, X, IdY, Y, IdZ, Z )>, CspVarInt<CspVarInt( IdY, Y, YDom )> } --> built-in<( ( *XDom ) . val(  ) )>

(constraint) CspVarIntDec( ( +int ), ( +string ), ( ?int ), ( -interval ) ), indexes: { <0> }
(constraint) CspVarInt( ( +int ), ( ?int ), ( -interval ) ), indexes: { <0,1> }
(constraint) CspTmpInt( ( +int ), ( ?int ), ( -interval ) )
(constraint) CspOpeq( ( +int ), ( ?int ), ( +int ), ( ?int ) ), indexes: { <0,1>, <2,3> }
(constraint) CspOple( ( +int ), ( ?int ), ( +int ), ( ?int ) ), indexes: { <2,3> }
(constraint) CspOpplus( ( +int ), ( ?int ), ( +int ), ( ?int ), ( +int ), ( ?int ) ), indexes: { <0,1>, <2,3>, <4,5> }
(constraint) ##labelling( ( +int ) ), indexes: { <0> }
(rule) CspVarInt( _, _, Dom ) ==> ( ( *Dom ) . empty(  ) ) | failure ;;
(rule) CspVarInt( _, X, XDom ) ==> ( ( *XDom ) . singleton(  ) ) | X %= ( ( *XDom ) . val(  ) ) ;;
(rule) CspVarInt( _, Val, Dom ) ==> ( Val . ground(  ) ) | maj_dom( Dom, ( *Val ) ) ;;
(rule) CspVarIntDec( Id, _, X, Dom ) ==> CspVarInt( Id, X, Dom ) ;;
(rule) CspTmpInt( I, X, Dom ) ==> CspVarInt( I, X, Dom ) ;;
(rule) plus @ CspVarInt( IdX, X, XDom ), CspVarInt( IdY, Y, YDom ), CspVarInt( IdZ, Z, ZDom ), CspOpplus( IdX, X, IdY, Y, IdZ, Z ) =>> ( Solvint :: plus_boundConsistency( XDom, YDom, ZDom ) ) ;;
(rule) eq_var_var @ CspVarInt( IdX, X, XDom ), CspVarInt( IdY, Y, YDom ), CspOpeq( IdX, X, IdY, Y ) ==> ( XDom %= YDom, X %= Y ) ;;
(rule) le_cste_var @ CspVarInt( IdY, Y, YDom ), CspOple( IdX, X, IdY, Y ) ==> ( Solvint :: le( X, YDom ) ) ;;
(rule) CspVarIntDec( Id, _, _, Dom ) \ labelling( Id ) <=> ( __it_i = ( ( *Dom ) . begin(  ) ), __it_end_i = ( ( *Dom ) . end(  ) ), __local_success__3 = false, behavior( ( __local_success__3 || ( __it_i == __it_end_i ) ), __local_success__3 = true, ( ++__it_i ), __local_success__3, , , ( i = ( *__it_i ), set_eq( Dom, i ), labelling( ( Id + 1 ) ) )) ) ;;
(rule) labelling( Id ) <=> print_store( ( *this ) ) ;;
(occ rule) eq_var_var @ [+CspOpeq( IdX, X, IdY, Y )#0][+CspVarInt( IdX, X, XDom )<idx#0>, +CspVarInt( IdY, Y, YDom )<idx#0>] --> ( XDom %= YDom, X %= Y ) ;;
(occ rule) le_cste_var @ [+CspOple( IdX, X, IdY, Y )#0][+CspVarInt( IdY, Y, YDom )<idx#0>] --> ( Solvint :: le( X, YDom ) ) ;;
(occ rule) plus @ [+CspOpplus( IdX, X, IdY, Y, IdZ, Z )#0#no_history][+CspVarInt( IdX, X, XDom )<idx#0>#no_history, +CspVarInt( IdY, Y, YDom )<idx#0>#no_history, +CspVarInt( IdZ, Z, ZDom )<idx#0>#no_history] --> ( Solvint :: plus_boundConsistency( XDom, YDom, ZDom ) ) ;;
(occ rule) [+CspTmpInt( I, X, Dom )#0][] --> CspVarInt( I, X, Dom ) ;;
(occ rule) [+CspVarInt( _, _, Dom )#0][( ( *Dom ) . empty(  ) )] --> failure ;;
(occ rule) [+CspVarInt( _, X, XDom )#1][( ( *XDom ) . singleton(  ) )] --> X %= ( ( *XDom ) . val(  ) ) ;;
(occ rule) [+CspVarInt( _, Val, Dom )#2][( Val . ground(  ) )] --> maj_dom( Dom, ( *Val ) ) ;;
(occ rule) plus @ [+CspVarInt( IdX, X, XDom )#3#no_history][+CspOpplus( IdX, X, IdY, Y, IdZ, Z )<idx#0>#no_history, +CspVarInt( IdZ, Z, ZDom )<idx#0>#no_history, +CspVarInt( IdY, Y, YDom )<idx#0>#no_history] --> ( Solvint :: plus_boundConsistency( XDom, YDom, ZDom ) ) ;;
(occ rule) plus @ [+CspVarInt( IdY, Y, YDom )#4#no_history][+CspOpplus( IdX, X, IdY, Y, IdZ, Z )<idx#1>#no_history, +CspVarInt( IdZ, Z, ZDom )<idx#0>#no_history, +CspVarInt( IdX, X, XDom )<idx#0>#no_history] --> ( Solvint :: plus_boundConsistency( XDom, YDom, ZDom ) ) ;;
(occ rule) plus @ [+CspVarInt( IdZ, Z, ZDom )#5#no_history][+CspOpplus( IdX, X, IdY, Y, IdZ, Z )<idx#2>#no_history, +CspVarInt( IdY, Y, YDom )<idx#0>#no_history, +CspVarInt( IdX, X, XDom )<idx#0>#no_history] --> ( Solvint :: plus_boundConsistency( XDom, YDom, ZDom ) ) ;;
(occ rule) eq_var_var @ [+CspVarInt( IdX, X, XDom )#6][+CspOpeq( IdX, X, IdY, Y )<idx#0>, +CspVarInt( IdY, Y, YDom )<idx#0>] --> ( XDom %= YDom, X %= Y ) ;;
(occ rule) eq_var_var @ [+CspVarInt( IdY, Y, YDom )#7][+CspOpeq( IdX, X, IdY, Y )<idx#1>, +CspVarInt( IdX, X, XDom )<idx#0>] --> ( XDom %= YDom, X %= Y ) ;;
(occ rule) le_cste_var @ [+CspVarInt( IdY, Y, YDom )#8][+CspOple( IdX, X, IdY, Y )<idx#0>] --> ( Solvint :: le( X, YDom ) ) ;;
(occ rule) [+CspVarIntDec( Id, _, X, Dom )#0][] --> CspVarInt( Id, X, Dom ) ;;
(occ rule) [-labelling( Id )#0][+CspVarIntDec( Id, _, _, Dom )<idx#0>] --> ( __it_i = ( ( *Dom ) . begin(  ) ), __it_end_i = ( ( *Dom ) . end(  ) ), __local_success__3 = false, behavior( ( __local_success__3 || ( __it_i == __it_end_i ) ), __local_success__3 = true, ( ++__it_i ), __local_success__3, , , ( i = ( *__it_i ), set_eq( Dom, i ), labelling( ( Id + 1 ) ) )) ) ;;
(occ rule) [-labelling( Id )#1][] --> print_store( ( *this ) ) ;;

(constraint store) CspVarIntDec( ( +int ), ( +string ), ( ?int ), ( -interval ) ), indexes: { <0> }
(constraint store) CspVarInt( ( +int ), ( ?int ), ( -interval ) ), indexes: { <0,1> }
(constraint store) CspTmpInt( ( +int ), ( ?int ), ( -interval ) )
(constraint store) CspOpeq( ( +int ), ( ?int ), ( +int ), ( ?int ) ), indexes: { <0,1>, <2,3> }
(constraint store) CspOple( ( +int ), ( ?int ), ( +int ), ( ?int ) ), indexes: { <2,3> }
(constraint store) CspOpplus( ( +int ), ( ?int ), ( +int ), ( ?int ), ( +int ), ( ?int ) ), indexes: { <0,1>, <2,3>, <4,5> }
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
// Rule le_cste_var, active constraint CspOple( IdX, X, IdY, Y ), occurrence 0
Begin CspOple_0
If empty store CspVarInt( IdY, Y, YDom ) Then goto CspOple_store
	Matching partner CspVarInt( IdY, Y, YDom ) with idx#0<IdY,Y>
		If history <CspOple( IdX, X, IdY, Y ),CspVarInt( IdY, Y, YDom )> Then
			store constraint CspOple( IdX, X, IdY, Y )
			( Solvint :: le( X, YDom ) )
			If not alived CspOple( IdX, X, IdY, Y ) Then goto next goal constraint
			goto next matching of CspVarInt( IdY, Y, YDom )
		End history
	End matching partner CspVarInt( IdY, Y, YDom )
End
// Fail through
Begin CspOple_store
	Store constraint CspOple
	Schedule constraint CspOple with variable index 1
	Schedule constraint CspOple with variable index 3
Goto next goal constraint
// Rule plus, active constraint CspOpplus( IdX, X, IdY, Y, IdZ, Z ), occurrence 0
Begin CspOpplus_0
If empty store CspVarInt( IdX, X, XDom ) Then goto CspOpplus_store
If empty store CspVarInt( IdY, Y, YDom ) Then goto CspOpplus_store
If empty store CspVarInt( IdZ, Z, ZDom ) Then goto CspOpplus_store
	Matching partner CspVarInt( IdX, X, XDom ) with idx#0<IdX,X>
		Matching partner CspVarInt( IdY, Y, YDom ) with idx#0<IdY,Y>
			If guard
				( CspVarInt( IdY, Y, YDom ) != CspVarInt( IdX, X, XDom ) )
			Then guard
				Matching partner CspVarInt( IdZ, Z, ZDom ) with idx#0<IdZ,Z>
					If guard
						( CspVarInt( IdZ, Z, ZDom ) != CspVarInt( IdY, Y, YDom ) )
						&& ( CspVarInt( IdZ, Z, ZDom ) != CspVarInt( IdX, X, XDom ) )
					Then guard
						store constraint CspOpplus( IdX, X, IdY, Y, IdZ, Z )
						( Solvint :: plus_boundConsistency( XDom, YDom, ZDom ) )
						If not alived CspOpplus( IdX, X, IdY, Y, IdZ, Z ) Then goto next goal constraint
						If not alived CspVarInt( IdX, X, XDom ) Then goto next matching of CspVarInt( IdX, X, XDom )
						If not alived CspVarInt( IdY, Y, YDom ) Then goto next matching of CspVarInt( IdY, Y, YDom )
						goto next matching of CspVarInt( IdZ, Z, ZDom )
					End guard
				End matching partner CspVarInt( IdZ, Z, ZDom )
			End guard
		End matching partner CspVarInt( IdY, Y, YDom )
	End matching partner CspVarInt( IdX, X, XDom )
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
// Rule plus, active constraint CspVarInt( IdX, X, XDom ), occurrence 3
Begin CspVarInt_3
If empty store CspOpplus( IdX, X, IdY, Y, IdZ, Z ) Then goto CspVarInt_4
If empty store CspVarInt( IdZ, Z, ZDom ) Then goto CspVarInt_4
If empty store CspVarInt( IdY, Y, YDom ) Then goto CspVarInt_4
	Matching partner CspOpplus( IdX, X, IdY, Y, IdZ, Z ) with idx#0<IdX,X>
		Matching partner CspVarInt( IdZ, Z, ZDom ) with idx#0<IdZ,Z>
			If guard
				( CspVarInt( IdZ, Z, ZDom ) != CspVarInt( IdX, X, XDom ) )
			Then guard
				Matching partner CspVarInt( IdY, Y, YDom ) with idx#0<IdY,Y>
					If guard
						( CspVarInt( IdY, Y, YDom ) != CspVarInt( IdZ, Z, ZDom ) )
						&& ( CspVarInt( IdY, Y, YDom ) != CspVarInt( IdX, X, XDom ) )
					Then guard
						store constraint CspVarInt( IdX, X, XDom )
						( Solvint :: plus_boundConsistency( XDom, YDom, ZDom ) )
						If not alived CspVarInt( IdX, X, XDom ) Then goto next goal constraint
						If not alived CspOpplus( IdX, X, IdY, Y, IdZ, Z ) Then goto next matching of CspOpplus( IdX, X, IdY, Y, IdZ, Z )
						If not alived CspVarInt( IdZ, Z, ZDom ) Then goto next matching of CspVarInt( IdZ, Z, ZDom )
						goto next matching of CspVarInt( IdY, Y, YDom )
					End guard
				End matching partner CspVarInt( IdY, Y, YDom )
			End guard
		End matching partner CspVarInt( IdZ, Z, ZDom )
	End matching partner CspOpplus( IdX, X, IdY, Y, IdZ, Z )
End
// Rule plus, active constraint CspVarInt( IdY, Y, YDom ), occurrence 4
Begin CspVarInt_4
If empty store CspOpplus( IdX, X, IdY, Y, IdZ, Z ) Then goto CspVarInt_5
If empty store CspVarInt( IdZ, Z, ZDom ) Then goto CspVarInt_5
If empty store CspVarInt( IdX, X, XDom ) Then goto CspVarInt_5
	Matching partner CspOpplus( IdX, X, IdY, Y, IdZ, Z ) with idx#1<IdY,Y>
		Matching partner CspVarInt( IdZ, Z, ZDom ) with idx#0<IdZ,Z>
			If guard
				( CspVarInt( IdZ, Z, ZDom ) != CspVarInt( IdY, Y, YDom ) )
			Then guard
				Matching partner CspVarInt( IdX, X, XDom ) with idx#0<IdX,X>
					If guard
						( CspVarInt( IdX, X, XDom ) != CspVarInt( IdZ, Z, ZDom ) )
						&& ( CspVarInt( IdX, X, XDom ) != CspVarInt( IdY, Y, YDom ) )
					Then guard
						store constraint CspVarInt( IdY, Y, YDom )
						( Solvint :: plus_boundConsistency( XDom, YDom, ZDom ) )
						If not alived CspVarInt( IdY, Y, YDom ) Then goto next goal constraint
						If not alived CspOpplus( IdX, X, IdY, Y, IdZ, Z ) Then goto next matching of CspOpplus( IdX, X, IdY, Y, IdZ, Z )
						If not alived CspVarInt( IdZ, Z, ZDom ) Then goto next matching of CspVarInt( IdZ, Z, ZDom )
						goto next matching of CspVarInt( IdX, X, XDom )
					End guard
				End matching partner CspVarInt( IdX, X, XDom )
			End guard
		End matching partner CspVarInt( IdZ, Z, ZDom )
	End matching partner CspOpplus( IdX, X, IdY, Y, IdZ, Z )
End
// Rule plus, active constraint CspVarInt( IdZ, Z, ZDom ), occurrence 5
Begin CspVarInt_5
If empty store CspOpplus( IdX, X, IdY, Y, IdZ, Z ) Then goto CspVarInt_6
If empty store CspVarInt( IdY, Y, YDom ) Then goto CspVarInt_6
If empty store CspVarInt( IdX, X, XDom ) Then goto CspVarInt_6
	Matching partner CspOpplus( IdX, X, IdY, Y, IdZ, Z ) with idx#2<IdZ,Z>
		Matching partner CspVarInt( IdY, Y, YDom ) with idx#0<IdY,Y>
			If guard
				( CspVarInt( IdY, Y, YDom ) != CspVarInt( IdZ, Z, ZDom ) )
			Then guard
				Matching partner CspVarInt( IdX, X, XDom ) with idx#0<IdX,X>
					If guard
						( CspVarInt( IdX, X, XDom ) != CspVarInt( IdY, Y, YDom ) )
						&& ( CspVarInt( IdX, X, XDom ) != CspVarInt( IdZ, Z, ZDom ) )
					Then guard
						store constraint CspVarInt( IdZ, Z, ZDom )
						( Solvint :: plus_boundConsistency( XDom, YDom, ZDom ) )
						If not alived CspVarInt( IdZ, Z, ZDom ) Then goto next goal constraint
						If not alived CspOpplus( IdX, X, IdY, Y, IdZ, Z ) Then goto next matching of CspOpplus( IdX, X, IdY, Y, IdZ, Z )
						If not alived CspVarInt( IdY, Y, YDom ) Then goto next matching of CspVarInt( IdY, Y, YDom )
						goto next matching of CspVarInt( IdX, X, XDom )
					End guard
				End matching partner CspVarInt( IdX, X, XDom )
			End guard
		End matching partner CspVarInt( IdY, Y, YDom )
	End matching partner CspOpplus( IdX, X, IdY, Y, IdZ, Z )
End
// Rule eq_var_var, active constraint CspVarInt( IdX, X, XDom ), occurrence 6
Begin CspVarInt_6
If empty store CspOpeq( IdX, X, IdY, Y ) Then goto CspVarInt_7
If empty store CspVarInt( IdY, Y, YDom ) Then goto CspVarInt_7
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
// Rule eq_var_var, active constraint CspVarInt( IdY, Y, YDom ), occurrence 7
Begin CspVarInt_7
If empty store CspOpeq( IdX, X, IdY, Y ) Then goto CspVarInt_8
If empty store CspVarInt( IdX, X, XDom ) Then goto CspVarInt_8
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
// Rule le_cste_var, active constraint CspVarInt( IdY, Y, YDom ), occurrence 8
Begin CspVarInt_8
If empty store CspOple( IdX, X, IdY, Y ) Then goto CspVarInt_store
	Matching partner CspOple( IdX, X, IdY, Y ) with idx#0<IdY,Y>
		If history <CspVarInt( IdY, Y, YDom ),CspOple( IdX, X, IdY, Y )> Then
			store constraint CspVarInt( IdY, Y, YDom )
			( Solvint :: le( X, YDom ) )
			If not alived CspVarInt( IdY, Y, YDom ) Then goto next goal constraint
			goto next matching of CspOple( IdX, X, IdY, Y )
		End history
	End matching partner CspOple( IdX, X, IdY, Y )
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


//----------------------- END INCLUDE HEADER ---------------------
#include <chrpp.hh>
class test1 {
	unsigned long int next_free_constraint_id = 1;
	//(constraint store) CspVarIntDec( ( +int ), ( +string ), ( ?int ), ( -interval ) ), indexes: { <0> }
public:
	struct CspVarIntDec {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var_ground< int >, chr::Logical_var_ground< string >, chr::Logical_var< int >, chr::Logical_var_mutable< interval > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0> >, true >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(test1* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
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
			chr::Weak_obj< test1 > _space;
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
			Constraint_callback(test1* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
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
			chr::Weak_obj< test1 > _space;
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
			Constraint_callback(test1* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
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
			chr::Weak_obj< test1 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename CspTmpInt::Constraint_store_t > CspTmpInt_constraint_store{ chr::make_shared< typename CspTmpInt::Constraint_store_t >("CspTmpInt") };
	//(constraint store) CspOpeq( ( +int ), ( ?int ), ( +int ), ( ?int ) ), indexes: { <0,1>, <2,3> }
public:
	struct CspOpeq {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var_ground< int >, chr::Logical_var< int >, chr::Logical_var_ground< int >, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,1>, chr::LNS::Index<2,3> >, true >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(test1* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
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
			chr::Weak_obj< test1 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename CspOpeq::Constraint_store_t > CspOpeq_constraint_store{ chr::make_shared< typename CspOpeq::Constraint_store_t >("CspOpeq") };
	//(constraint store) CspOple( ( +int ), ( ?int ), ( +int ), ( ?int ) ), indexes: { <2,3> }
public:
	struct CspOple {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var_ground< int >, chr::Logical_var< int >, chr::Logical_var_ground< int >, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<2,3> >, true >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(test1* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->CspOple_constraint_store && _space->CspOple_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_CspOple(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< test1 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename CspOple::Constraint_store_t > CspOple_constraint_store{ chr::make_shared< typename CspOple::Constraint_store_t >("CspOple") };
	//(constraint store) CspOpplus( ( +int ), ( ?int ), ( +int ), ( ?int ), ( +int ), ( ?int ) ), indexes: { <0,1>, <2,3>, <4,5> }
public:
	struct CspOpplus {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var_ground< int >, chr::Logical_var< int >, chr::Logical_var_ground< int >, chr::Logical_var< int >, chr::Logical_var_ground< int >, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,1>, chr::LNS::Index<2,3>, chr::LNS::Index<4,5> >, true >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(test1* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
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
			chr::Weak_obj< test1 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename CspOpplus::Constraint_store_t > CspOpplus_constraint_store{ chr::make_shared< typename CspOpplus::Constraint_store_t >("CspOpplus") };
	//(constraint store) labelling( ( +int ) ), indexes: { <0> }
public:
	struct labelling {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var_ground< int > >;
	};
public:
	unsigned int _ref_use_count  = 0;///< Count of shared references
	unsigned int _ref_weak_count = 0;///< Count of weak references + (#shared != 0)
	test1() { }
	~test1() {
		CspVarIntDec_constraint_store.release();
		CspVarInt_constraint_store.release();
		CspTmpInt_constraint_store.release();
		CspOpeq_constraint_store.release();
		CspOple_constraint_store.release();
		CspOpplus_constraint_store.release();
	}
	static chr::Shared_obj<test1> create() { return chr::make_shared<test1>(); }
	chr::Constraint_stores_iterator<chr::Shared_obj<typename CspVarIntDec::Constraint_store_t>,chr::Shared_obj<typename CspVarInt::Constraint_store_t>,chr::Shared_obj<typename CspTmpInt::Constraint_store_t>,chr::Shared_obj<typename CspOpeq::Constraint_store_t>,chr::Shared_obj<typename CspOple::Constraint_store_t>,chr::Shared_obj<typename CspOpplus::Constraint_store_t>> chr_store_begin() { return chr::Constraint_stores_iterator(CspVarIntDec_constraint_store,CspVarInt_constraint_store,CspTmpInt_constraint_store,CspOpeq_constraint_store,CspOple_constraint_store,CspOpplus_constraint_store); }
	typename CspVarIntDec::Constraint_store_t& get_CspVarIntDec_store() { return *CspVarIntDec_constraint_store; }
	typename CspVarInt::Constraint_store_t& get_CspVarInt_store() { return *CspVarInt_constraint_store; }
	typename CspTmpInt::Constraint_store_t& get_CspTmpInt_store() { return *CspTmpInt_constraint_store; }
	typename CspOpeq::Constraint_store_t& get_CspOpeq_store() { return *CspOpeq_constraint_store; }
	typename CspOple::Constraint_store_t& get_CspOple_store() { return *CspOple_constraint_store; }
	typename CspOpplus::Constraint_store_t& get_CspOpplus_store() { return *CspOpplus_constraint_store; }
	struct History {
		typename chr::Shared_obj< chr::History_dyn< 1 > > rule_0{ chr::make_shared< typename chr::History_dyn< 1 > >() };
		typename chr::Shared_obj< chr::History_dyn< 1 > > rule_1{ chr::make_shared< typename chr::History_dyn< 1 > >() };
		typename chr::Shared_obj< chr::History_dyn< 1 > > rule_2{ chr::make_shared< typename chr::History_dyn< 1 > >() };
		typename chr::Shared_obj< chr::History_dyn< 1 > > rule_3{ chr::make_shared< typename chr::History_dyn< 1 > >() };
		typename chr::Shared_obj< chr::History_dyn< 1 > > rule_4{ chr::make_shared< typename chr::History_dyn< 1 > >() };
		typename chr::Shared_obj< chr::History_dyn< 3 > > rule_6{ chr::make_shared< typename chr::History_dyn< 3 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_7{ chr::make_shared< typename chr::History_dyn< 2 > >() };
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
	chr::ES_CHR do_CspOpeq(typename CspOpeq::Type c_args, typename CspOpeq::Constraint_store_t::iterator c_it);
	chr::ES_CHR CspOpeq( chr::Logical_var_ground< int > arg0, chr::Logical_var< int > arg1, chr::Logical_var_ground< int > arg2, chr::Logical_var< int > arg3) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1, arg2, arg3);
		return do_CspOpeq(std::move(c_args), CspOpeq_constraint_store->end());
	}
	chr::ES_CHR do_CspOple(typename CspOple::Type c_args, typename CspOple::Constraint_store_t::iterator c_it);
	chr::ES_CHR CspOple( chr::Logical_var_ground< int > arg0, chr::Logical_var< int > arg1, chr::Logical_var_ground< int > arg2, chr::Logical_var< int > arg3) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1, arg2, arg3);
		return do_CspOple(std::move(c_args), CspOple_constraint_store->end());
	}
	chr::ES_CHR do_CspOpplus(typename CspOpplus::Type c_args, typename CspOpplus::Constraint_store_t::iterator c_it);
	chr::ES_CHR CspOpplus( chr::Logical_var_ground< int > arg0, chr::Logical_var< int > arg1, chr::Logical_var_ground< int > arg2, chr::Logical_var< int > arg3, chr::Logical_var_ground< int > arg4, chr::Logical_var< int > arg5) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1, arg2, arg3, arg4, arg5);
		return do_CspOpplus(std::move(c_args), CspOpplus_constraint_store->end());
	}
	chr::ES_CHR do_labelling(typename labelling::Type c_args);
	chr::ES_CHR labelling( chr::Logical_var_ground< int > arg0) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0);
		return do_labelling(std::move(c_args));
	}
};
chr::ES_CHR test1::do_CspOpeq(typename CspOpeq::Type c_args, typename CspOpeq::Constraint_store_t::iterator c_it) {
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
					if (_history.rule_6->check( {{std::get<0>(c_args),std::get<0>(*it0_0),std::get<0>(*it0_1)}} )) {
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
chr::ES_CHR test1::do_CspOple(typename CspOple::Type c_args, typename CspOple::Constraint_store_t::iterator c_it) {
	bool c_stored_before = !c_it.at_end();
	chr::Statistics::update_call_stack();
	[[maybe_unused]] CspOple_call:
	// ***************************************************
	// CspOple_0 <=> Rule le_cste_var, active constraint CspOple( IdX, X, IdY, Y ), occurrence 1
	[[maybe_unused]] CspOple_0:
	{
		if (CspVarInt_constraint_store->empty()) goto CspOple_store;
		auto& IdX = std::get<1>(c_args);
		auto& X = std::get<2>(c_args);
		auto& IdY = std::get<3>(c_args);
		auto& Y = std::get<4>(c_args);
		auto it0_0 = CspVarInt_constraint_store->template begin<0>(IdY,Y);
		while ( !it0_0.at_end() ) {
			auto YDom(std::get<3>(*it0_0));
			// Check history
			if (_history.rule_7->check( {{std::get<0>(c_args),std::get<0>(*it0_0)}} )) {
				it0_0.lock();
				if (!c_stored_before) {
					c_it = CspOple_constraint_store->add(c_args);
					auto ccb = chr::Shared_x_obj< chr::Logical_var_imp_observer_constraint >(new typename CspOple::Constraint_callback(this,c_it));
					chr::schedule_constraint_callback(std::get<2>(c_args), ccb);
					chr::schedule_constraint_callback(std::get<4>(c_args), ccb);
					c_stored_before = true;
				}
				c_it.lock();
				// Body
				chr::Statistics::inc_nb_rules();
				CHECK_ES( ( Solvint :: le( X, YDom ) ) );
				assert(c_stored_before);
				if (!c_it.alive()) {
					c_it.unlock();
					it0_0.unlock();
					return chr::ES_CHR::SUCCESS;
				}
				c_it.unlock();
				it0_0.next_and_unlock();
			} // End history
			else {
				++it0_0;
			}
		}
	}
	// Store constraint
	[[maybe_unused]] CspOple_store:
		if (!c_stored_before) {
			c_it = CspOple_constraint_store->add( c_args );
			auto ccb = chr::Shared_x_obj< chr::Logical_var_imp_observer_constraint >(new typename CspOple::Constraint_callback(this,c_it));
			chr::schedule_constraint_callback(std::get<2>(c_args), ccb);
			chr::schedule_constraint_callback(std::get<4>(c_args), ccb);
		}
	return chr::ES_CHR::SUCCESS;
}
chr::ES_CHR test1::do_CspOpplus(typename CspOpplus::Type c_args, typename CspOpplus::Constraint_store_t::iterator c_it) {
	bool c_stored_before = !c_it.at_end();
	chr::Statistics::update_call_stack();
	[[maybe_unused]] CspOpplus_call:
	// ***************************************************
	// CspOpplus_0 <=> Rule plus, active constraint CspOpplus( IdX, X, IdY, Y, IdZ, Z ), occurrence 1
	[[maybe_unused]] CspOpplus_0:
	{
		if (CspVarInt_constraint_store->empty()) goto CspOpplus_store;
		if (CspVarInt_constraint_store->empty()) goto CspOpplus_store;
		if (CspVarInt_constraint_store->empty()) goto CspOpplus_store;
		auto& IdX = std::get<1>(c_args);
		auto& X = std::get<2>(c_args);
		auto& IdY = std::get<3>(c_args);
		auto& Y = std::get<4>(c_args);
		auto& IdZ = std::get<5>(c_args);
		auto& Z = std::get<6>(c_args);
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
					auto it0_2 = CspVarInt_constraint_store->template begin<0>(IdZ,Z);
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
chr::ES_CHR test1::do_CspTmpInt(typename CspTmpInt::Type c_args, typename CspTmpInt::Constraint_store_t::iterator c_it) {
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
chr::ES_CHR test1::do_CspVarInt(typename CspVarInt::Type c_args, typename CspVarInt::Constraint_store_t::iterator c_it) {
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
	// CspVarInt_3 <=> Rule plus, active constraint CspVarInt( IdX, X, XDom ), occurrence 4
	[[maybe_unused]] CspVarInt_3:
	{
		if (CspOpplus_constraint_store->empty()) goto CspVarInt_4;
		if (CspVarInt_constraint_store->empty()) goto CspVarInt_4;
		if (CspVarInt_constraint_store->empty()) goto CspVarInt_4;
		auto& IdX = std::get<1>(c_args);
		auto& X = std::get<2>(c_args);
		auto& XDom = std::get<3>(c_args);
		auto it3_0 = CspOpplus_constraint_store->template begin<0>(IdX,X);
		while ( !it3_0.at_end() ) {
			auto IdY(std::get<3>(*it3_0));
			auto Y(std::get<4>(*it3_0));
			auto IdZ(std::get<5>(*it3_0));
			auto Z(std::get<6>(*it3_0));
			auto it3_1 = CspVarInt_constraint_store->template begin<0>(IdZ,Z);
			while ( !it3_1.at_end() ) {
				auto ZDom(std::get<3>(*it3_1));
				// Begin guard
				if (
					( std::get<0>(*it3_1) != std::get<0>(c_args) )
				) {
					auto it3_2 = CspVarInt_constraint_store->template begin<0>(IdY,Y);
					while ( !it3_2.at_end() ) {
						auto YDom(std::get<3>(*it3_2));
						// Begin guard
						if (
							( std::get<0>(*it3_2) != std::get<0>(c_args) )
							&& ( std::get<0>(*it3_2) != std::get<0>(*it3_1) )
						) {
							it3_0.lock();
							it3_1.lock();
							it3_2.lock();
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
								it3_0.unlock();
								it3_1.unlock();
								it3_2.unlock();
								return chr::ES_CHR::SUCCESS;
							}
							c_it.unlock();
							if (!it3_0.alive()) {
								it3_1.unlock();
								it3_2.unlock();
								it3_0.next_and_unlock();
								goto it3_0_next;
							}
							it3_0.unlock();
							if (!it3_1.alive()) {
								it3_2.unlock();
								it3_1.next_and_unlock();
								goto it3_1_next;
							}
							it3_1.unlock();
							it3_2.next_and_unlock();
							goto it3_2_next;
						} // End guard
						++it3_2;
						it3_2_next:;
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
	// CspVarInt_4 <=> Rule plus, active constraint CspVarInt( IdY, Y, YDom ), occurrence 5
	[[maybe_unused]] CspVarInt_4:
	{
		if (CspOpplus_constraint_store->empty()) goto CspVarInt_5;
		if (CspVarInt_constraint_store->empty()) goto CspVarInt_5;
		if (CspVarInt_constraint_store->empty()) goto CspVarInt_5;
		auto& IdY = std::get<1>(c_args);
		auto& Y = std::get<2>(c_args);
		auto& YDom = std::get<3>(c_args);
		auto it4_0 = CspOpplus_constraint_store->template begin<1>(IdY,Y);
		while ( !it4_0.at_end() ) {
			auto IdX(std::get<1>(*it4_0));
			auto X(std::get<2>(*it4_0));
			auto IdZ(std::get<5>(*it4_0));
			auto Z(std::get<6>(*it4_0));
			auto it4_1 = CspVarInt_constraint_store->template begin<0>(IdZ,Z);
			while ( !it4_1.at_end() ) {
				auto ZDom(std::get<3>(*it4_1));
				// Begin guard
				if (
					( std::get<0>(*it4_1) != std::get<0>(c_args) )
				) {
					auto it4_2 = CspVarInt_constraint_store->template begin<0>(IdX,X);
					while ( !it4_2.at_end() ) {
						auto XDom(std::get<3>(*it4_2));
						// Begin guard
						if (
							( std::get<0>(*it4_2) != std::get<0>(c_args) )
							&& ( std::get<0>(*it4_2) != std::get<0>(*it4_1) )
						) {
							it4_0.lock();
							it4_1.lock();
							it4_2.lock();
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
								it4_0.unlock();
								it4_1.unlock();
								it4_2.unlock();
								return chr::ES_CHR::SUCCESS;
							}
							c_it.unlock();
							if (!it4_0.alive()) {
								it4_1.unlock();
								it4_2.unlock();
								it4_0.next_and_unlock();
								goto it4_0_next;
							}
							it4_0.unlock();
							if (!it4_1.alive()) {
								it4_2.unlock();
								it4_1.next_and_unlock();
								goto it4_1_next;
							}
							it4_1.unlock();
							it4_2.next_and_unlock();
							goto it4_2_next;
						} // End guard
						++it4_2;
						it4_2_next:;
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
	// CspVarInt_5 <=> Rule plus, active constraint CspVarInt( IdZ, Z, ZDom ), occurrence 6
	[[maybe_unused]] CspVarInt_5:
	{
		if (CspOpplus_constraint_store->empty()) goto CspVarInt_6;
		if (CspVarInt_constraint_store->empty()) goto CspVarInt_6;
		if (CspVarInt_constraint_store->empty()) goto CspVarInt_6;
		auto& IdZ = std::get<1>(c_args);
		auto& Z = std::get<2>(c_args);
		auto& ZDom = std::get<3>(c_args);
		auto it5_0 = CspOpplus_constraint_store->template begin<2>(IdZ,Z);
		while ( !it5_0.at_end() ) {
			auto IdX(std::get<1>(*it5_0));
			auto X(std::get<2>(*it5_0));
			auto IdY(std::get<3>(*it5_0));
			auto Y(std::get<4>(*it5_0));
			auto it5_1 = CspVarInt_constraint_store->template begin<0>(IdY,Y);
			while ( !it5_1.at_end() ) {
				auto YDom(std::get<3>(*it5_1));
				// Begin guard
				if (
					( std::get<0>(*it5_1) != std::get<0>(c_args) )
				) {
					auto it5_2 = CspVarInt_constraint_store->template begin<0>(IdX,X);
					while ( !it5_2.at_end() ) {
						auto XDom(std::get<3>(*it5_2));
						// Begin guard
						if (
							( std::get<0>(*it5_2) != std::get<0>(c_args) )
							&& ( std::get<0>(*it5_2) != std::get<0>(*it5_1) )
						) {
							it5_0.lock();
							it5_1.lock();
							it5_2.lock();
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
								it5_0.unlock();
								it5_1.unlock();
								it5_2.unlock();
								return chr::ES_CHR::SUCCESS;
							}
							c_it.unlock();
							if (!it5_0.alive()) {
								it5_1.unlock();
								it5_2.unlock();
								it5_0.next_and_unlock();
								goto it5_0_next;
							}
							it5_0.unlock();
							if (!it5_1.alive()) {
								it5_2.unlock();
								it5_1.next_and_unlock();
								goto it5_1_next;
							}
							it5_1.unlock();
							it5_2.next_and_unlock();
							goto it5_2_next;
						} // End guard
						++it5_2;
						it5_2_next:;
					}
				} // End guard
				++it5_1;
				it5_1_next:;
			}
			++it5_0;
			it5_0_next:;
		}
	}
	// ***************************************************
	// CspVarInt_6 <=> Rule eq_var_var, active constraint CspVarInt( IdX, X, XDom ), occurrence 7
	[[maybe_unused]] CspVarInt_6:
	{
		if (CspOpeq_constraint_store->empty()) goto CspVarInt_7;
		if (CspVarInt_constraint_store->empty()) goto CspVarInt_7;
		auto& IdX = std::get<1>(c_args);
		auto& X = std::get<2>(c_args);
		auto& XDom = std::get<3>(c_args);
		auto it6_0 = CspOpeq_constraint_store->template begin<0>(IdX,X);
		while ( !it6_0.at_end() ) {
			auto IdY(std::get<3>(*it6_0));
			auto Y(std::get<4>(*it6_0));
			auto it6_1 = CspVarInt_constraint_store->template begin<0>(IdY,Y);
			while ( !it6_1.at_end() ) {
				auto YDom(std::get<3>(*it6_1));
				// Begin guard
				if (
					( std::get<0>(*it6_1) != std::get<0>(c_args) )
				) {
					// Check history
					if (_history.rule_6->check( {{std::get<0>(c_args),std::get<0>(*it6_0),std::get<0>(*it6_1)}} )) {
						it6_0.lock();
						it6_1.lock();
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
							it6_0.unlock();
							it6_1.unlock();
							return chr::ES_CHR::SUCCESS;
						}
						c_it.unlock();
						if (!it6_0.alive()) {
							it6_1.unlock();
							it6_0.next_and_unlock();
							goto it6_0_next;
						}
						it6_0.unlock();
						it6_1.next_and_unlock();
						goto it6_1_next;
					} // End history
					else {
						++it6_1;
						goto it6_1_next;
					}
				} // End guard
				++it6_1;
				it6_1_next:;
			}
			++it6_0;
			it6_0_next:;
		}
	}
	// ***************************************************
	// CspVarInt_7 <=> Rule eq_var_var, active constraint CspVarInt( IdY, Y, YDom ), occurrence 8
	[[maybe_unused]] CspVarInt_7:
	{
		if (CspOpeq_constraint_store->empty()) goto CspVarInt_8;
		if (CspVarInt_constraint_store->empty()) goto CspVarInt_8;
		auto& IdY = std::get<1>(c_args);
		auto& Y = std::get<2>(c_args);
		auto& YDom = std::get<3>(c_args);
		auto it7_0 = CspOpeq_constraint_store->template begin<1>(IdY,Y);
		while ( !it7_0.at_end() ) {
			auto IdX(std::get<1>(*it7_0));
			auto X(std::get<2>(*it7_0));
			auto it7_1 = CspVarInt_constraint_store->template begin<0>(IdX,X);
			while ( !it7_1.at_end() ) {
				auto XDom(std::get<3>(*it7_1));
				// Begin guard
				if (
					( std::get<0>(*it7_1) != std::get<0>(c_args) )
				) {
					// Check history
					if (_history.rule_6->check( {{std::get<0>(c_args),std::get<0>(*it7_0),std::get<0>(*it7_1)}} )) {
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
						if ((X %= Y) == chr::ES_CHR::FAILURE) return chr::ES_CHR::FAILURE;
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
	// CspVarInt_8 <=> Rule le_cste_var, active constraint CspVarInt( IdY, Y, YDom ), occurrence 9
	[[maybe_unused]] CspVarInt_8:
	{
		if (CspOple_constraint_store->empty()) goto CspVarInt_store;
		auto& IdY = std::get<1>(c_args);
		auto& Y = std::get<2>(c_args);
		auto& YDom = std::get<3>(c_args);
		auto it8_0 = CspOple_constraint_store->template begin<0>(IdY,Y);
		while ( !it8_0.at_end() ) {
			auto IdX(std::get<1>(*it8_0));
			auto X(std::get<2>(*it8_0));
			// Check history
			if (_history.rule_7->check( {{std::get<0>(c_args),std::get<0>(*it8_0)}} )) {
				it8_0.lock();
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
				CHECK_ES( ( Solvint :: le( X, YDom ) ) );
				assert(c_stored_before);
				if (!c_it.alive()) {
					c_it.unlock();
					it8_0.unlock();
					return chr::ES_CHR::SUCCESS;
				}
				c_it.unlock();
				it8_0.next_and_unlock();
			} // End history
			else {
				++it8_0;
			}
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
chr::ES_CHR test1::do_CspVarIntDec(typename CspVarIntDec::Type c_args, typename CspVarIntDec::Constraint_store_t::iterator c_it) {
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
chr::ES_CHR test1::do_labelling(typename labelling::Type c_args) {
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
auto space = test1::create();
chr::Logical_var<int> X[5];
chr::Logical_var_mutable<interval> Dom[5];
CHR_RUN(
Dom[0] = interval(1,5);
space->CspVarIntDec(0, string("x"), X[0], Dom[0]);
Dom[1] = interval(1,5);
space->CspVarIntDec(1, string("y"), X[1], Dom[1]);
Dom[2] = interval(2,10);
space->CspVarIntDec(2, string("z"), X[2], Dom[2]);

// TMP_3 = x + y
Dom[3] = interval(2,10); // domaine de x+y ∈ [2..10]
space->CspTmpInt(3, X[3], Dom[3]);

Dom[4] = interval(9,9); 
space->CspTmpInt(4, X[4], Dom[4]);

// z = TMP_3
space->CspOpeq(2, X[2], 3, X[3]);
// TMP_3 = x + y
space->CspOpplus(0, X[0], 1, X[1], 3, X[3]);
// z > 8 ↔ le(9, z)
space->CspOple(4, X[4], 2, X[2]);
    
);
//CHR_RUN(space->labelling(0);); 
chr::Statistics::print(std::cout);
print_store(*space);
return 0;
}
//----------------------- END INCLUDE HEADER ---------------------
