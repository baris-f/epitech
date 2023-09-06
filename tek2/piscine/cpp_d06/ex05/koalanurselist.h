#ifndef KOALANURSELIST_H_
# define KOALANURSELIST_H_

#include "koalanurse.h"

struct	KoalaNurseList
{
  KoalaNurseList(KoalaNurse*);
  ~KoalaNurseList();

  KoalaNurse	*koala;
  KoalaNurseList	*next;
  bool		isEnd();
  void		append(KoalaNurseList*);
  KoalaNurse	*getFromID(int);
  KoalaNurseList	*remove(KoalaNurseList*);
  KoalaNurseList	*removeFromID(int);
  void		dump();
  KoalaNurse	*getContent();
  KoalaNurseList	*getNext();
};

#endif /* !KOALANURSELIST_H_ */
