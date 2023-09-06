/*
** util.h for sodl in /home/fus/tmp/fusgine/inc
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Mon Mar 21 23:07:56 2016 Gaspard Thirion
** Last update Thu Apr 21 21:13:36 2016 Gaspard Thirion
*/

#ifndef UTIL_H_
# define UTIL_H_

#include <lapin.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "my.h"

#define	get_field	(char*)bunny_ini_get_field
#define	set		bunny_ini_set_field
#define ABS(v)          ((v < 0) ? (-1 * v) : (v))
#define MIN(a, b)       (a < b) ? (a) : (b)
#define MAX(a, b)       (a < b) ? (b) : (a)
#define NBOOL(a)       (a == 0) ? (1) : (0)
#define	BLIT		bunny_blit(&(_m->mwin->buffer), &(_m->mimg->clipable), &(_m->mpos))

typedef	unsigned int		t_col;
typedef t_bunny_window          t_win;
typedef t_bunny_position        t_2D;
typedef t_bunny_pixelarray      t_img;
typedef	t_bunny_clipable	t_clip;
typedef t_bunny_response        t_resp;
typedef t_bunny_event_state     t_state;
typedef t_bunny_keysym          t_key;
typedef t_bunny_mouse_button	t_click;
typedef t_bunny_ini		t_ini;
typedef t_bunny_ini_scope	t_scope;

typedef struct	s_f2D
{
  float		x;
  float		y;
}		t_f2D;

typedef struct	s_text
{
  char		*id;
  t_img		*img;
}		t_text;

typedef struct	s_sprite
{
  t_2D		pos;
  t_img		*img;
  int		sens;

  t_2D		start;
  t_2D		dim;
  t_2D		scale;

  char		*anim;
  t_2D		time;
  t_2D		num;
  t_2D		fstart;
}		t_sprite;

typedef struct	s_font
{
  char		*id;
  t_img		*img;
  int		size;
  t_col		col;
  t_2D		scale;
  t_2D		marge;
}		t_font;

typedef struct	s_line
{
  int		dx;
  int		dy;
  int		xinc;
  int		yinc;
  int		cumul;
}		t_line;

#endif /* !UTIL_H_ */
