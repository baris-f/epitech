#ifndef FRUIT_H_
# define FRUIT_H_

#include <iostream>

class Fruit {
 public :
  Fruit(std::string, int);
  Fruit(const Fruit &);
  virtual ~Fruit();
  Fruit &	operator=(const Fruit &);
 protected :
  std::string	_name;
  int		_vitamins;
 public :
  virtual std::string const &	getName() const = 0;
  int				getVitamins() const;
};

#endif /* !FRUIT_H_ */
