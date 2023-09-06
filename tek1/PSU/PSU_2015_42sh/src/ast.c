/*
** ast.c for ast in /home/grandma/PSU_2015_42sh
**
** Made by Corentin Grandmaire
** Login   <grandm_a@epitech.net>
**
** Started on  Tue May 31 14:56:48 2016 Corentin Grandmaire
** Last update Sun Jun  5 19:57:15 2016 Corentin Grandmaire
*/

#include "42s.h"

int		cut(t_ast *ast, int i, int r, t_42 *base)
{
  int		j;

  j = strlen(ast->cur) - i - r + 1;
  if ((ast->left = malloc(sizeof(t_ast))) == NULL
      || (ast->right = malloc(sizeof(t_ast))) == NULL
      || (ast->left->cur = malloc(sizeof(char) * (i + 1))) == NULL
      || (ast->right->cur = malloc(sizeof(char) * (j + 1))) == NULL)
    return (-1);
  strncpy(ast->left->cur, ast->cur, i);
  ast->left->cur[i] = '\0';
  strncpy(ast->right->cur, &(ast->cur[i + r]), j);
  ast->right->cur[j] = '\0';
  ast->cur[0] = ast->cur[i + r - 1];
  if (r == 2)
    ast->cur[1] = ast->cur[i + r - 2];
  ast->cur[r] = '\0';
  doast(ast->right, base->opt, base);
  doast(ast->left, base->opt, base);
  return (0);
}

int		doast(t_ast *ast, t_ptr *opt, t_42 *base)
{
  base->i[1] = (base->i[0] = strlen(ast->cur));
  while (--(base->i[0]) >= 0)
    if (ast->cur[base->i[0]] == ';' || ast->cur[base->i[0]] == '\n')
      {
	if (cut(ast, base->i[0], 1, base) == -1)
	  return (-1);
	else
	  return (0);
      }
  while (--(base->i[1]) >= 0)
    {
      base->i[2] = -1;
      while (++(base->i[2]) < OP_SIZE)
	if (what_ope(&(ast->cur[base->i[1]]), opt[base->i[2]].op))
	  {
	    if (cut(ast, (base->i[1] -= (base->i[2] >= 4) ? (0) : (1)),
		    (base->i[2] > 3) ? (1) : (2), base) == -1)
	      return (-1);
	    else
	      return (0);
	  }
    }
  ast->left = NULL;
  ast->right = NULL;
  return (0);
}

int		intast(t_ast *ast, t_ptr *opt, t_42 *base)
{
  int		j;

  j = -1;
  while (++j < OP_SIZE + 2)
    {
      if (strncmp(opt[j].op, ast->cur, my_strlen(opt[j].op)) == 0)
	{
	  opt[j].fct(ast, base);
	  return (j);
	}
    }
  return (-1);
}

int		exec_ast(t_ast *ast, t_ptr *opt, t_42 *base, int i)
{
  char		**tmp;
  int		ret;

  if (!ast || !ast->cur || !ast->cur[0])
    return (-42);
  if (((ret = intast(ast, opt, base)) >= 0) && i == 1 && ret != 7);
  else
    {
      if (i == 1 && ret != 7)
	{
	  if ((tmp = my_str_to_wordtab(ast->cur, ' ')) == NULL)
	    return (-1);
	  base->cmd = tmp[0];
	  base->argv = tmp;
	  base->ret = exec(base);
	}
      if (ast && ast->left)
	exec_ast(ast->left, opt, base, 1);
      if (ast && ast->right)
	exec_ast(ast->right, opt, base, 1);
    }
  return (0);
}

t_ast		*build_ast(char *str, t_ast *ast, t_42 *base)
{
  t_ptr		opt[] =
  {
    {"||", &(or)},
    {"<<", &(leftredir)},
    {">>", &(d_rightredir)},
    {"&&", &(and)},
    {"|", &(pipe_exec)},
    {"<", &(leftredir)},
    {">", &(rightredir)},
    {";", &(endpoint)},
    {"\n", &(endpoint)}
  };

  ast->left = NULL;
  ast->right = NULL;
  ast->cur = str;
  base->opt = opt;
  doast(ast, opt, base);
  if (ast->left != NULL)
    exec_ast(ast, opt, base, 0);
  del_ast(ast, 0);
  return (ast);
}
