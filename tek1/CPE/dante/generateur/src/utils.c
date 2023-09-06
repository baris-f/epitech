/*
** mrand.c for  in /home/fus/taff/dante/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Tue May  3 21:29:37 2016 Gaspard Thirion
** Last update Fri Jun  3 12:27:25 2016 Florent Baris
*/

#include "dante.h"

int     check_match(char *s1, char *s2)
{
  if (*s1 == *s2 && *s1 == '\0')
    return (1);
  if (*s1 == *s2 && *s1 != '\0')
    return (check_match(s1 + 1, s2 + 1));
  if (*s2 == '*' && *s1 != '\0')
    return (check_match(s1 + 1, s2) || check_match(s1, s2 + 1));
  if (*s2 == '*' && *s1 == '\0')
    return (check_match(s1, s2 + 1));
  return (0);
}

int     match(char *s1, char *s2)
{
  return (check_match(s1, s2));
}

int		mrand(int min, int max, unsigned long seed)
{
  if (seed > 0)
    srand(seed);
  return (rand() % (max + 1 - min) + min);
}

void		affmaz(t_maz *maz, int opt)
{
  int		i;

  i = -1;
  while (++i < maz->size - 1)
    {
      if (i != 0 && i % maz->x == 0)
	my_printf("\n");
      if (opt && (maz->tab[i] == 'P' || maz->tab[i] == 'I'))
	write(1, ".", 1);
      else if (opt || (!opt && maz->tab[i] == '*'))
	write(1, "X", 1);
      else
	write(1, &(maz->tab[i]), 1);
    }
  write(1, ".", 2);
  my_printf("\n");
}

int		outmaz(t_maz *maz, char *out)
{
  int		fd;
  int		i;

  remove(out);
  if ((fd = open(out, O_WRONLY | O_CREAT | O_EXCL, 00644)) == -1)
    return (-4);
  i = -1;
  while (++i < maz->size - 1)
    {
      if (i != 0 && i % maz->x == 0)
	write(fd, "\n", 1);
      if (maz->tab[i] == 'P' || maz->tab[i] == 'I')
	write(fd, "*", 1);
      else
	write(fd, "X", 1);
    }
  write(fd, "*", 1);
  close(fd);
  return (0);
}
