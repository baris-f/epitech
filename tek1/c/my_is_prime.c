/*
** my_is_prime.c for my_is_prime in /home/baris_f/rendu/Piscine_C_J05
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Fri Oct  2 12:49:39 2015 Florent Baris
** Last update Thu Jan 28 15:45:16 2016 Florent Baris
*/

#include "my.h"

int	my_is_prime(int nombre)
{
  int	result;
  int	i;

  i = 2;
  if (nombre <= 1)
    return (0);
  result = my_isprimerec(nombre, i);
  return (result);
}

int	my_isprimerec(int nb, int i)
{
  if (i == nb)
    return (1);
  if ((nb % i) == 0)
    return (0);
  i++;
  return(my_isprimerec(nb, i));
}