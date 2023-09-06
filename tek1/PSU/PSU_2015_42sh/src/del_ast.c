/*
** ast.c for ast in /home/grandma/PSU_2015_42sh
**
** Made by Corentin Grandmaire
** Login   <grandm_a@epitech.net>
**
** Started on  Tue May 31 14:56:48 2016 Corentin Grandmaire
** Last update Sun Jun  5 20:01:33 2016 Corentin Grandmaire
*/

#include "42s.h"

void		del_ast(t_ast *ast, int i)
{
  if (!ast->cur)
    return ;
  if (ast->left)
    del_ast(ast->left, i++);
  if (ast->right)
    del_ast(ast->right, i++);
  free(ast->cur);
  return ;
}
