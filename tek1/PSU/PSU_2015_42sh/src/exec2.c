/*
** exec2.c for 42sh in /home/dudu/rendu/PSU_2015_42sh/src
**
** Made by lucas duval
** Login   <duval_m@epitech.net>
**
** Started on  Sun Jun  5 20:56:37 2016 lucas duval
** Last update Sun Jun  5 21:14:07 2016 Corentin Grandmaire
*/

#include "42s.h"

char    *my_specialcat(char *s1, char *s2)
{
  int   i;
  int   j;
  int   len;
  char  *tmp;

  i = -1;
  j = -1;
  len = my_strlen(s1) + my_strlen(s2);
  if (!(tmp = calloc((len + 2), sizeof(char))))
    return (NULL);
  while (s1[++i])
    tmp[i] = s1[i];
  tmp[i++] = '/';
  while (s2[++j])
    tmp[j + i] = s2[j];
  return (tmp);
}

char	*check(t_42 *sh, char **pth)
{
  int	i;
  char	*tmp;

  i = -1;
  while (pth[++i])
    {
      tmp = my_specialcat(pth[i], sh->cmd);
      if (access(tmp, F_OK) != -1)
	return (tmp);
      free(tmp);
    }
  return (NULL);
}
