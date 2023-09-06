/*
** update.c for lemipc in /home/baris_f/rendu/tek2/PSU_2016_lemipc
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Sat Apr  1 19:01:58 2017 baris_f
** Last update Sat Apr  1 19:12:12 2017 baris_f
*/

#include "main.h"

int	searchSecond(t_dat *dat, int tid)
{
  int	i;
  int	j;
  int	nb;

  nb = 0;
  i = dat->x - 2;
  while (++i < dat->x + 2)
    {
      j = dat->y - 2;
      while (++j < dat->y + 2)
        if (i >= 0 && i < MAP_SIZE && j >= 0 && j < MAP_SIZE)
          if (dat->map->map[i][j] == tid)
            nb++;
    }
  if (nb >= 2)
    return (1);
  return (0);
}

int	isDead(t_dat *dat)
{
  int	i;
  int	j;

  i = dat->x - 2;
  while (++i < dat->x + 2)
    {
      j = dat->y - 2;
      while (++j < dat->y + 2)
	if (i >= 0 && i < MAP_SIZE && j >= 0 && j < MAP_SIZE)
	  if (dat->map->map[i][j] != dat->teamId && dat->map->map[i][j] != 0)
	    if (searchSecond(dat, dat->map->map[i][j]))
	      return (1);
    }
  return (0);
}

int	die(t_dat *dat)
{
  dat->map->map[dat->x][dat->y] = 0;
  dat->map->nb_player--;
  return (0);
}

int	spawn(t_dat *dat)
{
  if (dat->map->nb_player >= MAP_SIZE * MAP_SIZE)
    return (0);
  dat->x = rand() % MAP_SIZE;
  dat->y = rand() % MAP_SIZE;
  while (dat->map->map[dat->x][dat->y] != 0)
    {
      dat->x = rand() % MAP_SIZE;
      dat->y = rand() % MAP_SIZE;
    }
  dat->map->map[dat->x][dat->y] = dat->teamId;
  return (1);
}

void	update(t_dat *dat)
{
  int	d;
  int	stuck;

  stuck = 0;
  d = spawn(dat);
  while (d)
    {
      if (isDead(dat))
	d = die(dat);
      if (d && (move(dat, getDir(dat)) == 0 || isAlone(dat)))
	stuck++;
      if (d && (isDead(dat) || stuck >= 10))
	d = die(dat);
      if (dat->draw)
	cli_draw(dat->map);
      usleep(500000);
    }
  if (dat->draw)
    while (cli_draw(dat->map))
      usleep(500000);
}
