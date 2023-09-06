/*
** fonct.c for marv in /home/baris-f/rendu/marvin_baris_f
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sun May 15 23:16:47 2016 Florent Baris
** Last update Sun May 15 23:33:04 2016 Florent Baris
*/

#include "marvin.h"

char	*get_func(char *str)
{
  int	i;
  char	*tmp;

  i = -1;
  while (str[++i] != '(' && str[i]);
  if ((tmp = malloc (sizeof(char) * i + 1)) == NULL)
    exit(printf("malloc fail\n"));
  i = -1;
  while (str[++i] != '(' && str[i])
    tmp[i] = str[i];
  tmp[i] = '\0';
  return (tmp);
}

char    *get_param(char *str, char **av)
{
  int   i;
  int	j;
  char  *tmp;

  i = -1;
  while (str[++i] != '(' && str[i]);
  i--;
  j = 0;
  while (str[++i] != ' ' && str[i])
    j++;
  if (i == (int)strlen(av[1] - 1))
    exit(printf("pas de paramètre à la fonction\n"));
  if ((tmp = malloc (sizeof(char) * j + 1)) == NULL)
    exit(printf("malloc fail\n"));
  i -= j;
  j = -1;
  while (str[++i] != ' ' && str[i])
    tmp[++j] = str[i];
  tmp[j] = '\0';
  return (tmp);
}
