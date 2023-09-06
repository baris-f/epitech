/*
** update.c for update in /home/grandm_a/gfx_fdf1
**
** Made by Grandmaire Corentin
** Login   <grandm_a@epitech.net>
**
** Started on  Wed Nov 18 13:22:49 2015 Grandmaire Corentin
** Last update Fri Nov 27 14:38:14 2015 Florent Baris
*/

#include <lapin.h>
#include <lapin_enum.h>
#include <unistd.h>
#include <math.h>
#include "my_lap.h"

void    my_fill(t_bunny_pixelarray *pix, unsigned int color);
void                    tekline(t_bunny_pixelarray *pix,
                                t_bunny_position *pos,
                                unsigned int color);


t_bunny_response	update(void *_void)
{
  t_pass		*pass;

  pass = _void;
  bunny_display(pass->win);
  return (GO_ON);
}

int			main(int ac, char **av)
{
  t_pass		pass;
  t_bunny_position	*pos;

  pass.win = bunny_start(1000, 1000, 0, "baris_f pd");
  pass.img = bunny_new_pixelarray(1000, 1000);
  pass.imgpos->x = 0;
  pass.imgpos->y = 0;
  my_fill(pass.img, BLACK);

/*		instructions		*/
  grid(&pass, bunny_load_ini(av[1]), RED);
/*		instructions		*/


  bunny_blit(&(pass.win->buffer), &(pass.img->clipable), pass.imgpos);
  bunny_set_loop_main_function(update);
  bunny_loop(pass.win, 255, &pass);
  bunny_delete_clipable(&(pass.img->clipable));
  bunny_stop(pass.win);
  return (0);
}
