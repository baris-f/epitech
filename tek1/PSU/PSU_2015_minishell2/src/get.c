/*
** get.c for get in /home/baris-f/rendu/PSU/PSU_2015_minishell1
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sun Jan 24 21:02:58 2016 Florent Baris
** Last update Fri Jan 29 13:00:32 2016 Florent Baris
*/

#include "my.h"

char	*get_var(t_min *ishell, char *var)
{
  t_env *tmp;
  char	*content;

  tmp = ishell->env;
  while (tmp)
    {
      if (my_strcmp(tmp->env_name, var) == 0)
	{
	  content = malloc(sizeof(char) * my_strlen(tmp->env_variable) + 1);
	  my_memset(content, '\0', my_strlen(tmp->env_variable));
	  my_strcpy(content, tmp->env_variable);
	  return (content);
	}
      tmp = tmp->prec;
    }
  return (0);
}
