/*
** tool.h for tool in /home/baris-f/rendu/gfx/gfx_tekgui
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sun Feb 28 22:38:54 2016 Florent Baris
** Last update Sun Mar 20 21:29:35 2016 Gaspard Thirion
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
#include <unistd.h>
#include <time.h>
#include "my.h"

#define	WIN_W		1600
#define	WIN_H		900
#define FS		false

#define	BLIT		TRUE
#define	UI		FALSE
#define	CLEAR		FALSE
#define	DEBUG		FALSE

#define	WIN_WH		WIN_W / 2
#define	WIN_HH		WIN_H / 2
#define	FOV_W		M_PI / 3
#define	FOV_H		FOV_W * RATIO
#define	RATIO		(float)WIN_H / (float)WIN_W

#define DF_COL          0xFFB469FF
#define	CLEAR_COL	0xff303030

#define	D_R(v)		(v * (M_PI / 180))
#define	R_D(v)		(v * (180 / M_PI))
#define	ABS(v)		((v < 0) ? (v * -1) : (v))
#define	NORM(a, b)	(sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2)))

typedef t_bunny_window		t_win;
typedef t_bunny_pixelarray	t_img;
typedef	t_bunny_response	t_resp;
typedef t_bunny_position	t_2D;
typedef	t_bunny_sound		t_sound;
typedef unsigned int		t_col;
typedef	t_bunny_ini		t_ini;
typedef t_bunny_ini_scope	t_scope;

typedef enum	e_bool
  {
    FALSE	= 0,
    TRUE	= 1
  }		t_bool;

typedef struct	s_f2D
{
  float		x;
  float		y;
}		t_f2D;

typedef struct	s_f3D
{
  float		x;
  float		y;
  float		z;
}		t_f3D;

typedef struct	s_opt
{
  t_bool	debug;
  t_bool	clear;
  t_bool	ui;
  t_bool	blit;
}		t_opt;

typedef struct	s_bsf
{
  t_bunny_effect *effect;	
  t_bunny_sound	*sample;
  float		*dur;
  float		*freq;
  int		idx;
}		t_bsf;

typedef struct	s_base
{
  t_img		*img;
  t_img		*font;
  t_img		*mont;
  t_2D		mopos;
  t_img		*nu;
  t_2D		nupos;
  t_img		*herb;
  t_2D		hpos;
  t_img		*fire;
  t_2D		fipos;
  int		afire;
  char		*msg;
  t_2D		fpos;
  t_2D		mpos;
  t_2D		mous;

  t_bsf		bsf;
  t_win		*win;
  t_opt		opt;
  t_bool	bol;
}	       	t_base;

int		my_getnbr(char *str);
void            tekpixel(t_img*, t_2D, t_col);
void            tekfill(t_img*, t_col);
void            tekblit(t_img*, t_img*, t_2D*, t_2D*);
int		error(int, char*, char*);
t_resp		keys(t_bunny_event_state, t_bunny_keysym, void*);
t_img		*load_bitmap(char*);
int		key_event(t_base*);
t_resp		mouse_move(const t_2D*, void*);
void		rectangle(t_img*, t_2D*, t_2D*, t_col);
void		mpixel(t_img*, t_2D, t_col);
void		clear(t_img*, t_col);
t_resp		keys(t_bunny_event_state, t_bunny_keysym, void*);
unsigned int	get_int(t_scope *, char*);
t_bool		get_bool(t_scope *, char*);
t_2D		get_2D(t_scope*, char*);
char		*get_char(t_scope*, char*);
void		*get_fct(t_scope*, char*);
t_resp          click(t_bunny_event_state               state,
		      t_bunny_mousebutton               button,
		      void                              *your_data);
t_resp          mouse_move(const t_2D *relative, void *your_data);
#endif /* !TOOL_H_ */
