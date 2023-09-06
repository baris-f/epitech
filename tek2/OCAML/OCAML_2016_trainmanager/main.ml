open Train;;
open Journey;;
open Trainmanager;;

let split_on_char sep s = Str.split (Str.regexp sep) s;;
(*  let r = ref [] in
  let j = ref (String.length s) in
  for i = String.length s - 1 downto 0 do
    if s.[i] = sep then begin
      r := String.sub s (i + 1) (!j - i - 1) :: !r;
      j := i
    end
  done;
  String.sub s 0 !j :: !r *)

let handle line =
  match line with
  | "quit" :: _ -> exit 0
  | "list" :: _ -> TrainManager.listJourney ()
  | [func; train; date; h; citiesl] -> let module JInfo =
                                         struct
                                           let cities = split_on_char "," citiesl;;
                                           let date = let day = (split_on_char "-" date) in
                                                      let hour = (split_on_char ":" h) in
                                                      let getInt dat nb = (int_of_string (List.nth dat nb)) in
                                                      (getInt day 0, getInt day 1, getInt day 2, getInt hour 0, getInt hour 1);;
                                         end in let module JTgv = MakeJourney (TGV) (JInfo) in
                                                let module JThalys = MakeJourney (Thalys) (JInfo) in
                                                let module JEurostar = MakeJourney (Eurostar) (JInfo) in
                                                let module_ =
                                                  match train with
                                                  | "TGV" ->  (module JTgv : JOURNEY)
                                                  | "Thalys" -> (module JThalys : JOURNEY)
                                                  | "Eurostar" -> (module JEurostar : JOURNEY)
                                                  | _ -> exit 84 in
                                                let (module Tmp) = module_ in
                                                TrainManager.addJourney Tmp.info
  | ["delete"; id] -> TrainManager.deleteJourney id
  | _ -> ()

let rec main () =
  let input = read_line () in
  let tokens = Str.split (Str.regexp " ") input in
  handle tokens;
  main ();;

  (*Str.split (Str.regexp " ") "plop plip";;*)
  (*if (handle (split_on_char ' ' (read_line ()))) = false then main () else ();;*)

main();;

let affDate (a, b, c, d, e) =
  print_endline ((string_of_int a) ^ "-" ^ (string_of_int b) ^ "-" ^(string_of_int c) ^ "," ^ (string_of_int d) ^ ":" ^ (string_of_int e));;
