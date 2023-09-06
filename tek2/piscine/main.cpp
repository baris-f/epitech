//
// main.cpp for f in /home/baris_f/rendu/tek2/cpp_d17/ex00
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Fri Jan 20 10:00:55 2017 baris_f
// Last update Fri Jan 20 10:34:37 2017 baris_f
//

#include <iostream>
#include <algorithm>
#include <vector>
#include "find.hpp"

int main()
{
    std::vector<int> v(5, 3);

    std::cout << *do_find(v, 3) << std::endl;
}
