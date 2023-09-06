/*
** tetris.h for tetris in /home/dudu/rendu/PSU_2015_tetris/inc
**
** Made by lucas duval
** Login   <duval_m@epitech.net>
**
** Started on  Wed Mar  2 08:48:24 2016 lucas duval
** Last update Fri Mar 11 14:21:12 2016 Florent Baris
*/

#ifndef MY_SELECT_H_
# define MY_SELECT_H_

#include <ncurses.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include "my.h"

typedef struct  s_2D
{
  int		x;
  int		y;
}               t_2D;

typedef struct	s_tetrimino
{
  char		*name;
  int		ok;
  t_2D		size;
  char		**shape;
  int		**shapint;
  int		color;
}		t_tetri;

typedef struct s_tetris
{
  t_tetri	*tetriminos;
  int		nb_tetri;
  int		key;
  int		score;
  int		lines;
  int		lvl;
  int		time;
  int		cur;
  int		fmr;
  int		down;
  int		rot;
  t_2D		siz;
  t_2D		tpos;
  char		**map;
  WINDOW	*win;
  FILE		*file;
  SCREEN	*screen;
}		t_tetris;

void    arg_parser(char **av);
void    draw_board(t_tetris *tet);
void    draw_letter(t_tetris *tet, t_2D *pos, char *str, int size);
void    set_help();
void    set_level(char *lvl);
void    set_map_size(char *map);
void    set_hide_next();
void    set_debug_mode();
void    set_key_left(char *kl);
void    set_key_right(char *kr);
void    set_key_turn(char *kt);
void    set_key_drop(char *kd);
void    set_key_quit(char *kq);
void    set_key_pause(char *kp);
void	tetrimo_parser(int fd, t_tetri *tetrimos, char	*);
void    draw_tetri(t_tetris *tet);
void    get_tetrimino(t_tetris *tet);

#endif /* !MY_SELECT_H_ */
