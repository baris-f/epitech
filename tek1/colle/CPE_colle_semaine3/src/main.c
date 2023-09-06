/*
** main.c for 2048 in /home/baris-f/rendu/colle/CPE_colle_semaine3
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Fri May 13 14:27:46 2016 Florent Baris
** Last update Fri May 13 17:09:36 2016 Florent Baris
*/

#include "2048.h"

t_bunny_response	       	key(t_bunny_event_state state,
				    t_bunny_keysym key,
				    void *data)
{
  t_base	*_m;

  _m = (t_base *)data;
  if (key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  else if (key == BKS_LEFT && state == GO_DOWN)
    _m->move = 1;
  else if (key == BKS_RIGHT && state == GO_DOWN)
    _m->move = 2;
  else if (key == BKS_UP && state == GO_DOWN)
    _m->move = 3;
  else if (key == BKS_DOWN && state == GO_DOWN)
    _m->move = 4;
  return (GO_ON);
}

int	win(t_base *_m)
{
  int	i;

  i = -1;
  while (++i < 16)
    if (_m->grid[i] == 9)
      return (1);
  return (0);
}

t_bunny_response		mainloop(void *data)
{
  t_base			*_m;

  _m = (t_base*)data;
  if (_m->move > 0)
    {
      move(_m);
      if (new_number(_m) == -1)
	return ((write(1, "You lose\n", 9)) * 0 - 1);
      if (win(_m))
	return ((write(1, "You win\n", 8)) * 0);
      _m->move = 0;
    }
  bunny_blit(&(_m->win->buffer), &(_m->img->clipable), &_m->pos);
  draw_grid(_m);
  bunny_display(_m->win);
  return (GO_ON);
}

int				init(t_base *_m, char **av)
{
  int	i;

  srand(time(NULL));
  if ((_m->win = bunny_start(256, 256, 0, "512")) == NULL)
    return (-1);
  if ((_m->img = bunny_new_pixelarray(256, 256)) == NULL)
    return (-1);
  if ((_m->grid = malloc(sizeof (int) * 16)) == NULL)
    return (-1);
  if ((_m->numbers = (bunny_load_pixelarray(av[1]))) == NULL)
    return (-1);
  if (_m->numbers->clipable.clip_width < 640
      || _m->numbers->clipable.clip_height < 64)
    return (write(1, "img too small : minimum 640x64\n", 32) * 0 - 1);
  i = -1;
  while (++i < 16)
    _m->grid[i] = 0;
  _m->move = 0;
  new_number(_m);
  _m->pos.x = 0;
  _m->pos.y = 0;
  return (0);
}

int			main(int ac, char **av)
{
  t_base		_m;

  if (ac != 2)
    {
      write(1, "Usage : ./512 spritesheet_images\n", 34);
      return (-1);
    }
  if (init(&_m, av) == -1)
    return (-1);
  bunny_set_key_response(&key);
  bunny_set_loop_main_function(&mainloop);
  bunny_loop(_m.win, 150, &_m);
  free(_m.grid);
  bunny_stop(_m.win);
  return (0);
}
