/*
** my_strstr.c for my_strstr in /home/baris_f/rendu/Piscine_C_J06/ex_05
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Oct  5 13:53:37 2015 Florent Baris
** Last update Thu Jan 28 16:18:24 2016 Florent Baris
*/

#include "my.h"

char	*my_strstr(char *str, char *to_find)
{
  int	i;
  int	j;
  int	n_tofind;

  i = 0;
  j = 0;
  n_tofind = my_strlen(to_find);

  while (str[i] != '\0')
    {
      if (str[i] == to_find[j])
	  j++;
      else
	  j = 0;
      if (j == n_tofind)
	  return (str + (i - n_tofind + 1));
      i++;
    }

  return (0);
}
