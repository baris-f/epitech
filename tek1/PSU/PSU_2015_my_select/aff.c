/*
** aff.c for aff in /home/baris-f/rendu/PSU_2015_my_select
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sun Dec 13 14:06:00 2015 Florent Baris
** Last update Sun Dec 13 17:30:20 2015 Florent Baris
*/

#include <ncurses.h>
#include <stdlib.h>
#include "my_select.h"

void	initaff(t_all *s, t_size *t)
{
  t->trow = 0;
  t->tcol = 0;
  t->lcol = 0;
  s->nb_ocur = 0;
  s->selected = 0;
}

void	exitspace(t_all *s)
{
  endwin();
  delscreen(s->screen);
  my_printf("./my_select : not enought space\n");
  exit(0);
}

void    setnameon(t_all *s, int i)
{
  if (i == s->cur - 1)
    attron(A_UNDERLINE);
  if (matchselect(s->tab[i].name, s->search) == 0)
    {
      if (s->tab[i].hlight == 1)
	{
	  attron(A_REVERSE);
	  s->selected++;
	}
    }
  else
    {
      attron(COLOR_PAIR(1));
      s->nb_ocur++;
    }
}

void    setnameoff(t_all *s, int i)
{
  if (i == s->cur - 1)
    attroff(A_UNDERLINE);
  if (matchselect(s->tab[i].name, s->search) == 0)
    (s->tab[i].hlight == 1) ? (attroff(A_REVERSE)) : 0;
  else
    attroff(COLOR_PAIR(1));
}

void            aff(t_all *s)
{
  int           i;
  t_size        t;

  initaff(s, &t);
  i = -1;
  while (s->tab[++i].name)
    {
      getmaxyx(stdscr, t.row, t.col);
      t.row--;
      setnameon(s, i);
      if (t.tcol + t.lcol > t.col)
	exitspace(s);
      if (t.trow >= t.row)
	{
	  t.tcol += t.lcol;
	  t.lcol = 0;
	  t.trow = 0;
	}
      if (my_strlen(s->tab[i].name) + 1 > t.lcol)
	t.lcol = my_strlen(s->tab[i].name) + 1;
      mvprintw(t.trow, t.tcol, "%s", s->tab[i].name);
      setnameoff(s, i);
      t.trow++;
    }
}
