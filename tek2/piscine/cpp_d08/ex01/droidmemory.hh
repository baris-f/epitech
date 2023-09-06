#ifndef _DROIDMEMORY_HH_
# define _DROIDMEMORY_HH_

#include <iostream>
#include <cstdlib>

class	DroidMemory {
public :
  DroidMemory();
  ~DroidMemory();
  DroidMemory  &operator<<(DroidMemory const &);
  DroidMemory  &operator>>(DroidMemory &);
  DroidMemory  &operator+=(DroidMemory const &);
  DroidMemory  &operator+=(size_t const);
  DroidMemory     operator+(DroidMemory const &) const;
private :
  size_t	_FingerPrint;
  size_t	_Exp;
public :
  size_t	getFingerPrint() const;
  void		setFingerPrint(size_t);
  size_t	getExp() const;
  void		setExp(size_t);
};

std::ostream&    operator<<(std::ostream&, DroidMemory const &);

#endif /* _DROIDMEMORY_HH_ */
