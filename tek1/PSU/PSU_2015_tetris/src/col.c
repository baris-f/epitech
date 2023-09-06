/*
** col.c for col in /home/baris-f/rendu/PSU/PSU_2015_tetris
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sat Mar 12 00:20:00 2016 Florent Baris
** Last update Sun Mar 13 14:06:19 2016 Florent Baris
*/

#include "tetris.h"

int	iscol(t_tetris *tet)
{
  int   i;
  int   j;
  int   x;
  int   y;

  j = -1;
  i = -1;
  x = 0;
  y = 0;
  if (tet->rot == 0)
    while (++j < tet->tetriminos[tet->cur].size.y)
      {
	i = -1;
	while (++i < tet->tetriminos[tet->cur].size.x)
	  {
	    if (tet->tetriminos[tet->cur].shape[j][i] == '*')
	      {
		if (tet->tpos.y + j >= tet->siz.y || tet->map[tet->tpos.y + j][tet->tpos.x + i] != '0')
		  return (1);
	      }
	  }
      }
  else if (tet->rot == 1)
    while (++i < tet->tetriminos[tet->cur].size.x)
      {
	j = tet->tetriminos[tet->cur].size.y;
	y = 0;
	while (--j >= 0)
	  {
	    if (tet->tetriminos[tet->cur].shape[j][i] == '*')
	      if (tet->tpos.y + x >= tet->siz.y || tet->map[tet->tpos.y + x][tet->tpos.x + y] != '0')
		return (1);
	    y++;
	  }
	x++;
      }
  else if (tet->rot == 2)
    {
      j = tet->tetriminos[tet->cur].size.y;
      while (--j >= 0)
	{
	  i = tet->tetriminos[tet->cur].size.x;
	  y = 0;
	  while (--i >= 0)
	    {
	      if (tet->tetriminos[tet->cur].shape[j][i] == '*')
		{
		  if (tet->tpos.y + (tet->tetriminos[tet->cur].size.y - x) >
		      tet->siz.y || tet->map[tet->tpos.y + x][tet->tpos.x + y] != '0')
		    return (1);
		}
	      y++;
	    }
	  x++;
	}
    }
  else if (tet->rot == 3)
    {
      i = tet->tetriminos[tet->cur].size.x;
      while (--i >= 0)
	{
	  j = -1;
	  y = 0;
	  while (++j < tet->tetriminos[tet->cur].size.y)
	    {
	      if (tet->tetriminos[tet->cur].shape[j][i] == '*')
		{
		if (tet->tpos.y +  x
		    >= tet->siz.y || tet->map[tet->tpos.y + x][tet->tpos.x + y] != '0')
		  return (1);
		}
	      y++;
	    }
	  x++;
	}
    }
  return (0);
}
