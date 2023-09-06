/*
** my_power_rec.c for my_power_rec in /home/baris_f/rendu/Piscine_C_J05
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Fri Oct  2 10:25:41 2015 Florent Baris
** Last update Thu Jan 28 17:50:18 2016 Florent Baris
*/

#include "my.h"

int	my_power_rec(int nb, int power)
{
  int	result;

  result = 1;
  if (power == 0)
    return (1);
  result = my_powerrec(nb, power, result);
  return (result);
}

int	my_powerrec(int nb, int power, int result)
{
  if (power == 0)
    return (result);
  if ((result * nb) < result)
    return (0);
  if (-((result * nb) < result) && result < 0)
    return (0);
  result *= nb;
  my_powerrec(nb , power - 1, result);
  return (0);
}
