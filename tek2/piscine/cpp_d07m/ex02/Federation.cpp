//
// Federation.cpp for fede in /home/baris_f/rendu/tek2/cpp_d07m
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Tue Jan 10 09:37:13 2017 baris_f
// Last update Tue Jan 10 16:29:18 2017 baris_f
//

#include "Federation.hh"
#include "Borg.hh"

namespace Federation {
  namespace Starfleet {

    Ship::Ship(int length, int width, std::string name, short maxWarp)
    {
      _length = length;
      _width = width;
      _name = name;
      _maxWarp = maxWarp;
      _home = EARTH;
      _location = _home;
      std::cout << "The ship USS " << name << " has been finished. It is " << length << " m in length and " << width << " m in width." << std::endl << "It can go to Warp " << maxWarp << "!" << std::endl;
    }

    Ship::~Ship()    {

    }

    void	Ship::setupCore(WarpSystem::Core *newCore)
    {
      _core = newCore;
      std::cout << "USS " << _name << ": The core is set." << std::endl;
    }

    void	Ship::checkCore()
    {
      if (_core->checkReactor()->isStable())
	std::cout << "USS " << _name << ": The core is stable at the time." << std::endl;
      else
	std::cout << "USS " << _name << ": The core is unstable at the time." << std::endl;
    }

    void	Ship::promote(Captain* cap)
    {
      _captain = cap;
      std::cout << cap->getName() << ": I'm glad to be the captain of the USS " << _name << "." << std::endl;
    }

    bool         Ship::move(int warp, Destination d){
      if (warp <= _maxWarp && d != _location && _core->checkReactor()->isStable())
	return (true);
      return (false);
    }
    bool         Ship::move(int warp){
      if (warp <= _maxWarp && _home != _location && _core->checkReactor()->isStable())
	return (true);
      return (false);
    }
    bool         Ship::move(Destination d) {
      if (d!= _location && _core->checkReactor()->isStable())
	return (true);
      return (false);
    }
    bool         Ship::move()  {
      if (_home != _location && _core->checkReactor()->isStable())
	return (true);
      return (false);
    }

    //Captain
    Captain::Captain(std::string name)    {
      _name = name;
    }

    Captain::~Captain(){
    }

    std::string	Captain::getName(){
      return (_name);
    }

    int		Captain::getAge(){
      return (_age);
    }

    void	Captain::setAge(int age){
      _age = age;
    }

    //Ensign
    Ensign::Ensign(std::string name){
      _name = name;
      std::cout << "Ensign " << _name << ", awaiting orders." << std::endl;
    }

    Ensign::~Ensign(){

    }

  }

  //	Independant

  Ship::Ship(int length, int width, std::string name)
  {
    _length = length;
    _width = width;
    _name = name;
    _maxWarp = 1;
    _home = VULCAN;
    _location = _home;
    std::cout << "The independant ship " << name << " just finished its construction. It is " << length << " m in length and " << width << " m in width." << std::endl;
  }

  Ship::~Ship()  {

  }

  void        Ship::setupCore(WarpSystem::Core *newCore)
  {
    _core = newCore;
    std::cout << _name << ": The core is set." << std::endl;
  }

  void        Ship::checkCore()
  {
    if (_core->checkReactor()->isStable())
      std::cout << _name << ": The core is stable at the time." << std::endl;
    else
      std::cout << _name << ": The core is unstable at the time." << std::endl;
  }

  bool         Ship::move(int warp, Destination d){
    if (warp <= _maxWarp && d != _location && _core->checkReactor()->isStable())
      return (true);
    return (false);
  }
  bool         Ship::move(int warp){
    if (warp <= _maxWarp && _home != _location && _core->checkReactor()->isStable())
      return (true);
    return (false);
  }
  bool         Ship::move(Destination d) {
    if (d!= _location && _core->checkReactor()->isStable())
      return (true);
    return (false);
  }
  bool         Ship::move()  {
    if (_home != _location && _core->checkReactor()->isStable())
      return (true);
    return (false);
  }
}
/*
int     main()
{
  Federation::Starfleet::Ship UssKreog(289, 132, "Kreog", 6);
  Federation::Starfleet::Captain James("James T. Kirk");
  Federation::Starfleet::Ensign Ensign("Pavel Chekov");
  WarpSystem::QuantumReactor QR;
  WarpSystem::QuantumReactor QR2;
  WarpSystem::Core core(&QR);
  WarpSystem::Core core2(&QR2);

  UssKreog.setupCore(&core);
  UssKreog.checkCore();
  UssKreog.promote(&James);
  UssKreog.move();
  UssKreog.move(4, VULCAN);
  UssKreog.move(VULCAN);
  UssKreog.move(9);

  Borg::Ship Cube;
  Cube.setupCore(&core2);
  Cube.checkCore();
  Cube.move();
  Cube.move(4, VULCAN);
  Cube.move(VULCAN);
  Cube.move(9);

  return 0;
}
*/
