#include "Base.hpp"
#include "Marine.hpp"

Base::Base(sf::Texture* texture, const std::string type) : Building(texture, type){
  setHp(500);
  setLvl(1);
  setPos(10, 400);
  _lifemax = getHp();
  _shape.setPosition(getPos().x, getPos().y);
  _shape.setSize(sf::Vector2f(getRekt().width, getRekt().height / 10));
  _shape.setFillColor(sf::Color::Green);
  _shapeBack = _shape;
  _shapeBack.setFillColor(sf::Color::Magenta);
}

void Base::func(){
  data->money -=5;

  addAllyUnit(new Marine(getTexture("marine"), "ally", getRekt().width + 5.0f, getPos().y + (std::rand() %50)));
}

void Base::update(){
  _shape.setPosition(getPos().x, getPos().y);
  _shapeBack.setPosition(_shape.getPosition());
  _shape.setSize(sf::Vector2f (_shapeBack.getSize().x * getHp()/_lifemax, _shapeBack.getSize().y));
}

void   Base::draw(sf::RenderWindow* win)
{
  win->draw(*_sprite);
  win->draw(_shapeBack);
  win->draw(_shape);
}
