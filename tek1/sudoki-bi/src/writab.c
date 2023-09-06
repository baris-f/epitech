/*
** writab.c for osm in /home/fus/rendu/rush/sudoki-bi/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Sat Feb 27 17:33:46 2016 Gaspard Thirion
** Last update Sat Feb 27 18:09:42 2016 Gaspard Thirion
*/

#include "bibi.h"

void	writab(int *tab, char *name)
{
  FILE	*file;
  int	i;

  if ((file = fopen(name, "a")) == NULL)
    return;
  i = -1;
  fprintf(file, "\n|------------------|\n|");
  while (++i < 81)
    {
      if (i % 9 == 0 && i != 0)
	fprintf(file, "|\n|");
      if (tab[i] == 0)
	fprintf(file, "  ");
      else
	fprintf(file, " %d", tab[i]);
    }
  fprintf(file, "|\n|------------------|");
  fclose(file);
}
