
module type VAL =
  sig
    val x : int
  end

module type COUPLE =
  sig
    val couple : (int * int)
  end

module type MAKECOUPLE = functor (Val : VAL) (Val2 : VAL) -> COUPLE

module MakeCouple : MAKECOUPLE = functor (Val : VAL) (Val2 : VAL) ->
  struct
    let couple = (Val.x, Val2.x)
  end

module type PROJECTION = functor (Couple : COUPLE) -> VAL

module Fst : PROJECTION = functor (Couple :  COUPLE) ->
  struct
    let x = let a, _ = Couple.couple in a
  end

module Snd : PROJECTION = functor (Couple :  COUPLE) ->
  struct
    let x = let _, b = Couple.couple in b
  end

module Val2 : VAL =
  struct
    let x = 2
  end

module Val4 : VAL =
  struct
    let x = 4
  end

module Couple1 = MakeCouple (Val2) (Val4)
module Val22 = Fst (Couple1);;
print_endline (string_of_int Val22.x)
