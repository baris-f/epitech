/*
** LittleHand.h for little in /home/baris_f/rendu/tek2/cpp_d14m/ex01
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Tue Jan 17 16:11:17 2017 baris_f
** Last update Tue Jan 17 16:11:17 2017 baris_f
*/


#ifndef LITTLE_HAND_H_
# define LITTLE_HAND_H_

# include "FruitBox.h"
# include "Coconut.h"
# include "Lemon.h"
# include "Banana.h"
# include "Lime.h"

class LittleHand
{
 public:
  LittleHand();
  ~LittleHand();

 public:
  void sortFruitBox(FruitBox &, FruitBox &, FruitBox &, FruitBox &);
  static FruitBox * const * organizeCoconut(Coconut const * const *);
};

#endif /* LITTLE_HAND_H_ */
