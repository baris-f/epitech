module type TRAIN =
  sig
    val name : string
    val speed : int
    val cities : string list
    val isDeserved : string -> bool
  end

module type CITIESINFO =
  sig
    val dist : (string * string * int) list
    val getDist : string -> string -> int
  end

let equal str str2 =
  if (String.compare str str2) = 0 then true else false

let fst (a, b, c) = a
let snd (a, b, c) = b
let thr (a, b, c) = c

module CitiesInfo : CITIESINFO =
  struct
    let dist = [("Paris", "Lyon", 427) ;("Dijon", "Lyon", 192) ;("Paris", "Lille", 225) ; ("Paris", "Nancy", 327) ; ("Dijon", "Nancy", 226) ; ("Brest", "Rennes", 248) ; ("Lille", "London", 269) ; ("Liege", "Cologne", 118) ; ("Le Mans", "Paris", 201) ; ("Cologne", "Essen", 81) ; ("Lyon", "Marseille", 325) ; ("Brussels", "Liege", 104) ;("Paris", "Le Havre", 230) ; ("Rennes", "Le Mans", 163) ; ("Le Mans", "Nantes", 183) ; ("Paris", "Bordeaux", 568) ; ("Lille", "Brussels", 106) ; ("Nancy", "Strasbourg", 149) ; ("Paris", "Strasbourg", 449) ; ("Dijon", "Strasbourg", 309); ("Toulouse", "Bordeaux", 256) ; ("Brussels", "Amsterdam", 211) ; ("Montpellier", "Toulouse", 248) ; ("Marseille", "Montpellier", 176)]
    let getDist city city2 =
      let rec getd city city2 (l:(string * string * int) list) =
        match l with
        | [] -> -1
        | hd :: tl -> if ((equal city (fst hd)) && (equal city2 (snd hd)))
                         || ((equal city (snd hd)) && (equal city2 (fst hd)))
                      then thr hd else getd city city2 tl in
      getd city city2 dist
  end

module TGV : TRAIN =
  struct
    let name = "TGV"
    let speed = 230
    let cities = ["Brest" ; "Le Havre" ; "Lille" ; "Paris" ; "Strasbourg" ; "Nancy" ; "Dijon" ; "Lyon" ; "Nice" ; "Marseille" ; "Montpellier" ; "Perpignan" ; "Bordeaux" ; "Nantes" ; "Avignon" ; "Rennes" ; "Biarritz" ; "Toulouse" ; "Le Mans"]
    let isDeserved (city:string) =
      let rec des city (cities:string list) =
        match cities with
        | [] -> false
        | hd :: tl -> if equal hd city then true else des city tl in
      des city cities;;
  end

module Thalys : TRAIN =
  struct
    let name = "Thalys"
    let speed = 210
    let cities = ["Paris" ; "Lille" ; "Liege" ; "Brussels" ; "Amsterdam" ; "Cologne" ; "Essen"]
    let isDeserved (city:string) =
      let rec des city (cities:string list) =
        match cities with
        | [] -> false
        | hd :: tl -> if equal hd city then true else des city tl in
      des city cities;;
  end

module Eurostar : TRAIN =
  struct
    let name = "Eurostar"
    let speed = 160
    let cities = ["Paris" ; "London" ; "Brussels" ; "Lille"]
    let isDeserved (city:string) =
      let rec des city (cities:string list) =
        match cities with
        | [] -> false
        | hd :: tl -> if equal hd city then true else des city tl in
      des city cities;;
  end;;
