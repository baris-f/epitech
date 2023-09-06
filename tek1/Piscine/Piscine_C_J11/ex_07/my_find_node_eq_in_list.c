/*
** my_find_node_eq_in_list.c for my_find_node_eq_in_list in /home/baris_f/rendu/Piscine_C_J11/ex_07
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Oct 12 14:51:34 2015 Florent Baris
** Last update Tue Oct 13 17:35:11 2015 Florent Baris
*/

#include <stdlib>
#include "mylist.h"

void    *my_find_node_eq_in_list(t_list *begin,
				void *data_ref, int (*cmp)());
{
  while (begin != NULL)
    {
      if ((*cmp)(begin->data, data_ref) == 0)
        return (begin);
      begin = begin->next;
    }
}
