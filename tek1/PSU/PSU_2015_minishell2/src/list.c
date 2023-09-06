/*
** list.c for minishell1 in /home/baris-f/rendu/PSU/PSU_2015_minishell1
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sun Jan 24 11:03:53 2016 Florent Baris
** Last update Mon Jan 25 12:45:35 2016 Florent Baris
*/

#include "my.h"

void		push(t_env **p, char *name, char *var)
{
  t_env	*element;

  element = malloc(sizeof(t_env));
  if (!element)
    exit(EXIT_FAILURE);
  element->env_name = malloc(sizeof(char) * my_strlen(name) + 1);
  my_strcpy(element->env_name, name);
  element->env_variable = malloc(sizeof(char) * my_strlen(var) + 1);
  my_strcpy(element->env_variable, var);
  element->prec = *p;
  *p = element;
}

void		clear(t_env **p)
{
  t_env	*tmp;
  while (*p)
    {
      tmp = (*p)->prec;
      free((*p)->env_name);
      free((*p)->env_variable);
      free(*p);
      *p = tmp;
    }
}

int		length(t_env *p)
{
  int		n;

  n = 0;
  while (p)
    {
      n++;
      p = p->prec;
    }
  return (n);
}

void		view(t_env *p)
{
  int	i;
  i = 0;
  while (p != NULL)
    {
      my_printf("%s=%s\n", p->env_name, p->env_variable);
      p = p->prec;
      i++;
    }
}
