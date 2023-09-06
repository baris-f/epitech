/*
** env.c for 42sh in /home/dudu/rendu/PSU_2015_42sh
**
** Made by lucas duval
** Login   <duval_m@epitech.net>
**
** Started on  Tue May 10 09:41:26 2016 lucas duval
** Last update Sun Jun  5 20:55:11 2016 lucas duval
*/

#include "42s.h"

int	print_env(t_42 *base)
{
  print_tab(base->env);
  return (1);
}

int	add_env(t_42 *base, char *name, char *value)
{
  char	*new_ell;

  if (value)
    {
      if ((new_ell = malloc(sizeof(char)
			    * (strlen(name) + strlen(value) + 2))) == NULL)
	return (print_err(1));
      sprintf(new_ell, "%s=%s", name, value);
    }
  else
    {
      if ((new_ell = malloc(sizeof(char)
			    * (strlen(name) + 2))) == NULL)
	return (print_err(1));
      sprintf(new_ell, "%s=", name);
    }
  if ((base->env = realloc(base->env, sizeof(char *)
			   * (++base->nb_env + 1))) == NULL)
    return (print_err(1));
  base->env[base->nb_env - 1] = new_ell;
  base->env[base->nb_env] = NULL;
  return (1);
}

int	change_env(t_42 *base, char *name, char *value, int index)
{
  char	*new_ell;

  if (base->env[index])
    free(base->env[index]);
  if (value)
    {
      if ((new_ell = malloc(sizeof(char)
			    * (strlen(name) + strlen(value) + 2))) == NULL)
	return (print_err(1));
      sprintf(new_ell, "%s=%s", name, value);
    }
  else
    {
      if ((new_ell = malloc(sizeof(char)
			    * (strlen(name) + 2))) == NULL)
	return (print_err(1));
      sprintf(new_ell, "%s=", name);
    }
  base->env[index] = new_ell;
  return (1);
}

int	check_env(t_42 *base, char *name, char *value)
{
  int	i;

  i = -1;
  while (base->env[++i] && strncmp(base->env[i], name, strlen(name)) != 0);
  if (i >= base->nb_env)
    return (add_env(base, name, value));
  else
    return (change_env(base, name, value, i));
}

int	del_env(t_42 *base, char *name)
{
  int	i;

  i = -1;
  while (base->env[++i] && strncmp(base->env[i], name, strlen(name)) != 0);
  if (!(i >= base->nb_env))
    {
      if (base->env[i])
	free(base->env[i]);
      --i;
      while (base->env[++i])
	base->env[i] = base->env[i + 1];
      if ((base->env = realloc(base->env,
			       sizeof(char *) * (--base->nb_env + 1))) == NULL)
	return (print_err(1));
    }
  return (1);
}
