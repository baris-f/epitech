open Train;;
open Journey;;

let split_on_char sep s =
  let r = ref [] in
  let j = ref (String.length s) in
  for i = String.length s - 1 downto 0 do
    if s.[i] = sep then begin
      r := String.sub s (i + 1) (!j - i - 1) :: !r;
      j := i
    end
  done;
  String.sub s 0 !j :: !r

let journeys = []

let rec main () =
  let line = split_on_char ' ' (read_line ()) in
  if List.length line != 5 then print_endline "wrong command"
  else ();(MakeJourney List.TGV) :: journeys;
  if equal (List.hd line) "stop" then () else main();;

main();;
print_int TGV.speed;;
print_endline "";;
