#ifndef EX01_H_
# define EX01_H_

#include <iostream>
#include <cstring>

template<class Type>
int	compare(const Type& a, const Type& b)
{
  if (a < b)
    return (-1);
  else if (a > b)
    return (1);
  else
    return (0);
}

int	compare(const char * a, const char * b)
{
  if (strcmp(a, b) < 0)
    return (-1);
  else  if (strcmp(a, b) > 0)
    return (1);
  else
    return (0);
}

#endif /* !EX01_H_ */
