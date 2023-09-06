//
// Federation.cpp for fede in /home/baris_f/rendu/tek2/cpp_d07m
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Tue Jan 10 09:37:13 2017 baris_f
// Last update Tue Jan 10 16:37:52 2017 baris_f
//

#include "Federation.hh"

namespace Federation {
  namespace Starfleet {

    Ship::Ship(int length, int width, std::string name, short maxWarp)
    {
      _length = length;
      _width = width;
      _name = name;
      _maxWarp = maxWarp;
      std::cout << "The ship USS " << name << " has been finished. It is " << length << " m in length and " << width << " m in width." << std::endl << "It can go to Warp " << maxWarp << "!" << std::endl;
    }

    Ship::~Ship()
    {

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
  }
  Ship::Ship(int length, int width, std::string name)
  {
    _length = length;
    _width = width;
    _name = name;
    _maxWarp = 1;
    std::cout << "The independant ship " << name << " just finished its construction. It is " << length << " m in length and " << width << " m in width." << std::endl;
  }

  Ship::~Ship()
  {

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
}
/*
int main(void)
{
  Federation::Starfleet::Ship UssKreog(289, 132, "Kreog", 6);
  Federation::Ship Independant(150, 230, "Greok");
  WarpSystem::QuantumReactor QR;
  WarpSystem::QuantumReactor QR2;
  WarpSystem::Core core(&QR);
  WarpSystem::Core core2(&QR2);

  UssKreog.setupCore(&core);
  UssKreog.checkCore();
  Independant.setupCore(&core2);
  Independant.checkCore();

  QR.setStability(false);
  QR2.setStability(false);
  UssKreog.checkCore();
  Independant.checkCore();
  return 0;
}
*/
