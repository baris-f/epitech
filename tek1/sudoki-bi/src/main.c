/*
** main.c for zefho in /home/fus/rendu/rush/sudoki-bi/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Sat Feb 27 10:26:48 2016 Gaspard Thirion
** Last update Sat Feb 27 18:55:08 2016 Florent Baris
*/

#include "bibi.h"

int	debug(char c, int *tab)
{
  int	i;

  if ((c < '1' || c > '9') && c != '-' && c != '|' && c != ' ')
    {
      i = -1;
      while (++i < 81)
	tab[i] = -1;
      return (-1);
    }
  return (0);
}

int	gettab(char *buff, int *i, int *tab, int *bit)
{
  int	j;
  int	d;

  d = 0;
  j = -1;
  while (++j < 81 && (bit[j] = 0) == 0);
  j = 0;
  while (buff[*i] && j < 75)
    {
      while (buff[++(*i)] == '|' || buff[*i] == '-' || buff[*i] == '\n');
      while (buff[*i] && buff[*i] != '|')
	{
	  ++(*i);
	  d = (debug(buff[*i], tab) == -1) ? (-1) : (d);
	  if (d == 0)
	    tab[j] = (buff[*i] == ' ') ? (0) : buff[*i] - '0';
	  ++j;
	  ++(*i);
	  bit[j]  |= 1 << (tab[j] - 1);
	  if (tab[j] != 0)
	    bit[j] |= 1 << (9);
	}
    }
  return (0);
}

int	main(int ac, char **av)
{
  char	*buff;
  int	tab[81];
  int	tmp[81];
  int	bit[81];
  int	i;
  int	j;
  int	k;

  if (ac != 1 ||
      (buff = malloc(sizeof(char) * RD_SIZE)) == NULL
      || memset(buff, '\0', RD_SIZE) == NULL
      || (read(0, buff, RD_SIZE) == -1))
    return (-1);
  i = -1;
  j = 0;
  ++i;
  while (buff[++i])
    {
      gettab(buff, &i, tab, bit);
      k = -1;
      while (++k < 81)
	tmp[k] = tab[k];
      while (resolver(tab) == -1)
	{
	  usleep(10000);
	  disptab(tab, 0, j);
	  k = -1;
	  while (++k < 81)
	    tab[k] = tmp[k];
	  gettab(buff, &i, tab, bit);
	}
      disptab(tab, 0, j);
      /* writab(tab, "test"); */
      j = (j == 0) ? (1) : (j);
    }
  printf("\n");
  free(buff);
  return (0);
}
