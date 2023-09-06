/*
** move.c for move in /home/baris_f/rendu/tek2/PSU_2016_lemipc
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Sat Apr  1 19:02:45 2017 baris_f
** Last update Sat Apr  1 19:12:52 2017 baris_f
*/

#include "main.h"

int	isAlone(t_dat *dat)
{
  int	i;
  int	j;
  int	nb;
  int	prevtid;

  prevtid = 0;
  nb = 0;
  i = -1;
  while (++i < MAP_SIZE)
    {
      j = -1;
      while (++j < MAP_SIZE)
	if (dat->map->map[i][j] != 0)
	  {
	    if (prevtid != 0 && dat->map->map[i][j] != prevtid)
	      return (0);
	    prevtid = dat->map->map[i][j];
	    nb++;
	  }
    }
  if (nb >= 2)
    return (0);
  return (1);
}

int	move(t_dat *dat, t_dir dir)
{
  int	ret;

  ret = 1;
  if (dir == BUG)
    return (0);
  dat->sbuff.sem_op = -1;
  semop(dat->semId, &(dat->sbuff), 1);
  dat->map->map[dat->x][dat->y] = 0;
  if (dir == RIGHT && dat->x < MAP_SIZE
      && dat->map->map[dat->x + 1][dat->y] == 0)
    dat->x++;
  else if (dir == LEFT && dat->x > 0 && dat->map->map[dat->x - 1][dat->y] == 0)
    dat->x--;
  else if (dir == UP && dat->y > 0 && dat->map->map[dat->x][dat->y - 1] == 0)
    dat->y--;
  else if (dir == DOWN && dat->y < MAP_SIZE
	   && dat->map->map[dat->x][dat->y + 1] == 0)
    dat->y++;
  else
    ret = 0;
  dat->map->map[dat->x][dat->y] = dat->teamId;
  dat->sbuff.sem_op = 1;
  semop(dat->semId, &(dat->sbuff), 1);
  return (ret);
}
