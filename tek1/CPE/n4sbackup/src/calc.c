/*
** calc.c for n4s in /home/baris-f/rendu/CPE/CPE_2015_n4s
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sat May 28 18:34:18 2016 Florent Baris
** Last update Sat May 28 20:09:44 2016 Florent Baris
*/

#include "n4s.h"

void	get_lidar(t_base *need)
{
  char	*info;
  char	**lidar;
  int	i;

  info = send("get_info_lidar\n");
  lidar = my_str_to_wordtab(info, ':');
  i = 2;
  while (++i < 35)
    need->lidar[i - 3] = my_getnbr(lidar[i]);
  free(info);
  free(lidar);
}

int	calc(t_base *need)
{
  int	i;

  need->angle[0].ang = 0;
  need->angle[0].dist = need->lidar[0];
  i = 0;
  while (need->lidar[++i] < need->limit && i < 16);
  need->angle[1].ang = i - 1;
  need->angle[1].dist = need->lidar[i - 1];
  i = 32;
  need->angle[2].ang = 31;
  need->angle[2].dist = need->lidar[31];
  while (need->lidar[--i] < need->limit && i > 15);
  need->angle[3].ang = i + 1;
  need->angle[3].dist = need->lidar[i + 1];
  return (0);
}
