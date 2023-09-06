#ifndef EX04_H_
# define EX04_H_

#include <iostream>

template<typename t>
bool	equal(const t & a, const t & b);

template<typename t>
class	Tester {
public :
  bool	equal(const t &, const t &);
};

#endif /* !EX04_H_ */
