/*
** my_apply_on_list.c for my_apply_on_list in /home/baris_f/rendu/Piscine_C_J11/ex_04
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Oct 12 14:02:40 2015 Florent Baris
** Last update Mon Oct 12 14:21:17 2015 Florent Baris
*/

#include <stdlib.h>

int	my_apply_on_list(t_list *begin, int (*f)(void*));
{
  while (begin != NULL)
    {
      (*f)(begin->data);
      begin = begin->next;
    }
  return (0);
}
