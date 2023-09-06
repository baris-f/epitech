/*
** bubble.c for bubble in /home/baris-f/rendu/PSU_2015_my_ls
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sun Nov 29 17:10:55 2015 Florent Baris
** Last update Sun Nov 29 17:18:57 2015 Florent Baris
*/

#include <stdlib.h>
#include "my_ls.h"

void            my_rbubble(t_chaine *list)
{
  int   swop;
  t_chaine      *prev;
  t_chaine      *cur;
  char          *tmp;

  swop = 1;
  while (swop == 1)
    {
      prev = list;
      cur = list->next;
      swop = 0;
      while (prev->next != NULL)
	{
	  if (my_strcmpls(prev->name, cur->name) < 0)
	    {
	      tmp = my_strdup(prev->name);
	      prev->name = cur->name;
	      cur->name = tmp;
	      swop = 1;
	    }
	  cur = cur->next;
	  prev = prev->next;
	}
    }
}

void            my_bubble(t_chaine *list)
{
  int   swop;
  t_chaine      *prev;
  t_chaine      *cur;
  char          *tmp;

  swop = 1;
  while (swop == 1)
    {
      prev = list;
      cur = list->next;
      swop = 0;
      while (prev->next != NULL)
	{
	  if (my_strcmpls(prev->name, cur->name) > 0)
	    {
	      tmp = my_strdup(prev->name);
	      prev->name = cur->name;
	      cur->name = tmp;
	      swop = 1;
	    }
	  cur = cur->next;
	  prev = prev->next;
	}
    }
}
