/*
** main.c for asm in /home/dudu/rendu/CPE_2015_corewar/asm
**
** Made by lucas duval
** Login   <duval_m@epitech.net>
**
** Started on  Tue Mar 15 10:53:38 2016 lucas duval
** Last update Sun Mar 27 22:39:15 2016 lucas duval
*/

#include "my.h"

int		init(t_base *base, char *av)
{
  int	fd;

  fd = open(av, O_RDONLY);
  if (fd == -1)
    {
      my_printf("File %s not accessible\n", av);
      return (-1);
    }
  base->fd = fd;
  base->filename = get_filename(av);
  return (0);
}

char	**recuparg2(char *instruct, char separ, int i, char **arg)
{
  int	k;
  int	j;

  j = 0;
  k = 0;
  while (instruct[++i])
    {
      if (instruct[i] != separ)
	arg[j][k++] = instruct[i];
      else
	{
	  arg[j++][k] = '\0';
	  k = 0;
	}
    }
  arg[j + 1] = '\0';
  return (arg);
}

char	**recuparg(char *instruct, char separ)
{
  int	i;
  int	count;
  char	**arg;

  count = 2;
  i = -1;
  while (instruct != NULL && instruct[++i])
    if (instruct[i] == separ)
      count++;
  arg = my_malloc(sizeof(char *) * count);
  i = -1;
  while (++i < count)
    arg[i] = my_malloc(sizeof(char) * my_strlen(instruct));
  i = -1;
  return (recuparg2(instruct, separ, i, arg));
}

int		main(int ac, char **av)
{
  t_base	base;

  if (ac != 2)
    {
      my_printf("Bad usage: ./asm file\n");
      return (1);
    }
  if (init(&base, av[1]) == -1 || trait(&base) == -1)
    return (1);
  return (0);
}
