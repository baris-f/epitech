type contact = {fname:string; lname:string; age:int; email:string; phone:string}

module type CONTACT =
  sig
      val print : contact -> unit
  end

module Contact : CONTACT =
  struct
    let print (a:contact) = print_endline a.fname
  end
