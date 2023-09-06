/*
** my_strdup.c for my_strdup in /home/baris_f/rendu/Piscine_C_J08/ex_01
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Wed Oct  7 09:48:28 2015 Florent Baris
** Last update Thu Jan 28 16:16:04 2016 Florent Baris
*/

#include <stdlib.h>
#include "my.h"

char	*my_strdup(char *src)
{
  char	*str;
  int	len;
  int	i;

  i = 0;
  len = my_strlen(src);
  if ((str = malloc(sizeof(char) * len)) == NULL)
    return (0);
  while (src[i])
    {
      str[i] = src[i];
      i++;
    }
  str[i] = '\0';
  return (str);
}
