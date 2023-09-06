/*
** my_strcmpls.c for my_strcmpls in /home/baris-f/rendu/PSU_2015_my_ls
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Thu Nov 26 11:06:30 2015 Florent Baris
** Last update Sun Nov 29 22:04:36 2015 Florent Baris
*/

#include "my_ls.h"

int     my_strcmpls(char *s1, char *s2)
{
  int   i;
  char	*tmp1;
  char	*tmp2;

  tmp1 = my_strlowcase(s1);
  tmp2 = my_strlowcase(s2);
  while (!(isalphanum(tmp1[0])) && tmp1[0] != '\0')
    {
      (tmp1[my_strlen(tmp1) - 1])++;
      *tmp1++;
    }
  while (!(isalphanum(tmp2[0])) && tmp2[0] != '\0')
    {
      (tmp2[my_strlen(tmp2) - 1])++;
      *tmp2++;
    }
  i = 0;
  while (tmp1[i] == tmp2[i] && tmp1[i] != '\0' && tmp2[i] != '\0')
    i++;
  if (tmp1[i - 1] == tmp2[i - 1] && tmp1[i] == '\0' && tmp2[i] == '\0')
    return (0);
  return (tmp1[i] - tmp2[i]);
}
