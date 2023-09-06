/*
** drawing.c for bitmap in /home/baris_f/rendu/tek2/cpp_d01/ex03
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Wed Jan  4 16:20:26 2017 baris_f
** Last update Wed Jan  4 17:18:01 2017 baris_f
*/

#include <stdint.h>
#include "bitmap.h"
#include "drawing.h"
/*
int			main()
{
  t_bmp_header			header;
  t_bmp_info_header		info;
  unsigned int          *buffer;
  unsigned int          **img;
  t_point               p = {0, 0};
  size_t                size = 64;
  int                   d;

  buffer = malloc(size * size * sizeof(*buffer));
  img = malloc(size * size * sizeof(*buffer));
  img = malloc(size * sizeof(*img));
  memset(buffer, 0, size * sizeof(*buffer));
  for(size_t i = 0 ; i < size ; i++)
    img[i] = buffer + i * size;

  make_bmp_header(& header, size);
  make_bmp_info_header(&info, size);
  draw_square( img, &p, size, 0x0000FFFF);
  p.x = 0;
  p.y = 0;
  draw_square( img, &p, 22, 0x00FF0000);
  d = open ( "square.bmp" , O_CREAT | O_TRUNC | O_WRONLY, 0644);
  write( d, &header, sizeof(header));
  write( d, &info, sizeof(info));
  write( d, buffer, size * size * sizeof(*buffer));
  close( d );
  return (0);
}

void			make_bmp_header(t_bmp_header *header, size_t size)
{
  header->magic = 0x4D42;
  header->size = size * 4 * size + 54;
  header->_app1 = 0;
  header->_app2 = 0;
  header->offset = 54;
}

void			make_bmp_info_header(t_bmp_info_header *header, size_t size)
{
  header->size = 40;
  header->width = size;
  header->height = size;
  header->planes = 1;
  header->bpp = 32;
  header->compression = 0;
  header->raw_data_size = size * 4 * size;
  header->h_resolution = 0;
  header->v_resolution = 0;
  header->palette_size = 0;
  header->important_colors = 0;
}
*/
void			draw_square(uint32_t **img, t_point *orig, size_t size, uint32_t col)
{
  t_point		cur;

  cur.x = -1;
  while (++cur.x < size)
    {
      cur.y = -1;
      while (++cur.y < size)
	img[orig->x + cur.x][orig->y + cur.y] = col;
    }
}
