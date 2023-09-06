#include "Caserne.hpp"
#include "Tank.hpp"

Caserne::Caserne(sf::Texture* texture, const std::string type) : Building(texture, type){
  setHp(400);
  setLvl(1);
  setPos(20, 300);
  _lifemax = getHp();
  _shape.setPosition(getPos().x,getPos().y);
  _shape.setSize(sf::Vector2f(getRekt().width, getRekt().height / 10));
  _shape.setFillColor(sf::Color::Green);
  _shapeBack = _shape;
  _shapeBack.setFillColor(sf::Color::Magenta);
}

void Caserne::func(){
  data->money -=10;
  addAllyUnit(new Tank(getTexture("tank"), "ally", getRekt().width + 30.0f, getPos().y + (std::rand() %50)));
}

void Caserne::update(){
  _shape.setPosition(getPos().x, getPos().y);
  _shapeBack.setPosition(_shape.getPosition());
  _shape.setSize(sf::Vector2f (_shapeBack.getSize().x * getHp()/_lifemax, _shapeBack.getSize().y));
}

void   Caserne::draw(sf::RenderWindow* win)
{
  win->draw(*_sprite);
  win->draw(_shapeBack);
  win->draw(_shape);

}
