/*
** add.c for add in /home/baris_f/rendu/tek2/cpp_d02m/ex04
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Thu Jan  5 12:53:57 2017 baris_f
** Last update Thu Jan  5 19:27:26 2017 baris_f
*/

#include <stdlib.h>
#include "castmania.h"

int	normal_add(int a, int b)
{
  return (a + b);
}

int	absolute_add(int a, int b)
{
  return(abs(a) + abs(b));
}

void	exec_add(t_add *operation)
{
  if (operation->add_type == NORMAL)
    operation->add_op.res = normal_add(operation->add_op.a, operation->add_op.b);
  else if (operation->add_type == ABSOLUTE)
    operation->add_op.res = absolute_add(operation->add_op.a, operation->add_op.b);
}
