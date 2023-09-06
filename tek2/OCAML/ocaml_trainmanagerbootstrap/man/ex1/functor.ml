(******************************************************************************)
(*                                                                            *)
(*                       functor.ml in 5_functors                             *)
(*                       For Epitech's λ Knowledge Unit                       *)
(*                       Made by: David GIRON                                 *)
(*                       Modified by: David GIRON                             *)
(*                                                                            *)
(******************************************************************************)



(**   Functor prenant en parametre un module contenant une valeur "x" de type *)
(** entier et generant un module contenant une valeur "couple" de type int    *)
(** croix int.                                                                *)


(** La signature du module pris en parametre par le functor.                  *)
module type INTVAL =
  sig
    val x : int
  end


(** La signature du module cree par le functor.                               *)
module type INTCOUPLE =
  sig
    val couple : (int * int)
  end


(** La signature du functor.                                                  *)
module type MAKEINTCOUPLE = functor (IntVal : INTVAL) -> INTCOUPLE


(** Le functor.                                                               *)
module MakeIntCouple : MAKEINTCOUPLE = functor (IntVal : INTVAL) ->
  struct
    let couple = (IntVal.x, IntVal.x)
  end



(******************************************************************************)
