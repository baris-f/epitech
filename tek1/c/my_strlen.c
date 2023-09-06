/*
** my_strlen.c for my_strlen in /home/baris_f/rendu/Piscine_C_J04
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Thu Oct  1 09:27:05 2015 Florent Baris
** Last update Thu Jan 28 16:17:38 2016 Florent Baris
*/

#include "my.h"

int	my_strlen(char *str)
{
  int i;

  i = 0;
  while (str[i])
      i++;
  return (i);
}
