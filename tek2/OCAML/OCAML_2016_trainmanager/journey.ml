open Train

module type TRAIN =
  sig
    val name : string
    val speed : int
    val cities : string list
    val isDeserved : string -> bool
  end

type path = {city:string; arrival:int*int*int*int*int; depart:int*int*int*int*int}
type journey = {id:string; did:string; paths:path list}

module type JOURNEY =
  sig
    val info : journey
  end

module type JOURNEYINFO =
  sig
    val cities : string list
    val date : (int * int * int * int * int)
  end

module type MAKEJOURNEY = functor (Tr : TRAIN) (JInfo : JOURNEYINFO) -> JOURNEY

let cid = ref 1000;;

let affDate (a, b, c, d, e) =
  print_endline ((string_of_int a) ^ "-" ^ (string_of_int b) ^ "-" ^(string_of_int c) ^ "," ^ (string_of_int d) ^ ":" ^ (string_of_int e));;

module MakeJourney = functor (Tr : TRAIN) (JInfo : JOURNEYINFO) ->
 struct
   let id = Tr.name ^ " " ^ (string_of_int !(cid));;
   let did = Tr.name ^ (string_of_int !(cid));;
   let calc dist (d, m, y, h, min) =
     let nmin = min + (60 * ((dist mod Tr.speed) * 1000) / Tr.speed) / 1000 in
     let nh = h + (dist / Tr.speed) + nmin / 60 in
     let nd = (d + nh / 24) in
     let nm = (m + nd / 30) in
     let ny = (y + nm / 12) in
     (nd mod 30, nm mod 12, ny, nh mod 24, nmin mod 60);;

   let dep (d, m, y, h, min) tl = if tl = [] then (0, 0, 0, 0, 0) else
     let nmin = min + 10 in
     let nh = h + nmin / 60 in
     let nd = (d + nh / 24) in
     let nm = (m + nd / 30) in
     let ny = (y + nm / 12) in
     (nd mod 30, nm mod 12, ny, nh mod 24, nmin mod 60);;

   let rec calcDates cities (d, m, y, h, min) (l:path list) =
     match cities  with
     | [] -> l
     | chd :: ctl -> match ctl with
                     | [] -> l
                     | hd :: tl -> if (CitiesInfo.getDist chd hd) = -1 then []
                                   else let ndate = (calc (CitiesInfo.getDist chd hd) (d, m, y, h, min)) in
                                        calcDates ctl (dep ndate tl) (l @ [{city=hd; arrival=ndate; depart=(dep ndate tl)}]);;

   let tmp =  (calcDates (List.tl JInfo.cities) JInfo.date []) ;;
   let paths = [{city=(List.hd JInfo.cities); arrival=(0, 0, 0, 0, 0); depart=JInfo.date}] @ (calcDates JInfo.cities JInfo.date []) ;;
   let info = {id = id; did =  did; paths = paths};;
     cid := !(cid) + 1;;
 end
