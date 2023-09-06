#include "Unit.hpp"

Unit::Unit(sf::Texture* text, const std::string type, const sf::Vector2f& pos)
  : Entity(text, type, pos)
{
  setPos(pos);
}

Unit::Unit(sf::Texture* text, const std::string type, float x, float y)
  : Entity(text, type, x, y)
{
  setPos(x, y);
}
