#ifndef SICKKOALA_H_
# define SICKKOALA_H_

#include <iostream>
#include <algorithm>

struct		SickKoala
{
  SickKoala(std::string);
  ~SickKoala();
  std::string	name;
  void		poke();
  bool		takeDrug(std::string);
  void		overDrive(std::string);
  std::string	getName();
};

#endif /* !SICKKOALA_H_ */
