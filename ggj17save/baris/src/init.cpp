#include "Data.hpp"

void initTexture(){
  addTexture("arene", "./res/arene.png");
  addTexture("base", "./res/base.png");
  addTexture("hangar", "./res/hangar.png");
  addTexture("caserne", "./res/caserne.png");


  if(addTexture("marine", "res/terre.png") == false)
    std::exit(84) ;

  addTexture("text", "./res/v1.png");
  addTexture("button", "./res/v3.png");
}

void initUnitAndButton(){


  Base *ba = new Base(getTexture("base"), "building");
  Button *b = new Button(sf::Vector2f(20, 820), getTexture("marine"));
  b->listeners.push_back(ba);

  addButton(b);
  addOther(ba);
}

void initSound(){
  addSound("piou", "./res/piou.wav");
}
