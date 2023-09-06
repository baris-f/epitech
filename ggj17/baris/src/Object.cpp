#include "Object.hpp"

Object::Object(sf::Texture* text, const std::string type)
  : _type(type)
{
  if (text)
    _sprite = new sf::Sprite(*text);
  else
    _sprite  = NULL;
}

sf::Vector2f	Object::getPos() const
{
  return _sprite->getPosition();
}

sf::FloatRect	Object::getRekt() const
{
  return _sprite->getGlobalBounds();
}

void	Object::setPos(float x, float y)
{
  _sprite->setPosition(x, y);
}

void	Object::setPos(const sf::Vector2f& pos)
{
  _sprite->setPosition(pos.x, pos.y);
}

std::string	Object::getType() const { return (_type);}
sf::Sprite*	Object::getSprite() const { return (_sprite);}
