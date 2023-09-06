//
// Button.cpp for button in /home/baris_f/rendu/ggj17/baris
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Sat Jan 21 09:32:10 2017 baris_f
// Last update Sun Jan 22 10:05:50 2017 Duval Lucas
//

#include "Button.hpp"
#include "Data.hpp"

Button::Button(sf::Vector2f pos, sf::Texture* sprite)
  : Object(sprite, "Button")
{
  setPos(pos);
}

Button::~Button()
{

}

void Button::updateColor(){
  if (data->money < 5)
    _sprite->setColor(sf::Color(247, 60, 60));
  else
    _sprite->setColor(sf::Color(255, 255, 255));
}

void	Button::update()
{
  if (!getRekt().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*data->window))))
    return ;
  if (data->money < 5)
    return;
  for(IListener *l : listeners){
    l->func();
  }
}

void	Button::draw(sf::RenderWindow* win)
{
  win->draw(*_sprite);
}
