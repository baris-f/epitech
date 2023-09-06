(******************************************************************************)
(*                                                                            *)
(*                       main.ml in 5_functors                                *)
(*                       For Epitech's λ Knowledge Unit                       *)
(*                       Made by: David GIRON                                 *)
(*                       Modified by: David GIRON                             *)
(*                                                                            *)
(******************************************************************************)



let main () =
  let res = Functor.StringSerialize.serialize "coucou" in
    print_endline (Functor.StringSerialize.unserialize res)



(******************************************************************************)
let _ = main ()
