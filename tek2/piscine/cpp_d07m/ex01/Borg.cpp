//
// Borg.cpp for borg in /home/baris_f/rendu/tek2/cpp_d07m/ex01
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Tue Jan 10 11:01:04 2017 baris_f
// Last update Tue Jan 10 13:05:53 2017 baris_f
//

#include "Borg.hh"

namespace Borg {

  Ship::Ship()
  {
    _side = 300;
    _maxWarp = 9;
    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl <<
      "Your biological characteristics and technologies will be assimilated." << std::endl << "Resistance is futile." << std::endl;
  }

  Ship::~Ship()
  {

  }

  void        Ship::setupCore(WarpSystem::Core *newCore)
  {
    _core = newCore;
  }

  void        Ship::checkCore()
  {
    if (_core->checkReactor()->isStable())
      std::cout << "Everything is in order." << std::endl;
    else
      std::cout << "Critical failure imminent." << std::endl;
  }
}
