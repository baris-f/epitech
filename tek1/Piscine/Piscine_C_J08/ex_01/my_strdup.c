/*
** my_strdup.c for my_strdup in /home/baris_f/rendu/Piscine_C_J08/ex_01
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Wed Oct  7 09:48:28 2015 Florent Baris
** Last update Fri Oct  9 19:34:42 2015 Florent Baris
*/

#include<stdlib.h>

char	*my_strdup(char *src)
{
  char	*str;
  int	len;
  int	i;

  i = 0;
  len = my_strlen(src);
  str = malloc(len);
  while(src[i])
    {
      str[i] = src[i];
      i++;
    }
  str[i] = '\0';
  return (str);
}
