type 'a my_list = Item of ('a * 'a my_list) | Empty;;

let cons (data:'a) (list:'a my_list) = Item(data, list)

let lenght (list:'a my_list) =
    let rec lenght_rec n list =
    	match list with
	      | Empty -> n
	      | Item (_, next) -> lenght_rec (n + 1) next in
    lenght_rec 0 list

let hd (list:'a my_list) =
match list with
| Empty -> failwith "Empty list"
| Item (data, _) -> data

let tl (list:'a my_list) =
match list with
| Empty -> failwith "Empty list"
| Item (_, next) -> next

let nth (list:'a my_list) n =
if n > lenght list
then failwith "List too short"
else if n < 0
then failwith "Invalid argument"
else
let rec nth_rec i (list:'a my_list) =
if i = n
then hd list
else
nth_rec (i + 1) (tl list) in
nth_rec 0 list

let rev (list:'a my_list) =
match list with
| Empty -> Empty
| _ -> let rec rev_rec (list:'a my_list) (dest:'a my_list) =
       match list with
         | Empty -> dest
         | _ -> rev_rec (tl list) (cons (hd list) dest) in
    rev_rec list Empty

let rec rev_append (list:'a my_list) (dest:'a my_list) =
match list with
| Empty -> dest
| _ -> rev_append (tl list) (cons (hd list) dest)

let append (list:'a my_list) (dest:'a my_list) =
rev_append (rev list) dest

let rec flatten (list:('a my_list) my_list) =
match list with
| Empty -> Empty
| _ -> append (hd list) (flatten (tl list))

let rec iter (f:'a -> 'b) (list:'a my_list) =
match list with
| Empty -> ()
| _ -> begin
f (hd list);
iter (f) (tl list)
end;;

let rec map (f:'a -> 'b) (list:'a my_list) =
match list with
| Empty -> Empty
| _ -> cons (f (hd list)) (map (f) (tl list));;

let rec fold_left (f:'a -> 'b ->'a) (arg:'a) (list:'a my_list) =
match list with
| Empty -> arg
| _ -> f (fold_left f arg (tl list)) (hd list)

let rec for_all (f:'a -> bool) (list:'a my_list) =
match list with
| Empty -> true
| _ -> f (hd list) && for_all f (tl list);;

let rec exists (f:'a -> bool) (list:'a my_list) =
match list with
| Empty -> false
| _ -> f (hd list) || for_all f (tl list);;

let rec mem (arg:'a) (list:'a my_list) =
match list with
| Empty -> false
| _ -> if (hd list) = arg then true else mem arg (tl list)

let rec memq (arg:'a) (list:'a my_list) =
match list with
| Empty -> false
| _ -> if (hd list) == arg then true else memq arg (tl list)