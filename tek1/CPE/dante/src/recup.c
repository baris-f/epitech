/*
** utils.c for ofk in /home/fus/taff/colle/CPE_colle_semaine1/gas/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Wed Apr 27 15:29:47 2016 Gaspard Thirion
** Last update Wed May 11 17:21:39 2016 Florent Baris
*/

#include "dante.h"

char		*my_realloc(char *tmp, int old, int new)
{
  int		i;
  char		*ret;

  i = -1;
  if ((ret = malloc(sizeof(char) * new)) == NULL)
    return (NULL);
  while (++i < old)
    ret[i] = tmp[i];
  --i;
  while (++i < new)
    ret[i] = 'A';
  if (tmp)
    free(tmp);
  return (ret);
}

int		mstrcpy(char *src, char *dest, int start, int end)
{
  int		i;

  if (!dest || !src)
    return (-1);
  i = -1;
  while (++i < end - start)
    dest[i + start] = src[i];
  return (0);
}

char		*recup(int fd)
{
  char		*buff;
  char		*tmp;
  int		i;
  int		ret;

  if ((buff = malloc(sizeof(char) * SIZE)) == NULL)
    return (NULL);
  i = 0;
  ret = 1;
  tmp = NULL;
  while (ret > 0)
    {
      if ((tmp = my_realloc(tmp, i, i + SIZE)) == NULL
	  || (ret = read(fd, buff, SIZE)) == -1
	  || mstrcpy(buff, tmp, i, i + ret) == -1)
	return (NULL);
      i += ret;
      tmp[i] = '\0';
    }
  free(buff);
  return (tmp);
}
