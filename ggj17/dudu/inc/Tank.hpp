#ifndef TANK_HPP_
# define TANK_HPP_

#include "Unipod.hpp"

class Tank : public Unipod
{
public :
  Tank(sf::Texture *text, std::string type);
  Tank(sf::Texture *text, std::string type, float, float);
  ~Tank();

  void	update();
  void	draw(sf::RenderWindow *win);
};

#endif /* !MARINE_H_ */
