/*
** my_strcapitalize.c for my_strcapitalize in /home/baris_f/rendu/Piscine_C_J06/ex_10
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Oct  5 16:10:02 2015 Florent Baris
** Last update Thu Jan 28 16:14:35 2016 Florent Baris
*/

#include "my.h"

char	*my_strcapitalize(char *str)
{
  int i;

  i = 0;
  while (str[i])
    {
      if ((i > 0 && (str[i - 1] < 'a' || str[i - 1] > 'z') &&
	  (str[i - 1] < '0' || str[i - 1] > '9') &&
	  (str[i - 1] < 'A' || str[i - 1] > 'Z') &&
	  (str[i] >= 'a' && str[i] <= 'z'))
	  || (i == 0 && (str[i] >= 'a' && str[i] <= 'z')))
	str[i] -= 32;
      i++;
    }
  return (str);
}
