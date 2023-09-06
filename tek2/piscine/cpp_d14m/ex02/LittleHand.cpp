//
// LittleHand.cpp for ls in /home/baris_f/rendu/tek2/cpp_d14m/ex01
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Tue Jan 17 16:07:55 2017 baris_f
// Last update Tue Jan 17 16:07:55 2017 baris_f
//


#include "LittleHand.h"

LittleHand::LittleHand()
{
}

LittleHand::~LittleHand()
{
}

void		LittleHand::sortFruitBox(FruitBox &unsorted, FruitBox &lemons,
					 FruitBox &bananas, FruitBox &limes)
{
  int		count;
  Fruit		*fruit;
  Lemon		*lemon;
  Banana	*banana;
  Lime		*lime;

  count = unsorted.nbFruits();
  while (count-- > 0)
    {
      fruit = unsorted.pickFruit();
      if ((lemon = dynamic_cast<Lemon *>(fruit)) != NULL)
	lemons.putFruit(lemon);
      else if ((banana = dynamic_cast<Banana *>(fruit)) != NULL)
	bananas.putFruit(banana);
      else if ((lime = dynamic_cast<Lime *>(fruit)) != NULL)
	limes.putFruit(lime);
      std::cout << count << std::endl;
    }
}

FruitBox * const	*LittleHand::organizeCoconut(Coconut const * const * coconuts_packet)
{
  int			i;
  int			j;
  int			count;
  FruitBox		**boxes;

  i = 0;
  j = 0;
  count = 0;
  while (coconuts_packet[count] != NULL)
    count++;
  count = count / 6 + (count % 6 != 0);
  boxes = new FruitBox *[count + 1];
  boxes[count] = 0;
  while (i < count)
    {
      boxes[i] = new FruitBox(6);
      while (coconuts_packet[j] != NULL && boxes[i]->putFruit((Fruit *)coconuts_packet[j]))
	j++;
      i++;
    }
  return (boxes);
}
