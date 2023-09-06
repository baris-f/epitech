/*
** ptr.c for  in /home/grandma/PSU_2015_42sh
**
** Made by Corentin Grandmaire
** Login   <grandm_a@epitech.net>
**
** Started on  Thu Jun  2 12:19:59 2016 Corentin Grandmaire
** Last update Sun Jun  5 20:01:55 2016 Corentin Grandmaire
*/

#include "42s.h"

int	and(t_ast *ast, t_42 *base)
{
  exec_ast(ast->left, base->opt, base, 1);
  if (base->ret != 0)
    return (-1);
  else
    exec_ast(ast->right, base->opt, base, 1);
  if (base->ret != 0)
    return (-1);
  return (0);
}

int	or(t_ast *ast, t_42 *base)
{
  exec_ast(ast->left, base->opt, base, 1);
  if (base->ret != 0)
    exec_ast(ast->right, base->opt, base, 1);
  return (0);
}

int	endpoint(t_ast *ast, t_42 *base)
{
  (void)ast;
  (void)base;
  return (0);
}
