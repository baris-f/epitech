/*
** func_ptr.c for func in /home/baris_f/rendu/tek2/cpp_d02m/ex03
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Thu Jan  5 10:16:02 2017 baris_f
** Last update Thu Jan  5 19:35:51 2017 baris_f
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include "func_ptr.h"

void	print_normal(char *str)
{
  write(1, str, strlen(str));
  write(1, "\n", 1);
}

void	print_reverse(char *str)
{
  for(int i = strlen(str) - 1; i >= 0; i--)
    write(1, &str[i], 1);
  write(1, "\n", 1);
}

void	print_upper(char *str)
{
  char	c;

  for(int i = 0; i < (int)strlen(str); i++)
    {
      c = toupper(str[i]);
      write(1, &c, 1);
    }
  write(1, "\n", 1);
}

void	print_42(char *str)
{
  (void)str;
  write(1, "42\n", 3);
}

void	do_action(t_action action, char *str)
{
  t_fct fct[] = {&print_normal, &print_reverse, &print_upper, &print_42};

  if (action >= PRINT_NORMAL && action <= PRINT_42)
    fct[action](str);
}
