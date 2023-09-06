//
// Borg.cpp for borg in /home/baris_f/rendu/tek2/cpp_d07m/ex01
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Tue Jan 10 11:01:04 2017 baris_f
// Last update Tue Jan 10 16:46:28 2017 baris_f
//

#include "Borg.hh"

namespace Borg {

  Ship::Ship(int wF, short repair)
  {
    _side = 300;
    _maxWarp = 9;
    _shield = 100;
    _weaponFrequency = wF;
    _repair = repair;
    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl <<
      "Your biological characteristics and technologies will be assimilated." << std::endl << "Resistance is futile." << std::endl;
    _home = UNICOMPLEX;
    _location = _home;
  }

    Ship::Ship(int wF)
  {
    _side = 300;
    _maxWarp = 9;
    _shield = 100;
    _weaponFrequency = wF;
    _repair = 3;
    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl <<
      "Your biological characteristics and technologies will be assimilated." << std::endl << "Resistance is futile." << std::endl;
    _home = UNICOMPLEX;
    _location = _home;
  }

    Ship::Ship()
  {
    _side = 300;
    _maxWarp = 9;
    _shield = 100;
    _weaponFrequency = 0;
    _repair = 3;
    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl <<
      "Your biological characteristics and technologies will be assimilated." << std::endl << "Resistance is futile." << std::endl;
    _home = UNICOMPLEX;
    _location = _home;
  }

  Ship::~Ship()
  {

  }

  void		Ship::setupCore(WarpSystem::Core *newCore)
  {
    _core = newCore;
  }

  void		Ship::checkCore()
  {
    if (_core->checkReactor()->isStable())
      std::cout << "Everything is in order." << std::endl;
    else
      std::cout << "Critical failure imminent." << std::endl;
  }

  bool	       Ship::move(int warp, Destination d){
    if (warp <= _maxWarp && d != _location && _core->checkReactor()->isStable())
      return (true);
    return (false);
  }
  bool	       Ship::move(int warp){
    if (warp <= _maxWarp && _home != _location && _core->checkReactor()->isStable())
      return (true);
    return (false);
  }
  bool	       Ship::move(Destination d) {
    if (d!= _location && _core->checkReactor()->isStable())
      return (true);
    return (false);
  }
  bool	       Ship::move()  {
    if (_home != _location && _core->checkReactor()->isStable())
      return (true);
    return (false);
  }

  int		Ship::getShield(){
    return (_shield);
  }
  void		Ship::setShield(int shield){
    _shield = shield;
  }
  int		Ship::getWeaponFrequency(){
    return (_weaponFrequency);
  }
  void		Ship::setWeaponFrequency(int wF){
    _weaponFrequency = wF;
  }
  short		Ship::getRepair(){
    return (_repair);
  }
  void		Ship::setRepair(short repair){
    _repair = repair;
  }

  void		Ship::fire(Federation::Starfleet::Ship* target)
  {
    target->setShield(target->getShield() - getWeaponFrequency());
    std::cout << "Firing on target with "<< getWeaponFrequency()  << "GW frequency." << std::endl;
  }

  void		Ship::fire(Federation::Ship *target)
  {
    target->getCore()->checkReactor()->setStability(false);
    std::cout << "Firing on target with "<< getWeaponFrequency()  << "GW frequency." << std::endl;
  }

  void		Ship::repair()
  {
    if (getRepair() <= 0)
      {
	std::cout << "Energy cells depleted, shield weakening." << std::endl;
	return ;
      }
    	std::cout << "Begin shield re-initialisation... Done. Awaiting further instructions." << std::endl;
    setRepair(getRepair() - 1);
    setShield(100);
  }
}
