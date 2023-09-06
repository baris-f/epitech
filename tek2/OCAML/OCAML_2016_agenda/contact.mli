type contact = {fname:string; lname:string; age:int; email:string; phone:string}

module type CONTACT =
  sig
    val print : contact -> unit
  end

module Contact : CONTACT
