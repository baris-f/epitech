#ifndef _BOX_HH_
# define _BOX_HH_

#include "Wrap.hh"
#include "Object.hh"

class	Box : public Wrap
{
public :
  Box(std::string name = "Box");
  ~Box();
public :
  void	wrapMeThat(Object *);
};
#endif /* _BOX_HH_ */
