/*
** turn.c for n4s in /home/baris-f/rendu/CPE/CPE_2015_n4s
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sat May 28 22:53:55 2016 Florent Baris
** Last update Mon May 30 23:20:21 2016 Florent Baris
*/

#include "n4s.h"

int	getspeed(int nba, int nbb, t_base *need)
{
  int	ret;

  if (nba < 0)
    nba *= -1;
  if (nbb < 0)
    nbb *= -1;
  if (need->lidar[16] >= 2500)
    ret = 10;
  else if (need->lidar[16] >= 2000)
    ret = 8;
  else if (need->lidar[16] > 1500)
    ret = 6;
  else if (need->lidar[16] > 1000)
    ret = 4;
  else if (need->lidar[16] > 500)
    ret = 2;
  else
    ret = 1;
  if (nba + nbb != 0)
    ret = 1;
  return (ret);
}

void	set_turn(t_base *need)
{
  int	nba;
  int	nbb;

  nba = need->lefta * 180 / PI * need->rotspeed;
  nbb = need->righta * 180 / PI * need->rotspeed;
  if (nba > 0 || nba < -100)
    nba = 0;
  if (nbb < 0 || nbb > 100)
    nbb = 0;
  free(turn(nba + nbb, need));
  free(move(getspeed(nba, nbb, need)));
}

void    imfucked(t_base *need, int left, int right)
{
  if (left < 75 && left < right && right - left > 50)
    free(turn(5, need));
  else if (left - right > 50)
    free(turn(-5, need));
  else
    free(turn(0, need));
  free(move(-8));
}

void    handle_turn(t_base *need)
{
  if (need->lidar[8] < 75 || need->lidar[24] < 75)
    imfucked(need, need->lidar[8], need->lidar[24]);
  calc(need);
  need->rotspeed = 3;
  calculate(need, need->angle);
  set_turn(need);
}
