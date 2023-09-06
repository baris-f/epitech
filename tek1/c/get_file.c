/*
** get_file.c for get_file in /home/baris-f/rendu/CPE/CPE_2015_corewar/corewar/baris_f
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Wed Mar 16 20:11:13 2016 Florent Baris
** Last update Wed Mar 16 20:13:12 2016 Florent Baris
*/

#include <baris.h>

int     my_open(char *filepath)
{
  int   fd;

  fd = open(filepath, S_IRUSR);
  if (fd == -1)
    exit(0);
  return (fd);
}

int     my_read(int fd, char *buf, int count)
{
  int   test;

  my_memset(buf, '\0', count + 1);
  test = read(fd, buf, count);
  if (test == -1)
    {
      write(1, "read fail\n", 10);
      exit(0);
    }
  else if (test < count)
    return (-1);
  else
    return (0);
}

char    *my_realloc(char *str, int newsize)
{
  char  *tmp;

  if (str == NULL ||
      (tmp = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
    return 0;
  my_memset(tmp, '\0', my_strlen(str));
  my_strcat(tmp, str);
  free(str);
  if ((str = malloc(sizeof(char) * newsize + 1)) == NULL)
    {
      write(1, "realloc fail\n", 13);
      return (0);
    }
  my_memset(str, '\0', newsize + 1);
  my_strcat(str, tmp);
  newsize -= 2;
  while (str[++newsize])
    str[newsize] = '\0';
  return (str);
}

char    *get_file(int fd)
{
  int           i;
  char          *tmpbuf;
  char          *tmp;

  if (fd == -1)
    return (0);
  if ((tmpbuf = malloc(sizeof(char) * RS + 1)) == NULL)
    return 0;
  my_read(fd, tmpbuf, RS);
  if ((tmp = malloc(sizeof(char) * RS + 1)) == NULL)
    return 0;
  i = -1;
  while (i == -1)
    {
      tmpbuf = my_realloc(tmpbuf, my_strlen(tmpbuf) + RS);
      if (my_read(fd, tmp, RS) == 0)
	i = 0;
      else
	i = 1;
      my_strcat(tmpbuf, tmp);
      i -= 1;
    }
  close(fd);
  free(tmp);
  return (tmpbuf);
}
