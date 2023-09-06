#ifndef BASE_HPP_
# define BASE_HPP_

#include "Building.hpp"
#include "Data.hpp"

class Base : public Building {
public:
  Base(sf::Texture*, const std::string);
  virtual ~Base(){}
  virtual void func();
  virtual void update();
  virtual void draw(sf::RenderWindow *);
};


#endif /* !BASE_HPP_ */
