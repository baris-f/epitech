/*
** my_find_prime_sup.c for my_find_prime_sup in /home/baris_f/rendu/Piscine_C_J05
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Fri Oct  2 13:36:49 2015 Florent Baris
** Last update Thu Jan 28 17:49:35 2016 Florent Baris
*/

#include "my.h"

int	my_find_prime_sup(int nb)
{
  if (my_is_prime(nb) == 1)
    return (nb);
  else
    my_find_prime_sup(nb + 1);
  return (0);
}
