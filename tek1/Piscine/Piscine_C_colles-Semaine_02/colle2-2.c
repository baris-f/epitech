/*
** colle2-2.c for colle2-2 in /home/baris_f/rendu/Piscine_C_colles-Semaine_02
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sat Oct 10 12:05:30 2015 Florent Baris
** Last update Sun Oct 11 10:59:50 2015 Florent Baris
*/

#include <stdlib.h>

int	infloop(char *strd, int len, int time, int i)
{
  char	temp;

  while (1)
    {
      i = -1;
      while (++i < len)
	{
	  usleep(time);
	  temp = strd[i];
	  strd[i] = strd[len + i];
	  strd[len + i] = temp;
	  my_putchar('\r');
	  my_putstr(strd);
	}
      i = len;
      while (--i >= 0)
	{
	  usleep(time);
	  temp = strd[i];
	  strd[i] = strd[len + i];
	  strd[len + i] = temp;
	  my_putchar('\r');
	  my_putstr(strd);
	}
    }
}

int	main(int argc, char **argv)
{
  int	len;
  int	i;
  char	*strd;
  int	time;

  if (argc != 2 && argc != 3)
    {
      my_putstr("Usage : ./colle2-2 word [speed]\n");
      return (0);
    }
  if (argc == 3)
    time = my_getnbr(argv[2]);
  else
    time = 500000;
  len = my_strlen(argv[1]);
  strd = malloc(sizeof(char) * len * 2);
  if (strd == NULL)
    return (0);
  i = -1;
  while (++i < len * 2)
     strd[i] = ' ';
  i = -1;
  while (argv[1][++i])
    strd[i] = argv[1][i];
  my_putstr(strd);
  infloop(strd, len, time, i);
}
