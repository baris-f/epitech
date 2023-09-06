//
// my_cat.cpp for  in /home/baris_f/rendu/tek2/cpp_d06/ex00
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Mon Jan  9 09:39:09 2017 baris_f
// Last update Mon Jan  9 11:20:42 2017 baris_f
//

#include <iostream>
#include <string>
#include <iomanip>

int	main()
{
  float	value;
  std::string	type;

  std::cin >> value;
  std::cin >> type;
  std::cout << std::right << std::setw (16) << std::fixed << std::setprecision(3);
  if (type == "Celsius")
    std::cout << (float)(value / (5.0 / 9.0) + 32) << std::setw (16) << "Fahrenheit" << std::endl;
  else if (type == "Fahrenheit")
    std::cout << (float)(5.0 / 9.0 * (value - 32))  << std::setw (16) << "Celsius" << std::endl;
  return (0);
}
