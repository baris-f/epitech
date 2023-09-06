#ifndef DATA_HPP_
# define DATA_HPP_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Unit.hpp"

typedef void (*pf)();

class   Data
{
private:
  sf::Sprite* _mouse;
  std::map<std::string, sf::Texture *> textureList;
  std::map<std::string, sf::Sound *> soundList;
  std::map<std::string, pf> functionList;

  std::vector<Unit *> allyUnitList;
  std::vector<Unit *> enemyUnitList;
  std::vector<int> buttonList;
  std::vector<int> towerList;
  std::vector<int> otherList;

  sf::RenderWindow* window;

  public:
  Data();
  ~Data();

  void displayMouse();
  void mousePos(int, int);

  sf::RenderWindow* getWindow();
  pf getFunc(std::string name);
  sf::Texture *getTexture(std::string name);
  std::vector<Unit *> &getAllyUnits();
  std::vector<Unit *> &getEnemyUnits();

  bool addTexture(std::string name, std::string path);
  void addFunc(std::string name, pf f);
  void addAllyUnit(Unit *);
  void addEnemyUnit(Unit *);

  void updateAlly();
  void updateEnemy();

  void drawAlly();
  void drawEnemy();

  void display();
  void clear();

  void playSound(std::string name){
    soundList.find(name)->second->play();
  }
};


#endif /* !DATA_HPP_ */
