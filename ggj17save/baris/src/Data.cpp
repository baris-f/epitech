#include <algorithm>
#include "Data.hpp"

void	initData(){
  data->window = new sf::RenderWindow(sf::VideoMode(1600, 900), "sfml");
  data->window->setFramerateLimit(60);
  data->window->setMouseCursorVisible(false);
  addTexture("mouse", "./res/mouse.png");
  addTexture("map", "./res/map.png");

  data->_mouse = new sf::Sprite(*getTexture("mouse"));
  data->_mouse->setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition()));
  data->_map = new sf::Sprite(*getTexture("map"));
  data->_mouse->setPosition(sf::Vector2f(0,0));

  addSound("background", "./res/ggj.ogg");
  playSound("background", true);

  data->money = 10;
  data->font = new sf::Font;
  data->font->loadFromFile("./res/arial.ttf");

  data->moneyText = new sf::Text(std::to_string(data->money), *data->font);
  data->moneyText->setCharacterSize(30);
  data->moneyText->setStyle(sf::Text::Bold);
  data->moneyText->setFillColor(sf::Color::Yellow);
  data->moneyText->setPosition(10, 10);

  data->time = 0;
  data->timeText = new sf::Text(std::to_string(data->time) + " s", *data->font);
  data->timeText->setCharacterSize(30);
  data->timeText->setStyle(sf::Text::Bold);
  data->timeText->setPosition(10, 40);

  data->wave = 0;

  data->waveText = new sf::Text("Wave : " + std::to_string(data->wave), *data->font);
  data->waveText->setCharacterSize(30);
  data->waveText->setStyle(sf::Text::Bold);
  data->waveText->setPosition(20, 70);

  data->nbAllyUnit = new sf::Text("Ally Units : " + data->allyUnitList.size(), *data->font);
  data->nbAllyUnit->setCharacterSize(30);
  data->nbAllyUnit->setStyle(sf::Text::Bold);
  data->nbAllyUnit->setPosition(20, 100);

  data->nbEnemyUnit = new sf::Text("Enemy Units : " + data->enemyUnitList.size(), *data->font);
  data->nbEnemyUnit->setCharacterSize(30);
  data->nbEnemyUnit->setStyle(sf::Text::Bold);
  data->nbEnemyUnit->setPosition(20, 130);
}


void createWave(){
  if (data->enemyUnitList.empty()){
    data->wave++;
    int nb = (std::rand() % (data->wave * 2) + data->wave);
    for (int i = 0; i < nb; ++i){
      Marine *m = new Marine(getTexture("marine"), "enemy");
      m->setPos(1500, std::rand() % 600);
      addEnemyUnit(m);
    }
    data->waveText->setString("Wave : " +std::to_string(data->wave));
  }
}

void displayWave(){
  data->window->draw(*data->waveText);
  data->nbAllyUnit->setString("Ally Units : " + std::to_string(data->allyUnitList.size()));
  data->nbEnemyUnit->setString("Enemy Units : " + std::to_string(data->enemyUnitList.size()));

  data->window->draw(*data->nbAllyUnit);
  data->window->draw(*data->nbEnemyUnit);
}

void updateTime(){
  static int f = 0;
  if (f == 60){
    data->time++;
    f = 0;
  }
  else
    f++;
  if (!(data->time % 30)){
    createWave();
  }

  data->timeText->setString(std::to_string(data->time) + " s");
}

void displayTime(){
  data->window->draw(*data->timeText);
}

void updateMoney(){
  static int f = 0;
  if (f == 120) {
    data->money++;
    f = 0;
  } else
    f++;
  data->moneyText->setString(std::to_string(data->money) + " gold");
}

void displayMoney(){
  data->window->draw(*data->moneyText);
}

void	mousePos(int x, int y){
  data->_mouse->setPosition(static_cast<float>(x), static_cast<float>(y));
}

bool addSound(std::string name, std::string path){
  sf::SoundBuffer *buffer = new sf::SoundBuffer;
  if (!buffer->loadFromFile(path)){
    std::cerr << "Erreur chargement son [" << name << "]" << std::endl;
    return false;
  }
  data->soundList.insert(std::pair<std::string, sf::SoundBuffer *>(name, buffer));
  return true;
}

void playSound(std::string name, bool loop, int vol){
  sf::Sound *newS = new sf::Sound;
  sf::SoundBuffer *SB = new sf::SoundBuffer(*data->soundList.find(name)->second);
  if (!SB)
    return;
  newS->setBuffer(*SB);
  newS->setLoop(loop);
  newS->setVolume(vol);
  newS->play();
}

void	displayMouse(){
  data->window->draw(*data->_mouse);
}

void	displayMap(){
  data->window->draw(*data->_map);
}

sf::Texture*	getTexture(std::string name){
  return data->textureList.find(name)->second;
}

bool	addTexture(std::string name, std::string path){
  sf::Texture *newT = new sf::Texture;

  if (!newT->loadFromFile(path)){
    std::cerr << "Erreur chargement texure [" << name << "]" << std::endl;
    return false;
  }
  data->textureList.insert(std::pair<std::string, sf::Texture *>(name, newT));
  return true;
}

