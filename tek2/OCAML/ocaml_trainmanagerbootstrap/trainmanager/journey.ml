open Train

module type TRAIN =
  sig
    val name : string
    val speed : int
    val cities : string list
    val isDeserved : string -> bool
  end

module type JOURNEY =
  sig
    val id : string
    val cities : string list
    val dates : (int * int * int * int * int) list
    val calcDates : unit -> int
  end

module type MAKEJOURNEY = functor (Tr : TRAIN) -> JOURNEY

let cid = 1000;;

module MakeJourney = functor (Tr : TRAIN) ->
 struct
   let id = Tr.name ^ " " ^ (string_of_int (cid + 1));;
     cid = cid + 1;;
   let cities = []
   let dates = []
   let calcDates =
     let rec parse (chd::ctl) (dhd::dtl) =
       match ctl with
       | [] -> 0
       | hd :: tl -> if (CitiesInfo.getDist chd hd) = -1 then -1 else parse ctl dtl in
     parse cities (List.tl dates);;
 end
