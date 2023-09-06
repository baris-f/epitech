/*
** bitmap_header.c for bitmap in /home/baris_f/rendu/tek2/cpp_d01/ex02
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Wed Jan  4 16:07:40 2017 baris_f
** Last update Wed Jan  4 16:24:21 2017 baris_f
*/

#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include "bitmap.h"

/*
int			main()
{
  t_bmp_header		header;
  t_bmp_info_header	info;
  int			d;
  uint32_t		pixel = 0x1234567;

  make_bmp_header(&header, 32);
  make_bmp_info_header(&info, 32);
  d = open ("32px.bmp" , O_CREAT | O_TRUNC | O_WRONLY, 0644) ;
  write(d, &header, sizeof(header)) ;
  write(d, &info, sizeof(info)) ;
  for(size_t i = 0; i < 32 * 32 ; ++i)
    write(d, &pixel, sizeof(pixel)) ;
  close(d) ;
  return (0);
}
*/
void make_bmp_header (t_bmp_header *header, size_t size)
{
  header->magic = 0x4D42;
  header->size = size * 4 * size * 4 + 54;
  header->_app1 = 0;
  header->_app2 = 0;
  header->offset = 54;
}

void make_bmp_info_header (t_bmp_info_header *header, size_t size)
{
  header->size = 40;
  header->width = size;
  header->height = size;
  header->planes = 1;
  header->bpp = 32;
  header->compression = 0;
  header->raw_data_size = size * 4 * size * 4;
  header->h_resolution = 0;
  header->v_resolution = 0;
  header->palette_size = 0;
  header->important_colors = 0;
}
