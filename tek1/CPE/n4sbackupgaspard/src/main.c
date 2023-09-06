/*
** main.c for n4s in /home/baris-f/rendu/CPE/CPE_2015_n4s
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Tue Apr 26 14:54:33 2016 Florent Baris
** Last update Mon May 30 23:20:07 2016 Florent Baris
*/

#include <stdio.h>
#include <stdlib.h>
#include "n4s.h"


int	main()
{
  t_base	need;

  if ((need.lidar = malloc(sizeof(int) * 32)) == NULL)
    return (-1);
  need.limit = 600;
  free(send("START_SIMULATION\n"));
  need.pturn = 0;
  need.pspeed = 10;
  /* free(move(10)); */
  while (get_lidar(&need) == 0)
    handle_turn(&need);
  free(send("CAR_FORWARD:0.0\n"));
  free(send("STOP_SIMULATION\n"));
  return (0);
}
