/*
** matchselect.c for matchselect in /home/baris-f/rendu/PSU_2015_my_select
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Wed Dec  2 20:14:27 2015 Florent Baris
** Last update Sun Dec 13 17:19:30 2015 Florent Baris
*/

#include <stdlib.h>
#include <ncurses.h>
#include "my_select.h"

int     matchselect(char *s1, char *s2)
{
  char  *tmp;
  int   ret;
  int	i;

  if (s2[0] == '\0')
    return (0);
  i = -1;
  while (s2[++i])
    if (s2[i] == '*')
	return (recmatch(s1, s2));
  tmp = malloc(sizeof(char) * (my_strlen(s2) + 3));
  i = -1;
  while (++i < my_strlen(s2) + 3)
    tmp[i] = '\0';
  tmp[0] = '*';
  my_strcat(tmp, s2);
  tmp[my_strlen(s2) + 1] = '*';
  ret = recmatch(s1, tmp);
  free(tmp);
  return (ret);
}
