/*
** new_get.c for newget in /home/baris-f/rendu/CPE/CPE_2015_corewar/corewar/baris_f
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Fri Mar 18 14:40:51 2016 Florent Baris
** Last update Thu Mar 24 10:33:07 2016 Florent Baris
*/

#include "corewar.h"

unsigned char	*get_cor(char *filepath)
{
  int	i;
  int	nbr;
  int	fd;
  unsigned char	buf[2];
  unsigned char	*try;

  try = malloc(sizeof(unsigned char) * 10 + 1);
  fd = open(filepath, O_RDONLY);
  i = 0;
  while ((nbr = read(fd, buf, 1)) > 0)
    {
      try[i] = buf[0];
      try = realloc(try, (i * sizeof(unsigned char) + 10));
      i++;
    }
  if (i == 0)
    {
      write(1, "read fail\n", 10);
      exit(0);
    }
  return (try);
}
