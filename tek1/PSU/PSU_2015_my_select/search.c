/*
** search.c for search in /home/baris-f/rendu/PSU_2015_my_select
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Thu Dec 10 18:13:06 2015 Florent Baris
** Last update Sun Dec 13 17:32:35 2015 Florent Baris
*/

#include <ncurses.h>
#include <stdlib.h>
#include "my_select.h"

void	selectsearch(t_all *s)
{
    s->i = -1;
    while (s->tab[++s->i].name)
      if (matchselect(s->tab[s->i].name, s->search) == 1)
	s->tab[s->i].hlight = 1;
    s->j = -1;
    while (s->search[++s->j])
      s->search[s->j] = '\0';
    clear();
    aff(s);
    mvprintw(s->row, 0, "CURSOR POSITION : %d SELECTED ELEMENTS : %-*d",
	     s->cur, s->col, s->selected);
    refresh();
    s->key = getch();
    s->i = -1;
}

void	delsearch(t_all *s)
{
  s->search[s->i--] = '\0';
  aff(s);
  if (s->i >= 0)
    mvprintw(s->row, 0, "SEARCH \"%s\" %d FOUNDED", s->search, s->nb_ocur);
  else
    mvprintw(s->row, 0, "CURSOR POSITION : %d SELECTED ELEMENTS : %-*d",
	     s->cur, s->col, s->selected);
  refresh();
  s->key = getch();
  clear();
}

void	search(t_all *s)
{
  if (s->i + 1 < s->lmax)
    s->search[++s->i] = s->key;
  aff(s);
  mvprintw(s->row, 0, "SEARCH \"%s\" %d FOUNDED", s->search, s->nb_ocur);
  refresh();
  s->key = getch();
  while (s->key == 263 && s->i >= 0)
    delsearch(s);
  if (s->key == 32)
    selectsearch(s);
  else if (!isprintable(s->key))
    {
      s->j = -1;
      while (s->search[++s->j])
	s->search[s->j] = '\0';
    }
  clear();
}
