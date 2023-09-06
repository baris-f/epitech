/*
** 2048.h for 2048 in /home/baris-f/rendu/colle/CPE_colle_semaine3
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Fri May 13 14:55:40 2016 Florent Baris
** Last update Fri May 13 17:04:45 2016 Florent Baris
*/

#ifndef MY_H_
# define MY_H_

#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <lapin.h>

typedef	struct		s_2D
{
  int	x;
  int	y;
}			t_2D;

typedef struct		s_base
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*img;
  t_bunny_pixelarray	*numbers;
  t_bunny_position	pos;
  int			*grid;
  int			move;
}			t_base;

t_bunny_response	mouse(t_bunny_event_state               state,
			      t_bunny_mousebutton               button,
			      void                              *data);

t_bunny_response	key(t_bunny_event_state state
			    ,t_bunny_keysym key,
			    void *data);

int			init(t_base *_m, char **av);
int			draw_grid(t_base *_m);
int			new_number(t_base *_m);
int			move(t_base *_m);
void			set_cell_right(t_base *_m, int idx, int mov);
void			set_cell_left(t_base *_m, int idx, int mov);
void			set_cell_down(t_base *_m, int idx, int mov);
void			set_cell_up(t_base *_m, int idx, int mov);
#endif /* !MY_H_ */
