/*
** draw.c for draw in /home/baris_f/rendu/tek2/PSU_2016_lemipc
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Sat Apr  1 19:03:03 2017 baris_f
** Last update Sat Apr  1 19:07:52 2017 baris_f
*/

#include "main.h"

int	cli_draw(t_map *map)
{
  int	i;
  int	j;

  printf("\e[1;1H\e[2J");
  i = -1;
  while (++i < MAP_SIZE)
    {
      j = -1;
      while (++j < MAP_SIZE)
	if (!map->map[j][i])
	  printf(". ");
	else
	  printf("%d ", map->map[j][i]);
      printf("\n");
    }
  printf("nb_player : %d\n", map->nb_player);
  if (map->nb_player <= 0)
    return (0);
  return (1);
}
