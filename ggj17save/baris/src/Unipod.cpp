//
// Unipod.cpp for unipod in /home/baris_f/rendu/ggj17/baris
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Sun Jan 22 01:02:21 2017 baris_f
// Last update Sun Jan 22 04:42:39 2017 baris_f
//

#include "Unipod.hpp"

Unipod::Unipod(sf::Texture* text, const std::string type) : Unit (text, type)
{

}

void	Unipod::move()
{
  sf::Vector2f  dif;
  sf::Vector2f  ratio;

  if (!_target || _target->getSprite() == NULL || getSprite() == NULL)
    return ;
  dif.x = abs(getPos().x - _target->getPos().x);
  dif.y = abs(getPos().y - _target->getPos().y);;
  ratio.y =(MIN(dif.x, dif.y) / (MAX(dif.y, dif.x) + 1));
  ratio.x = 1 - ratio.y;
  if (_target->getPos().x + 5 > getPos().x)
    setPos(getPos().x + _speed * ratio.x, getPos().y);
  else if (_target->getPos().x - 5 < getPos().x)
    setPos(getPos().x - _speed * ratio.x, getPos().y);
  if (_target->getPos().y + 5 > getPos().y)
    setPos(getPos().x, getPos().y + _speed * ratio.y);
  else if (_target->getPos().y - 5 < getPos().y)
    setPos(getPos().x, getPos().y - _speed * ratio.y);
  //setPos(sf::Vector2f(getPos().x - getRekt().width, getPos().y - getRekt().height));
}
