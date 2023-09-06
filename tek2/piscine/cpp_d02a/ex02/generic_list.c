/*
** simple_list.c for simplelist in /home/baris_f/rendu/tek2/cpp_d02a/ex00
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Thu Jan  5 14:56:59 2017 baris_f
** Last update Fri Jan  6 08:48:55 2017 baris_f
*/

#include <stdlib.h>
#include <stdio.h>
#include "generic_list.h"

unsigned int	list_get_size(t_list list)
{
  unsigned int nb;

  if (list == NULL)
    return (0);
  nb = 1;
  while (list && list->next != NULL)
    {
      nb++;
      list = list->next;
    }
  return (nb);
}

t_bool          list_is_empty(t_list list)
{
  if (list == NULL)
    return(TRUE);
  else
    return(FALSE);
}

void            list_dump(t_list list, t_value_displayer val_disp)
{
  if (list == NULL)
    return ;
  while (list->next != NULL)
    {
      val_disp(list->value);
      list = list->next;
    }
  val_disp(list->value);
}

t_bool  list_add_elem_at_front(t_list *front_ptr, void *elem)
{
  t_node *newnode;

  if ((newnode = malloc(sizeof(t_node))) == NULL)
      return (FALSE);
  newnode->value = elem;
  newnode->next = *front_ptr;
  *front_ptr = newnode;
  return (TRUE);
}

t_bool  list_add_elem_at_back(t_list *front_ptr, void *elem)
{
  t_node *newnode;
  t_list tmp;

  tmp = *front_ptr;
  if ((newnode = malloc(sizeof(t_node))) == NULL)
    return (FALSE);
  newnode->value = elem;
  if (tmp == NULL)
    {
      newnode->next = NULL;
      *front_ptr = newnode;
      return (TRUE);
    }
  while (tmp && tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = newnode;
  newnode->next = NULL;
  return (TRUE);
}

t_bool  list_add_elem_at_position(t_list *front_ptr, void *elem, unsigned int position)
{
  t_node *newnode;
  t_list tmp;
  unsigned int	i;

  i = 0;
  tmp = *front_ptr;
  if ((newnode = malloc(sizeof(t_node))) == NULL)
    return (FALSE);
  newnode->value = elem;
  if (tmp == NULL)
    {
      newnode->next = NULL;
      *front_ptr = newnode;
      return (TRUE);
    }
  while (tmp && tmp->next != NULL && ++i < position)
    tmp = tmp->next;
  //  printf("%d < %d\n", i, position);
  if (i < position)
    return (FALSE);
  newnode->next = tmp->next;
  tmp->next = newnode;
  return (TRUE);
}

t_bool  list_del_elem_at_front(t_list *front_ptr)
{
  t_list tmp;

  if (*front_ptr == NULL)
    return (FALSE);
  tmp = *front_ptr;
  *front_ptr = tmp->next;
  free(tmp);
  return (TRUE);
}

t_bool  list_del_elem_at_back(t_list *front_ptr)
{
  t_list tmp;

  if (*front_ptr == NULL)
    return (FALSE);
  tmp = *front_ptr;
  while (tmp && tmp->next->next != NULL)
    tmp = tmp->next;
  free(tmp->next);
  tmp->next = NULL;
  return (TRUE);
}

t_bool  list_del_elem_at_position(t_list *front_ptr, unsigned int position)
{
  t_list tmp;
  t_list tmpnext;
  unsigned int  i;

  i = -1;
  tmp = *front_ptr;
  while (tmp && tmp->next != NULL && ++i + 1 < position)
    tmp = tmp->next;
  if (i + 1 < position)
    return (FALSE);
  tmpnext = tmp->next->next;
  free(tmp->next);
  tmp->next = tmpnext;
  return (TRUE);
}

void	*list_get_elem_at_front(t_list list)
{
  if (list == NULL)
    return (0);
  return (list->value);
}

void	*list_get_elem_at_back(t_list list)
{
  if (list == NULL)
    return (0);
  while (list && list->next != NULL)
    list = list->next;
  return (list->value);
}

void	*list_get_elem_at_position(t_list list, unsigned int position)
{
  unsigned int	i;

  i = -1;
  if (list == NULL)
    return (0);
  while (list && list->next != NULL && ++i < position)
    list = list->next;
  if (i < position)
    return (0);
  return (list->value);
}

t_node  *list_get_first_node_with_value(t_list list, void *value, t_value_comparator val_comp)
{
  if (list == NULL)
    return (NULL);
  while (list->next != NULL)
    {
      if (val_comp(list->value, value) == 0)
	return (list);
      list = list->next;
    }
    return (NULL);
}
