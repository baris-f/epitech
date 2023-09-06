/*
** check_err.c for p4 in /home/baris-f/rendu/colle/CPE_colle_semaine2
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Wed May  4 18:22:25 2016 Florent Baris
** Last update Wed May  4 18:22:40 2016 Florent Baris
*/

#include "p4.h"

int	check_nbr(int x, int y, t_p4 *p4)
{
  if (x * y < 20)
    return (-1);
  if (x > 80)
    {
      my_putstr("width must be <= 80\n");
      return (-1);
    }
  if (y > 16)
    {
      my_putstr("height must be <= 16\n");
      return (-1);
    }
  p4->size.x = x;
  p4->size.y = y;
  return (0);
}

int	check_avatar(t_p4 *p4, char a, char b)
{
  if (a == b || a == p4->p2 ||
      p4->p1 == b)
    {
      my_putstr("Choose an other avatar\n");
      return (-1);
    }
  if (a == ' ' || b == ' ')
    {
      my_putstr("No invisible character allowed\n");
      return (-1);
    }
  p4->p1 = a;
  p4->p2 = b;
  return (0);
}

int	check_arb(char a, t_p4 *p4)
{
  if (a == p4->p1 || a == p4->p2)
    {
      my_putstr("Choose an other avatar\n");
      return (-1);
    }
  if (a == ' ')
    {
      my_putstr("No invisible character allowed\n");
      return (-1);
    }
  else
    p4->end = a;
  return (0);
}
