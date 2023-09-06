/*
** my_square_root.c for my_square_root in /home/baris_f/rendu/Piscine_C_J05
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Fri Oct  2 10:44:49 2015 Florent Baris
** Last update Thu Jan 28 17:53:32 2016 Florent Baris
*/

#include "my.h"

int	my_square_root(int nb)
{
  int	result;

  result = 0;
  result = my_sq(nb, result);
  return (result);
}

int	my_sq(int nb, int result)
{
  if ((result * result) > nb)
    return (0);
  if ((result * result) == nb)
    return (result);
  my_sq(nb, result + 1);
  return (0);
}
