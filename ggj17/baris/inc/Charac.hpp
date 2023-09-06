#ifndef CHARAC_HPP_
# define CHARAC_HPP_

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Lifebar.hpp"

enum Team{ BLUE, RED};

class Charac : public Object{
public :
  Charac(int hp = 100, float speed = 0.1f, int dmg = 25, float range = 10, int treload = 60, sf::Vector2f pos = sf::Vector2f(0, 0), Team team = BLUE);
  ~Charac();
private :
  Team			_team;
  int			_hp;
  int			_dmg;
  float			_speed;
  int			_treload;
  int			_ctreload;
  float			_range;
  sf::Vector2f		_pos;
  sf::CircleShape	_shape;
  Lifebar		_lifebar;
public :
  Charac *		_target;

  void			attack();
  void			move();
  void			update();
  void			draw(sf::RenderWindow*);
  //  void			findTarget();

  int			getHp() const;
  void			setHp(int);
  int			getDmg() const;
  void			setDmg(int);
  sf::Vector2f		getPos() const;
  void			setPos(sf::Vector2f);
  sf::CircleShape	getShape();
};

#endif
