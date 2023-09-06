/*
** getnextline.c for getnextline in /home/baris-f/rendu/CPE_2015_bsq
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Tue Dec 15 12:21:50 2015 Florent Baris
** Last update Thu Feb 11 17:09:29 2016 Florent Baris
*/

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "my.h"

int	my_memsetlencat(char *str, int size, int opt, char *src)
{
  int	i;
  int	len;

  len = -1;
  while (str[++len]);
  i = -1;
    if (opt == 1)
      return (len);
    else if (opt == 2)
      while (++i < size)
	str[i] = '\0';
    else if (opt == 3)
      while (src[++i])
	str[len + i] = src[i];
  return (i);
}

void    my_read(int fd, char *buf, size_t count)
{
  int   test;

  my_memsetlencat(buf, my_memsetlencat(buf, 0, 1, 0), 2, 0);
  test = read(fd, buf, count);
  if (test == -1)
    {
      write(1, "read fail\n", 10);
      exit(0);
    }
}

char	*my_realloc(char *str, int newsize)
{
  char	*tmp;

  if (str != NULL)
    if ((tmp = malloc(sizeof(char) * my_memsetlencat(str, 0, 1, 0))) == NULL)
      return 0;
  my_memsetlencat(tmp, my_memsetlencat(str, 0, 1, 0), 2, 0);
  my_memsetlencat(tmp, 0, 3, str);
  if ((str = malloc(sizeof(char) * newsize + 1)) == NULL)
    {
      write(1, "realloc fail\n", 13);
      return (0);
    }
  my_memsetlencat(str, newsize, 2, 0);
  my_memsetlencat(str, 0, 3, tmp);
  newsize -= 2;
  while (str[++newsize])
    str[newsize] = '\0';
  return (str);
}

char   		*get_next_norm(int *i, int *j,
			       char *tmpbuf)
{
  char	*tmp;

  if (tmpbuf[0] == '\0')
    return 0;
  (*j) = (*i) + 1;
  while (tmpbuf[++(*i)] && tmpbuf[(*i)] != '\n');
  if ((tmp = malloc(sizeof(char) * (*i) - (*j) + 1)) == NULL)
    return 0;
  my_memsetlencat(tmp, (*i) - (*j) + 1, 2, 0);
  (*i) = (*j) - 1;
  return (tmp);
}

char		*get_next_line(const int fd)
{
  static int	i = -1;
  static int	j = 0;
  static char	tmpbuf[READ_SIZE + 1];
  char		*tmp;

  if (i == -1)
    my_read(fd, tmpbuf, READ_SIZE);
  if ((tmp = get_next_norm(&i, &j, tmpbuf)) == NULL)
    return 0;
  while (tmpbuf[++i] && tmpbuf[i] != '\n')
    {
      tmp[i - j] = tmpbuf[i];
      tmp[i - j + 1] = '\0';
      if (tmpbuf[i + 1] == '\0')
	{
	  my_read(fd, tmpbuf, READ_SIZE);
	  i = -1;
	  j = my_memsetlencat(tmp, 0, 1, 0) * -1;
	  tmp = my_realloc(tmp, my_memsetlencat(tmp, 0, 1, 0) + READ_SIZE);
	}
    }
  tmp[i - j] = '\0';
  if (tmpbuf[i + 1] == '\0')
    i = -1;
  return (tmp);
}
