#include <lapin.h>
#include <lapin_enum.h>
#include <unistd.h>
#include <math.h>

void    my_fill(t_bunny_pixelarray *pix, unsigned int color);

void                    tekfill(t_bunny_pixelarray *img, unsigned int col)
{
  unsigned int          *buff;
  int                   i;

  i = -1;
  buff = (unsigned int*)img->pixels;
  while (++i < (img->clipable.clip_width * img->clipable.clip_height))
    buff[i] = col;
}

int                     main(int ac, char **av)
{
  t_bunny_position	pos[2];
  t_bunny_window	*win;
  t_bunny_pixelarray	*img;
  t_bunny_pixelarray	*ori;

  pos->x = 0;
  pos->y = 0;
  win = bunny_start(500, 500, 0, "baris_f pd");
  img = bunny_new_pixelarray(500, 500);
  ori = bunny_new_pixelarray(250, 250);

  tekfill(ori, BLUE);

  /*              instructions            */
  stretch(img, ori);

  /*              instructions            */

  while(1)
    {
    bunny_blit(&(win->buffer), &(img->clipable), pos);
    bunny_display(win);
    }

  bunny_stop(win);
  return (0);
}
