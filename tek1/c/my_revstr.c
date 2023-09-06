/*
** my_revstr.c for my_revstr in /home/baris_f/rendu/Piscine_C_J06/ex_04
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Oct  5 10:27:01 2015 Florent Baris
** Last update Thu Jan 28 16:13:03 2016 Florent Baris
*/

#include "my.h"

char	*my_revstr(char *str)
{
  char	temp;
  int	len;
  int	i;

  i = 0;
  len = my_strlen(str);
  while (i < len / 2)
    {
      temp = str[i];
      str[i] = str[len - i - 1];
      str[len - i - 1] = temp;
      i++;
    }
  return (str);
}
