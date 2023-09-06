#ifndef	FEDERATION_HH_
 #define FEDERATION_HH_

#include <iostream>
#include "WarpSystem.hh"
#include "Destination.hh"

namespace Borg {
  class Ship;
}

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
      Ship(int, int, std::string, short, int);
      Ship();
      ~Ship();
    private :
      int		_length;
      int		_width;
      std::string	_name;
      short		_maxWarp;
      WarpSystem::Core	*_core;
      Captain		*_captain;
      Destination	_location;
      Destination	_home;
      int		_shield;
      int		_photonTorpedo;
    public :
      void		setupCore(WarpSystem::Core*);
      void		checkCore();
      void		promote(Captain*);
      bool	move(int, Destination); // move _location to d
      bool	move(int); // move _location to _home
      bool	move(Destination); // move _location to d
      bool	move(); // move _location to _home
      int	getShield();
      void	setShield(int);
      int	getTorpedo();
      void	setTorpedo(int);
      void	fire(Borg::Ship*);
      void	fire(int, Borg::Ship*);
    };
  };
  class Ship{
  public :
    Ship(int, int, std::string);
    ~Ship();
  private :
    int			_length;
    int			_width;
    std::string		_name;
    short		_maxWarp;
    WarpSystem::Core	*_core;
    Destination		_location;
    Destination		_home;
  public :
    void              setupCore(WarpSystem::Core*);
    void		checkCore();
    bool move(int, Destination); // move _location to d
    bool move(int); // move _location to _home
    bool move(Destination); // move _location to d
    bool move(); // move _location to _home
    WarpSystem::Core	*getCore();
  };
};


#endif	/* FEDERATION_HH_ */
