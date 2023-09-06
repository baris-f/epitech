/*
** exec.c for 42sh in /home/dudu/rendu/PSU_2015_42sh
**
** Made by lucas duval
** Login   <duval_m@epitech.net>
**
** Started on  Fri May 27 10:18:54 2016 lucas duval
** Last update Sun Jun  5 21:00:46 2016 lucas duval
*/

#include "42s.h"

t_fonc          build[7] =
  {
    {"setenv", &env_builtin},
    {"unsetenv", &env_builtin},
    {"env", &env_builtin},
    {"cd", &cd_builtin},
    {"echo", &echo_builtin},
    {"exit", &ex},
    {"\0", NULL}
  };

int    handle_exit_signal(int status)
{
  if (status == 11)
    my_printf("segmentation fault (core dumped)\n");
  else if (status == 8)
    my_printf("floating point exception\n");
  else if (status == 4)
    my_printf("illegal instruction\n");
  else if (status == 13)
    my_printf("Write on a pipe with no one to read it\n");
  if (status != 0)
    return (1);
  return (0);
}

int	check_build(t_42 *sh)
{
  int	i;

  i = -1;
  while (build[++i].name)
    {
      if (my_strcmp(sh->cmd, build[i].name) == 0)
	return ((build[i].func)(sh));
    }
  return (0);
}

char	*check_cmd(t_42 *sh, char *path)
{
  char	**pth;

  if (access(sh->cmd, F_OK ) != -1)
    return (sh->cmd);
  if (sh->cmd[0] == '.' || sh->cmd[0] == '/')
    {
      if (access(sh->cmd, F_OK ) != -1)
	return (sh->cmd);
      else
	return (NULL);
    }
  if (path == NULL || (pth = my_str_to_wordtab(path, ':')) == NULL)
    {
      if (access(sh->cmd, F_OK ) != -1)
	return (sh->cmd);
      else
	return (NULL);
    }
  return (check(sh, pth));
}

int	exec(t_42 *sh)
{
  char	*tmp;
  int	ret;

  if ((ret = check_build(sh)) == 1)
    return (0);
  else if (ret == -1)
    return (1);
  if ((tmp = check_cmd(sh, getstr("PATH=", sh->env))) == NULL)
    {
      my_printf("%s: Command not found\n", sh->cmd);
      return (-1);
    }
  sh->pid = fork();
  if (sh->pid == 0)
    execve(tmp, sh->argv, sh->env);
  else
    {
      waitpid(sh->pid, &sh->status, WUNTRACED);
      if (WIFSIGNALED(sh->status))
	ret = handle_exit_signal(WTERMSIG(sh->status));
    }
  return (ret);
}
