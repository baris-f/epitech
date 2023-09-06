/*
** my_strcpy.c for my_strcpy in /home/baris_f/rendu/Piscine_C_J06/ex_02
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Oct  5 09:07:33 2015 Florent Baris
** Last update Thu Jan 28 23:31:13 2016 Florent Baris
*/

#include "my.h"

char *my_strcpy(char *dest, char *src)
{
  int i;

  i = 0;
  while(src[i])
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return dest;
}
/* char	*my_strcpy(char *dest, char *src) */
/* { */
/*   int	i; */

/*   i = 0; */
/*   while (src[i]) */
/*     { */
/*       dest[i] = src[i]; */
/*       i++; */
/*     } */
/*   dest[i] = '\0'; */
/*   return (dest); */
/* } */
