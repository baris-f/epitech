#include "Data.hpp"
#include <chrono>

void    handleKey(sf::Keyboard::Key key, sf::RenderWindow &window)
{
  if (key == sf::Keyboard::Escape)
    window.close();
}

void
update(Data *d){
  sf::Event     event;
  while (d->getWindow()->isOpen())
    {

      while (d->getWindow()->pollEvent(event))
        {

          if (event.type == sf::Event::MouseMoved)
            {
              d->mousePos(event.mouseMove.x, event.mouseMove.y);
            }

          if (event.type == sf::Event::MouseButtonPressed){
            if (event.mouseButton.button == sf::Mouse::Left)
              {
                d->updateButton();
              }
          }

          if (sf::Event::KeyPressed)
            handleKey(event.key.code, *d->getWindow());

          if (event.type == sf::Event::Closed)
            d->getWindow()->close();
        }

      d->updateAlly();

      d->checkSound();
      std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }
}

void
render(Data *d)
{
  while (d->getWindow()->isOpen())
    {
      d->clear();

      d->displayMap();

      d->drawAlly();
      d->drawEnemy();
      d->drawButton();

      d->displayMouse();

      d->display();
    }
}
