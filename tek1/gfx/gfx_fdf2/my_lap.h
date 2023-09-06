/*
** my_lap.h for my_lap.h in /home/baris-f/rendu/gfx_fdf2
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Dec 21 22:05:54 2015 Florent Baris
** Last update Mon Dec 21 22:16:54 2015 Florent Baris
*/

#ifndef MY_LAP_H_
# define MY_LAP_H_

#include <lapin.h>
#include <lapin_enum.h>
#include <unistd.h>
#include <stdio.h>

# define ABS(Value) ((Value < 0) ? (Value * -1) : (Value))
# define AFF(pos, name) (my_printf("%s = ( %d ; %d )\n", name, pos.x, pos.y))
# define PAFF(pos, name) (my_printf("%s = ( %d ; %d )\n", name, pos->x, pos->y))
# define RM 0xffb469ff
# define ESC 36
# define LEFT 71
# define RIGHT 72

typedef struct		s_v3
{
  int			x;
  int			y;
  int			z;
}			t_v3;

typedef struct          s_ini
{
  char			*name;
  t_bunny_ini		*file;
  t_bunny_ini_scope	*scope;
  char			*type;
  t_bunny_position	org;
  t_bunny_position	dim;
  t_v3			scale;
  float			ang;
}			t_ini;

typedef struct		s_pass
{
  t_bunny_window        *win;
  t_bunny_pixelarray    *img;
  t_bunny_position      pos[1];
  t_color		col[1];
  int			fill;
  t_ini			*ini;
}			t_pass;

void                    fdf2(t_bunny_pixelarray *pix, char **av);
void                    tekisoproject(t_bunny_position *out, int x, int y,
				      int z);
void                    tektabline(t_bunny_pixelarray *img, t_bunny_position *tab,
				   unsigned int col, int n);
int			my_strcmp(char*, char*);
void			ovales(t_bunny_pixelarray *pix, t_bunny_position *pos, int *radius);
void                    tekline(t_bunny_pixelarray *img, t_bunny_position *tab,
				unsigned int col);
int			my_getnbr(const char*);
void                    tekpixel(t_bunny_pixelarray *img, t_bunny_position *pos,
				 unsigned int col);
void                    tekblit(t_bunny_pixelarray*, t_bunny_pixelarray*,
				unsigned int);
void			tekfill(t_bunny_pixelarray*, t_color*);
void			tekllproject(t_bunny_position*, t_bunny_position,
				     t_ini*);
void			tekinioproject(t_bunny_position*, t_bunny_position,
				     t_ini*);
void			tekpoly(t_bunny_pixelarray*, t_bunny_position*,
				t_color*, int);
void                    tekcircle(t_bunny_pixelarray*, t_bunny_position,
				  int*, unsigned int);
void                    bmp_load(char*, t_bunny_pixelarray*);

t_bunny_response        tekclick(t_bunny_event_state, t_bunny_mousebutton, void*);
t_bunny_response	tekmove(t_bunny_position*, void*);
t_bunny_response	tekkey(t_bunny_event_state, t_bunny_keysym, void*);
t_bunny_response	update(void*);

#endif /* !MY_LAP_H_ */
