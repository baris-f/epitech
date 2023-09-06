/*
** main.c for p4 in /home/baris-f/rendu/colle/CPE_colle_semaine1
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Wed Apr 27 15:09:55 2016 Florent Baris
** Last update Wed May  4 18:26:57 2016 Florent Baris
*/

#include "p4.h"

int	init(t_p4 *p4)
{
  p4->size.x = 7;
  p4->size.y = 6;
  p4->p1 = 'X';
  p4->p2 = 'O';
  p4->end = '#';
  p4->ia = 1;
  srand(time(NULL));
  return (0);
}

int	end(t_p4 *p4)
{
  (void)p4;
  return (0);
}

int		main(int ac, char **av)
{
  t_p4	p4;
  int	i;

  (void)ac;
  (void)av;
  if (init(&p4) == -1)
    return (-1);
  if ((p4.map = malloc(sizeof(char) * p4.size.x * p4.size.y + 1)) == NULL)
    return (-1);
  i = -1;
  while (++i < p4.size.x * p4.size.y)
    p4.map[i] = ' ';
  power4(&p4);
  end(&p4);
  return (0);
}
