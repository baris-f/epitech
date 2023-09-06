/*
** getnextline.c for getnextline in /home/baris-f/rendu/CPE_2015_bsq
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Tue Dec 15 12:21:50 2015 Florent Baris
** Last update Thu Dec 17 14:34:42 2015 Florent Baris
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

void	my_realloc(char *str, int newsize)
{
  char	*tmp;
  int	i;

  i = -1;
  tmp = my_strdup(str);
  free(str);
  if ((str = malloc(sizeof(char) * (newsize - my_strlen(str)))) == NULL)
    return ;
  while (++i < (newsize - my_strlen(str)))
    str[i] = '\0';
  my_strcat(str, tmp);
  free(tmp);
}

char		*getnextline(const int fd, int size)
{
  static int	cur = 0;
  static int	i = -1, j = 0;
  static char	*tmpbuf;
  char		*tmp;

  if (cur == 0)
    {
      if ((tmpbuf = malloc(sizeof(char) * size)) == NULL)
	exit(0);
      my_read(fd, tmpbuf, size);
    }
  j = i + 1;
  while (tmpbuf[++i] && tmpbuf[i] != '\n');
  if ((tmp = malloc(sizeof(char) * i - j + 1)) == NULL)
    return (0);
  i = j - 1;
  while (tmpbuf[++i] && tmpbuf[i] != '\n')
      tmp[i - j] = tmpbuf[i];
  cur++;
  return (tmp);
}
