//
// Charac.cpp for charac in /home/baris_f/rendu/ggj17/sfml
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Thu Jan 19 19:45:47 2017 baris_f
// Last update Sat Jan 21 16:07:28 2017 baris_f
//

#include <cmath>
#include "Charac.hpp"

//#define DIST(a, b) (sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2)))
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))

float	dist(sf::Vector2f pos1, sf::Vector2f pos2)
{
  return (sqrt(pow(pos2.x - pos1.x, 2) + pow(pos2.y - pos1.y, 2)));
}

Charac::Charac(int hp, float speed, int dmg, float range, int treload, sf::Vector2f pos, Team team) : Object(NULL, "Charac"), _lifebar(_pos, sf::Vector2f(hp / 7, hp / 20), _hp, hp)
{
  _hp = hp;
  _dmg = dmg;
  _pos = pos;
  _speed = speed;
  _treload = treload;
  _ctreload = 0;
  _team = team;
  _range = range;
  _shape.setRadius(hp / 10);
  if (team == BLUE)
    _shape.setFillColor(sf::Color::Blue);
  else
    _shape.setFillColor(sf::Color::Red);
}

Charac::~Charac()
{

}

void	Charac::update()
{
  if (!_target || _hp <= 0)
    return ;
  if (_target->getHp() > 0)
    {
      if (dist(_target->getPos(), _pos) < _range * 10)
	attack();
      else
	move();
    }
  _lifebar.update();
}

void	Charac::draw(sf::RenderWindow* win)
{
  if (_hp <= 0)
    return ;
  win->draw(_shape);
  _lifebar.draw(win);
}

void	Charac::move()
{
  sf::Vector2f	dif;
  sf::Vector2f	ratio;

  dif.x = abs(_pos.x - _target->getPos().x);
  dif.y = abs(_pos.y - _target->getPos().y);;
  ratio.y =(MIN(dif.x, dif.y) / (MAX(dif.y, dif.x) + 1));
  ratio.x = 1 - ratio.y;
  if (_target->getPos().x + 5 > _pos.x)
    _pos.x += _speed * ratio.x;
  else if (_target->getPos().x - 5 < _pos.x)
    _pos.x -= _speed * ratio.x;
  if (_target->getPos().y + 5 > _pos.y)
    _pos.y += _speed * ratio.y;
  else if (_target->getPos().y - 5 < _pos.y)
    _pos.y -= _speed * ratio.y ;
  _shape.setPosition(sf::Vector2f(_pos.x - _shape.getRadius(), _pos.y - _shape.getRadius()));
}

void	Charac::attack()
{
  if (!_target)
    return ;
  if (_ctreload > 0)
    {
      _ctreload--;
      return ;
    }
  _ctreload = _treload;
  sf::Vertex line[] =
    {
      sf::Vertex(_pos),
      sf::Vertex(_target->getPos())
    };
  line[0].color = _shape.getFillColor();
  line[1].color = sf::Color::Green;
  //  data->getWindow()->draw(line, 2, sf::Lines);
  _target->setHp(_target->getHp() - _dmg);
}

int                   Charac::getHp() const { return (_hp);}
void                  Charac::setHp(int hp) {
  if (hp < 0)
    hp = 0;
  _hp = hp;
}
int                   Charac::getDmg() const { return (_dmg);}
void                  Charac::setDmg(int dmg) {
  if (dmg < 0)
    dmg = 0;
  _dmg = dmg;
}
sf::Vector2f          Charac::getPos() const { return (_pos);}
void                  Charac::setPos(sf::Vector2f pos)  {_pos = pos;}
sf::CircleShape		Charac::getShape() { return (_shape);}
