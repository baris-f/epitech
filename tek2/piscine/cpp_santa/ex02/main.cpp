//
// main.cpp for  in /home/grandm_a/cpp_d10/cpp_santa/ex1
//
// Made by grandm_a
// Login   <corentin.grandmaire@epitech.eu>
//
// Started on  Sat Jan 14 02:12:20 2017 grandm_a
// Last update Sun Jan 15 02:03:46 2017 baris_f
//

#include "Toy.hh"
#include "Teddy.hh"
#include "LittlePony.hh"
#include "Object.hh"
#include "ConveyorBeltPePeNoel.hh"


Object **MyUnitTests()
{
  Object **tests;

  tests = new Object*[2];
  tests[0] = new Teddy("bisounours");
  tests[1] = new LittlePony("gay pony");

  return (tests);
}

int	main()
{
  Object **tab = MyUnitTests();

  std::cout << *tab[0] << *tab[1];
}
