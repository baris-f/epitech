/*
** my_params_in_list.c for my_params_in_list in /home/baris_f/rendu/Piscine_C_J11/ex_01
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Oct 12 09:54:34 2015 Florent Baris
** Last update Mon Oct 12 14:09:30 2015 Florent Baris
*/

#include <stdlib.h>
#include "mylist.h"

int	my_put_in_list(t_list **list, char *av)
{
  t_list *elem;

  elem = malloc(sizeof(*elem));
  if (elem == NULL)
    return (1);
  elem->data = av;
  elem->next = *list;
  *list = elem;

  return (0);
}

void		my_show_list(t_list *list)
{
  t_list	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      my_putstr(tmp->data);
      my_putchar('\n');
      tmp = tmp->next;
    }
}

t_list *my_params_in_list(int ac, char **av)
{
  t_list *list;
  int	i;

  list = NULL;
  while (i < ac)
    {
      my_put_in_list(&list, av[i]);
      i++;
    }
  return (list);
}
