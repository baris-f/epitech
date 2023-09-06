#ifndef _PEON_HH_
# define _PEON_HH_

#include <iostream>
#include "Victim.hh"

class	Peon : public Victim {
public :
  Peon(std::string);
  ~Peon();
public :
  virtual void		getPolymorphed() const;
};


#endif /* _PEON_HH_ */
