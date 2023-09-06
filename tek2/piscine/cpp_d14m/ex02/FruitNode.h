#ifndef FRUITNODE_H_
# define FRUITNODE_H_

#include "Fruit.h"

struct FruitNode {
  Fruit*	_fruit;
  FruitNode*	_next;
};

#endif /* !FRUITNODE_H_ */
