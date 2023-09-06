#include "Entity.hpp"

Entity::Entity(sf::Texture* text, const std::string type, const sf::Vector2f& pos)
  : Object(text, type), _life(0), _lvl(0)
{
  setPos(pos);
}

Entity::Entity(sf::Texture* text, const std::string type, float x, float y)
  : Object(text, type), _life(0), _lvl(0)
{
  setPos(x, y);
}

void	Entity::draw(sf::RenderWindow* window)
{
  window->draw(*_sprite);
}

void	Entity::update(Data *d)
{
  (void)d;
  sf::Vector2f	tmp(1, 0);
  setPos(getPos() + tmp);
}


void Entity::func(){
  sf::Vector2f  tmp(0, 10);
  setPos(getPos() + tmp);
}
