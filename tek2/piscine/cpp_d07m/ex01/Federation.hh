#ifndef	FEDERATION_HH_
 #define FEDERATION_HH_

#include <iostream>
#include "WarpSystem.hh"

namespace Federation {
  namespace Starfleet{
    class Captain {
    public :
      Captain(std::string);
      ~Captain();
    private :
      std::string	_name;
      int		_age;
    public :
      std::string	getName();
      int		getAge();
      void		setAge(int);
    };
    class Ensign {
    public :
      Ensign(std::string);
      ~Ensign();
    private :
      std::string	_name;
    };
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
      Captain		*_captain;
    public :
      void		setupCore(WarpSystem::Core*);
      void		checkCore();
      void		promote(Captain*);
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
