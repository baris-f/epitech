#ifndef _WRAP_HH_
# define _WRAP_HH_

#include <iostream>

#include "Object.hh"

class Wrap
{
public:
  Wrap(){};
  ~Wrap(){};
protected:
  bool		_opened;
  Object	*_content;
public :
  void		wrapMeThat();
  void		openMe();
  Object*	takeMe();
};

#endif /* _WRAP_HH_ */
