/*
** turn.c for n4s in /home/baris-f/rendu/CPE/CPE_2015_n4s
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sat May 28 22:53:55 2016 Florent Baris
** Last update Mon May 30 15:32:32 2016 Florent Baris
*/

#include "n4s.h"

int	rturn(int nb)
{
  if (nb > 8)
    nb = 8;
  else if (nb < -8)
    nb = -8;
  free(turn(nb));
  return (nb);
}

int	rmove(int nb, int left, int right)
{
  if (nb > 0)
    nb = 10 - nb;
  else if (nb < 0)
    nb = (10 + nb) * -1;
  if (nb < 0)
    nb *= -1;
  if (nb > 1)
    nb--;
  if (left < 400 || right < 400)
    nb /= 2;
  if (nb == 0 && left > 400 && right > 400)
    nb = 10;
  else if (nb == 0)
    nb = 7;
  /* if (need->pturn > 6 || need->pturn < -6) */
  /*   if (nb > 3) */
  /*     nb = 3; */
  free(move(nb));
  return (nb);
}
void	set_turn(t_base *need, int left, int right)
{
  int	nb;

  nb = 0;
  if (left > need->limit && right > need->limit)
    free(turn(0));
  else if (left < right)
    {
      nb = (1000 / left);
      if ((need->limit - left * 2) > 0 &&
	  ((right - left) / (need->limit - left * 2)) > 0)
	nb /= ((right - left) / (need->limit - left * 2));
      nb *= -1;
    }
  else
    {
      nb = (1000 / right);
      if ((need->limit - left * 2) > 0 &&
	  ((left - right) / (need->limit - right * 2)) > 0)
	nb /= ((left - right) / (need->limit - right * 2));
    }
  nb = rturn(nb);
  rmove(nb, left, right);
}

void    handle_turn(t_base *need, int left, int right)
{
  (void)need;
  (void)left;
  (void)right;
  calc_prct(need);
  set_turn(need, need->left, need->right);

}
