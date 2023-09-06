/*
** load_bitmap.c for loadbmp in /home/baris-f/rendu/gfx/gfx_tekgui
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sun Feb 28 18:23:26 2016 Florent Baris
** Last update Sun Feb 28 18:23:28 2016 Florent Baris
*/

#include "tool.h"

t_col		*bmpread(char *name, t_2D *pos)
{
  t_col		*buff;
  int		fd;
  int		len;

  if ((fd = open(name, S_IRUSR)) < 0
      || (buff = malloc(27)) == NULL
      || (read(fd, buff, 27)) < 0)
    return (NULL);
  pos->x = (int)(buff[4] / 0x10000);
  pos->y = (int)(buff[5] / 0x10000);
  len = pos->x * pos->y;
  free(buff);
  if ((buff = malloc(sizeof(t_col) * (len))) == NULL
      || (read(fd, buff, sizeof(t_col) * (len))) < 0)
    return (NULL);
  my_printf("%s : (%d ; %d) = %d\n", name, pos->x, pos->y, len);
  close(fd);
  return (buff);
}

t_img		*load_bitmap(char *name)
{
  t_col		*buff;
  int		i;
  t_2D		pos;
  t_img		*tmp;

  if ((buff = bmpread(name, &pos)) == NULL)
    return (NULL);
  if ((tmp = bunny_new_pixelarray(pos.x, pos.y)) == NULL)
    return (NULL);
  i = 27;
  while (--(pos.y) >= 0)
    {
      pos.x = -1;
      while (++(pos.x) < tmp->clipable.clip_width && ++i)
	tekpixel(tmp, pos, 0xff000000 + (buff[i] & 0xff0000)
		 / 0x10000 + (buff[i] & 0xff00) + (buff[i] & 0xff) * 0x10000);
    }
  free(buff);
  return (tmp);
}
