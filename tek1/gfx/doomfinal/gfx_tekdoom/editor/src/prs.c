/*
** prs.c for prs in /home/baris-f/rendu/gfx/gfx_tekdoom/gfx_wolf3d
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Wed Jan 20 19:03:22 2016 Florent Baris
** Last update Wed Jan 20 23:19:54 2016 Florent Baris
*/

#include <wolf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

t_img           *prs_load(char *name, t_base *pass)
{
  t_img         *ret;
  int           fd;
  int           x;
  int           y;
  t_col         *buff;
  t_col         *dest;
  int           i;
  int           size;

  fd = open(name, O_RDONLY);
  if ((buff = malloc(sizeof(t_col*) * 2)) == NULL)
    return (NULL);
  if (fd == -1)
    return (NULL);
  read(fd, buff, 2);
  x = (int)buff[0] & 0x0000FFFF;
  printf("%x\n", buff[0] & 0x0000FFFF);
  read(fd, buff, 2);
  y = (int)buff[0] & 0x0000FFFF;
  printf("%x\n", buff[0] & 0x0000FFFF);
  printf("fd : %d %s %d  %d\n", fd, name, x, y);
  ret = bunny_new_pixelarray(x, y);
  if ((pass->edit.tmp = bunny_new_pixelarray(x, y)) == NULL)
    return (NULL);
  size = x * y * 4;
  buff = malloc(sizeof(t_col*) * size);
  read(fd, buff, size);
  dest = (t_col*)ret->pixels;
  i = -1;
  while (++i < size)
    dest[i] = buff[i];
  free(buff);
  close(fd);
  return (ret);
}

void            tofile(t_img *bmp, char *name)
{
  int           fd;
  t_col         *buff;
  t_2D          dim;

  buff = (t_col*)bmp->pixels;
  fd = open(name, O_CREAT | O_RDWR, S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH);
  dim.x = bmp->clipable.clip_width;
  dim.y = bmp->clipable.clip_height;
  printf("%d  %d\n", dim.x, dim.y);
  write(fd, &dim.x, 2);
  write(fd, &dim.y, 2);
  write(fd, buff, dim.x * dim.y * 4);
  close(fd);
}
