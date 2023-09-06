(******************************************************************************)
(*                                                                            *)
(*                       functor.ml in 5_functors                             *)
(*                       For Epitech's λ Knowledge Unit                       *)
(*                       Made by: David GIRON                                 *)
(*                       Modified by: David GIRON                             *)
(*                                                                            *)
(******************************************************************************)



(**   Functor prenant en parametre un module contenant une valeur "x" de type *)
(** t et generant un module contenant une valeur "couple" de type t croix t.  *)



(** La signature du module pris en parametre par le functor.                  *)
module type VAL =
  sig
    type t
    val x : t
    val to_string : unit -> string
  end


(** La signature du module cree par le functor.                               *)
module type COUPLE =
  sig
    type t
    val couple : (t * t)
    val to_string : unit -> string
  end


(** La signature du functor.                                                  *)
module type MAKECOUPLE = functor (Val : VAL) -> COUPLE


(** Le functor.                                                               *)
module MakeCouple : MAKECOUPLE = functor (Val : VAL) ->
  struct
    type t = Val.t
    let couple = (Val.x, Val.x)
    let to_string () = "("^(Val.to_string ())^", "^(Val.to_string ())^")"
  end


(** Module StringVal respectant la signature VAL.                             *)
module StringVal : VAL =
  struct
    type t = string
    let x = "cou"
    let to_string () = x
  end


(** Module IntListVal respectant la signature VAL.                            *)
module IntListVal : VAL =
  struct
    type t = int list
    let x = [1; 2; 3]
    let to_string () = String.concat " " (List.map string_of_int x)
  end


(** Application du module StringVal au functor et creation de StringCouple.   *)
module StringCouple = MakeCouple (StringVal)


(** Application du module IntListVal au functor et creation de IntListCouple. *)
module IntListCouple = MakeCouple (IntListVal)



(******************************************************************************)
