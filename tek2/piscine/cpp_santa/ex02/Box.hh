#ifndef _BOX_HH_
# define _BOX_HH_

#include "Wrap.hh"

class	Box : public Wrap, public Object
{
public :
  Box();
  ~Box();
public :
  void	wrapMeThat(Object*);
  void	openMe();
  void	closeMe();
};
#endif /* _BOX_HH_ */
