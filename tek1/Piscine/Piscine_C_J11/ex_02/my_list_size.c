/*
** my_list_size.c for my_list_size in /home/baris_f/rendu/Piscine_C_J11/ex_02
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Oct 12 10:36:35 2015 Florent Baris
** Last update Tue Oct 13 17:33:28 2015 Florent Baris
*/

#include <stdlib.h>
#include "mylist.h"

int		my_list_size(t_list *begin)
{
  t_list	*tmp;
  int		i;

  tmp = begin;
  i = 0;
  while (tmp != NULL)
    {
      tmp = tmp->next;
      i++;
    }
  return (i);
}
