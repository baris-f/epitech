/*
** Coconut.h for ls in /home/baris_f/rendu/tek2/cpp_d14m/ex01
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Tue Jan 17 16:07:24 2017 baris_f
** Last update Tue Jan 17 16:14:12 2017 baris_f
*/

#ifndef COCONUT_H_
# define COCONUT_H_

# include "Fruit.h"

class Coconut : public Fruit
{
 public:
  Coconut();
  ~Coconut();
  virtual std::string const &	getName() const;
};

#endif /* COCONUT_H_ */
