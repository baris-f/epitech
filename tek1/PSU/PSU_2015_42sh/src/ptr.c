/*
** ptr.c for  in /home/grandma/PSU_2015_42sh
**
** Made by Corentin Grandmaire
** Login   <grandm_a@epitech.net>
**
** Started on  Thu Jun  2 12:19:59 2016 Corentin Grandmaire
** Last update Sun Jun  5 20:54:57 2016 lucas duval
*/

#include "42s.h"

int	pipe3(t_ast *ast, t_42 *base, int fd[2])
{
  close(fd[1]);
  dup2(fd[0], STDIN_FILENO);
  exec_ast(ast->right, base->opt, base, 1);
  exit(-1);
}

int	pipe_exec(t_ast *ast, t_42 *base)
{
  int	fd[2];
  pid_t	child2;
  int	child1[2];

  pipe(fd);
  child1[0] = fork();
  if (child1[0] == 0)
    {
      close(fd[0]);
      dup2(fd[1], STDOUT_FILENO);
      exec_ast(ast->left, base->opt, base, 1);
      exit(-1);
    }
  child2 = fork();
  if (child2 == 0)
    pipe3(ast, base, fd);
  close(fd[0]);
  close(fd[1]);
  waitpid(child2, &child1[1], 0);
  return (0);
}

int	rightredir(t_ast *ast, t_42 *base)
{
  int	fd;
  int	stdout;

  if (ast->right->cur[0] == ' ')
    fd = open(&ast->right->cur[1], O_CREAT | O_TRUNC | O_WRONLY, 0644);
  else
    fd = open(ast->right->cur, O_CREAT | O_TRUNC | O_WRONLY, 0644);
  stdout = dup(1);
  if (fd < 0)
    printf("Open Fail\n");
  dup2(fd, 1);
  close(fd);
  exec_ast(ast->left, base->opt, base, 1);
  dup2(stdout, 1);
  close(stdout);
  return (0);
}

int	d_rightredir(t_ast *ast, t_42 *base)
{
  int	fd;
  int	stdout;

  if (ast->right->cur[0] == ' ')
    fd = open(&ast->right->cur[1], O_CREAT | O_APPEND | O_WRONLY, 0644);
  else
    fd = open(ast->right->cur, O_CREAT | O_APPEND | O_WRONLY, 0644);
  stdout = dup(1);
  if (fd < 0)
    printf("Open Fail\n");
  dup2(fd, 1);
  close(fd);
  exec_ast(ast->left, base->opt, base, 1);
  dup2(stdout, 1);
  close(stdout);
  return (0);
}

int	leftredir(t_ast *ast, t_42 *base)
{
  int	fd;
  pid_t	pid;
  int	it;
  int	stdout;

  stdout = dup(1);
  pid = fork();
  if (pid == 0)
    {
      if (ast->right->cur[0] == ' ')
	fd = open(&ast->right->cur[1], O_RDONLY);
      else
	fd = open(ast->right->cur, O_RDONLY);
      close(STDIN_FILENO);
      dup2(fd, STDIN_FILENO);
      exec_ast(ast->left, base->opt, base, 1);
      return (0);
    }
  waitpid(pid, &it, 0);
  dup2(stdout, 1);
  close(stdout);
  return (0);
}
