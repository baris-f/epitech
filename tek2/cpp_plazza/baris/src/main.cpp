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

int             main()
{
  std::string     line;
  Parse         parser;

  while (std::getline(std::cin, line))
    parser.cut(line);
  return (0);
}
