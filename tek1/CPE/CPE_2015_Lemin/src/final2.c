/*
** final2.c for lemin in /home/baris-f/rendu/CPE/CPE_2015_Lemin
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sun Apr 24 22:49:38 2016 Florent Baris
** Last update Thu Apr 28 13:06:15 2016 Florent Baris
*/

#include "lemin.h"

int     notended(t_base *base)
{
  int   i;
  int   nb;

  i = -1;
  nb = 0;
  while (++i < base->nb_four)
    if (base->four[i].x != base->end)
      nb++;
  return (nb);
}

void    sort(t_base *base)
{
  int   i;
  int   stop;
  t_ret tmp;

  stop = 1;
  while (stop)
    {
      stop = 0;
      i = -1;
      while (++i < base->nb_path - 1)
	{
	  if (base->ret[i].len > base->ret[i + 1].len)
	    {
	      tmp = base->ret[i];
	      base->ret[i] = base->ret[i + 1];
	      base->ret[i + 1] = tmp;
	      stop = 1;
	    }
	}
    }
  print(base);
}

void	setk(t_base *base, int i, int j, int k)
{
  if (base->ret[i].path[j] != base->end)
    base->room[base->ret[i].path[j]] = 1;
  base->room[base->four[k].x] = 0;
  aff(k + 1, base->ret[i].path[j], 0);
  base->four[k].x = base->ret[i].path[j];
  base->four[k].y = 1;
}
