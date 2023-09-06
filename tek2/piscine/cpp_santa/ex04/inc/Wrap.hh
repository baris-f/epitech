#ifndef _WRAP_HH_
# define _WRAP_HH_

#include <iostream>

#include "Object.hh"

class Wrap : public Object
{
public:
  Wrap(std::string const &, std::string const&, int, bool);
  Wrap(Wrap const &);
  ~Wrap();
protected:
  bool		_opened;
  Object	*_content;
public :
  void		wrapMeThat(Object *);
  void		openMe();
  void		closeMe();
  Object*	takeMe();
  bool		getOpened();
};

#endif /* _WRAP_HH_ */
