/*
** turn.c for n4s in /home/baris-f/rendu/CPE/CPE_2015_n4s
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sat May 28 22:53:55 2016 Florent Baris
** Last update Sat May 28 23:03:26 2016 Florent Baris
*/

#include "n4s.h"

void	calc_turn(t_base *need, int left, int right)
{
  (void)need;
  if (left > 400 && right > 400)
    free(turn(0));
  if (left < 500 && left < right && right - left > 150)
    free(turn(-1));
  else if (right < 500 && right < left && left - right > 150)
    free(turn(1));
  else if (left < 900 && left < right && right - left < 450)
    free(turn(-3));
  else if (right < 900 && left - right < 450)
    free(turn(3));
  else if (left < 900 && left < right && right - left < 250)
    free(turn(-5));
  else if (right < 900 && left - right < 250)
    free(turn(5));
  else
    free(turn(0));
}

void    handle_turn(t_base *need, int left, int right)
{
  (void)need;
  calc_turn(need, left, right);
  if (left < 1100 && left < right && right - left < 450)
    free(move(6));
  else if (right < 1100 && left - right < 450)
    free(move(6));
  else
    free(move(10));
}
