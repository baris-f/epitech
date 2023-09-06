#ifndef DATA_HPP_
# define DATA_HPP_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Unit.hpp"
#include "Marine.hpp"
#include "Button.hpp"
#include "Building.hpp"
#include "Base.hpp"
#include "Caserne.hpp"

struct   Data
{
  sf::Text *nbAllyUnit;

  sf::Text *nbEnemyUnit;

  int wave;
  sf::Text *waveText;

  int money;
  sf::Font *font;
  sf::Text *moneyText;

  int time;
  sf::Text *timeText;

  sf::Sprite* _mouse;
  sf::Sprite* _map;

  std::map<std::string, sf::Texture *> textureList;
  std::map<std::string, sf::SoundBuffer *> soundList;

  std::vector<Unit*> allyUnitList;
  std::vector<Unit*> enemyUnitList;
  std::vector<Button*> buttonList;

  std::vector<int> towerList;
  std::vector<Building *> otherList;

  sf::RenderWindow* window;
};

extern Data*	data;

void initData();

void updateMoney();
void displayMoney();
void displayWave();

void updateTime();
void displayTime();

void displayMap();
void displayMouse();
void mousePos(int, int);

bool addTexture(std::string name, std::string path);
bool addSound(std::string name, std::string path);
void addAllyUnit(Unit*);
void addEnemyUnit(Unit*);
void addButton(Button *);
void addOther(Building *);

sf::Texture* getTexture(std::string name);

void updateAlly();
void updateEnemy();
void updateButton();
void updateButtonColor();
void updateOther();

void drawAlly();
void drawEnemy();
void drawButton();
void drawOther();

void display();
void clear();

float   dist(sf::Vector2f pos1, sf::Vector2f pos2);

void    drawShoot(Entity * me, Entity * target);
Entity* findTarget(Entity * me);

void playSound(std::string name, bool loop, int vol = 100);


#endif /* !DATA_HPP_ */
