/*
** signal.c for signal in /home/baris-f/rendu/PSU/PSU_2015_minishell1
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sun Jan 24 21:00:54 2016 Florent Baris
** Last update Fri Jan 29 14:23:18 2016 Florent Baris
*/

#include "my.h"

void    sign()
{
  my_printf("\n");
  return ;
}

void    handle_exit_signal(int status)
{
  if (status == 11)
    my_printf("Segmentation fault (core dumped)\n");
  else if (status == 8)
    my_printf("Segmentation fault : Floating point exception\n");
  else if (status == 4)
    my_printf("Invalid Operation\n");
  else if (status == 13)
    my_printf("Writing in a pipe without stream\n");
}

void    set_signal(void)
{
  signal(SIGINT, &sign);
  signal(SIGQUIT, &sign);
}
