#ifndef _GIFTPAPER_HH_
# define _GIFTPAPER_HH_

#include "Wrap.hh"
#include "Box.hh"

class	GiftPaper : public Wrap
{
public :
  GiftPaper(std::string name = "GiftPaper");
  ~GiftPaper();
public :
  void	wrapMeThat(Box*);
};

#endif /* _GIFTPAPER_HH_ */
