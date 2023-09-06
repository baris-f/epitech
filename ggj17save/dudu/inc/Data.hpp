#ifndef DATA_HPP_
# define DATA_HPP_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Unit.hpp"
#include "Button.hpp"
class Button;

typedef void (*pf)();

class   Data
{
private:
  sf::Sprite* _mouse;
  sf::Sprite* _map;
  std::map<std::string, sf::Texture *> textureList;
  std::map<std::string, sf::SoundBuffer *> soundList;
  std::map<std::string, pf> functionList;

  std::vector<Unit *> allyUnitList;
  std::vector<Unit *> enemyUnitList;
  std::vector<Button *> buttonList;

  std::vector<int> towerList;
  std::vector<int> otherList;

  sf::RenderWindow* window;

  public:
  Data();
  ~Data();

  void displayMap();
  void displayMouse();
  void mousePos(int, int);

  sf::RenderWindow* getWindow();
  pf getFunc(std::string name);
  sf::Texture *getTexture(std::string name);
  std::vector<Unit *> &getAllyUnits();
  std::vector<Unit *> &getEnemyUnits();

  bool addTexture(std::string name, std::string path);
  bool addSound(std::string name, std::string path);
  void addFunc(std::string name, pf f);
  void addAllyUnit(Unit *);
  void addEnemyUnit(Unit *);

  void addButton(Button *);

  void updateAlly();
  void updateEnemy();
  void updateButton();

  void drawAlly();
  void drawEnemy();
  void drawButton();

  void display();
  void clear();

  void playSound(std::string name, bool loop){
    sf::Sound *newS = new sf::Sound;
    newS->setBuffer(*soundList.find(name)->second);
    newS->setLoop(loop);
    newS->play();
  }
};


#endif /* !DATA_HPP_ */
