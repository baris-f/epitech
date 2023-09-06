(******************************************************************************)
(*                                                                            *)
(*                   application_simple.ml in 5_functors                      *)
(*                   For Epitech's λ Knowledge Unit                           *)
(*                   Made by: David GIRON                                     *)
(*                   Modified by: David GIRON                                 *)
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


(** Module IntVal respectant la signature INTVAL.                             *)
module IntVal =
  struct
    let x = 10
  end


(** Application du module IntVal au functor et creation de IntCouple1.        *)
module IntCouple1 = MakeIntCouple (IntVal)


(** Application d'un module anonyme respectant la signature INTVAL au functor *)
(** et creation de IntCouple2.                                                *)
module IntCouple2 = MakeIntCouple (struct let x = 42 end)



(******************************************************************************)
