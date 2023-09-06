/*
** my_strdup.c for my_strdup in /home/baris_f/rendu/Piscine_C_J08/ex_01
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Wed Oct  7 09:48:28 2015 Florent Baris
** Last update Wed Oct  7 10:03:32 2015 Florent Baris
*/

#include<stdlib.h>

char	*my_strdup(char *src)
{
  char	*str;
  int	len;

  len = my_strlen(src);
  str = malloc(len);
  str = src;
  return (str);
}