void	addAllyUnit(Unit *u){
  data->allyUnitList.push_back(u);
}

void	addEnemyUnit(Unit *u){
  data->enemyUnitList.push_back(u);
}

void	addOther(Building *b){
  data->otherList.push_back(b);
}

void	updateOther(){
  if (!data->otherList.empty()){
    for (Building *u : data->otherList)
      if (u->getHp() <= 0)
	{
	  data->otherList.erase(std::remove(data->otherList.begin(), data->otherList.end(), u), data->otherList.end());
	}
      else
	u->update();
  }
}

void	updateAlly(){
  if (!data->allyUnitList.empty()){
    for (Unit *u : data->allyUnitList)
      if (u->getHp() <= 0)
	{
	  data->allyUnitList.erase(std::remove(data->allyUnitList.begin(), data->allyUnitList.end(), u), data->allyUnitList.end());
	  // delete u;
	}
      else
	u->update();
  }
}

void	updateEnemy(){
  if (!data->enemyUnitList.empty()){
    for (Unit *u : data->enemyUnitList)
      if (u->getHp() <= 0)
	{
	  data->enemyUnitList.erase(std::remove(data->enemyUnitList.begin(), data->enemyUnitList.end(), u), data->enemyUnitList.end());
	  //	  delete u;
	  data->money +=5;
	}
      else
	u->update();
  }
}

void	drawAlly(){
  if (!data->allyUnitList.empty())
    for (Unit *u : data->allyUnitList)
      u->draw(data->window);
}

void	drawEnemy(){
  if (!data->enemyUnitList.empty())
  for (Unit *u : data->enemyUnitList)
    u->draw(data->window);
}

void	drawOther(){
  if (!data->otherList.empty())
    for (Building *u : data->otherList)
      u->draw(data->window);
}

void	addButton(Button *b){
  data->buttonList.push_back(b);
}

void	updateButton(){
  for (Button *b : data->buttonList)
    b->update();
}

void	updateButtonColor(){
  for (Button *b : data->buttonList)
    b->updateColor();
}

void	drawButton(){
  for (Button *b : data->buttonList)
    b->draw(data->window);
}

void    display(){
  data->window->display();
}

void    clear(){
  data->window->clear();
}

float   dist(sf::Vector2f pos1, sf::Vector2f pos2)
{
  return (sqrt(pow(pos2.x - pos1.x, 2) + pow(pos2.y - pos1.y, 2)));
}

void	drawShoot(Entity * me, Entity * target)
{
  if (me && target && me->getPos().x != 0 && me->getPos().y != 0 && target->getPos().x != 0 && target->getPos().y != 0){
    sf::Vector2f linepos;
    sf::Vector2f linepos2;

    if (me->getType() == "ally")
      {
	linepos = sf::Vector2f(me->getPos().x + me->getRekt().width, me->getPos().y + me->getRekt().height / 2);
	linepos2 = sf::Vector2f(target->getPos().x, target->getPos().y + target->getRekt().height / 2);
      }
    else
      {
	linepos = sf::Vector2f(me->getPos().x, me->getPos().y + me->getRekt().height / 2);
	linepos2 = sf::Vector2f(target->getPos().x + target->getRekt().width * 2 / 3, target->getPos().y + target->getRekt().height / 2);
      }
    sf::Vertex line[] =
      {
	sf::Vertex(linepos),
	sf::Vertex(linepos2)
      };
    if (me->getType() == "ally")
      line[0].color = sf::Color::Blue;
    else
      line[0].color = sf::Color::Red;
    line[1].color = sf::Color::Green;
    data->window->draw(line, 2, sf::Lines);
  }
}

Entity*	findTarget(Entity * me)
{
  Entity *target;
  float      mdist;

  target = NULL;
  if (me->getType() == "ally")
    {
      if (data->enemyUnitList.empty())
	return (NULL);
      mdist = dist(data->enemyUnitList[0]->getPos(), me->getPos());
      target = data->enemyUnitList[0];
      for (Unit* U:data->enemyUnitList)
	{
	  if (dist(U->getPos(), me->getPos()) < mdist)
	    {
	      mdist = dist(U->getPos(), me->getPos());
	      target = U;
	    }
	}
    }
  else
    {
      if (data->allyUnitList.empty() && data->otherList.empty())
	return (NULL);
      if (!data->allyUnitList.empty())
	{
	  mdist = dist(data->allyUnitList[0]->getPos(), me->getPos());
	  target = data->allyUnitList[0];
	  for (Unit* U:data->allyUnitList)
	    {
	      if (dist(U->getPos(), me->getPos()) < mdist)
		{
		  mdist = dist(U->getPos(), me->getPos());
		  target = U;
		}
	    }
	}
      if (!data->otherList.empty())
	{
	  if (!target)
	    {
	      mdist = dist(data->otherList[0]->getPos(), me->getPos());
	      target = data->otherList[0];
	    }
	  for (Building* U:data->otherList)
	    {
	      if (dist(U->getPos(), me->getPos()) < mdist)
		{
		  mdist = dist(U->getPos(), me->getPos());
		  target = U;
		}
	    }
	}
    }
  return (target);
}
