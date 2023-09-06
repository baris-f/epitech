#ifndef FRUITBOX_H_
# define FRUITBOX_H_

#include "Fruit.h"
#include "FruitNode.h"

class FruitBox {
 public :
  FruitBox(int size);
  ~FruitBox();

 private :
  FruitNode*	_head;
  int		_size;
  int		_msize;
 public :
  int		nbFruits();
  bool		putFruit(Fruit* f);
  Fruit*	pickFruit();
  FruitNode*	head();
  void		disp();
};

#endif /* !FRUITBOX_H_ */
