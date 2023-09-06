/*
** ia.c for ia in /home/baris_f/rendu/tek2/PSU_2016_lemipc
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Sat Apr  1 19:02:53 2017 baris_f
** Last update Sat Apr  1 19:08:43 2017 baris_f
*/

#include "main.h"

int	dist(t_dat *dat, t_v2 other)
{
  return (abs(dat->x - other.x) + abs(dat->y - other.y));
}

t_v2	getNearestAlly(t_dat *dat)
{
  int	i;
  int	j;
  int	curb;
  t_v2	bpos;

  i = -1;
  curb = 0;
  bpos.x = MAP_SIZE / 2;
  bpos.y = MAP_SIZE / 2;
  while (++i < MAP_SIZE)
    {
      j = -1;
      while (++j < MAP_SIZE)
        if (dat->map->map[i][j] == dat->teamId && !(i == dat->x && j == dat->y))
          if (curb == 0 || curb > abs(dat->x - i) + abs(dat->y - j))
            {
              curb = abs(dat->x - i) + abs(dat->y - j);
              bpos.x = i;
              bpos.y = j;
            }
    }
  return (bpos);
}

t_v2	getNearestEnnemy(t_dat *dat)
{
  int	i;
  int	j;
  int	curb;
  t_v2	bpos;

  i = -1;
  curb = 0;
  bpos.x = MAP_SIZE / 2;
  bpos.y = MAP_SIZE / 2;
  while (++i < MAP_SIZE)
    {
      j = -1;
      while (++j < MAP_SIZE)
        if (dat->map->map[i][j] != dat->teamId && dat->map->map[i][j] != 0)
          if (curb == 0 || curb > abs(dat->x - i) + abs(dat->y - j))
            {
              curb = abs(dat->x - i) + abs(dat->y - j);
              bpos.x = i;
              bpos.y = j;
            }
    }
  return (bpos);
}

t_dir	findDirTo(t_dat *dat, t_v2 other)
{
  if (abs(dat->x - other.x) > abs(dat->y - other.y))
    {
      if (dat->x > other.x)
        return (LEFT);
      else
        return (RIGHT);
    }
  else
    {
      if (dat->y > other.y)
        return (UP);
      else
        return (DOWN);
    }
}

t_dir	getDir(t_dat *dat)
{

  t_v2	bapos;
  t_v2	bepos;

  bapos = getNearestAlly(dat);
  bepos = getNearestEnnemy(dat);
  if (dist(dat, bapos) > dist(dat, bepos) && dist(dat, bapos) > 1)
    return (findDirTo(dat, bapos));
  else
    return (findDirTo(dat, bepos));
}
