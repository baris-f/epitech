/*
** stack.c for stack in /home/baris_f/rendu/tek2/cpp_d02a/ex03
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Thu Jan  5 21:05:50 2017 baris_f
** Last update Fri Jan  6 08:51:24 2017 baris_f
*/

#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include "generic_list.h"

unsigned int	stack_get_size(t_stack stack)
{
  return (list_get_size(stack));
}

t_bool          stack_is_empty(t_stack stack)
{
  return (list_is_empty(stack));
}

t_bool  stack_push(t_stack *stack_ptr, void *elem)
{
  return (list_add_elem_at_front(stack_ptr, elem));
}

t_bool  stack_pop(t_stack *stack_ptr)
{
  return(list_del_elem_at_front(stack_ptr));
}

void    *stack_top(t_stack stack)
{
  if (stack == NULL)
    return (0);
  return(list_get_elem_at_front(stack));
}

/*
int     main(void)
{
  t_stack       stack = NULL;
  int   i=5;
  int   j=4;
  int   *data;

  stack_push(&stack, &i);
  stack_push(&stack, &j);
  data = (int*)stack_top(stack);
  printf("Before pop: %d\n", *data);
  stack_pop(&stack);
  data = (int*)stack_top(stack);
  printf("After pop:  %d\n", *data);
  return (0);
}
*/
