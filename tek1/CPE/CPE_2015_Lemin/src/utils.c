/*
** utils.c for lemin in /home/dudu/rendu/CPE_2015_lemin
**
** Made by lucas duval
** Login   <duval_m@epitech.net>
**
** Started on  Mon Apr 18 08:55:51 2016 lucas duval
** Last update Mon Apr 25 08:52:41 2016 lucas duval
*/

#include "lemin.h"

void	*my_memcpy(void *dest, void *src, size_t n)
{
  size_t i;
  char *d;
  char *s;
  s = src;
  d = dest;
  i = -1;
  while (++i < n)
    d[i] = s[i];
  return (dest);
}

void	*my__realloc(void *ptr, size_t size, size_t old)
{
  void	*newptr;

  if (size <= old)
    return (ptr);
  newptr = malloc(size);
  newptr = my_memcpy(newptr, ptr, old);
  free(ptr);
  return (newptr);
}
