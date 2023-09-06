#ifndef BANANA_H_
# define BANANA_H_

#include "Fruit.h"

class Banana : public Fruit {
 public :
  Banana();
  ~Banana();

  virtual std::string const &	getName() const;
};

#endif /* !BANANA_H_ */
