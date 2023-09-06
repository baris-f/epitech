/*
** my_str_islower.c for my_str_islower in /home/baris_f/rendu/Piscine_C_J06/ex_13
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Oct  5 16:46:04 2015 Florent Baris
** Last update Thu Jan 28 16:16:32 2016 Florent Baris
*/

#include "my.h"

int     my_str_islower(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    {
      if ((str[i] < 'a' || str[i] > 'z'))
        return (0);
      i++;
    }
  return (1);
}
