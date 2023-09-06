/*
** draw.c for draw in /home/baris-f/rendu/PSU/PSU_2015_tetris
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Tue Mar  1 15:59:06 2016 Florent Baris
<<<<<<< HEAD
** Last update Sun Mar 20 23:32:23 2016 Florent Baris
=======
** Last update Wed Mar  9 16:44:02 2016 lucas duval
>>>>>>> 9973444069e8148543e205fb268cf28461a9e4e0
*/

#include "tetris.h"

void	draw_box(t_tetris *tet, t_2D *pos, t_2D *size)
{
  int	i;
  int	j;

  i = -1;
  while (++i < size->y)
    {
      j = -1;
      while (++j < size->x)
	{
	  if (i == 0 && j == 0)
	    mvwaddch(tet->win, i + pos->y, j + pos->x, ACS_ULCORNER);
	  else if (i == 0 && j == size->x - 1)
	    mvwaddch(tet->win, i + pos->y, j + pos->x, ACS_URCORNER);
	  else if (i == size->y - 1 && j == 0)
	    mvwaddch(tet->win, i + pos->y, j + pos->x, ACS_LLCORNER);
	  else if (i == size->y - 1 && j == size->x - 1)
	    mvwaddch(tet->win, i + pos->y, j + pos->x, ACS_LRCORNER);
	  else if (i == 0 || i == size->y - 1)
	    mvwaddch(tet->win, i + pos->y, j + pos->x, ACS_HLINE);
	  else if (j == 0 || j == size->x - 1)
	    mvwaddch(tet->win, i + pos->y, j + pos->x, ACS_VLINE);
	}
    }
}

void	draw_title(t_tetris *tet, t_2D *pos)
{
  int	i;

  i = -1;
  while (++i < 6)
    {
      wattron(tet->win, COLOR_PAIR(i + 1));
      if (i == 0 || i == 2)
	draw_letter(tet, pos, "XXXXXOOXO000X0000X0000X00", 5);
      else if (i == 1)
	draw_letter(tet, pos, "XXXXXX0000XXX00X0000XXXXX", 5);
      else if (i == 3)
	draw_letter(tet, pos, "XXXXOXOOOXXXXX0X00X0X000X", 5);
      else if (i == 4)
	{
	  pos->x -= 1;
	  draw_letter(tet, pos, "OOXOOOOOOOOOXOOOOXOOOOXOO", 5);
	  pos->x -= 1;
	}
      else
	draw_letter(tet, pos, "XXXXXXOOO0XXXXX0000XXXXXX", 5);
      pos->x += 6;
      pos->y -= 5;
      wattroff(tet->win, COLOR_PAIR(i + 1));
    }
}

void	draw_score(t_tetris *tet, t_2D *pos)
{
  t_2D	size;
  int	tim;
  int	i;
  int	j;

  size.x = 20;
  size.y = 14;
  draw_box(tet, pos, &size);
  pos->x += 2;
  pos->y += 2;
  mvwprintw(tet->win, pos->y, pos->x, "%s         %d", "Score", tet->score);
  pos->y += 2;
  mvwprintw(tet->win, pos->y, pos->x, "%s         %d", "Lines", tet->lines);
  mvwprintw(tet->win, ++pos->y, pos->x, "%s         %d", "Level", tet->lvl);
  tim = time(NULL) - tet->time;
  mvwprintw(tet->win, ++pos->y, pos->x, "%s     %d : %d ", "Timer", tim / 60, tim % 60);
  pos->y += 2;
  mvwprintw(tet->win, pos->y, pos->x, "%s", "Next");
  pos->x += 7;
  j = -1;
  if (tet->cur == -1)
    {
      tet->cur = tet->ncur;
      tet->ncur = -1;
    }
  if (tet->ncur == -1)
    while (tet->tetriminos[tet->ncur = rand() % (tet->nb_tetri + 1)].ok != 1);
  wattron(tet->win, COLOR_PAIR(tet->tetriminos[tet->ncur].color));
  while (++j < tet->tetriminos[tet->ncur].size.y)
    {
      i = -1;
      while (++i < tet->tetriminos[tet->ncur].size.x)
  	{
  	  if (tet->tetriminos[tet->ncur].shape[j][i] == '*')
  	    mvwprintw(tet->win, pos->y + j, pos->x + i, " ");
  	}
    }
  wattroff(tet->win, COLOR_PAIR(tet->tetriminos[tet->ncur].color));
}

void	draw_board(t_tetris *tet)
{
  t_2D	pos;
  t_2D	size;

  size.x = tet->siz.x + 2;
  size.y = tet->siz.y + 2;
  getmaxyx(stdscr, pos.y, pos.x);
  pos.x = pos.x * 3 / 4 - size.x + 1;
  pos.y = pos.y / 2 - size.y / 2;
  draw_box(tet, &pos, &size);
  getmaxyx(stdscr, pos.y, pos.x);
  pos.x = pos.x / 4 - 10;
  pos.y = pos.y / 3;
  draw_score(tet, &pos);
  pos.x = 1;
  pos.y = 1;
  draw_title(tet, &pos);
}

void	draw_tetri(t_tetris *tet)
{
  int	i;
  int	j;

  i = -1;
  my_printf("Tetriminos : %d\n", tet->nb_tetri);
  while(++i < tet->nb_tetri)
    {
      if (tet->tetriminos[i].ok)
	{
	  my_printf("Tetriminos : Name %s : Size %d*%d : Color %d :\n",
		    tet->tetriminos[i].name, tet->tetriminos[i].size.x,
		    tet->tetriminos[i].size.y, tet->tetriminos[i].color);
	  j = -1;
	  while (++j < tet->tetriminos[i].size.y)
	    my_printf("%s\n", tet->tetriminos[i].shape[j]);
	}
      else
	my_printf("Tetriminos : Name %s : Error\n", tet->tetriminos[i].name);
    }
}
