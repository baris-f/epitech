#ifndef _GIFTPAPER_HH_
# define _GIFTPAPER_HH_

#include "Wrap.hh"

class	GiftPaper : public Wrap, public Object
{
public :
  GiftPaper(std::string name = "GiftPaper");
  ~GiftPaper();
public :
  void	wrapMeThat(Object*);
  void	openMe();
};

#endif /* _GIFTPAPER_HH_ */
