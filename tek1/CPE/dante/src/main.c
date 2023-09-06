/*
** main.c for ds in /home/fus/taff/dante/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Tue May  3 21:22:12 2016 Gaspard Thirion
** Last update Thu May 19 23:31:54 2016 Gaspard Thirion
*/

#include "dante.h"

int		err(int e)
{
  if (e == -1)
    my_printf("memory error\n");
  else if (e == -2)
    my_printf("usage : ./parser [file] or redirection\n");
  else if (e == -3)
    my_printf("unable to load maze\n");
  else if (e == -4)
    my_printf("no solution\n");
  return (e);
}

int		main(int ac, char **av)
{
  t_maz		maz;
  int		fd;
  int		e;

  if (ac < 1 || ac > 2)
    return (err(-2));
  fd = 0;
  if (ac == 2 && av[1]
      && (fd = open(av[1], O_RDONLY)) == -1)
    return (err(-3));
  if ((e = parser(&maz, fd)) < 0
      || (e = solver(&maz, VERB)) < 0)
    return (err(e));
  affmaz(&maz, 0);
  free(maz.map);
  close(fd);
  return (0);
}
