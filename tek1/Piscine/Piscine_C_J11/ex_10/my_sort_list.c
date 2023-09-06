/*
** my_sort_list.c for my_sort_list in /home/baris_f/rendu/Piscine_C_J11/ex_10
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Oct 12 18:04:43 2015 Florent Baris
** Last update Mon Oct 12 19:46:14 2015 Florent Baris
*/

#include <stdlib.h>
#include "mylist.h"

int		my_sort_list(t_list **begin, int (*cmp)())
{
  int		swap;
  t_list	tmp;
  t_list	now;
  t_list	after;

  while (swap > 0)
    {
      swap = 0;
      now = *begin;
      while (now != NULL)
	{
	  after = now->next;
	  if ((*cmp)(now->data, after->data ) > 0)
	    {

	      swap++;
	    }
	  now = now->next;
	}
    }
}
