/*
** my_putstr.c for my_putstr in /home/baris_f/rendu/Piscine_C_J04
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Thu Oct  1 09:09:15 2015 Florent Baris
** Last update Thu Jan 28 16:15:38 2016 Florent Baris
*/

#include "my.h"

void	my_putstr(char *str)
{
  int i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
}
