/*
** main.c for ds in /home/fus/taff/dante/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Tue May  3 21:22:12 2016 Gaspard Thirion
** Last update Fri Jun  3 12:35:00 2016 Florent Baris
*/

#include "dante.h"

void		libere(t_maz *maz)
{
  free(maz->prev);
  free(maz->tab);
}

int		err(int e)
{
  if (e == -1)
    my_printf("memory error\n");
  else if (e == -2)
    my_printf("usage : ./mazgen type[p|i|c] X Y [seed]\n");
  else if (e == -3)
    my_printf("minimal size : 2x2\n");
  else if (e == -4)
    my_printf("output error : \nmaybe already existing file out.maz\n");
   else if (e == -5)
    my_printf("unable to create maze, change seed\n");
  return (e);
}

int		initmaz(t_maz *maz)
{
  int		i;

  maz->size = maz->x * maz->y;
  if ((maz->tab = malloc(sizeof(char) * maz->size)) == NULL
      || (maz->prev = malloc(sizeof(int) * maz->size)) == NULL)
    return (-1);
  i = -1;
  while (++i < maz->size)
    maz->tab[i] = '*';
  my_printf("Dimension : %dx%d seed : %d type = ",
	    maz->x, maz->y, maz->seed);
  my_printf(((maz->type == 2) ? ("cellular\n")
	     : (maz->type == 1) ? ("imperfect\n")
	     : ("perfect\n")));
  return (0);
}

int		main(int ac, char **av)
{
  t_maz		maz;
  int		e;
  char		c;

  if (ac < 3 || ac > 5 || (av[3] && match("parfait", av[3]) != 0
			   && (c = av[3][0]) != 'p' && c != 'i' && c != 'c'))
    return (err(-2));
  (ac < 4) ? (c = 'i') : (0);
  if ((maz.x = my_getnbr(av[1])) < 2
      || (maz.y = my_getnbr(av[2])) < 2)
    return (err(-3));
  if (ac > 4 && match("parfait", av[3]) == 0)
    c = 'p';
  maz.type = (c == 'i') ? (1) : (c == 'c') ? (2) : (0);
  maz.seed = (ac == 5) ? ((unsigned long)my_getnbr(av[4]))
    : ((unsigned long)av[0]);
  mrand(0, 10, maz.seed);
  if ((e = initmaz(&maz)) < 0
      || ((maz.type == 0) && (e = perfect(&maz)) < 0)
      || ((maz.type == 1) && (e = imperfect(&maz)) < 0)
      || ((maz.type == 2) && (e = cellular(&maz)) < 0)
      || (e = outmaz(&maz, (c == 'i') ? ("imperfect.maz")
		     : (c == 'c') ? ("cellular.maz")
		     : ("perfect.maz"))) < 0)
    return (err(e));
  affmaz(&maz, 1);
  libere(&maz);
  return (0);
}
