/*
** main.c for coucouduu in /home/grandma/PSU_2015_42sh
**
** Made by Corentin Grandmaire
** Login   <grandm_a@epitech.net>
**
** Started on  Mon May  2 13:00:37 2016 Corentin Grandmaire
** Last update Sun Jun  5 21:03:33 2016 Corentin Grandmaire
*/

#include "42s.h"

int	primary_loop(t_42 *base, t_ast *ast)
{
  char	buff[1025];
  int   size;

  while (42)
    {
	prompt(base);
	memset(buff, '\0', 1025);
	size = read(0, buff, 1024);
	if (size == -1)
	  return (-1);
	if ((base->cmdt = epur_str(buff)) == NULL)
	  return (-1);
	if (size == 0)
	  {
	    exit(0);
	    printf("\n");
	  }
	if (verif_cmdt(base, -1) == -1 || verif_cmdt(base, -1) == 2);
	else if ((buff[0] != '\n' && size > 0) && (++base->idx < 2147483647))
	  ast = build_ast(base->cmdt, ast, base);
	set_signal();
      }
  return (0);
}

int	main(__attribute__((unused)) int ac, __attribute__((unused)) char **av,
	     char **env)
{
  t_42	base;
  t_ast	ast;
  int	ret;

  if (init(&base, env) == -1)
    return (-1);
  set_signal();
  welcome(&base);
  ret = primary_loop(&base, &ast);
  free_tab(base.env);
  return (ret);
}
