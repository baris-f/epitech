/*
** my_rev_list.c for my_rev_list in /home/baris_f/rendu/Piscine_C_J11/ex_03
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Oct 12 10:46:43 2015 Florent Baris
** Last update Mon Oct 12 19:19:03 2015 Florent Baris
*/

#include <stdlib.h>
#include "mylist.h"

int		my_rev_list(t_list **begin)
{
  t_list	*prev;
  t_list	*now;
  t_list	*final_list;

  final_list = NULL;
  now = *begin;
  while (now != NULL)
    {
      prev = now->next;
      now->next = final_list;
      final_list = now;
      now = prev;
    }
  *begin = final_list;
  return (0);
}
