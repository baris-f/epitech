/*
** main.c for tetris in /home/dudu/rendu/PSU_2015_tetris
**
** Made by lucas duval
** Login   <duval_m@epitech.net>
**
** Started on  Thu Feb 25 08:59:19 2016 lucas duval
<<<<<<< HEAD
** Last update Sat Mar 19 13:01:13 2016 Florent Baris
=======
** Last update Wed Mar  9 12:36:39 2016 lucas duval
>>>>>>> 9973444069e8148543e205fb268cf28461a9e4e0
*/

#include "tetris.h"

void    my_memset(char *str, char c, int size)
{
  int   i;

  i = -1;
  while (++i < size)
    str[i] = c;
}

void    init(t_tetris *tet)
{
  t_2D	pos;
  int	i;

  srand(time(NULL));
  /* tet->file = fopen("/dev/tty", "w+"); */
  tet->screen = newterm("xterm", NULL, stdin);
  set_term(tet->screen);
  start_color();
  use_default_colors();
  init_color(COLOR_CYAN, 700, 350, 0);
  init_pair(1, COLOR_BLACK, COLOR_RED);
  init_pair(2, COLOR_BLACK, COLOR_CYAN);
  init_pair(3, COLOR_BLACK, COLOR_YELLOW);
  init_pair(4, COLOR_BLACK, COLOR_GREEN);
  init_pair(5, COLOR_BLACK, COLOR_BLUE);
  init_pair(6, COLOR_BLACK, COLOR_MAGENTA);
  tet->tpos.x = -1;
  tet->tpos.y = -1;
  tet->cur = -1;
  tet->score = 0;
  tet->lines = 0;
  tet->lvl = 1;
  tet->fmr = -1;
  tet->down = 0;
  tet->siz.x = 20;
  tet->siz.y = 20;
  if ((tet->map = malloc(tet->siz.y * sizeof(char *))) == NULL)
    return ;
  i = -1;
  while (++i < tet->siz.y)
    if ((tet->map[i] = malloc(tet->siz.x * sizeof(char))) == NULL)
      return ;
  i = -1;
  while (++i < tet->siz.y)
    my_memset(tet->map[i], '0', tet->siz.x);
  tet->time = time(NULL);
  getmaxyx(stdscr, pos.y, pos.x);
  tet->win = newwin(pos.y, pos.x, 0, 0);
  noecho();
  raw();
  keypad(stdscr, TRUE);
  curs_set(0);
}

void    quit(t_tetris *tet)
{
  int	i;

  i = -1;
  while (++i < tet->siz.y)
    free(tet->map[i]);
  free(tet->map);
  endwin();
  delscreen(tet->screen);
}

void	controls(t_tetris *tet)
{
  if (tet->key == 260 && tet->tpos.x > 0)
    tet->tpos.x--;
  else if (tet->key == 261 && tet->tpos.x < 20 - tet->tetriminos[tet->cur].size.x)
    tet->tpos.x++;
  else if (tet->key == 259)
    {
      wclear(tet->win);
    tet->rot++;
    }
  else if (tet->key == 258)
    tet->down = 1;
  else if (tet->key == 115)
    delline(tet, 20);
}

int	main(int ac, char **av)
{
  t_tetris	tet;

  (void)ac;
  arg_parser(av);
  get_tetrimino(&tet);
  ordre(tet.tetriminos, tet.nb_tetri);
  draw_tetri(&tet);
  init(&tet);
  while (1)
    {
      nodelay(stdscr, 1);
      draw_board(&tet);
      game(&tet);
      mvwprintw(tet.win, 30, 30, "%d", tet.fmr);
      wrefresh(tet.win);
      tet.key = getch();
      if (tet.lvl <= 30 && tet.lvl > 0 && tet.down == 0)
	usleep(20000 * (1 / (float)tet.lvl));
      else
	usleep(20000 * (1 / (float)30));
      if (tet.fmr == 19 || tet.key == 260 || tet.key == 261)
	wclear(tet.win);
      if (tet.key == 113)
	{
	  quit(&tet);
	  return (0);
	}
      else
	controls(&tet);
    }
  return (0);
}
