(******************************************************************************)
(*                                                                            *)
(*                       main.ml in 5_functors                                *)
(*                       For Epitech's λ Knowledge Unit                       *)
(*                       Made by: David GIRON                                 *)
(*                       Modified by: David GIRON                             *)
(*                                                                            *)
(******************************************************************************)



let main () =
  print_endline (Functor.StringCouple.to_string ());
  print_endline (Functor.IntListCouple.to_string ())



(******************************************************************************)
let _ = main ()
