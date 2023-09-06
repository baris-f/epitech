/*
** main.c for n4s in /home/baris-f/rendu/CPE/CPE_2015_n4s
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Tue Apr 26 14:54:33 2016 Florent Baris
** Last update Mon May 30 15:46:32 2016 Florent Baris
*/

#include <stdio.h>
#include <stdlib.h>
#include "n4s.h"

void	imfucked(t_base *need, int left, int right)
{
  (void)need;
  fprintf(need->fp, "wall hit  ");
  if (left < 75 && left < right && right - left > 50)
    free(turn(5));
  else if (left - right > 50)
    free(turn(-5));
  else
    free(turn(0));
  free(move(-8));
}

void	manage(t_base *need)
{
  int	left;
  int	right;

  left = need->lidar[12];
  right = need->lidar[24];
  if (left < 75 || right < 75
      || need->lidar[0] < 50 || need->lidar[31] < 50)
    imfucked(need, left, right);
  else
    {
      handle_turn(need, left, right);
    }
}

int	main()
{
  t_base	need;
  int		j;

  need.fp = fopen ("debug.txt", "w+");
  if ((need.lidar = malloc(sizeof(int) * 32)) == NULL)
    return (-1);
  need.limit = 1000;
  free(send("START_SIMULATION\n"));
  j = 0;
  need.pturn = 0;
  need.pspeed = 10;
  free(move(10));
  (void)j;
  while (get_lidar(&need) == 0)
    {
      calc(&need);
      manage(&need);
    }
  free(send("CAR_FORWARD:0.0\n"));
  free(send("STOP_SIMULATION\n"));
  return (0);
}
