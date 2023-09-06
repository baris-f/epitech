#ifndef	FEDERATION_HH_
 #define FEDERATION_HH_

#include <iostream>
#include "WarpSystem.hh"

namespace Federation {
  namespace Starfleet{
    class Ship{
    public :
      Ship(int, int, std::string, short);
      ~Ship();
    private :
      int		_length;
      int		_width;
      std::string	_name;
      short		_maxWarp;
      WarpSystem::Core	*_core;
    public :
      void		setupCore(WarpSystem::Core*);
      void		checkCore();
    };
  };
  class Ship{
  public :
    Ship(int, int, std::string);
    ~Ship();
  private :
    int               _length;
    int               _width;
    std::string       _name;
    short             _maxWarp;
    WarpSystem::Core              *_core;
  public :
    void              setupCore(WarpSystem::Core*);
    void		checkCore();
  };
};


#endif	/* FEDERATION_HH_ */
