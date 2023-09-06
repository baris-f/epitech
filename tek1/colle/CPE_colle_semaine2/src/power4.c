/*
** power4.c for power4 in /home/baris-f/rendu/colle/CPE_colle_semaine2
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Wed May  4 14:56:28 2016 Florent Baris
** Last update Wed May  4 17:16:53 2016 Florent Baris
*/

#include "p4.h"

int	aff(t_p4 *p4)
{
  int	i;
  int	j;

  i = -1;
  while (++i < p4->size.y)
    {
      j = -1;
      my_putchar('|');
      while (++j < p4->size.x)
	my_putchar(p4->map[p4->size.x * i + j]);
      my_putstr("|\n");
    }
  i = -1;
  my_putchar('+');
  while (++i < p4->size.x)
    my_putchar('-');
  my_putstr("+\n");
  return (0);
}

int	insert(t_p4 *p4, int nb, char p)
{
  int	i;

  if (nb <= 0 || nb > p4->size.x)
    {
      if (nb <= 0)
	my_putstr("Invalid number.\n");
      else
	my_putstr("This column is out of range.\n");
      return (-1);
    }
  i = 0;
  nb--;
  while (p4->map[p4->size.x * i + nb] == ' ' && i < p4->size.y)
    i++;
  i--;
  if (i < 0)
    {
      my_putstr("This column is full.\n");
      return (-1);
    }
  p4->map[p4->size.x * i + nb] = p;
  return (0);
}

int    	nextturn(t_p4 *p4, char p)
{
  int	nb;
  char	*tmp;

  if (my_putstr("Player ") == -1)
    return (-1);
  my_putchar(p);
  my_putstr(", where do you want to play: ");
  if ((tmp = malloc(sizeof(char) * 11)) == NULL)
    return (-1);
  if (read(0, tmp, 10) == -1)
    return (-1);
  nb = my_getnbr(tmp);
  if (insert(p4, nb, p) == -1)
    {
      free(tmp);
      nextturn(p4, p);
    }
  else
    free(tmp);
  return (0);
}

int	power4(t_p4 *p4)
{
  int	turn;

  turn = -1;
  while (over(p4) == 0)
    {
      aff(p4);
      turn++;
      if (turn % 2 == 0)
	{
	  if (nextturn(p4, p4->p1) == -1)
	    return (-1);
	}
      else if (p4->ia == 0)
	{
	if (nextturn(p4, p4->p2) == -1)
	  return (-1);
	}
      else
	if (ia(p4) == -1)
	  return (-1);
    }
  return (0);
}
