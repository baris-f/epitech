/*
** main.c for menger in /home/baris_f/rendu/tek2/cpp_d01/ex01
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Wed Jan  4 12:34:57 2017 baris_f
** Last update Wed Jan  4 17:41:05 2017 baris_f
*/

#include <stdio.h>
#include "bitmap.h"

int     menger(int size, int depth);
int     gnb(char *str);

int	main(int ac, char** av)
{
  t_bmp_header          header;
  t_bmp_info_header     info;
  int                   d;
  uint32_t              pixel = 0x00000000;
  t_bmp_header                  header;
  t_bmp_info_header             info;
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
  if (ac != 4 || gnb(av[2]) % 3 != 0 || gnb(av[2]) < gnb(av[3]))
    {
      printf("\n");
      return (0);
    }
  make_bmp_header(&header, 32);
  make_bmp_info_header(&info, 32);
  d = open (av[1] , O_CREAT | O_TRUNC | O_WRONLY, 0644);
  write(d, &header, sizeof(header)) ;
  write(d, &info, sizeof(info)) ;
  for(size_t i = 0; i < 32 * 32 ; ++i)
    write(d, &pixel, sizeof(pixel)) ;
  close(d) ;
  menger(gnb(av[2]), gnb(av[3]));
  return(0);
}
