/*
** ai.c for ai in /home/baris-f/rendu/CPE/CPE_2015_Allum1
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sun Feb 21 14:22:38 2016 Florent Baris
** Last update Sun Feb 21 16:02:18 2016 Florent Baris
*/

#include "alum.h"

int     get_state(t_board *bd)
{
  int   i;
  int   nb;

  nb = 0;
  i = -1;
  while (++i < bd->line)
    {
      nb ^= bd->alum[i];
    }
  return (nb);
}

int     bruteforce(t_board *bd)
{
  int   x;
  int   y;

  x = 0;
  while (1)
    {
      y = 0;
      while (++y < bd->alum[x])
	{
	  bd->alum[x] -= y;
	  if (get_state(bd) == 0)
	    {
	      my_printf("AI's turn...\n");
	      my_printf("AI removed %d match(es) from line %d\n", y, x + 1);
	      return (0);
	    }
	  bd->alum[x] += y;
	}
      if (++x > bd->line)
	return (-1);
    }
  return (0);
}

int	caniwin(t_board *bd)
{
  int	i;
  int	nb;
  int	f;
  i = -1;
  nb = 0;
  while (++i < bd->line || nb == 2)
      if (bd->alum[i] > 0)
	{
	  f = i;
	  nb++;
	}
  if (nb == 1 && bd->alum[f] > 1)
    {
      my_printf("AI's turn...\n");
      my_printf("AI removed %d match(es) from line %d\n", bd->alum[f] - 1, f + 1);
      bd->alum[f] -= bd->alum[f] - 1;
      return (0);
    }
  return (-1);
}

void    ais_turn(t_board *bd)
{
  int   i;

  i = -1;
  if (caniwin(bd) == -1)
  if (bruteforce(bd) == -1)
    while (i != -2 && ++i < bd->line)
      if (bd->alum[i] > 0)
	{
	  my_printf("AI's turn...\n");
	  my_printf("AI removed %d match(es) from line %d\n", 1, i + 1);
	  bd->alum[i] -= 1;
	  i = -2;
	}
  if (nbalum(bd) <= 0)
    {
      my_printf("You won, well played !\n");
    }
}

int     nbalum(t_board *bd)
{
  int   i;
  int   nb;

  i = -1;
  nb = 0;
  while (++i < bd->line)
    nb += bd->alum[i];
  return (nb);
}
