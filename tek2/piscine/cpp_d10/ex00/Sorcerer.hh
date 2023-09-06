#ifndef _SORCERER_HH_
# define _SORCERER_HH_

#include <iostream>
#include "Victim.hh"

class	Sorcerer {
public :
  Sorcerer(std::string, std::string);
  ~Sorcerer();
private :
  std::string	_name;
  std::string	_title;

public :
  std::string const&	getName() const;
  std::string const&	getTitle() const;
  void			polymorph(Victim const&);
};

std::ostream&	operator<<(std::ostream&, Sorcerer const&);

#endif /* _SORCERER_HH_ */
