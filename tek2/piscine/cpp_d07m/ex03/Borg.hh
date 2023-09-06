#ifndef BORG_HH_
 #define BORG_HH_

#include "Federation.hh"

namespace Federation {
  namespace Starfleet {
    class Ship;
  }
  class Ship;
}

namespace Borg {
  class Ship {
  public :
    Ship(int, short);
    Ship(int);
    Ship();
    ~Ship();
  private :
    int		_side;
    short	_maxWarp;
    WarpSystem::Core  *_core;
    Destination         _location;
    Destination         _home;
    int			_shield;
    int			_weaponFrequency;
    short		_repair;
  public:
    void              setupCore(WarpSystem::Core*);
    void              checkCore();
    bool move(int, Destination); // move _location to d
    bool move(int); // move _location to _home
    bool move(Destination); // move _location to d
    bool move(); // move _location to _home
    int getShield();
    void setShield(int);
    int getWeaponFrequency();
    void setWeaponFrequency(int);
    short getRepair();
    void setRepair(short);
    void	fire(Federation::Starfleet::Ship*);
    void	fire(Federation::Ship*);
    void	repair();
  };
}

#endif /* BORG_HH_ */
