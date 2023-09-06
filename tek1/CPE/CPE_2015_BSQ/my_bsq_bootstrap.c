/*
** my_bsq_bootstrap.c for my_bsq_bootstrap.c in /home/baris-f/rendu/CPE_2015_bsq
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Nov 23 16:40:24 2015 Florent Baris
** Last update Mon Dec 21 23:25:49 2015 Florent Baris
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int	my_open(char *filepath)
{
  int	fd;

  fd = open(filepath, S_IRUSR);
    if (fd == -1)
      exit(0);
  return (fd);
}

void	my_read(int fd, char *buf, size_t count)
{
  int	test;
  int	i;

  i = -1;
  while (++i < my_strlen(buf))
    buf[i] = '\0';
  test = read(fd, buf, count);
  if (test == -1)
    exit(0);
  close(fd);
}

int	check(int x, int y, int size, char **map)
{
  int	i;
  int	j;

  j = y - 1;
  while (++j - y < size)
    {
      i = x - 1;
      while (++i - x < size)
	{
	  if (map[j][i] == 'o')
	      return (0);
	}
    }
  return (1);
}

void	applyx(int x, int y, int size, char **map)
{
  int	i;
  int	j;

  j = y - 1;
  while (++j - y < size)
    {
      i = x - 1;
      while (++i - x < size)
	map[j][i] = 'x';
    }
}

int	bsq(char **map, int rows, int size, int *fpos)
{
  int	x;
  int	y;
  int	col;

  col = my_strlen(map[0]);
  y = -1;
  while (++y + size < rows)
    {
      x = -1;
      while (++x + size < col)
	if (check(x, y, size, map) == 1)
	  {
	    fpos[0] = x;
	    fpos[1] = y;
	    return (1);
	  }
    }
  return (0);
}
