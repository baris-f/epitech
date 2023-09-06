/*
** final.c for lemin in /home/baris-f/rendu/CPE/CPE_2015_Lemin
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sun Apr 24 16:27:40 2016 Florent Baris
** Last update Mon Apr 25 19:55:26 2016 Florent Baris
*/

#include "lemin.h"

void	aff(int	four, int room, int reset)
{
  static int	esp = 0;

  if (reset)
    {
      esp = 0;
      return ;
    }
  if (esp > 0)
    my_printf(" ");
  my_printf("P%d-%d", four, room);
  esp++;
}

void	reset_mov(t_base *base)
{
  int	i;

  aff(1, 1, 1);
  i = -1;
  while (++i < base->nb_four)
    base->four[i].y = 0;
  i = -1;
  while (++i < base->nb_node)
    base->room[i] = 0;
  i = -1;
  while (++i < base->nb_four)
    if (base->four[i].x != base->start && base->four[i].x != base->end)
      base->room[base->four[i].x] = 1;
}

void	send_four(t_base *base)
{
  int	i;
  int	j;
  int	k;

  i = -1;
  reset_mov(base);
  while (++i < base->nb_path)
    {
      j = base->ret[i].len + 1;
      while (--j > 0)
	{
	  k = -1;
	  while (++k < base->nb_four)
	      if (base->four[k].x == base->ret[i].path[j - 1]
    && base->four[k].y != 1 && base->room[base->ret[i].path[j]] == 0)
		{
		  setk(base, i, j, k);
		  k = base->nb_four;
		}
	}
    }
  my_printf("\n");
}

int	final(t_base *base)
{
  int	i;

  if ((base->room = malloc(sizeof(int) * base->nb_node)) == NULL)
    return (-1);
  if ((base->four = malloc(sizeof(t_2D) * base->nb_four)) == NULL)
    return (-1);
  sort(base);
  i = -1;
  while (++i < base->nb_four)
    {
      base->four[i].x = base->start;
      base->four[i].y = 0;
    }
  while (notended(base))
    send_four(base);
  free(base->room);
  free(base->four);
  return (0);
}
