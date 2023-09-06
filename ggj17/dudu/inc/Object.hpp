#ifndef OBJ
#define OBJ

#include <iostream>
#include <cmath>
#include <thread>
#include <chrono>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class	Object
{
public:
  Object(sf::Texture*, std::string);
  virtual ~Object(){};
protected:
  sf::Sprite*	_sprite;
  std::string	_type;
public:
  sf::Vector2f	getPos() const;
  sf::FloatRect	getRekt() const;
  void		setPos(float, float);
  void		setPos(const sf::Vector2f&);
  std::string	getType() const;
  sf::Sprite*	getSprite() const;
  virtual void	update() = 0;
  virtual void	draw(sf::RenderWindow*) = 0;
};

#endif
