/*
** main.c for minishell in /home/baris-f/rendu/PSU/PSU_2015_minishell1
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sun Jan 24 11:03:36 2016 Florent Baris
** Last update Sun Jan 31 23:13:54 2016 Florent Baris
*/

#include "my.h"

void	elsepid(t_min *ishell)
{
  ishell->buffer[ishell->ret - 1] = 0;
  checko(ishell);
  waitpid(ishell->pid, &ishell->status, WUNTRACED);
  if (WIFSIGNALED(ishell->status))
    handle_exit_signal(WTERMSIG(ishell->status));
}

void	testpid(t_min *ishell)
{
  ishell->pid = fork();
  if (ishell->pid == -1)
    {
      my_printf("Fork failed\n");
      free(ishell->user);
      exit(EXIT_FAILURE);
    }
  else if (ishell->pid == 0)
    {
      ishell->buffer[ishell->ret - 1] = 0;
      check(ishell);
      free(ishell->user);
      exit (0);
    }
  else if (ishell->ret == 0)
    {
      my_printf("\n");
      free(ishell->user);
      exit (0);
    }
  else
    elsepid(ishell);
}

void	init(t_min *ishell, char **env)
{
  get_env(ishell, env);
  ishell->user = get_var(ishell, "USER");
  ishell->cur = 0;
  ishell->buffer[0] = 0;
}

int	quite (char **argv)
{
  if (argv[0] == NULL)
    return (-1);
  if (my_strncmp(argv[0], "exit", 4) == 0)
    {
      if (argv[1] != NULL)
	my_printf("%d\n", my_getnbr(argv[1]));
      return (0);
    }
  return(my_strncmp(argv[0], "exit", 4));
}

int	main(int __attribute__ ((unused)) ac,
	     char __attribute__ ((unused)) **av, char **env)
{
  t_min	ishell;
  int	i;

  init(&ishell, env);
  while (quite(my_str_to_wordtab(ishell.buffer)) != 0)
    {
      ishell.status = 0;
      set_signal();
      my_printf("(%s %d)$ ", ishell.user, ++ishell.cur);
      i = 0;
      while (i < 4096)
	ishell.buffer[i++] = 0;
      ishell.ret = read(0, ishell.buffer, 4096);
      if (my_strncmp(ishell.buffer, "cd", 2) == 0 && ishell.buffer[0] != '\n'
	  && ishell.ret != -1)
	cd(&ishell, my_str_to_wordtab(ishell.buffer));
      else if (ishell.ret == 0)
	return (write(1, "\n", 1) * 0);
      else if (my_strcmp(ishell.buffer, "exit\n") != 0
	       && ishell.buffer[0] != '\n' && ishell.ret != -1)
	testpid(&ishell);
      else
	ishell.cur--;
    }
  free(ishell.user);
  return (0);
}
