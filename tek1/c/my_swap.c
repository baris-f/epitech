/*
** my_swap.c for my_swap in /home/baris_f/rendu/Piscine_C_J04
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Thu Oct  1 08:55:32 2015 Florent Baris
** Last update Thu Jan 28 17:56:29 2016 Florent Baris
*/

#include "my.h"

void	my_swap(int *a, int *b)
{
  int	swap;

  swap = *a;
  *a = *b;
  *b = swap;
}
