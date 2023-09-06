/*
** cd_builtin.c for 42sh in /home/dudu/rendu/PSU_2015_42sh
**
** Made by lucas duval
** Login   <duval_m@epitech.net>
**
** Started on  Fri Jun  3 21:14:18 2016 lucas duval
** Last update Sun Jun  5 16:45:03 2016 Corentin Grandmaire
*/

#include "42s.h"

void	cd__(t_42 *sh)
{
  char  *old;
  char  *new;

  old = getstr("PWD=", sh->env);
  new = getstr("OLDPWD=", sh->env);
  if (old && new)
    {
      if (chdir(new) == 0)
	{
	  check_env(sh, "OLDPWD", old);
	  check_env(sh, "PWD", new);
	}
      else
	printf("Error can't change dirrectory\n");
    }
  else
    printf("Error can't find old directory\n");
  if (new)
    free(new);
  if (old)
    free(old);
}

void	cd_home(t_42 *sh)
{
  char	*new;
  char	*old;

  new = getstr("HOME=", sh->env);
  if (new)
    {
      old = getstr("PWD=", sh->env);
      if (chdir(new) == 0)
	{
	  check_env(sh, "OLDPWD", old);
	  check_env(sh, "PWD", new);
	}
      else
	printf("Error can't change dirrectory\n");
      free(new);
      if (old)
	free(old);
    }
  else
    printf("Error \"HOME\" var not defined\n");
}

int     cd_builtin(t_42 *sh)
{
  char  *old;
  char  *new;

  if (sh->argv[1])
    if (my_strcmp(sh->argv[1], "-") == 0)
      cd__(sh);
    else
      if (chdir(sh->argv[1]) == 0)
	{
	  old = getstr("PWD=", sh->env);
	  new = calloc(1024, sizeof(char) * 1024);
	  getcwd(new, 1024);
	  if (old)
	    check_env(sh, "OLDPWD", old);
	  check_env(sh, "PWD", new);
	  if (new)
	    free(new);
	  if (old)
	    free(old);
	}
      else
	printf("Error can't change dirrectory\n");
  else
    cd_home(sh);
  return (1);
}
