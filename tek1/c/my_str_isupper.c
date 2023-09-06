/*
** my_str_isupper.c for my_str_isupper in /home/baris_f/rendu/Piscine_C_J06/ex_14
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Oct  5 16:47:59 2015 Florent Baris
** Last update Thu Jan 28 16:17:14 2016 Florent Baris
*/

#include "my.h"

int     my_str_isupper(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    {
      if ((str[i] < 'A' || str[i] > 'Z'))
        return (0);
      i++;
    }
  return (1);
}
