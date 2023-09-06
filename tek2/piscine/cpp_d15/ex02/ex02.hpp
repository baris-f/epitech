#ifndef EX02_H_
# define EX02_H_

#include <iostream>
#include <cstring>

template<typename Type>
Type     min(const Type& a, const Type& b)
{
  std::cout << "template min" << std::endl;
  if (a > b)
    return (b);
  else
    return (a);
}

int     min(int a, int b)
{
  std::cout << "non-template min" << std::endl;
  if (a > b)
    return (b);
  else
    return (a);
}

template<typename Type>
Type     templateMin(Type* tab, int size)
{
  Type cmin;

  if (size == 0)
    return (0);
  cmin = tab[0];
  for (int i = 0; i < size; i++)
    cmin = min(cmin, tab[i]);
  return (cmin);
}

int	nonTemplateMin(int* tab, int size)
{
  int cmin;

  if (size == 0)
    return (0);
  cmin = tab[0];
  for (int i = 0; i < size; i++)
    cmin = min<int>(cmin, tab[i]);
  return (cmin);
}




#endif /* !EX02_H_ */
