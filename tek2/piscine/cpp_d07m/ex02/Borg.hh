#ifndef BORG_HH_
 #define BORG_HH_

#include "Federation.hh"

namespace Borg {
  class Ship {
  public :
    Ship();
    ~Ship();
  private :
    int		_side;
    short	_maxWarp;
    WarpSystem::Core  *_core;
    Destination         _location;
    Destination         _home;
  public:
    void              setupCore(WarpSystem::Core*);
    void              checkCore();
    bool move(int, Destination); // move _location to d
    bool move(int); // move _location to _home
    bool move(Destination); // move _location to d
    bool move(); // move _location to _home
  };
}

#endif /* BORG_HH_ */
