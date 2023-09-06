/*
** main.c for main in /home/cridli_p/rendu/colles/CPE_colle_semaine3
**
** Made by Paul Cridlig
** Login   <cridli_p@epitech.net>
**
** Started on  Wed May 11 16:28:56 2016 Paul Cridlig
** Last update Tue May 17 16:52:34 2016 Florent Baris
*/

#include <unistd.h>
#include <math.h>
#include <lapin.h>
#include <stdlib.h>
#include <time.h>
#include "include/my.h"
#define WIDTH 1600
#define HEIGHT 900

void    tekpixel(t_bunny_pixelarray  *pix, t_bunny_position *pos,
                 unsigned int color)
{
  unsigned int *img;

  img = (unsigned int*)pix->pixels;
  img[(pix->clipable.clip_width) * pos->y + pos->x] = color;
}

void                    tekcircle(t_bunny_pixelarray *pix, t_bunny_position O,
				  int *R,
				  unsigned int col)
{
  t_bunny_position      cur;
  float                 alpha;
  float                 p;

  alpha = 0.0;
  p = 0.05;
  p = p / 180 * M_PI;
  while (alpha < 2 * M_PI)
    {
      alpha += p;
      cur.x = O.x + cos(alpha) * R[1];
      cur.y = O.y + sin(alpha) * R[2];
      tekpixel(pix, &cur, col);
    }
}

t_bunny_response        key(t_bunny_event_state state,
                            t_bunny_keysym key,
                            void *data)
{
  (void)state;
  (void)data;
  if (key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

void    my_bunny_fill(t_bunny_pixelarray *pix, t_bunny_position pos)
{
  while (pos.y <= HEIGHT)
    {
      pos.x = 0;
      while (pos.x <= WIDTH)
        {
          pos.x++;
          tekpixel(pix, &pos, BLACK);
        }
      pos.y++;
    }
}

int			main()
{
  t_bunny_window	*window;
  t_bunny_pixelarray	*pix;
  t_bunny_position	pos;
  t_bunny_music		*mu;
  int			i;
  t_bunny_pixelarray    *pix2;
  int			tab[3];

  pix2 =  bunny_load_pixelarray("stargate.png");
  window = bunny_start(WIDTH, HEIGHT, 0, "Stargate");
  pix = bunny_new_pixelarray(WIDTH, HEIGHT);
  if ((mu = bunny_load_music("stargate.ogg")) == NULL)
    return (-1);
  bunny_set_key_response(key);
  bunny_sound_play(&mu->sound);
  i = 220;
  while (--i > 0)
    {
      pos.x = 0;
      pos.y = 0;
      tab[1] = i;
      tab[2] = i;
      my_bunny_fill(pix, pos);
      pos.x = WIDTH / 2 + 100;
      pos.y = HEIGHT / 3;
      tekcircle(pix2, pos, tab, BLUE);
      pos.x = 0;
      pos.y = 0;
      bunny_blit(&window->buffer, &pix->clipable, &pos);
      add_pic(window, pix2);
      bunny_display(window);
    }
  bunny_loop(window, 200, NULL);
  bunny_stop(window);
  bunny_delete_sound(&mu->sound);
  return (0);
}
