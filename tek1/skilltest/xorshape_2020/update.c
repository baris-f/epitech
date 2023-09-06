/*
** update.c for update in /home/grandm_a/gfx_fdf1
**
** Made by Grandmaire Corentin
** Login   <grandm_a@epitech.net>
**
** Started on  Wed Nov 18 13:22:49 2015 Grandmaire Corentin
** Last update Mon Nov 30 09:52:16 2015 Florent Baris
*/

#include <lapin.h>
#include <lapin_enum.h>
#include <unistd.h>
#include "my_lap.h"

void    my_fill(t_bunny_pixelarray *pix, unsigned int color)
{
  unsigned int *pixel;
  int           i;

  i = -1;
  pixel = pix->pixels;
  while (pixel[++i])
    pixel[i] = color;
}

t_bunny_response	update(void *_void)
{
  t_pass		*pass;

  pass = _void;
  bunny_display(pass->win);
  return (GO_ON);
}

int			main()
{
  t_pass	       pass;
  t_bunny_shape shapes[3] =
    {
      {400, 400, 100, RED, GREEN},
      {450, 500, 200, RED, BLUE},
      {200, 200, 100, WHITE, GREEN}
    };

  pass.win = bunny_start(1000, 1000, 0, "baris_f pd");
  pass.img = bunny_new_pixelarray(1000, 1000);
  pass.imgpos->x = 0;
  pass.imgpos->y = 0;


/*		instructions		*/
  xor_shape(pass.img, shapes, 3);
/*		instructions		*/


  bunny_blit(&(pass.win->buffer), &(pass.img->clipable), pass.imgpos);
  bunny_set_loop_main_function(update);
  bunny_loop(pass.win, 255, &pass);
  bunny_delete_clipable(&(pass.img->clipable));
  bunny_stop(pass.win);
  return (0);
}
