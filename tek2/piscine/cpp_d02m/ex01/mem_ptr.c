/*
** mem_ptr.c for memptr in /home/baris_f/rendu/tek2/cpp_d02m/ex01
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Thu Jan  5 09:18:50 2017 baris_f
** Last update Thu Jan  5 12:07:40 2017 baris_f
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "mem_ptr.h"
/*
typedef struct	s_str_op
{
  char	*str1;
  char	*str2;
  char	*res;
}		t_str_op;
*/
void add_str(char *str1, char *str2, char **res)
{
  if ((*res = malloc(sizeof(char) * (strlen(str1) + strlen(str2) + 1))))
    sprintf(*res, "%s%s", str1, str2);
}

void add_str_struct(t_str_op *str_op)
{
  if ((str_op->res = malloc(sizeof(char) * (strlen(str_op->str1) + strlen(str_op->str2) + 1))))
    sprintf(str_op->res, "%s%s", str_op->str1, str_op->str2);
}

/*
int main ( void )
{
  char  *str1 = "Hi," ;
  char  *str2 = "It works !" ;
  char  *res;
  t_str_op      str_op ;
  add_str(str1, str2 , &res) ;
  printf ("%s\n", res);
  str_op.str1 = str1;
  str_op.str2 = str2;
  add_str_struct (&str_op) ;
  printf ( "%s\n", str_op.res) ;
  return ( 0 ) ;
}
*/
