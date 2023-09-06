/*
** tool.h for plat in /home/fus/tmp/plat2/inc
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Mon Dec 21 14:28:29 2015 Gaspard Thirion
** Last update Tue Jan 26 09:50:21 2016 Florent Baris
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

#define	WIN_W		1280
#define	WIN_H		720
#define WIN_WH		WIN_W / 2
#define WIN_HH		WIN_H / 2
#define FS		false
#define	BLIT		TRUE
#define	CLEAR		TRUE
#define	UI		FALSE
#define DF_COL          0xFFB469FF
#define HIT		0.3

#define	X_SENSI		0.05
#define Y_SENSI		0.05
#define	MV_SENSI	0.30
#define NB_TEXT		23

#define	TARG_W		WIN_W
#define	FOV		1.047198	/* M_PI / 3 */
#define	DF_W_HEIGHT	2
#define	UNIT		1
#define	D_PROJ		TARG_W / tan(FOV / 2)
#define	PAS		FOV / WIN_W

#define	FOV_H		0.523599	/* FOV / 2 */
#define	MID		1.570796	/* M_PI / 2 */
#define	DOUBLE		6.283185	/* M_PI * 2 */
#define	DWN_PI		4.712389	/* 3 * M_PI / 2 */

#define	DF_GR_COL	BLUE
#define	SKY_COL		0xFFffaa00
#define	GRND_COL	0xFF666666

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

typedef struct	s_f3D
{
  float		x;
  float		y;
  float		z;
}		t_f3D;

typedef struct  s_blit
{
  t_2D          start;
  t_2D          dim;
  unsigned int  alpha;
}               t_blit;

typedef struct	s_play
{
  t_f3D		pos;
  t_f2D		vec;
  t_f2D		ang;
  t_f2D		dist;
}		t_play;

typedef struct	s_key
{
  int		k_z;
  int		k_q;
  int		k_s;
  int		k_d;
  int		k_up;
  int		k_down;
  int		k_left;
  int		k_right;
}		t_key;

typedef struct	s_text
{
  t_col		ref;
  int		map;
  t_img		*img;
}		t_text;

typedef struct	s_base
{
  t_win		*win;
  t_img		*img;
  t_text	*prs;
  t_2D		mpos;
  t_play	play;
  t_key		keys;
  t_bunny_music *music;
  int		swtch;
}	       	t_base;

int	error(int, char*, char*);
void	mpixel(t_img*, t_2D, t_col);
void	mblit(t_img*, t_img*, t_col);
void	clear(t_img*, t_col);
t_resp	keys(t_bunny_event_state, t_bunny_keysym, void*);
t_img	*load_bitmap(char*);
void	display(t_base*);
t_f2D	chk_verti(t_base*, t_f3D, float, t_col*);
t_f2D	chk_hori(t_base*, t_f3D, float, t_col*);
t_img	*prs_load(char*);
void	draw_wall(t_base*, t_f2D, t_col, float);
void	text_wall(t_base*, t_f2D, t_col, float, float);
int	move(t_base*,float, int);
int	key_event(t_base*);
t_resp	mouse_move(const t_2D*, void*);

#endif /* !TOOL_H_ */
