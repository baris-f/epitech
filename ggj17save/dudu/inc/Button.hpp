#ifndef BUTTON_H_
# define BUTTON_H_

#include <list>

#include "Object.hpp"
#include "Data.hpp"
#include "IListener.hpp"

class Button : public Object{
public :
  Button(sf::Vector2f pos, sf::Texture* sprite);
  ~Button();

public :
  void	update(Data *);
  void	draw(sf::RenderWindow*);
  std::list<IListener *> listeners;
};

#endif /* !BUTTON_H_ */
