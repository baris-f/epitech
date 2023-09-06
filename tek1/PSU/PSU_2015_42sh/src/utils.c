/*
** utils.c for 42sh in /home/dudu/rendu/PSU_2015_42sh
**
** Made by lucas duval
** Login   <duval_m@epitech.net>
**
** Started on  Tue May 10 09:05:31 2016 lucas duval
** Last update Fri Jun  3 15:08:42 2016 lucas duval
*/

#include "42s.h"

int	count_env(char **env)
{
  int	i;

  i = -1;
  while (env[++i]);
  return (i);
}

int	print_err(int err)
{
  if (err == 1)
    printf("Error malloc failled\n");
  return (-1);
}

void	print_tab(char **tab)
{
  int	i;

  i = -1;
  if (tab)
    while (tab[++i])
      printf("%s\n", tab[i]);
}

void	free_tab(char **tab)
{
  int	i;

  i = -1;
  if (tab)
    while (tab[++i])
      free(tab[i]);
  free(tab);
}
