#ifndef KOALADOCTORLIST_H_
# define KOALADOCTORLIST_H_

#include "koaladoctor.h"

struct	KoalaDoctorList
{
  KoalaDoctorList(KoalaDoctor*);
  ~KoalaDoctorList();

  KoalaDoctor	*koala;
  KoalaDoctorList	*next;
  bool		isEnd();
  void		append(KoalaDoctorList*);
  KoalaDoctor	*getFromName(std::string);
  KoalaDoctorList	*remove(KoalaDoctorList*);
  KoalaDoctorList	*removeFromName(std::string);
  void		dump();
  KoalaDoctor	*getContent();
  KoalaDoctorList	*getNext();
};

#endif /* !SICKKOALALIST_H_ */
