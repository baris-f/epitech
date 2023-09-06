/*
** main.c for sjof in /home/fus/tmp/fusgine/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Tue Mar 15 22:01:46 2016 Gaspard Thirion
** Last update Wed Apr 20 23:48:44 2016 Gaspard Thirion
*/

#include "engine.h"

void	setzero(t_main *_m)
{
  int	i;

  _m->mpos.x = 0;
  _m->mpos.y = 0;
  _m->mouse[0].x = 0;
  _m->mouse[0].y = 0;
  _m->mouse[1].x = 0;
  _m->mouse[1].y = 0;
  _m->map.pos.x = 0;
  _m->map.pos.y = 0;
  _m->map.mov = -1;
  i = -1;
  while (++i < NB_BUT)
    {
      _m->gui.but[i].pos[0].x = -1;
      _m->gui.but[i].text = NULL;
    }
  /* _m->map.cur = -1; */
}

int		init(t_main *_m, char *proj, char *map)
{
  setzero(_m);
  setgui(_m);
  if (loadproj(_m, proj) == -1
      || (map && gmap(_m, &_m->map, map) == -1)
      || (!map && (_m->map.img = new_sprite(_m, _m->map.name)) == NULL))
    {
      my_printf("initialisation fail\n");
      return (-1);
    }
  _m->clock = 0;
  _m->gui.butt = -1;
  bunny_set_loop_main_function(&update);
  bunny_set_key_response(&keyboard);
  bunny_set_click_response(&mouse);
  bunny_set_move_response(&mouse_move);
  return (0);
}

t_resp		clean(t_main *_m)
{
  bunny_stop(_m->mwin);
  bunny_delete_clipable(&(_m->mimg->clipable));
  return (EXIT_ON_SUCCESS);
}

int		main(int ac, char **av)
{
  t_main	_m;
  char		*tmp;

  if (ac != 3)
    return (write(1, "Usage: ./editor [project.ini] [map.ini || text_name]\n", 54) * 0 - 1);
  tmp = NULL;
  if (nmatch(av[2], "*.ini") > 0)
    tmp = av[2];
  else if ((_m.map.name = av[2]) == NULL)
    return (write(1, "wrong image\n", 13) * 0 - 1);
  if (init(&_m, av[1], tmp) == -1)
    return (-1);
  bunny_loop(_m.mwin, 60, &_m);
  export(&_m, (tmp) ? (tmp) : (_m.map.name));
  clean(&_m);
  return (0);
}
