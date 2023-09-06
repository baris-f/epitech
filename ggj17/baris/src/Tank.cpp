#include "Tank.hpp"
#include "proto.h"
#include "Data.hpp"


Tank::Tank(sf::Texture *text, std::string type) : Unipod(text, type)
{
  _attacked = false;
  setHp(240);
  setLvl(1);
  setDmg(7);
  setRange(65);
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

Tank::Tank(sf::Texture *text, std::string type, float x, float y) : Unipod(text, type)
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

Tank::~Tank()
{

}

void	Tank::update()
{
  updateTarget();
  if (targetInRange())
    attack();
  else
    if (getType() == "ally")
      if (data->enemyUnitList.empty() && getPos().x > 300)
	setPos(getPos().x -1, getPos().y - ((std::rand()%3) -1));
      else
	move();
    else
      move();
  _shape.setPosition(getPos().x, getPos().y);
  _shapeBack.setPosition(_shape.getPosition());
  _shape.setSize(sf::Vector2f (_shapeBack.getSize().x * getHp()/_lifemax, _shapeBack.getSize().y));
}

void	Tank::draw(sf::RenderWindow* win)
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
