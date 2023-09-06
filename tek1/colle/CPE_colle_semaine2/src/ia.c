/*
** ia.c for p4 in /home/baris-f/rendu/colle/CPE_colle_semaine2
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Wed May  4 17:15:57 2016 Florent Baris
** Last update Wed May  4 17:36:05 2016 Florent Baris
*/

#include "p4.h"

int	ia(t_p4 *p4)
{
  int	nb;

  nb = rand() % p4->size.x + 1;
  while (p4->map[nb] != ' ')
    nb = rand() % (p4->size.x + 1);
  insert(p4, nb, 'O');
  my_putstr("ia played in column ");
  my_putnbr(nb);
  my_putchar('\n');
  return (0);
}
