/*
** Lime.h for lime in /home/baris_f/rendu/tek2/cpp_d14m/ex01
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Tue Jan 17 16:09:42 2017 baris_f
** Last update Tue Jan 17 16:17:49 2017 baris_f
*/

#ifndef LIME_H_
# define LIME_H_

# include "Fruit.h"

class Lime : public Fruit
{
 public:
  Lime();
  ~Lime();
  virtual std::string const &	getName() const;
};

#endif /* LIME_H_ */
