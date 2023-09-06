/*
** tetris.h for tetris in /home/dudu/rendu/PSU_2015_tetris/inc
**
** Made by lucas duval
** Login   <duval_m@epitech.net>
**
** Started on  Wed Mar  2 08:48:24 2016 lucas duval
** Last update Sun Mar 20 21:44:53 2016 lucas duval
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

typedef struct s_key
{
  int	quit;
  int	left;
  int	right;
  int	turn;
  int	drop;
  int	pause;
}		t_key;

typedef struct s_tetris
{
  int		debug;
  int		aff_next;
  t_tetri	*tetriminos;
  int		nb_tetri;
  int		key;
  t_key		keys;
  int		score;
  int		lines;
  int		lvl;
  int		time;
  int		ncur;
  int		cur;
  int		fmr;
  int		down;
  int		rot;
  t_2D		size_map;
  t_2D		siz;
  t_2D		tpos;
  int		pause;
  int		lindel;
  char		**map;
  WINDOW	*win;
  FILE		*file;
  SCREEN	*screen;
}		t_tetris;

void    arg_parser(char **av, t_tetris *tet);
void    draw_board(t_tetris *tet);
void    draw_letter(t_tetris *tet, t_2D *pos, char *str, int size);
void    set_help();
void    set_level(char *lvl, int, t_tetris *tet);
void    set_map_size(char *map, t_tetris *);
void    set_key_left(char *kl, int, t_tetris *tet);
void    set_key_right(char *kr, int, t_tetris *tet);
void    set_key_turn(char *kt, int, t_tetris *tet);
void    set_key_drop(char *kd, int, t_tetris *tet);
void    set_key_quit(char *kq, int, t_tetris *tet);
void    set_key_pause(char *kp, int, t_tetris *tet);
void	tetrimo_parser(int fd, t_tetri *tetrimos, char	*);
void    draw_tetri(t_tetris *tet);
void    get_tetrimino(t_tetris *tet);
void    print_debug(t_tetris *tet);
void    ordre(t_tetri *files, int nbval);
void    game(t_tetris *tet);
int     iscol(t_tetris *tet);
void    quit(t_tetris *tet);

#endif /* !MY_SELECT_H_ */
