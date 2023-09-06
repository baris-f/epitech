/*
** my_putchar.c for my_putchar in /home/baris_f/rendu/c
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Wed Sep 30 09:46:50 2015 Florent Baris
** Last update Thu Jan 28 16:11:58 2016 Florent Baris
*/

#include "my.h"

void	my_putchar(char c)
{
  write (1, &c, 1);
}
