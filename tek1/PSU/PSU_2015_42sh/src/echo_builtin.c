/*
** echo_builtin.c for 42 in /home/baris-f/rendu/PSU/PSU_2015_42sh
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sat Jun  4 13:54:16 2016 Florent Baris
** Last update Sun Jun  5 21:29:03 2016 Florent Baris
*/

#include "42s.h"

int     isalph(char c)
{
  if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
    return (1);
  return (0);
}

int     exist_env(t_42 *base, char *name)
{
  int   i;
  int	j;

  i = -1;
  while (base->env[++i] && strncmp(base->env[i], name, strlen(name)) != 0);
  if (i >= base->nb_env)
    return (0);
  j = -1;
  while (base->env[i][++j] && base->env[i][j] != '=');
  while (base->env[i][++j])
    my_putchar(base->env[i][j]);
  return (1);
}

void    aff_var_env(t_42 *sh, int i, int *f)
{
  int   sj;
  int	j;
  char  *tmp;

  j = *f;
  sj = j;
  while (sh->argv[i][++j] && isalph(sh->argv[i][j]));
  tmp = calloc(0, sizeof (char) * (j - sj));
  j = sj;
  while (sh->argv[i][++j] && isalph(sh->argv[i][j]))
    tmp[(j - 1) - sj] = sh->argv[i][j];
  tmp[j] = '\0';
  exist_env(sh, tmp);
  while (sh->argv[i][++j])
    if (sh->argv[i][j] == '$')
      aff_var_env(sh, i, &j);
    else
      my_putchar(sh->argv[i][j]);
  *f = j;
}

void    echo_all(t_42 *sh, int i)
{
  int   j;
  int	end;

  end = 1;
  if (i)
    end = 0;
  while (sh->argv[++i])
    {
      j = -1;
      while (sh->argv[i][++j])
	{
	  if (sh->argv[i][j] == '$')
	    aff_var_env(sh, i, &j);
	  else
	    my_putchar(sh->argv[i][j]);
	}
      if (sh->argv[i + 1])
	my_putchar(' ');
    }
  if (end)
    printf("\n");
}

int     echo_builtin(t_42 *sh)
{
  if (!sh->argv[1])
    return (0);
  if (my_strcmp(sh->argv[1], "-n") == 0)
    echo_all(sh, 1);
  else
    echo_all(sh, 0);
  return (1);
}
