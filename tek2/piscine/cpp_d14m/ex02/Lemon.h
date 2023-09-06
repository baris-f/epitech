#ifndef LEMON_H_
# define LEMON_H_

#include "Fruit.h"

class Lemon : public Fruit {
 public :
  Lemon();
  ~Lemon();

  virtual std::string const &   getName() const;
};

#endif /* !LEMON_H_ */
