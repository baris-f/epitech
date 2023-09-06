#ifndef OBJ
#define OBJ

#include <iostream>
#include <thread>
#include <chrono>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class	Object
{
public:
  Object(sf::Texture*, std::string);
  ~Object(){};
protected:
  //  Data&		_data;
  sf::Sprite*	_sprite;
  std::string	_type;
public:
  sf::Vector2f	getPos() const;
  sf::FloatRect	getSize() const;
  void		setPos(float, float);
  void		setPos(const sf::Vector2f&);
  virtual void	update() = 0;
  virtual void	draw(sf::RenderWindow*) = 0;
};

#endif
