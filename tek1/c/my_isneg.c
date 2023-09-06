/*
** my_isneg.c for my_isneg in /home/baris_f/rendu/Piscine_C_J03
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Wed Sep 30 10:02:17 2015 Florent Baris
** Last update Thu Jan 28 16:02:30 2016 Florent Baris
*/

#include "my.h"

int	my_isneg(int nb)
{
  if (nb >= 0)
    {
      my_putchar('P');
    }
  else
    {
      my_putchar('N');
    }
  return (0);
}
