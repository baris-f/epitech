//
// Lifebar.cpp for life in /home/baris_f/rendu/ggj17/baris
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Sat Jan 21 11:30:15 2017 baris_f
// Last update Sun Jan 22 05:04:11 2017 baris_f
//

#include "Lifebar.hpp"

Lifebar::Lifebar(Entity * ent, sf::Vector2f size, int life, int lifemax) : _life(life)
{
  _ent = ent;
  _lifemax = lifemax;
  _shape.setPosition(ent->getPos().x - size.x / 2, ent->getPos().y - size.y * 4 / 3);
  _size = size;
  _shape.setSize(size);
  _shape.setFillColor(sf::Color::Green);
  _shapeBack = _shape;
  _shapeBack.setFillColor(sf::Color::Magenta);
}

Lifebar::~Lifebar()
{

}

void	Lifebar::update()
{
  _shape.setPosition(_ent->getPos().x - _shapeBack.getSize().x / 2, _ent->posPos().y - _shapeBack.getSize().y);
  _shapeBack.setPosition(_shape.getPosition());
  _size = sf::Vector2f (_shapeBack.getSize().x * _ent->getHp()/_lifemax, _shapeBack.getSize().y);
  _shape.setSize(_size);
}

void	Lifebar::draw(sf::RenderWindow* win)
{
  //  data.getWindow().draw(_shapeBack);
  //data.getWindow().draw(_shape);
  win->draw(_shapeBack);
  win->draw(_shape);
}
