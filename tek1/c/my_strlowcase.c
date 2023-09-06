/*
** my_strlowcase.c for my_strlowcase in /home/baris_f/rendu/Piscine_C_J06/ex_09
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Oct  5 15:58:47 2015 Florent Baris
** Last update Thu Jan 28 16:17:46 2016 Florent Baris
*/

#include "my.h"

void	*my_strlowcase(char *str)
{
  int   i;
  char	*tmp;

  tmp = my_strdup(str);
  i = 0;
  while (tmp[i])
    {
      if (tmp[i] <= 'Z' && tmp[i] >= 'A')
	tmp[i] += 32;
      i++;
    }
  return (tmp);
}
