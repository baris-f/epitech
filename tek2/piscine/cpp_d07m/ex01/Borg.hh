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
  public:
    void              setupCore(WarpSystem::Core*);
    void              checkCore();
  };
}

#endif /* BORG_HH_ */
