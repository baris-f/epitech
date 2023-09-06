//
// main.cpp for plazza in /home/baris_f/rendu/tek2/cpp_plazza/baris
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Wed Apr 26 12:32:19 2017 baris_f
// Last update Sat Apr 29 15:06:34 2017 baris_f
//

#include "Parse.hpp"
#include "Tasker.hpp"

int main(int ac, char **av)
{
  int nbThread;
  std::string line;
  Parse parser;
  Tasker tasker;

  if (ac != 2 || !av[1] || (nbThread = std::atoi(av[1])) <= 0)
    nbThread = 1;
  tasker.init(nbThread);
  while (std::getline(std::cin, line))
  {
    parser.cut(line);
    // parser.affSerials();
    parser.cleanSerials();
  }
  return (0);
}
