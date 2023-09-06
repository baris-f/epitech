/*
** my_select.c for my_select in /home/baris-f/rendu/PSU_2015_my_select
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Nov 30 12:44:03 2015 Florent Baris
** Last update Tue Mar  1 18:30:21 2016 Florent Baris
*/

#include <ncurses.h>
#include <stdlib.h>
#include "my_select.h"

void	setszero(t_all *s, int ac, char **av)
{
  s->max = ac - 1;
  s->tab = malloc(sizeof(t_info) * (ac - 1));
  s->cur = 1;
  s->i = 0;
  s->lmax = 0;
  while (++s->i < ac)
    {
      if (s->lmax < my_strlen(av[s->i]))
	s->lmax = my_strlen(av[s->i]);
      s->tab[s->i - 1].name = my_strdup(av[s->i]);
      s->tab[s->i - 1].hlight = 0;
    }
  s->search = malloc(sizeof(char) * s->lmax + 1);
  s->i = -1;
  while (s->search[++s->i])
    s->search[s->i] = '\0';
  s->i = 0;
}

void    init(t_all *s, int ac, char **av)
{
  ESCDELAY = 25;
  s->file = fopen("/dev/tty", "w+");
  s->screen = newterm("xterm", s->file, s->file);
  set_term(s->screen);
  start_color();
  use_default_colors();
  init_pair(1, COLOR_BLACK, COLOR_GREEN);
  setszero(s, ac, av);
  noecho();
  raw();
  keypad(stdscr, TRUE);
  curs_set(0);
}

void	onearg(int ac)
{
  if (ac == 1)
    {
      my_printf("Usage : ./my_select elem1 elem2 ...\n");
      exit(0);
    }
}

void	quit(t_all *s)
{
  endwin();
  delscreen(s->screen);
}

int	main(int ac, char **av)
{
  t_all s;

  onearg(ac);
  init(&s, ac, av);
  while (1)
    {
      getmaxyx(stdscr, s.row, s.col);
      s.row--;
      aff(&s);
      mvprintw(s.row, 0, "CURSOR POSITION : %d SELECTED ELEMENTS : %-*d",
	       s.cur, s.col, s.selected);
      refresh();
      s.key = getch();
      clear();
      opt(&s);
      s.i = -1;
       if (keyexit(&s) == 1 || s.key == 27)
	 {
	   quit(&s);
	   return (0);
	 }
      controls(&s);
      mvprintw(s.row, 0, "CURSOR POSITION : %d SELECTED ELEMENTS : %-*d",
	       s.cur, s.col, s.selected);
    }
}
