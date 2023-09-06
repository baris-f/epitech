(******************************************************************************)
(*                                                                            *)
(*                       functor.ml in 5_functors                             *)
(*                       For Epitech's λ Knowledge Unit                       *)
(*                       Made by: David GIRON                                 *)
(*                       Modified by: David GIRON                             *)
(*                                                                            *)
(******************************************************************************)



(**   Functor prenant en parametre un module serializable et generant un      *)
(** module le serialisant.                                                    *)



(** La signature du module pris en parametre par le functor.                  *)
module type VAL =
  sig
    type t
    val length : t -> int
  end


(** La signature du module cree par le functor.                               *)
module type SERIALIZE =
  sig
    type t_in
    type t_out
    val serialize : t_in -> t_out
    val unserialize : t_out -> t_in
  end


(** La signature du functor.                                                  *)
module type MAKESERIALIZE = functor (Val : VAL) -> SERIALIZE with type t_in = Val.t


(** Le functor.                                                               *)
module MakeSerialize : MAKESERIALIZE = functor (Val : VAL) ->
  struct
    type t_in = Val.t
    type t_out = (Val.t * int)
    let serialize v = (v, Val.length v)
    let unserialize (v, _) = v
  end


(** Application du module String au functor et creation de StringSerialize.   *)
module StringSerialize = MakeSerialize (String)



(******************************************************************************)
