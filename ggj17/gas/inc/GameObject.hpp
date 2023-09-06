#ifndef GO
#define GO

#include <iostream>
#include <SFML/Graphics.hpp>

class	GameObject
{
public:
  GameObject(std::string, std::string, float, float);
  ~GameObject(){};
private:
  std::string	_name;
  sf::Texture	*_texture;
  sf::Sprite	*_sprite;
public:
  const std::string&	getName() const;
  void	draw(sf::RenderWindow*) const;
  void	move(float, float);
};

#endif
