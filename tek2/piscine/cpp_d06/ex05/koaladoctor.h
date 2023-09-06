#ifndef KOALADOCTOR_H_
# define KOALADOCTOR_H_

#include "koalanurse.h"

struct	KoalaDoctor
{
  KoalaDoctor(std::string);
  ~KoalaDoctor();
  std::string	name;
  bool		status;
  void		diagnose(SickKoala*);
  void		timeCheck();
  std::string	getName();
};

#endif /* !KOALADOCTOR_H_ */
