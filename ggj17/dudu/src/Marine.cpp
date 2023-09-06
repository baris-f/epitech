//
// Marine.cpp for marine in /home/baris_f/rendu/ggj17/baris
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Sun Jan 22 03:47:22 2017 baris_f
// Last update Sun Jan 22 17:08:43 2017 Duval Lucas
//

#include "Marine.hpp"
#include "proto.h"
#include "Data.hpp"


Marine::Marine(sf::Texture *text, std::string type) : Unipod(text, type)
{
  _attacked = false;
  setHp(120);
  setLvl(1);
  setDmg(15);
  setRange(200);
  setFireRate(60);
  _fireTime = 0;
  setSpeed(3);
  _lifemax = getHp();
  _shape.setPosition(getPos().x - getRekt().width / 2, getPos().y - getRekt().height * 4 / 3);
  _shape.setSize(sf::Vector2f(getRekt().width, getRekt().height / 10));
  _shape.setFillColor(sf::Color::Green);
  _shapeBack = _shape;
  _shapeBack.setFillColor(sf::Color::Magenta);
}

Marine::Marine(sf::Texture *text, std::string type, float x, float y) : Unipod(text, type)
{
  _attacked = false;
  setHp(120);
  setLvl(1);
  setDmg(15);
  setRange(130);
  setFireRate(60);
  _fireTime = 0;
  setSpeed(3);
  setPos(x, y);
  _lifemax = getHp();
  _shape.setPosition(getPos().x - getRekt().width / 2, getPos().y - getRekt().height * 4 / 3);
  _shape.setSize(sf::Vector2f(getRekt().width, getRekt().height / 10));
  _shape.setFillColor(sf::Color::Green);
  _shapeBack = _shape;
  _shapeBack.setFillColor(sf::Color::Magenta);
}

Marine::~Marine()
{

}

void	Marine::update()
{
  updateTarget();
  if (targetInRange())
    attack();
  else
    if (getType() == "ally")
      if (data->enemyUnitList.empty() && getPos().x > 200)
	setPos(getPos().x -1, getPos().y - ((std::rand() %3) -1));
      else
	move();
    else
      move();
  _shape.setPosition(getPos().x, getPos().y);
  _shapeBack.setPosition(_shape.getPosition());
  _shape.setSize(sf::Vector2f (_shapeBack.getSize().x * getHp()/_lifemax, _shapeBack.getSize().y));
}

void	Marine::draw(sf::RenderWindow* win)
{
  if (_attacked == true)
    {
      if (_target){
	drawShoot(this, _target);
	playSound("piou", false, 50);
      }
      _attacked = false;
    }
  win->draw(*_sprite);
  win->draw(_shapeBack);
  win->draw(_shape);
}
