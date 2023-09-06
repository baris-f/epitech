/*
** bitmap.h for bitmap in /home/baris_f/rendu/tek2/cpp_d01/ex02
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Wed Jan  4 16:08:05 2017 baris_f
** Last update Wed Jan  4 16:08:07 2017 baris_f
*/

#ifndef BITMAP_H_
# define BITMAP_H_

#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct	__attribute__((packed)) s_bmp_header
{
  uint16_t	magic;
  uint32_t	size;
  uint16_t	_app1;
  uint16_t	_app2;
  uint32_t	offset;
}		t_bmp_header;

typedef struct	__attribute__((packed)) s_bmp_info_header
{
  uint32_t	size;
  int32_t	width;
  int32_t	height;
  uint16_t	planes;
  uint16_t	bpp;
  uint32_t	compression;
  uint32_t	raw_data_size;
  int32_t	h_resolution;
  int32_t	v_resolution;
  uint32_t	palette_size;
  uint32_t	important_colors;
}		t_bmp_info_header;

void make_bmp_header		(t_bmp_header* , size_t);
void make_bmp_info_header	(t_bmp_info_header* , size_t);

#endif /* !BITMAP_H_ */
