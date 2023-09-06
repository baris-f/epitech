/*
** load_bitmap.c for bitmap in /home/fus/tmp/bmp/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Thu Jan 14 16:09:12 2016 Gaspard Thirion
** Last update Sat Jan 16 21:57:52 2016 Gaspard Thirion
*/

#include "tool.h"

t_col		*bmpread(char *name, int *i, t_2D *pos)
{
  t_col		*buff;
  int		fd;
  int		len;

  if ((fd = open(name, S_IRUSR)) < 0
      || (buff = malloc(sizeof(t_col) * 6)) == NULL
      || (read(fd, buff, 6)) < 0)
    return (NULL);
  len = buff[0] / 0x10000 + buff[1] * 0x10000;
  free(buff);
  if ((buff = malloc(sizeof(t_col) * len)) == NULL
      || (read(fd, buff, len)) < 0)
    return (NULL);
  close(fd);
  pos->x = buff[3];
  pos->y = buff[4];
  *i = buff[1] - 43;
  return (buff);
}

t_img		*load_bitmap(char *name)
{
  t_col		*buff;
  int		i;
  t_2D		pos;
  t_img		*tmp;

  if ((buff = bmpread(name, &i, &pos)) == NULL)
    return (NULL);
  if ((tmp = bunny_new_pixelarray(pos.x, pos.y)) == NULL)
    return (NULL);
  pos.y = tmp->clipable.clip_height;
  while (--(pos.y) >= 0)
    {
      pos.x = -1;
      while (++(pos.x) < tmp->clipable.clip_width && ++i)
	{
	  mpixel(tmp, pos, (buff[i] & 0xff) * 0x10000 + (buff[i] & 0xff00) + (buff[i] / 0x10000 & 0xff) + 0xff000000);
	}
    }
  free(buff);
  return (tmp);
}
