#ifndef EX03_H_
# define EX03_H_

#include <iostream>

template <typename t>
void	print(const t& elem)
{
  std::cout << elem << std::endl;
}

template <typename t>
void	foreach(t * tab, void(& func)(const t&), int size)
{
  for (int i = 0; i < size; i++)
    func(tab[i]);
}

#endif /* !EX03_H_ */
