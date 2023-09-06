#ifndef SICKKOALALIST_H_
# define SICKKOALALIST_H_

#include "sickkoala.h"

struct	SickKoalaList
{
  SickKoalaList(SickKoala*);
  ~SickKoalaList();

  SickKoala	*koala;
  SickKoalaList	*next;
  bool		isEnd();
  void		append(SickKoalaList*);
  SickKoala	*getFromName(std::string);
  SickKoalaList	*remove(SickKoalaList*);
  SickKoalaList	*removeFromName(std::string);
  void		dump();
  SickKoala	*getContent();
  SickKoalaList	*getNext();
};

#endif /* !SICKKOALALIST_H_ */
