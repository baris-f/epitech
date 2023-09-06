/*
** tekbmp.c for tekbmp in /home/fus/tmp/rush/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Mon Dec  7 20:28:55 2015 Gaspard Thirion
** Last update Mon Jan 18 12:50:36 2016 Gaspard Thirion
*/

#include "tool.h"

typedef struct		s_bmp
{
  int			start;
  int			width;
  int			height;
  int			bitnum;
  int			comp;
  int			size;
}			t_bmp;

void			bmp_info(t_bmp *file)
{
  my_printf("start = %d : (%d x %d), bitnum = %d, comp = %s, size = %d\n",
	    file->start,
	    file->width,
	    file->height,
	    file->bitnum,
	    ((file->comp == 0) ? ("none")
	     : (file->comp == 1) ? ("RLE-8")
	     : (file->comp == 2) ? ("RLE-4")
	     : ("err")),
	    file->size
	    );
}

unsigned int		bmp_read(FILE *fd, unsigned char *buff, int size)
{
  int			i;
  unsigned int		out;

  out = 0;
  i = -1;
  while (++i < size && fread(buff, 1, 1, fd))
    out += buff[0] * ((i == 1) ? (0x100) : (i == 2) ? (0x10000)
		      : (i == 3) ? (0x1000000) : (1));
  return (out);
}

void			bmp_init(FILE *fd, t_bmp *file)
{
  unsigned char		*buff;

  if ((buff = malloc(sizeof(char))) == NULL)
    return;
  bmp_read(fd, buff, 10);
  file->start = bmp_read(fd, buff, 4);
  bmp_read(fd, buff, 4);
  file->width = bmp_read(fd, buff, 4);
  file->height = bmp_read(fd, buff, 4);
  bmp_read(fd, buff, 2);
  file->bitnum = bmp_read(fd, buff, 2) / 8;
  (file->bitnum < 4) ? (file->bitnum = 3):(0);
  file->comp = bmp_read(fd, buff, 4);
  file->size = bmp_read(fd, buff, 4);
  bmp_read(fd, buff, file->start - 38);
  free(buff);
}

void			bmp_blit(FILE *fd, t_bmp *file, t_bunny_pixelarray *tmp)
{
  unsigned char		*buff;
  int			i;
  int			j;
  unsigned int		col;
  unsigned int		*pix;

  if ((buff = malloc(sizeof(char))) == NULL)
    return;
  pix = (unsigned int*)tmp->pixels;
  i = 0;
  while (i < file->size)
    {
      j = -1;
      col = 0xff;
      while (++j < file->bitnum && fread(buff, 1, 1, fd))
	{
	  col *= 0x100;
	  col += buff[0];
	}
      pix[i / file->bitnum] = col;
      i += j;
    }
  free(buff);
}

void			bmp_load(char *bmp, t_bunny_pixelarray *dest)
{
  FILE			*fd;
  t_bmp			file;
  t_bunny_pixelarray	*tmp;

  if (bmp == NULL || (fd = fopen(bmp, "rb")) == NULL)
    return;
  bmp_init(fd, &file);
  tmp = bunny_new_pixelarray(file.width, file.height);
  tmp->clipable.clip_x_position = 0;
  tmp->clipable.clip_y_position = 0;
  tmp->clipable.clip_width = file.width;
  tmp->clipable.clip_height = file.height;
  bmp_info(&file);
  bmp_blit(fd, &file, tmp);
  mblit(dest, tmp, 0);
  fclose(fd);
  bunny_delete_clipable(&tmp->clipable);
}
