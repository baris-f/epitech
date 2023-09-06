/*
** input.c for input in /home/baris-f/rendu/PSU_2015_my_select
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Wed Dec  2 20:17:16 2015 Florent Baris
** Last update Sun Dec 13 17:47:21 2015 Florent Baris
*/

#include <ncurses.h>
#include <stdlib.h>
#include "my_select.h"

void    controls(t_all *s)
{
  if (s->key == 260)
    s->cur -= s->row;
  s->nb_col_full = s->max / s->row;
  s->nb_elem_last_col = s->max - s->row * s->nb_col_full;
  (s->cur <= 0) ? (s->cur + s->row <= s->nb_elem_last_col) ?
    (s->cur += s->row * (s->nb_col_full + 1) - 1) :
    (s->cur += s->row * (s->nb_col_full) - 1): 0;
  if (s->key == 261)
    s->cur += s->row;
  if (s->cur > s->max)
    s->cur = s->cur % s->row + 1;
  (s->key == 32) ? ((s->tab[s->cur - 1].hlight == 1) ?
		    (s->tab[++s->cur - 2].hlight = 0) :
		    (s->tab[++s->cur - 2].hlight = 1)) : 0;
  if (s->key == 259)
    s->cur--;
  if (s->cur < 1)
    s->cur = s->max;
  if (s->key == 258)
    s->cur++;
  if (s->cur > s->max)
    s->cur = 1;
}

void	opt(t_all *s)
{
  s->i = -1;
  if (s->key == 18)
    while (s->tab[++s->i].name)
      (s->tab[s->i].hlight == 1) ? (s->tab[s->i].hlight = 0)
	: (s->tab[s->i].hlight = 1);
  if (s->key == 1)
    while (s->tab[++s->i].name)
      (s->tab[s->i].hlight = 1);
  if (s->key == 4)
    while (s->tab[++s->i].name)
      (s->tab[s->i].hlight = 0);
  while (isprintable(s->key))
    search(s);
}

int     keyexit(t_all *s)
{
  if (s->key == 263 || s->key == 330)
    {
      s->max--;
      free(s->tab[s->cur - 1].name);
      s->i = s->cur - 2;
      while (s->tab[++s->i].name)
	s->tab[s->i] = s->tab[(s->i + 1)];
      (s->cur > s->max) ? (s->cur--) : 0;
    }
  if (s->key == 10 || s->tab[0].name == NULL)
    {
      endwin();
      delscreen(s->screen);
      while (++s->i < s->max)
      	{
      	  if (s->tab[s->i].hlight == 1)
      	    my_printf("%s ", s->tab[s->i].name);
      	  free(s->tab[s->i].name);
      	}
      my_putchar('\n');
      free(s->search);
      free(s->tab);
      return (1);
    }
  return (0);
}
