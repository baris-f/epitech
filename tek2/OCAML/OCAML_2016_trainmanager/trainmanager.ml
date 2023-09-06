open Train
open Journey

type jrlist = {mutable list : journey list}

module type TRAINMANAGER =
  sig
    val journeys : jrlist
    val addJourney : journey -> unit
    val deleteJourney : string -> unit
    val listJourney : unit -> unit
  end

module TrainManager : TRAINMANAGER =
  struct
    let journeys = {list = []}
    let addJourney jr =  (print_endline ("Trip created: " ^ jr.id); (journeys.list <- (jr :: journeys.list));())
    let deleteJourney id = (
      let rec del jrs id =
        match jrs with
        | [] -> jrs
        | (hd :: tl) -> if equal hd.did id then tl else (hd :: del tl id) in
      journeys.list <- del journeys.list id; ());;
    let listJourney () = (
        let rec affPath paths =
          match paths with
          | [] -> ()
          | hd :: tl -> let form i = if i < 10 then "0" ^ (string_of_int i) else (string_of_int i) in
                        let getd (d, m, y, h, min) = "(" ^ (form d) ^ "-" ^ (form m) ^ "-" ^ (form y) ^ "," ^ (form h) ^ ":" ^(form min) ^ ")" in
                        let fd = if hd.arrival = (0,0,0,0,0) then "(,)" else (getd hd.arrival) in
                        let ld = if hd.depart = (0,0,0,0,0) then "(,)" else (getd hd.depart) in
                        print_endline (hd.city ^ " " ^ fd ^ " " ^ ld); affPath tl in
    let rec aff jrs =
        match jrs with
        | [] -> ()
        | hd :: tl -> print_endline hd.id;affPath hd.paths ; aff tl in aff (List.rev journeys.list);())
  end
