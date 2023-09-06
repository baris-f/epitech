/*
** my_memset.c for memset in /home/baris-f/rendu/c
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Thu Jan 28 15:24:35 2016 Florent Baris
** Last update Thu Jan 28 23:00:19 2016 Florent Baris
*/

#include "my.h"

void	my_memset(char *str, char c, int size)
{
  int	i;

  i = -1;
  while (++i < size)
    str[i] = c;
}
