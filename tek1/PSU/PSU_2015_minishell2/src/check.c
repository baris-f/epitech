/*
** check.c for check in /home/baris-f/rendu/PSU/PSU_2015_minishell1
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sun Jan 24 21:08:33 2016 Florent Baris
** Last update Sun Jan 31 23:35:29 2016 Florent Baris
*/

#include "my.h"

void    own_command(t_min *ishell, char **argv)
{
  if (my_strcmp(argv[0], "env") == 0)
    view(ishell->env);
  if (my_strcmp(argv[0], "unsetenv") == 0)
    {
      if (argv[1])
	unsetenv(ishell, argv[1]);
      else
	my_printf("Usage: unsetenv var\n");
    }
  if (my_strcmp(argv[0], "setenv") == 0)
    {
      if (argv[1] && argv[2])
	push(&ishell->env, argv[1], argv[2]);
      else
	my_printf("Usage: setenv var arg\n");
    }
}

void    check_cmd(t_min *ishell, char **env)
{
  char  *tmp;
  int   i;
  int   len;

  i = 0;
  len = -1;
  ishell->path = get_var(ishell, "PATH");
  while (ishell->path && ishell->path[i + 1] != '\0')
    {
      while (ishell->path[++len + i] != ':' && ishell->path[len + i]);
      tmp = malloc(sizeof(char) * (len + my_strlen(ishell->argv[0]) + 2));
      ishell->cmd = malloc(sizeof(char) * (len + my_strlen(ishell->argv[0])
					   + 2));
      my_strncpy(tmp, ishell->path + i, len);
      my_strcat(tmp, "/");
      my_strcat(tmp, ishell->argv[0]);
      my_strcpy(ishell->cmd, tmp);
      free(tmp);
      if (access(ishell->cmd, F_OK ) != -1)
	execve(ishell->cmd, ishell->argv, env);
      i += len + 1;
      free(ishell->cmd);
    }
  free(ishell->path);
}

void    check(t_min *ishell)
{
  char  **env;

  ishell->argv = my_str_to_wordtab(ishell->buffer);
  if (!(my_strcmp(ishell->argv[0], "env") == 0
	|| my_strcmp(ishell->argv[0], "unsetenv") == 0
	|| my_strcmp(ishell->argv[0], "setenv") == 0
	|| my_strcmp(ishell->argv[0], "cd") == 0
    	|| my_strcmp(ishell->argv[0], "exit") == 0))
    {
      env = malloc(sizeof(char *) * length(ishell->env) + 1);
      make_env(ishell, env);
      if (access(ishell->argv[0], F_OK) != -1 && isalph(ishell->argv[0][0]))
	execve(ishell->argv[0], ishell->argv, env);
      else if (isalph(ishell->argv[0][0]))
	check_cmd(ishell, env);
      my_printf("%s: command not found\n", ishell->argv[0]);
    }
}

void    checko(t_min *ishell)
{
  char  **argv;

  if (ishell->pid != 0)
    {
      argv = my_str_to_wordtab(ishell->buffer);
      own_command(ishell, argv);
    }
}
