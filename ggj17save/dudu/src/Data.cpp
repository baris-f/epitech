#include "Data.hpp"

Data::Data(){
  window = new sf::RenderWindow(sf::VideoMode(1600, 900), "sfml");
  window->setFramerateLimit(60);
  window->setMouseCursorVisible(false);
  addTexture("mouse", "./res/mouse.png");
  addTexture("map", "./res/map.png");
  _mouse = new sf::Sprite(*getTexture("mouse"));
  _mouse->setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition()));
  _map = new sf::Sprite(*getTexture("map"));
  _mouse->setPosition(sf::Vector2f(0,0));
  addSound("background", "./res/ggj.ogg");
  playSound("background", true);
}

Data::~Data(){

}

void Data::mousePos(int x, int y){
  _mouse->setPosition(static_cast<float>(x), static_cast<float>(y));
}

void Data::displayMouse(){
  window->draw(*_mouse);
}

void Data::displayMap(){
  window->draw(*_map);
}

sf::RenderWindow* Data::getWindow(){
  return window;
}

sf::Texture *Data::getTexture(std::string name){
  return textureList.find(name)->second;
}

bool Data::addTexture(std::string name, std::string path){
  sf::Texture *newT = new sf::Texture;
  if (!newT->loadFromFile(path)){
    std::cerr << "Erreur chargement texure [" << name << "]" << std::endl;
    return false;
  }

  textureList.insert(std::pair<std::string, sf::Texture *>(name, newT));
  return true;
}

bool Data::addSound(std::string name, std::string path){
  sf::SoundBuffer *buffer = new sf::SoundBuffer;
  if (!buffer->loadFromFile(path)){
    std::cerr << "Erreur chargement son [" << name << "]" << std::endl;
    return false;
  }
  soundList.insert(std::pair<std::string, sf::SoundBuffer *>(name, buffer));
  return true;
}

void Data::addFunc(std::string name, pf f){
  functionList.insert(std::pair<std::string, pf>(name, f));
}

pf Data::getFunc(std::string name){
  return functionList.find(name)->second;
}

std::vector<Unit *> &Data::getAllyUnits(){
  return allyUnitList;
}

std::vector<Unit *> &Data::getEnemyUnits(){
  return enemyUnitList;
}

void Data::addAllyUnit(Unit *u){
  allyUnitList.push_back(u);
}

void Data::addEnemyUnit(Unit *u){
  enemyUnitList.push_back(u);
}

void Data::updateAlly(){
  for (Unit *u : allyUnitList)
    {
      u->update(this);
    }
}

void Data::updateEnemy(){
  for (Unit *u : enemyUnitList)
    {
      u->update(this);
    }
}


void Data::drawAlly(){
  for (Unit *u : allyUnitList)
    {
      u->draw(window);
    }
}

void Data::drawEnemy(){
  for (Unit *u : enemyUnitList)
    {
      u->draw(window);
    }
}


void Data::display(){
  window->display();
}

void Data::clear(){
  window->clear();
}


void Data::addButton(Button *b){
  buttonList.push_back(b);
}

void Data::updateButton(){
  for (Button *b : buttonList)
    {
      b->update(this);
    }
}

void Data::drawButton(){
  for (Button *b : buttonList)
    {
      b->draw(window);
    }
}
