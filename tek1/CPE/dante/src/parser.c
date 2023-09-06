/*
** parser.c for  in /home/fus/taff/dante/parser/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Thu May 19 01:07:00 2016 Gaspard Thirion
** Last update Thu May 19 17:55:03 2016 Gaspard Thirion
*/

#include "dante.h"

void	get_lenght(t_maz *maz, char *map)
{
  int	i;

  i = -1;
  while (map[++i] && map[i] != '\n');
  maz->x = i;
  maz->y = 2;
  while (map[++i])
    if (map[i] == '\n')
      maz->y++;
  maz->size = maz->x * maz->y;
}

char	chkcell(t_maz *maz, char *map, int ri)
{
  char	c;
  int	x;
  int	y;

  if (map[ri] == '*')
    c = 1;
  else
    return (0);
  y = ri / (maz->x + 1);
  x = ri - (maz->x + 1) * y;
  if (x >= 0 && x < maz->x && y - 1 >= 0 && y - 1 < maz->y
      && map[x + (y - 1) * (maz->x + 1)] == '*')
    SET(c, CAN_UP);
  if (x >= 0 && x < maz->x && y + 1 >= 0 && y + 1 < maz->y
      && map[x + (y + 1) * (maz->x + 1)] == '*')
    SET(c, CAN_DOWN);
  if (x - 1 >= 0 && x - 1 < maz->x && y >= 0 && y < maz->y
      && map[x - 1 + y * (maz->x + 1)] == '*')
    SET(c, CAN_LEFT);
  if (x + 1 >= 0 && x + 1 < maz->x && y >= 0 && y < maz->y
      && map[x + 1 + y * (maz->x + 1)] == '*')
    SET(c, CAN_RIGHT);
  return (c);
}

void	fill(t_maz *maz, char *map)
{
  int	i;
  int	d;

  i = -1;
  d = 0;
  while (++i < maz->size)
    if (map[i + d] == '\n')
      {
	d++;
	i--;
      }
    else
      maz->map[i] = chkcell(maz, map, i + d);
}

int	parser(t_maz *maz, int fd)
{
  char	*map;

  if ((map = recup(fd)) == NULL)
    return (-3);
  get_lenght(maz, map);
  if ((maz->map = malloc(sizeof (unsigned int) * maz->size)) == NULL)
    return (-1);
  fill(maz, map);
  free(map);
  return (0);
}
