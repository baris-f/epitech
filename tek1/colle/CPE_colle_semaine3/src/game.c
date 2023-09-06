/*
** game.c for 2048 in /home/baris-f/rendu/colle/CPE_colle_semaine3
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Fri May 13 15:41:21 2016 Florent Baris
** Last update Fri May 13 16:59:40 2016 Florent Baris
*/

#include "2048.h"

void	move_down(t_base *_m)
{
  int	j;
  int	i;
  int	tmp;

  i = -1;
  while (++i < 4)
    {
      tmp = 4;
      while (--tmp >= 0)
	{
	  j = tmp - 1;
	  while (++j < 4)
	    {
	      if (j + 1 < 4  && _m->grid[j * 4 + i] != 0
		  && _m->grid[(j + 1) * 4 + i] == _m->grid[j * 4 + i])
		set_cell_down(_m, j * 4 + i, 0);
	      else if (j + 1 < 4 && _m->grid[(j + 1) * 4 + i] == 0
		       && _m->grid[j * 4 + i] != 0)
		set_cell_down(_m, j * 4 + i, 1);
	    }
	}
    }
}

void	move_up(t_base *_m)
  {
  int	j;
  int	i;
  int	tmp;

  i = -1;
  while (++i < 4)
    {
      tmp = -1;
      while (++tmp < 4)
	{
	  j = tmp + 1;
	  while (--j >= 0)
	    {
	      if (j - 1 >= 0  && _m->grid[j * 4 + i] != 0
		  && _m->grid[(j - 1) * 4 + i] == _m->grid[j * 4 + i])
		set_cell_up(_m, j * 4 + i, 0);
	      else if (j - 1 >= 0 && _m->grid[(j - 1) * 4 + i] == 0
		       && _m->grid[j * 4 + i] != 0)
		set_cell_up(_m, j * 4 + i, 1);
	    }
	}
    }
}

void	move_right(t_base *_m)
{
  int	j;
  int	i;
  int	tmp;

  i = -1;
  while (++i < 4)
    {
      tmp = 4;
      while (--tmp >= 0)
	{
	  j = tmp - 1;
	  while (++j < 4)
	    {
	      if (j + 1 < 4  && _m->grid[i * 4 + j] != 0
		  && _m->grid[i * 4 + j + 1] == _m->grid[i * 4 + j])
		set_cell_right(_m, i * 4 + j, 0);
	      else if (j + 1 < 4 && _m->grid[i * 4 + j + 1] == 0
		       && _m->grid[i * 4 + j] != 0)
		set_cell_right(_m, i * 4 + j, 1);
	    }
	}
    }
}

void	move_left(t_base *_m)
{
  int   j;
  int   i;
  int   tmp;

  i = -1;
  while (++i < 4)
    {
      tmp = -1;
      while (++tmp < 4)
	{
	  j = tmp + 1;
	  while (--j > 0)
	    {
	      if (j - 1 >= 0  && _m->grid[i * 4 + j] != 0
		  && _m->grid[i * 4 + j - 1] == _m->grid[i * 4 + j])
		set_cell_left(_m, i * 4 + j, 0);
	      else if (j - 1 >= 0 && _m->grid[i * 4 + j - 1] == 0
		       && _m->grid[i * 4 + j] != 0)
		set_cell_left(_m, i * 4 + j, 1);
	    }
	}
    }
}
int	move(t_base *_m)
{
  if (_m->move == 1)
    move_left(_m);
  else if (_m->move == 2)
    move_right(_m);
  else if (_m->move == 3)
    move_up(_m);
  else if (_m->move == 4)
    move_down(_m);
  return (0);
}
