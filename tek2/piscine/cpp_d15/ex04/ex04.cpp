//
// ex04.cpp for tester in /home/baris_f/rendu/tek2/cpp_d15/ex04
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Wed Jan 18 22:12:24 2017 baris_f
// Last update Thu Jan 19 09:23:10 2017 baris_f
//

#include "ex04.hpp"

template<typename t>
bool    Tester<t>::equal(const t & a, const t & b)
{
  if (a == b)
    return (true);
  return (false);
}


template<typename t>
bool  equal(const t & a, const t & b)
{
  if (a == b)
    return (true);
  return (false);
}

template bool	Tester<int>::equal(const int &, const int &);
template bool	Tester<float>::equal(const float &, const float &);
template bool	Tester<double>::equal(const double &, const double &);
template bool	Tester<std::string>::equal(const std::string &, const std::string &);

template bool	equal<int>(const int &, const int &);
template bool	equal<float>(const float &, const float &);
template bool	equal<double>(const double &, const double &);
template bool	equal<std::string>(const std::string &, const std::string &);
