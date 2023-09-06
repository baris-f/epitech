/*
** my_fill.c for my_fill.c in /home/baris_f/rendu/gfx_fdf1
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Wed Nov 18 16:17:54 2015 Florent Baris
** Last update Sun Nov 22 21:02:41 2015 Florent Baris
*/

#include <lapin.h>
#include <unistd.h>
#include <lapin_enum.h>

void    my_fill(t_bunny_pixelarray *pix, unsigned int color)
{
  unsigned int *pixel;
  int           i;

  i = -1;
  pixel = (unsigned int*)pix->pixels;
  while (pixel[++i])
    pixel[i] = color;
}
