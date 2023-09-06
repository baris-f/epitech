open Contact
open Agenda

let affcontact con =
  print_endline con.fname;;

let obj = [{fname="4"; lname="baris"; age=5; email="caca@caca.fr"; phone="0632345678";}];;
let obj = Agenda.addContact obj ("3", "toussaint", 5, "caca@caca.fr", "0612345679");;
let obj = Agenda.addContact obj ("2", "pdt", 8, "caca@caca.fr", "0612345679");;
let obj = Agenda.addContact obj ("1", "konar", 4, "c@ca.fr", "0123456789");;
print_int (Agenda.getContactId obj Age "5");;
List.iter affcontact obj;;
Agenda.removeContact obj 1;;
List.iter affcontact obj;;
Agenda.removeContact obj 1;;
List.iter affcontact obj;;
Agenda.removeContact obj 1;;
Agenda.removeContact obj 1;;

print_int (Agenda.getContactId obj Age "5");;

