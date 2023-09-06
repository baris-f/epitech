open Contact

type field = All | Id | FirstName | LastName | Age | Email | Phone

module type AGENDA =
  sig
    val addContact : contact list -> string * string * int * string * string -> contact list;;
    val getContactId   : contact list -> field -> string -> int
    val removeContact  : contact list -> int -> contact list
    val printContacts  : contact list -> field -> string -> unit
  end

let equal str str2 =
  if (String.compare str str2) = 0 then true else false

let affContact con =
print_endline con.fname;;

module Agenda : AGENDA =
  struct
    let addContact (l:contact list) (data:string * string * int * string * string) =
      let z = function
        | a, b, c, d, e -> if c < 0 || c > 120 then failwith "Agenda.Add_Contact_With_Invalid_Data"
                           else
                             if String.length d < 5
                             || String.index d '@' = 0 || String.index d '@' >= String.length d - 3
                             || String.index d '.' <= 1 || String.index d '.' = String.length d - 1
                             then failwith "Agenda.Add_Contact_With_Invalid_Data"
                             else
                             if String.length (String.trim e) < 10 || String.index e '0' != 0
                             then failwith "Agenda.Add_Contact_With_Invalid_Data"
                             else
                             {fname= String.trim (String.capitalize a);
                              lname= String.trim (String.uppercase b);
                              age=c; email = d; phone = String.trim e}
      in (z data) :: l;;
      let getContactId (l:contact list) (f:field) (data:string) =
        let rec gcon (l:contact list) (f:field) (data:string) (idx:int) =
        match l with
        | [] -> -1
        | hd :: next -> match f with
                        | All -> if equal data hd.fname || equal data hd.lname || data = string_of_int hd.age || equal data hd.email || equal data hd.phone
                                 then idx else gcon next f data idx + 1
                        | Id -> if List.length l > int_of_string data then int_of_string data else -1
                        | FirstName -> if equal data hd.fname then idx else gcon next f data idx + 1
                        | LastName -> if equal data hd.lname then idx else gcon next f data idx + 1
                        | Age -> if int_of_string data = hd.age then idx else gcon next f data idx + 1
                        | Email -> if equal data hd.email then idx else gcon next f data idx + 1
                        | Phone -> if equal data hd.phone then idx else gcon next f data idx + 1
        in
        gcon l f data 0;;
      let removeContact (l:contact list) (id:int) =
        match l with
        | [] -> failwith "Remove_Impossible_On_An_Empty"
        | _ -> if id > (List.length l - 1) then failwith "Remove_Using_An_Invalid_Id" else
           let rec remo (l:contact list) (id:int) (cid:int) =
                 match l with
                 | [] -> l
                 | hd :: tl -> if id = cid then tl else remo tl id (cid + 1)
               in
               remo l id 0;;

        let replaceContacts list id data=
          let new_list = removeContact list id in
          addContact new_list data;;

        let printContacts (l:contact list) (f:field) (data:string) =
print_endline "coucou";;
  end
