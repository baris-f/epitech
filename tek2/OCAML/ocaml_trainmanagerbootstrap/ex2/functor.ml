
module type EVALEXPR =
sig
  type expr =
    | Add of (expr * expr)
    | Mul of (expr * expr)
    | Value of int

  val eval : expr -> int
end


module EvalExpr : EVALEXPR =
struct
  type expr =
    | Add of (expr * expr)
    | Mul of (expr * expr)
    | Value of int

  let rec eval = function
    | Add (lhs, rhs) -> ( + ) (eval lhs) (eval rhs)
    | Mul (lhs, rhs) -> ( * ) (eval lhs) (eval rhs)
    | Value v -> v
end
