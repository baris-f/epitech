#ifndef KOALANURSE_H_
# define KOALANURSE_H_

#include <fstream>
#include "sickkoala.h"

struct          KoalaNurse
{
  KoalaNurse(int);
  ~KoalaNurse();
  int		ID;
  bool		status;
  void          giveDrug(std::string, SickKoala*);
  std::string   readReport(std::string);
  void		timeCheck();
};


#endif /* !KOALANURSE_H_ */
