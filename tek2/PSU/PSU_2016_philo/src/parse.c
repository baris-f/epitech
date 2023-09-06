/*
** parse.c for parse in /home/baris_f/rendu/tek2/PSU_2016_philo
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Wed Mar  8 12:35:01 2017 baris_f
** Last update Wed Mar  8 13:41:50 2017 baris_f
*/

#include "philo.h"

int	parse(int ac, char** av, int *p, int*e)
{
  int	i;

  if (ac < 5)
    {
      fprintf(stderr, "Usage : %s -p nbphilo -e nbeat\n", av[0]);
      return (-1);
    }
  *p = 0;
  *e = 0;
  i = -1;
  while (++i < ac)
      if (av[i][0] == '-')
	{
	  if (av[i][1] == 'p' && av[i + 1])
	    *p = atoi(av[i + 1]);
	  else if (av[i][1] == 'e' && av[i + 1])
	    *e = atoi(av[i + 1]);
	}
  if (*p <= 0 || *e <= 0)
    {
      fprintf(stderr, "error : nbphilo or nbeat inferior or egal to 0.\n");
      return (-1);
    }
  return (0);
}
