/*
** buildin.c for 42sh in /home/dudu/rendu/PSU_2015_42sh/
**
** Made by lucas duval
** Login   <duval_m@epitech.net>
**
** Started on  Tue May 31 09:02:20 2016 lucas duval
** Last update Sat Jun  4 21:44:09 2016 lucas duval
*/

#include "42s.h"

int	env_builtin(t_42 *sh)
{
  if (my_strcmp(sh->cmd, "env") == 0)
    return (print_env(sh));
  else if (my_strcmp(sh->cmd, "setenv") == 0)
    {
      if (sh->argv[1])
	return (check_env(sh, sh->argv[1], sh->argv[2]));
      else
	return (print_env(sh));
    }
  else if (my_strcmp(sh->cmd, "unsetenv") == 0)
    {
      if (sh->argv [1])
	return (del_env(sh, sh->argv[1]));
      else
	printf("Usage: unsetenv VAR\n");
    }
  return (1);
}

int	ex(t_42 *sh)
{
  if (sh->argv[1] && my_str_isnum(sh->argv[1]) == 1)
    exit(my_getnbr(sh->argv[1]));
  else
    exit(0);
  return (0);
}
