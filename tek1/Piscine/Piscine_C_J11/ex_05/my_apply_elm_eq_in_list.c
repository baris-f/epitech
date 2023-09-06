/*
** my_apply_elm_eq_in_list.c for my_apply_elm_eq_in_list in /home/baris_f/rendu/Piscine_C_J11/ex_05
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Oct 12 14:24:08 2015 Florent Baris
** Last update Mon Oct 12 14:38:58 2015 Florent Baris
*/

#include <stdlib.h>
#include "mylist.h"

int	my_apply_on_eq_in_list(t_list *begin, int (*f)(),
			   void *data_ref, int (*cmp)())
{
  while (begin != NULL)
    {
      if ((*cmp)(begin->data, data_ref) == 0)
	  (*f)(begin->data);
      begin = begin->next;
    }
}
