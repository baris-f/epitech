//
// Order.cpp for plazza in /home/baris_f/rendu/tek2/cpp_plazza/baris
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Sat Apr 29 15:36:06 2017 baris_f
// Last update Sat Apr 29 15:57:43 2017 baris_f
//

#include "Order.hpp"

Order::Order(std::string nfile, Information norder){
  file = nfile;
  order = norder;
};

void    operator<<(std::string &ser, Order const &ord)
{
  ser = std::to_string(static_cast<int>(ord.getOrder())) + "|" + ord.getFile();
}
