#ifndef _VICTIM_HH_
# define _VICTIM_HH_

#include <iostream>

class	Victim {
public :
  Victim(std::string);
  ~Victim();
protected :
  std::string	_name;

public :
  std::string const&	getName() const;
  virtual void 		getPolymorphed() const;
};

std::ostream&	operator<<(std::ostream&, Victim const&);

#endif /* _VICTIM_HH_ */
