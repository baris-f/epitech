/*
** parse.c for parse in /home/baris_f/rendu/tek2/PSU_2016_philo
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Wed Mar  8 12:35:01 2017 baris_f
** Last update Sat Jul  1 15:11:43 2017 baris_f
*/

#include "ia.h"

int     affHelp(char **av)
{
  fprintf(stderr, "USAGE: %s -p port -n name -h machine\n\tport is\
 the port number\n\tname is the name of the team\n\tmachine is the name of the \
 machine; localhost by default\n", av[0]);
  return (-1);
}

int	parse(int ac, char** av, t_data *d)
{
  int	i = -1;

  if (ac == 2 && strcmp(av[1], "-help") == 0)
    return (affHelp(av));
  while (++i < ac)
      if (av[i][0] == '-')
	{
	  if (av[i][1] == 'p' && av[i + 1])
	    d->port = atoi(av[i + 1]);
	  else if (av[i][1] == 'n' && av[i + 1])
	    d->name = strdup(av[i + 1]);
	  else if (av[i][1] == 'h' && av[i + 1])
	    d->machine = strdup(av[i + 1]);
	}
  if (d->name == NULL || d->machine == NULL || d->port == -1)
    return (affHelp(av));
  printf("port : %d\nname : %s\nmachine : %s\n", d->port, d->name, d->machine);
  return (0);
}
