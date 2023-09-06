#ifndef UNI
#define UNI

#include "Entity.hpp"

class Data;
class Object;

class	Unit : public Entity
{
public:
  Unit(sf::Texture*, const std::string, float, float);
  Unit(sf::Texture*, const std::string, const sf::Vector2f&);
  ~Unit(){};
};

#endif
