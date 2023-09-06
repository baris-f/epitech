#include "Data.hpp"

void    handleKey(sf::Keyboard::Key &key, sf::RenderWindow &window)
{

  if (key == sf::Keyboard::Escape)
    window.close();
}

void all(Data *data){
  sf::Event     event;
  while (data->window->isOpen())
    {
      event.key.code = sf::Keyboard::Unknown;
      clear();

      displayMap();

      while (data->window->pollEvent(event))
	{

	  switch (event.type){
	  case sf::Event::Closed:
	    data->window->close();
	    break;
	  case sf::Event::MouseMoved :
	    mousePos(event.mouseMove.x, event.mouseMove.y);
	    break;

	  case sf::Event::MouseButtonPressed :
	    if (event.mouseButton.button == sf::Mouse::Left)
	      {
		updateButton();
	      }
	    break;
	  case sf::Event::KeyPressed:
	    handleKey(event.key.code, *data->window);
	    break;

	  default:
            break;
	  }

	}

      updateAlly();
      updateEnemy();
      updateOther();

      updateMoney();
      updateTime();
      updateButtonColor();




      drawAlly();
      drawEnemy();
      drawOther();
      drawButton();

      displayMoney();
      displayTime();
      displayWave();

      displayMouse();
      display();

    }
}

void	update(Data *data){
  sf::Event     event;
  while (data->window->isOpen())
    {


      while (data->window->pollEvent(event))
        {

          if (event.type == sf::Event::MouseMoved)
            {
              mousePos(event.mouseMove.x, event.mouseMove.y);
            }

          if (event.type == sf::Event::MouseButtonPressed){
            if (event.mouseButton.button == sf::Mouse::Left)
              {
                updateButton();
              }
          }

          if (sf::Event::KeyPressed)
	    handleKey(event.key.code, *data->window);

          if (event.type == sf::Event::Closed)
            data->window->close();
        }

      updateAlly();
      updateEnemy();
      updateOther();

      updateMoney();
      updateTime();
      updateButtonColor();
      sf::sleep(sf::milliseconds(16));

    }
}

void	render(Data *data)
{
  while (data->window->isOpen())
    {
      clear();

      displayMap();

      drawAlly();
      drawEnemy();
      drawOther();
      drawButton();

      displayMoney();
      displayTime();
      displayWave();

      displayMouse();
      display();

    }
}
