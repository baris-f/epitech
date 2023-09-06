/*
** my_show_wordtab.c for my_show_wordtab in /home/baris_f/rendu/Piscine_C_J08/ex_03
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Wed Oct  7 12:28:18 2015 Florent Baris
** Last update Thu Jan 28 17:52:17 2016 Florent Baris
*/

#include "my.h"

void	my_show_wordtab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      i++;
    }
}
