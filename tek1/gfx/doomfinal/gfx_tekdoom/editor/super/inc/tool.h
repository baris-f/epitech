/*
** tool.h for plat in /home/fus/tmp/plat2/inc
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Mon Dec 21 14:28:29 2015 Gaspard Thirion
** Last update Mon Jan 18 12:47:54 2016 Gaspard Thirion
*/

#ifndef TOOL_H_
# define TOOL_H_

#include <math.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <lapin.h>
#include <lapin_enum.h>
#include <my.h>
#include <unistd.h>

#define	WIN_W		1000
#define	WIN_H		800
#define FS		false
#define DF_COL          0xFFB469FF
#define	READ_SIZE	10
#define	D_R(v)		(v * (M_PI / 180))
#define	R_D(v)		(v * (180 / M_PI))
#define	ABS(v)		((v < 0) ? (v * -1) : (v))
#define	NORM(a, b)	(sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2)))

typedef t_bunny_window		t_win;
typedef t_bunny_pixelarray	t_img;
typedef	t_bunny_response	t_resp;
typedef t_bunny_ini		t_ini;
typedef t_bunny_position	t_2D;
typedef unsigned int		t_col;

typedef enum	e_bool
  {
    TRUE	= 0,
    FALSE	= 1
  }		t_bool;
typedef struct	s_f2D
{
  float		x;
  float		y;
}		t_f2D;

typedef struct  s_blit
{
  t_2D          start;
  t_2D          dim;
  unsigned int  alpha;
}               t_blit;

typedef struct	s_base
{
  t_win		*win;
  t_img		*img;
  t_2D		mpos;
  t_bool	blit;
  t_blit	mopt;
}	       	t_base;

int	error(int, char*, char*);
void	mpixel(t_img*, t_2D, t_col);
void	mblit(t_img*, t_img*, t_col);
void	clear(t_img*, t_col);
t_img	*load_bitmap(char*);
void	bmp_load(char*, t_bunny_pixelarray*);
char	*get_next_line(int);

#endif /* !TOOL_H_ */
