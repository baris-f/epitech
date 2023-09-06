/*
** my_putnbr_base.c for my_putnbr_base.c in /home/fus/rendu/PSU_2015_my_printf
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Thu Nov 12 12:38:18 2015 Gaspard Thirion
** Last update Sat Feb 27 15:00:33 2016 Gaspard Thirion
*/

#include "bibi.h"

void	my_putnbr_base(int nbr, int base)
{
  int	d;
  int	aff;

  printf(" ");
  d = 1;
  while ((nbr / d) >= base)
    d = base * d;
  while (d > 0)
    {
      aff = ((nbr / d % base) + '0');
      if (aff >= 58)
      	aff += 39;
      printf("%c", aff);
      d = d / base;
    }
}
