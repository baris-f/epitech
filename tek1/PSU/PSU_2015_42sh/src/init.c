/*
** init.c for 42sh in /home/dudu/rendu/PSU_2015_42sh
**
** Made by lucas duval
** Login   <duval_m@epitech.net>
**
** Started on  Tue May 10 08:55:42 2016 lucas duval
** Last update Fri Jun  3 14:08:02 2016 Corentin Grandmaire
*/

#include "42s.h"

int	init(t_42 *base, char **env)
{
  int	i;
  int	size;

  setbuf(stdout, NULL);
  i = -1;
  base->nb_env = count_env(env);
  if ((base->env = malloc(sizeof(char*) * (base->nb_env + 1))) == NULL)
    return (print_err(1));
  while (env[++i])
    {
      size = strlen(env[i]);
      if ((base->env[i] = malloc(sizeof(char) * (size + 1))) == NULL)
	return (print_err(1));
      strcpy(base->env[i], env[i]);
    }
  base->env[i] = NULL;
  base->idx = 1;
  base->redir = 0;
  return (0);
}
