#ifndef LIFEBAR_HPP_
# define LIFEBAR_HPP_

#include "Object.hpp"

class Lifebar
{
 public :
  Lifebar(Entity * ent, sf::Vector2f size, int life, int lifemax);
  ~Lifebar();
 private :
  int			_life;
  int			_lifemax;
  Entity *		_ent;
  sf::Vector2f		_size;
  sf::RectangleShape	_shape;
  sf::RectangleShape	_shapeBack;
 public :
  void	update();
  void	draw(sf::RenderWindow*);
};

#endif /* !LIFEBAR_HPP_ */
