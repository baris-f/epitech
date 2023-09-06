//
// my_cat.cpp for  in /home/baris_f/rendu/tek2/cpp_d06/ex00
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Mon Jan  9 09:39:09 2017 baris_f
// Last update Mon Jan  9 19:07:29 2017 baris_f
//

#include <iostream>
#include <fstream>
#include <string>

int	main(int ac, char **av)
{
  int		i;
  std::ifstream	myfile;
  char	c;

  if (ac < 2)
    {
      std::cout << "my_cat: Usage: ./my_cat file [...]" << std::endl;
      return (0);
    }
  i = -1;
  while (++i < ac - 1)
    {
      myfile.open(av[i + 1]);
      if (myfile.is_open())
	{
	  while (myfile.get(c))
	    std::cout << c;
	  myfile.close();
	}
      else
	std::cout << "my_cat : <" << av[i + 1] << ">: No such file or directory" << std::endl;
    }
  return (0);
}
