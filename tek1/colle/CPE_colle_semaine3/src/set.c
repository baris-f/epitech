/*
** set.c for 2048 in /home/baris-f/rendu/colle/CPE_colle_semaine3
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Fri May 13 16:37:04 2016 Florent Baris
** Last update Fri May 13 17:00:01 2016 Florent Baris
*/

#include "2048.h"

void	set_cell_right(t_base *_m, int idx, int mov)
{
  if (mov)
    _m->grid[idx + 1] = _m->grid[idx];
  else
    _m->grid[idx + 1]++;
  _m->grid[idx] = 0;
}

void	set_cell_left(t_base *_m, int idx, int mov)
{
  if (mov)
    _m->grid[idx - 1] = _m->grid[idx];
  else
    _m->grid[idx - 1]++;
  _m->grid[idx] = 0;
}

void	set_cell_down(t_base *_m, int idx, int mov)
{
  if (mov)
    _m->grid[idx + 4] = _m->grid[idx];
  else
    _m->grid[idx + 4]++;
  _m->grid[idx] = 0;
}

void	set_cell_up(t_base *_m, int idx, int mov)
{
  if (mov)
    _m->grid[idx - 4] = _m->grid[idx];
  else
    _m->grid[idx - 4]++;
  _m->grid[idx] = 0;
}
