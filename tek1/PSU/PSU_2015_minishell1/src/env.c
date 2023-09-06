/*
** env.c for env in /home/baris-f/rendu/PSU/PSU_2015_minishell1
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sun Jan 24 20:58:21 2016 Florent Baris
** Last update Fri Jan 29 13:23:13 2016 Florent Baris
*/

#include "my.h"

void    get_env(t_min *ishell, char **env)
{
  int   i;
  int   len;
  char  *name;
  char  *var;

  i = -1;
  ishell->env = NULL;
  while (env[++i])
    {
      len = -1;
      while (env[i][++len] != '=');
      if ((name = malloc(sizeof(char) * len + 2)) == NULL)
	return ;
      my_strncpy(name, env[i], len);
      len = my_strlen(env[i] + len + 1);
      if ((var = malloc(sizeof(char) * len + 2)) == NULL)
	return ;
      my_strcpy(var, env[i] + my_strlen(name) + 1);
      push(&ishell->env, name, var);
      free(name);
    }
}

void    unsetenv(t_min *ishell, char *argv)
{
  t_env *first;
  t_env *last;

  first = ishell->env;
  last = NULL;
  while (ishell->env)
    {
      if (my_strcmp(ishell->env->env_name, argv) == 0)
	{
	  ishell->env->prec = last;
	  free(last);
	  ishell->env = first;
	  free(first);
	  return ;
	}
      last = ishell->env;
      ishell->env = ishell->env->prec;
    }
}

void    make_env(t_min *ishell, char **env)
{
  int   i;
  t_env *tmp;

  i = 0;
  tmp = ishell->env;
  while (tmp)
    {
      env[i] = malloc(sizeof(char ) * (my_strlen(tmp->env_name)
				       + my_strlen(tmp->env_variable) + 2));
      my_strcpy(env[i], tmp->env_name);
      my_strcat(env[i], "=");
      my_strcat(env[i], tmp->env_variable);
      tmp = tmp->prec;
      i++;
    }
  env[i - 1] = NULL;
  free(tmp);
}
