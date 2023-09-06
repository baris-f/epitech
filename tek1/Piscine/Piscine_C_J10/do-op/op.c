/*
** op.c for op in /home/baris_f/rendu/Piscine_C_J10/do-op
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Fri Oct  9 14:20:06 2015 Florent Baris
** Last update Fri Oct  9 17:09:39 2015 Florent Baris
*/

#include "do-op.h"

int   add(int a, int b)
{
  my_put_nbr(a + b);
}

int   sub(int a, int b)
{
  my_put_nbr(a - b);
}

int   mul(int a, int b)
{
  my_put_nbr(a * b);
}

int   div(int a, int b)
{
  if (b != 0)
    my_put_nbr(a / b);
  else
    my_putstr("Stop : division by zero");
}

int   mod(int a, int b)
{
  if (b != 0)
    my_put_nbr(a % b);
  else
    my_putstr("Stop : modulo by zero");
}
