/*
** game.c for 2048 in /home/baris-f/rendu/colle/CPE_colle_semaine3
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Fri May 13 15:12:38 2016 Florent Baris
** Last update Fri May 13 16:56:44 2016 Florent Baris
*/

#include "2048.h"

int	mrand(int min, int max)
{
  return (rand() % (max + 1 - min) + min);
}

int	new_number(t_base *_m)
{
  int	nb;
  int	i;

  i = -1;
  while (_m->grid[(nb = mrand (0, 15))] != 0 && ++i < 200);
  if (i == 200)
    return (-1);
  _m->grid[nb] = 1;
  return (0);
}
