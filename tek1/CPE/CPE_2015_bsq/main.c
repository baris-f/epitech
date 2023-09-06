/*
** main.c for mainbsq in /home/baris-f/rendu/CPE_2015_bsq
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sun Dec 20 08:35:58 2015 Florent Baris
** Last update Mon Dec 21 23:33:04 2015 Florent Baris
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my.h"

void	init(t_var *v, int ac, char **av)
{
  int	i;

  if (ac != 2)
    {
      my_printf("Usage : ./bsq map\n");
      exit(0);
    }
  if (stat(av[1], &v->info) == -1)
    {
      my_printf("stat fail\n");
      exit(0);
    }
  v->fd = my_open(av[1]);
  i = -1;
  v->buff = getnextline(v->fd, v->info.st_size);
  v->rows = my_getnbr(v->buff);
  if (v->rows == 1)
    exit((int)write(1, "x\n", 2));
  v->size = v->rows / 2;
  v->sizedif = v->size;
  if ((v->map = malloc(sizeof(char *) * v->rows)) == NULL)
    return ;
  while (++i < v->rows)
    v->map[i] = getnextline(v->fd, v->info.st_size);
}

int     main(int ac, char **av)
{
  t_var	v;

  init(&v, ac, av);
  v.j = -1;
  while (v.size != v.size + v.sizedif / 2 || (v.size == v.sizedif))
    {
      if (v.sizedif > 1)
	v.sizedif /= 2;
      if (bsq(v.map, v.rows, v.size, v.fpos) == 1)
	v.size += v.sizedif;
      else
	v.size -= v.sizedif;
      if (v.size == 2 && bsq(v.map, v.rows, v.size, v.fpos) == 0)
	  v.sizedif = 0;
      if (v.size == 2 && bsq(v.map, v.rows, v.size, v.fpos) == 0)
	  v.size = 1;
    }
  applyx(v.fpos[0], v.fpos[1], v.size, v.map);
  while (++(v.j) < v.rows)
    {
      my_printf("%s\n", v.map[v.j]);
      free(v.map[v.j]);
    }
  free(v.map);
  free(v.buff);
}
