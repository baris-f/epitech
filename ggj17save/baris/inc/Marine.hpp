#ifndef MARINE_H_
# define MARINE_H_

#include "Unipod.hpp"

class Marine : public Unipod
{
public :
  Marine(sf::Texture *text, std::string type);
  Marine(sf::Texture *text, std::string type, float, float);
  ~Marine();

  void	update();
  void	draw(sf::RenderWindow *win);
};

#endif /* !MARINE_H_ */
