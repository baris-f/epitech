#include "Data.hpp"

void initTexture(){
  addTexture("arene", "./res/arene.png");
  addTexture("base", "./res/base.png");
  addTexture("hangar", "./res/hangar.png");
  addTexture("caserne", "./res/caserne.png");


  if(addTexture("marine", "res/terre.png") == false)
    std::exit(84) ;

  if(addTexture("tank", "res/volant.png") == false)
    std::exit(84) ;

  addTexture("text", "./res/v1.png");
  addTexture("button", "./res/v3.png");
}

void initUnitAndButton(){


  Base *ba = new Base(getTexture("base"), "building");
  Button *b = new Button(sf::Vector2f(20, 800), getTexture("marine"), 5);
  b->listeners.push_back(ba);

  Caserne *ca = new Caserne(getTexture("caserne"), "building");
  Button *bc = new Button(sf::Vector2f(100, 800), getTexture("tank"), 10);
  bc->listeners.push_back(ca);

  addButton(b);
  addOther(ba);
  addButton(bc);
  addOther(ca);
}

void initSound(){
  addSound("piou", "./res/piou.wav");
}
