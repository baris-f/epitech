/*
** over.c for p4 in /home/baris-f/rendu/colle/CPE_colle_semaine2
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Wed May  4 15:36:36 2016 Florent Baris
** Last update Wed May  4 18:21:25 2016 Florent Baris
*/

#include "p4.h"

int	limit(t_p4 *p4, int idx, int x, int y)
{
  x += idx % p4->size.x;
  y += idx / p4->size.y;
  if (x < 0 || x > p4->size.x || y < 0 || y > p4->size.y)
    return (0);
  return (1);
}

int     affend(t_p4 *p4, char p, int idx, int sens)
{
  int   i;

  i = -1;
  if (sens == 1)
    while (++i < 4)
      p4->map[idx + i] = p4->end;
  else if (sens == 2)
    while (++i < 4)
      p4->map[idx + i + i * p4->size.y] = p4->end;
  else if (sens == 3)
    while (++i < 4)
      p4->map[idx + i * p4->size.y] = p4->end;
  else
    while (++i < 4)
      p4->map[idx - i + i * p4->size.y] = p4->end;
  aff(p4);
  my_putstr("Congrats, player ");
  my_putchar(p);
  my_putstr(" won !\n");
  return (1);
}

int     check(t_p4 *p4, char p, int idx)
{
  int   i;

  i = -1;
  while (p4->map[idx + ++i] == p && i < 4 && limit(p4, idx, i, 0));
  if (i == 4)
    return (affend(p4, p, idx, 1));
  i = 0;
  while (p4->map[idx + i + i * p4->size.y] == p && i < 4 &&
	 limit(p4, idx, i, i))
    i++;
  if (i == 4)
    return (affend(p4, p, idx, 2));
  i = -1;
  while (p4->map[idx + ++i * p4->size.y] == p && i < 4 && limit(p4, idx, 0, i));
  if (i == 4)
    return (affend(p4, p, idx, 3));
  i = 0;
  while (p4->map[idx - i + i * p4->size.y] == p && i < 4 &&
	 limit(p4, idx, -i, i))
    i++;
  if (i == 4)
    return (affend(p4, p, idx, 4));
  return (0);
}

int     over(t_p4 *p4)
{
  int   i;
  int	j;

  i = -1;
  while (++i < p4->size.x)
    if (p4->map[i] == ' ')
      i = p4->size.x + 2;
  if (i == p4->size.x)
    {
      my_putstr("It's a tie, nobody wins.\n");
      return (1);
    }
  i = -1;
  while (++i < p4->size.y)
    {
      j = -1;
      while (++j < p4->size.x)
	if (p4->map[p4->size.y * i + j % p4->size.x] != ' ')
	  if (check(p4, p4->map[p4->size.y * i + j % p4->size.x],
		    p4->size.y * i + j % p4->size.x) == 1)
	    return (1);
    }
  return (0);
}
