/*
** my_strcat.c for my_strcat in /home/baris_f/rendu/c
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Tue Oct  6 10:12:56 2015 Florent Baris
** Last update Thu Jan 28 23:03:32 2016 Florent Baris
*/

#include "my.h"

char    *my_strcat(char *dest, char *src)
{
  int   j;
  int   i;

  j = 0;
  while (dest[j])
    j++;
  i = 0;
  while (src[i])
    {
      dest[i + j] = src[i];
      i++;
    }
  dest[i + j] = '\0';
  return (dest);
}
