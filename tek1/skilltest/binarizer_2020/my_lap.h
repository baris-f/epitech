/*
** my_lap.h for fdf in /home/fus/rendu/gfx_fdf1
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Wed Nov 18 22:14:40 2015 Gaspard Thirion
** Last update Tue Dec  1 14:35:56 2015 Gaspard Thirion
*/

#ifndef MY_LAP_H_
# define MY_LAP_H_

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

t_color			getcolor(t_bunny_pixelarray*, t_bunny_position*);
void			tekfill(t_bunny_pixelarray*, t_color*);
void			tekpixel(t_bunny_pixelarray*, t_bunny_position*,
				 t_color*);
void			tekline(t_bunny_pixelarray*, t_bunny_position*,
				t_color*);
void			tekllproject(t_bunny_position*, t_bunny_position,
				     t_ini*);
void			tekisoproject(t_bunny_position*, t_bunny_position,
				     t_ini*);
void                    tektabline(t_bunny_pixelarray*, t_bunny_position*,
				   t_color*, int);
void			tekpoly(t_bunny_pixelarray*, t_bunny_position*,
				t_color*, int);
void                    tekcircle(t_bunny_pixelarray*, t_bunny_position*,
				  t_v3, t_color*);

t_bunny_response        tekclick(t_bunny_event_state, t_bunny_mousebutton, void*);
t_bunny_response	tekmove(t_bunny_position*, void*);
t_bunny_response	tekkey(t_bunny_event_state, t_bunny_keysym, void*);
t_bunny_response	update(void*);

#endif /* !MY_LAP_H_ */
