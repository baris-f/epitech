#include "include/my.h"
#include <lapin.h>


void                    add_pic( t_bunny_window *window,
				t_bunny_pixelarray *pix2)
{
  t_bunny_position	pos;

  pos.x = 490;
  pos.y = 150;
  bunny_blit(&window->buffer, &pix2->clipable, &pos);
}
