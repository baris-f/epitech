#ifndef CASERNE_HPP_
# define CASERNE_HPP_

#include "Building.hpp"
#include "Data.hpp"

class Caserne : public Building {
public:
  Caserne(sf::Texture*, const std::string);
  virtual ~Caserne(){}
  virtual void func();
  virtual void update();
  virtual void draw(sf::RenderWindow *);
};


#endif /* !BASE_HPP_ */
