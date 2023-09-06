//
// Button.cpp for button in /home/baris_f/rendu/ggj17/baris
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Sat Jan 21 09:32:10 2017 baris_f
// Last update Sun Jan 22 01:52:34 2017 Duval Lucas
//

#include "Button.hpp"

Button::Button(sf::Vector2f pos, sf::Texture* sprite) : Object(sprite, "Button")
{
  setPos(pos);
}

Button::~Button()
{

}

void	Button::update(Data *data)
{
  if (!getRekt().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*data->getWindow()))))
    return ;
  data->playSound("piou", false);
  for(IListener *l : listeners){
    l->func();
  }
}

void	Button::draw(sf::RenderWindow* win)
{
  win->draw(*_sprite);
}
