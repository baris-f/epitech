/*
** my_rm_all_eq_from_list.c for my_rm_all_eq_from_list in /home/baris_f/rendu/Piscine_C_J11/ex_08
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Oct 12 14:55:13 2015 Florent Baris
** Last update Tue Oct 13 19:26:02 2015 Florent Baris
*/

#include <stdlib.h>
#include "mylist.h"

int		my_rm_all_eq_from_list(t_list **begin,
			       void *data_ref, int (*cmp)())
{
  t_list	prev;
  t_list	now;

  prev = NULL;
  now = *begin;
  while (now != NULL)
    {
      if ((*cmp)(now->data, data_ref) == 0)
	if (prev == NULL)
	  *begin = now->next;
      prev->next = now->next;
      prev = now;
      now = now->next;
    }
}
