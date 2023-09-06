#include "Data.hpp"

void initTexture(Data *d){
  d->addTexture("arene", "./res/arene.png");
  d->addTexture("base", "./res/base.png");
  d->addTexture("hangar", "./res/hangar.png");
  d->addTexture("caserne", "./res/caserne.png");

  d->addTexture("text", "./res/v1.png");
  d->addTexture("button", "./res/v3.png");
}

void initUnitAndButton(Data *d){
  Unit *a = new Unit(d->getTexture("text"), "ally", 100, 100);
  Button *b = new Button(sf::Vector2f(20, 20), d->getTexture("button"));
  b->listeners.push_back(a);
  d->addButton(b);

  d->addAllyUnit(a);
  d->addEnemyUnit(new Unit(d->getTexture("text"), "", 300, 100));
}

void initSound(Data *d){
  d->addSound("piou", "./res/piou.wav");
}
