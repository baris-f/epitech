/*
** util.h for sodl in /home/fus/tmp/fusgine/inc
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Mon Mar 21 23:07:56 2016 Gaspard Thirion
** Last update Wed Apr 20 10:57:39 2016 Gaspard Thirion
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
#include <math.h>
#include "my.h"

typedef t_bunny_ini		t_ini;
typedef	unsigned int		t_col;
typedef t_bunny_window          t_win;
typedef t_bunny_keysym          t_key;
typedef t_bunny_clipable	t_clip;
typedef t_bunny_response        t_resp;
typedef t_bunny_position        t_2D;
typedef t_bunny_ini_scope	t_scope;
typedef t_bunny_pixelarray      t_img;
typedef t_bunny_event_state     t_state;

typedef struct	s_f2D
{
  float		x;
  float		y;
}		t_f2D;

typedef struct  s_text
{
  char          *id;
  t_img         *img;
}               t_text;

typedef struct  s_sprite
{
  t_2D          pos;
  t_img         *img;
  int           sens;

  t_2D          start;
  t_2D          dim;
  t_2D          scale;

  char          *anim;
  t_2D          time;
  t_2D          num;
  t_2D          fstart;
}               t_sprite;

typedef struct	s_font
{
  char		*id;
  t_img		*img;
  int		size;
  t_col		col;
  t_2D		scale;
  t_2D		marge;
}		t_font;

#endif /* !UTIL_H_ */
