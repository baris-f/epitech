/*
** draw_letters.c for letetrs in /home/baris-f/rendu/PSU/PSU_2015_tetris
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Tue Mar  1 17:59:32 2016 Florent Baris
** Last update Thu Mar 10 16:33:19 2016 Florent Baris
*/

#include "tetris.h"

void	draw_letter(t_tetris *tet, t_2D *pos, char *str, int size)
{
  int   i;

  i = -1;
  while (str[++i])
    {
      if (str[i] == 'X')
	mvwprintw(tet->win, pos->y, pos->x + i % size, " ");
      if ((i + 1) % size == 0 && i != 0)
      	pos->y++;
    }
}
