#include "Data.hpp"

Data::Data(){
  window = new sf::RenderWindow(sf::VideoMode(1600, 900), "sfml");
  window->setFramerateLimit(60);
  window->setMouseCursorVisible(false);
  addTexture("mouse", "./res/mouse.png");
  _mouse = new sf::Sprite(*getTexture("mouse"));
  _mouse->setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition()));
}

Data::~Data(){

}

void Data::mousePos(int x, int y){
  _mouse->setPosition(static_cast<float>(x), static_cast<float>(y));
}
void Data::displayMouse(){
  window->draw(*_mouse);
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
      u->update();
    }
}

void Data::updateEnemy(){
  for (Unit *u : enemyUnitList)
    {
      u->update();
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
