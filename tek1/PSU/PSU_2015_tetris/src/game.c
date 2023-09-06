/*
1;2802;0c** game.c for game in /home/baris-f/rendu/PSU/PSU_2015_tetris
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Mar  7 16:49:14 2016 Florent Baris
** Last update Sun Mar 20 23:36:05 2016 Florent Baris
*/

#include "tetris.h"

void	affmap(t_tetris *tet, t_2D *pos)
{
  int	i;
  int	j;

  j = -1;
  while (++j < tet->siz.y)
    {
      i = -1;
      while (++i < tet->siz.x)
	{
	  if (tet->map[j][i] != '0')
	    {
	      wattron(tet->win, COLOR_PAIR(tet->map[j][i] - 48));
	      mvwprintw(tet->win, pos->y + j, pos->x + i, " ");
	      wattroff(tet->win, COLOR_PAIR(tet->map[i][j] - 48));
	    }
	}
    }
}

void	delline(t_tetris *tet, int j)
{
  int	x;
  int	y;

  y = j;
  while (--y > 0)
    {
      x = -1;
      while (++x < tet->siz.x)
	tet->map[y][x] = tet->map[y - 1][x];
    }
}

void	checkmap(t_tetris *tet)
{
  int   i;
  int   j;
  int	nb;

  j = -1;
  nb = 0;
  while (++j < tet->siz.y)
    {
      i = -1;
      while (++i < tet->siz.x)
	{
	  if (tet->map[j][i] == '0')
	    i = tet->siz.x + 2;
	}
      if (i == tet->siz.x)
	{
	  delline(tet, j + 1);
	  nb++;
	}
    }
  if (nb > 0)
    {
      tet->score += (50 * nb) * (tet->lvl + 1);
      wclear(tet->win);
      tet->lindel += nb;
    }
  while (tet->lvl * 10 <= tet->lindel)
    tet->lvl++;
}

void	putinmap(t_tetris *tet)
{
  int	i;
  int	j;
  int	x;
  int	y;

  j = -1;
  i = -1;
  x = 0;
  y = 0;
  if (tet->tpos.y <= 0)
    {
      quit(tet);
      exit(0);
    }
  if (tet->rot == 0)
    while (tet->tetriminos[tet->cur].shape[++j])
      {
	i = -1;
	while (tet->tetriminos[tet->cur].shape[j][++i])
	  {
	    if (tet->tetriminos[tet->cur].shape[j][i] == '*')
		tet->map[tet->tpos.y + j - 1][tet->tpos.x + i] =
	      	tet->tetriminos[tet->cur].color + 48;
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
	      tet->map[tet->tpos.y + x - 1][tet->tpos.x + y] =
	      	tet->tetriminos[tet->cur].color + 48;
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
		tet->map[tet->tpos.y + x - 1][tet->tpos.x + y] =
		  tet->tetriminos[tet->cur].color + 48;
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
		tet->map[tet->tpos.y + x - 1][tet->tpos.x + y] =
		  tet->tetriminos[tet->cur].color + 48;
	      y++;
	    }
	  x++;
	}
    }
}

void	affcur(t_tetris *tet, t_2D *pos)
{
  int	i;
  int	j;
  int	x;
  int	y;

  if (tet->tpos.x >= 0)
    if (iscol(tet) == 1)
      {
	if (tet->key == tet->keys.left)
	  tet->tpos.x++;
	else if(tet->key == tet->keys.right)
	  tet->tpos.x--;
	else
	  {
	    putinmap(tet);
	    tet->cur = -1;
	    tet->down = 0;
	    tet->tpos.y = 0;
	    tet->tpos.x = -1;
	  }
      }
  if (tet->cur == -1)
    {
      tet->cur = tet->ncur;
      tet->ncur = -1;
    }
  if (tet->tpos.x < 0)
    {
      tet->tpos.x = 9 - tet->tetriminos[tet->cur].size.x / 2;
      tet->tpos.y = 0;
    }
  j = -1;
  i = -1;
  x = 0;
  y = 0;
  wattron(tet->win, COLOR_PAIR(tet->tetriminos[tet->cur].color));
  if (tet->rot == 0)
    while (tet->tetriminos[tet->cur].shape[++j])
      {
	i = -1;
	while (tet->tetriminos[tet->cur].shape[j][++i])
	  {
	    if (tet->tetriminos[tet->cur].shape[j][i] == '*')
		mvwprintw(tet->win, pos->y + tet->tpos.y + j, pos->x + tet->tpos.x
			  + i, " ");
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
		mvwprintw(tet->win, pos->y + tet->tpos.y + x, pos->x + tet->tpos.x + y, " ");
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
		  mvwprintw(tet->win, pos->y + tet->tpos.y + x, pos->x + tet->tpos.x
			    + y, " ");
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
		  mvwprintw(tet->win, pos->y + tet->tpos.y + x, pos->x + tet->tpos.x + y, " ");
	      y++;
	    }
	  x++;
	}
    }
  wattroff(tet->win, COLOR_PAIR(tet->tetriminos[tet->cur].color));
}

void		game(t_tetris *tet)
{
  t_2D		pos;

  if (++tet->fmr >= 20)
    {
      tet->fmr = -1;
      if (tet->pause == 0)
	tet->tpos.y++;
    }
  if (tet->rot > 3)
    tet->rot = 0;
  if (tet->cur == -1)
    {
      tet->cur = tet->ncur;
      tet->ncur = -1;
    }
  if (tet->ncur == -1)
    while (tet->tetriminos[tet->ncur = rand() % (tet->nb_tetri + 1)].ok != 1);
  getmaxyx(stdscr, pos.y, pos.x);
  pos.x = pos.x * 3 / 4 - 22 / 2 + 1;
  pos.y = pos.y / 2 - 22 / 2 + 1;
  checkmap(tet);
  affmap(tet, &pos);
  affcur(tet, &pos);
}
