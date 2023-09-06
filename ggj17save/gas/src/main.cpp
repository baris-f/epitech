//
// main.cpp for  in /home/fus/taff/ggj17/sfml/src
//
// Made by Gaspard Thirion
// Login   <thirio_b@epitech.net>
//
// Started on  Sat Jan 14 20:43:04 2017 Gaspard Thirion
// Last update Sat Jan 21 18:07:31 2017 Gaspard Thirion
//

#include "Data.hpp"

Data*	data;

void	handleKey(sf::Keyboard::Key key, sf::RenderWindow &window)
{
  if (key == sf::Keyboard::Escape)
    window.close();
}

int	main()
{
  sf::Event	event;
  data = new Data;

  data->addTexture("text", "res/v1.png");
  data->addAllyUnit(new Unit(data->getTexture("text"), "ally", 100, 100));

  while (data->getWindow()->isOpen())
    {
      while (data->getWindow()->pollEvent(event))
	{
	  if (event.type == sf::Event::MouseMoved)
	    {
	      data->mousePos(event.mouseMove.x, event.mouseMove.y);
	    }
	  if (sf::Event::KeyPressed)
	    handleKey(event.key.code, *data->getWindow());
	  if (event.type == sf::Event::Closed)
	    data->getWindow()->close();
	}
      data->clear();
      data->updateAlly();
      data->drawAlly();
      data->drawEnemy();
      data->displayMouse();
      data->display();
    }
  return (0);
}
