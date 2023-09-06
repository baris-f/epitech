/*
** queue.c for queue in /home/baris_f/rendu/tek2/cpp_d02a/ex04
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Thu Jan  5 21:55:00 2017 baris_f
** Last update Fri Jan  6 08:56:26 2017 baris_f
*/

#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
#include "generic_list.h"

unsigned int    queue_get_size(t_queue queue)
{
  return (list_get_size(queue));
}

t_bool          queue_is_empty(t_queue queue)
{
  return (list_is_empty(queue));
}

t_bool  queue_push(t_queue *queue_ptr, void *elem)
{
  return (list_add_elem_at_back(queue_ptr, elem));
}

t_bool  queue_pop(t_queue *queue_ptr)
{
  return (list_del_elem_at_front(queue_ptr));
}

void    *queue_front(t_queue queue)
{
  return (list_get_elem_at_front(queue));
}
/*
int     main(void)
{
  t_queue       queue=NULL;
  int           i=5;
  int           j=4;
  int           *data;

  queue_push(&queue, &i);
  queue_push(&queue, &j);
  data=(int*)queue_front(queue);
  printf("before pop: %d\n", *data);
  queue_pop(&queue);
  data=(int*)queue_front(queue);
  printf("after pop:  %d\n", *data);
  return(0);
}
*/
