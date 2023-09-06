/*
** main.c for sjof in /home/fus/tmp/fusgine/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Tue Mar 15 22:01:46 2016 Gaspard Thirion
** Last update Fri Apr 22 10:07:41 2016 Florent Baris
*/

#include "engine.h"

int	init2(t_main *_m)
{
  if ((_m->fight.lb = bunny_load_pixelarray("res/lifebar.png")) == NULL)
    return (-1);
  _m->player.life = 100;
  _m->fight.life = 100 - rand() % 30;
  _m->player.lvl = 1;
  _m->player.dmg = 10;
  _m->player.pot = 5;
  _m->fight.lvl = 1;
  _m->fight.dmg = 3;
  _m->fight.lb->clipable.scale.x = (float)_m->s.x / (float)1000;
  _m->fight.lb->clipable.scale.y = (float)_m->s.x / (float)1000;
  return (0);
}

int		init(t_main *_m, char *proj)
{
  if (loadproj(_m, proj) == -1)
    {
      my_printf("Initialisation failed\n");
      return (-1);
    }

  _m->i = 0;
  _m->fight.end = 0;
  _m->s = set2D(_m->s, _m->mimg->clipable.buffer.width,
		_m->mimg->clipable.buffer.height, 1);
  _m->sh = set2D(_m->s, _m->s.x / 2, _m->s.y / 2, 1);
  _m->player.idle = find_anim(_m, "pidle");
  _m->player.walk = find_anim(_m, "pwalk");
  _m->player.atk = find_anim(_m, "patk");
  _m->fight.idle = find_anim(_m, "e0idle");
  _m->fight.atk = find_anim(_m, "e0atk");
  _m->fight.sens = 0;
  _m->fight.tend = -1;
  _m->player.nod = 0;
  _m->player.a = 0;
  _m->player.pnod = 0;
  _m->mouse[0] = set2D(_m->mouse[0], 0, 0, 1);
  _m->mouse[1] = set2D(_m->mouse[0], 0, 0, 1);
  _m->mpos.x = 0;
  _m->mpos.y = 0;
  _m->clock = 0;
  _m->map[_m->i].pos.x = 0;
  _m->map[_m->i].pos.y = 0;
  if (_m->player.idle == NULL || _m->player.walk == NULL || _m->fight.idle == NULL
      || _m->fight.atk == NULL || _m->player.atk == NULL)
    {
      my_printf("anim manquante\n");
      return (-1);
    }
  _m->player.size.x = _m->player.idle->dim.x * _m->player.idle->scale.x;
  _m->player.size.y = _m->player.idle->dim.y * _m->player.idle->scale.y;
  _m->player.pos.x = _m->map[_m->i].node[0].pos.x - _m->player.size.x / 2;
  _m->player.pos.y = _m->map[_m->i].node[0].pos.y - _m->player.size.y * 2 / 3;
  _m->mouse[1] = _m->map[_m->i].node[0].pos;
  setgui(_m);
  bunny_set_loop_main_function(&update);
  bunny_set_key_response(&keyboard);
  bunny_set_click_response(&mouse);
  bunny_set_move_response(&mouse_move);
  return (init2(_m));
}

t_resp		clean(t_main *_m)
{
  bunny_stop(_m->mwin);
  bunny_delete_clipable(&(_m->mimg->clipable));
  bunny_delete_sound(&_m->mu->sound);
  return (EXIT_ON_SUCCESS);
}

int		main(int ac, char **av)
{
  t_main	_m;

  if (ac != 2 || !av[1])
    {
      my_printf("%s [ini project]\n", av[0]);
      return (-1);
    }
  else if (init(&_m, av[1]) == -1
	   || (_m.path = malloc(sizeof(int) * _m.map[_m.i].nb_node)) == NULL
	   || (_m.mu = bunny_load_music("res/menu.ogg")) == NULL)
    return (-1);
  _m.path[0] = -1;
  bunny_sound_play(&_m.mu->sound);
  bunny_loop(_m.mwin, 255, &_m);
  clean(&_m);
  return (0);
}
