/*
1;2802;0c** main.c for main in /home/baris-f/rendu/gfx_wolf3d
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sat Dec 26 17:27:16 2015 Florent Baris
** Last update Mon Jan 11 18:46:41 2016 Florent Baris
*/

#include <lapin.h>
#include <lapin_enum.h>
#include <unistd.h>
#include "../inc/wolf.h"

t_bunny_response        tekkey(t_bunny_event_state state, t_bunny_keysym key,
			       void *_void)
{

  (void)state;
  (void)_void;
  if (key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

t_bunny_response	update(void *_void)
{
  t_pass		*pass;

  pass = (t_pass*)_void;
  tekfill(pass->img, BLACK);
  web(pass, pass->nbline, pass->nbface);
  bunny_blit(&(pass->win->buffer), &(pass->img->clipable), &pass->pos[0]);
  bunny_display(pass->win);
  return (GO_ON);
}

int	dashhelp()
{
  write(1, "Usage: ./lloth [nbline] [nbface]\n\n", 34);
  write(1,
"Option :\n --help                       Print this help text and exit\n\n", 77);
  write(1, "This program draw a spiderweb.\n", 31);
  write(1, "nbline is the number of lines from the center to the borders,\n"
	, 62);
  write(1, "and nbface is the number of lines facing the center.\n", 53);
  return (0);
}

int			main(int ac, char **av)
{
  t_pass		pass[1];
  int			x;
  int			y;

  if (ac == 2 && av[1][0] == '-' && av[1][5] == 'p')
    return (dashhelp());
  if (ac > 3)
    return (write(1, "Usage: ./lloth [nbline] [nbface]\n", 18) * 0 - 1);
  x = IMG_WIDTH;
  y = IMG_HEIGHT;
  if ((pass->win = bunny_start(x, y, 0, "SpiderWeb")) == NULL)
    return (0);
  if ((pass->img = bunny_new_pixelarray(x, y)) == NULL)
    return (0);
  pass->pos->x = 0;
  pass->pos->y = 0;
  bunny_set_loop_main_function(update);
  bunny_set_key_response(tekkey);
  (ac == 2 || ac == 3) ? (pass->nbline = my_getnbr(av[1])) : (pass->nbline = 5);
  (ac == 3) ? (pass->nbface = my_getnbr(av[2])) : (pass->nbface = 5);
  pass->ini->init = 0;
  bunny_loop(pass->win, 150, pass);
  bunny_delete_clipable(&pass->img->clipable);
  bunny_stop(pass->win);
  return (0);
}
