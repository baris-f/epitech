#ifndef IGRAPH_H_
# define IGRAPH_H_

#include <lapin.h>
#include <math.h>

#define WIN_WIDTH	1280
#define WIN_HEIGHT	720
#define IMG_WIDTH	1280
#define IMG_HEIGHT	720
#define IMG_HEIGHTHALF	IMG_HEIGHT / 2

# define ABS(Value) ((Value < 0) ? (Value * -1) : (Value))
# define AFF(pos, name) (my_printf("%s = ( %d ; %d )\n", name, pos.x, pos.y))
# define PAFF(pos, name) (my_printf("%s = ( %d ; %d )\n", name, pos->x, pos->y))
# define RM 0xffb469ff
# define ESC 36
# define LEFT 71
# define RIGHT 72
# define UP 73
# define DOWN 74

typedef t_bunny_pixelarray	t_img;
typedef t_bunny_window		t_win;
typedef t_bunny_position	t_pos;

typedef struct s_v3
{
  int	x;
  int	y;
  int	z;
}		t_v3;

typedef struct          s_player
{
  t_bunny_position      pos;
  int                   len;
  int                   ang;
}                       t_player;

typedef struct          s_ini
{
  char                  *name;
  t_bunny_ini           *file;
  t_bunny_ini_scope     *scope;
  char                  *type;
  t_bunny_position      org;
  t_bunny_position      dim;
  int                   scale;
  float                 ang;
  int			init;
}                       t_ini;

typedef struct          s_pass
{
  t_bunny_window        *win;
  t_bunny_pixelarray    *img;
  t_bunny_position      pos[1];
  t_color               col[1];
  int                   fill;
  t_ini                 ini[1];
  t_player              player[1];
}                       t_pass;

void	my_put_pixel_to_img(t_img *, t_pos *pos);

#endif /* !IGRAPH_H_ */
