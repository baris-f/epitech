/*
** calc.c for n4s in /home/baris-f/rendu/CPE/CPE_2015_n4s
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sat May 28 18:34:18 2016 Florent Baris
** Last update Mon May 30 16:38:55 2016 Florent Baris
*/

#include <math.h>
#include "n4s.h"

float	calang(t_ray *tab)
{
  float	ang;

  ang = (tab[1].y - tab[0].y) / (tab[1].x - tab[0].x);
  ang = (float)(atan(ang) + (PI / 3));
  return (ang);
}

void	calculate(t_base *need, t_ray *tab)
{
  int	i;

  i = -1;
  while (++i < 4)
    {
      tab[i].ang *= 3.75;
      tab[i].x = -(float)(cos(tab[i].ang * PI / 180) * tab[i].dist);
      tab[i].y = (float)sin(tab[i].ang * PI / 180) * tab[i].dist;
    }
  need->lefta = calang(&(tab[0]));
  need->righta = calang(&(tab[2]));
}

int	get_lidar(t_base *need)
{
  char	*info;
  char	**lidar;
  int	ret;
  int	i;

  info = send("get_info_lidar\n");
  lidar = my_str_to_wordtab(info, ':');
  i = 2;
  ret = 0;
  while (++i < 35)
    need->lidar[i - 3] = my_getnbr(lidar[i]);
  if (lidar[35] && match(lidar[35], "Track Cleared") != 0)
    ret = 1;
  free(info);
  free(lidar);
  return (ret);
}

void	calc_prct(t_base *need)
{
  int	i;

  i = -1;
  need->left = 0;
  need->right = 0;
  while (++i < 16)
    need->left += need->lidar[i];
  need->left /= 16;
  i--;
  while (++i < 32)
    need->right += need->lidar[i];
  need->right /= 16;

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
