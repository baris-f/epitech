/*
** tri.c for tetris in /home/dudu/rendu/PSU_2015_tetris
**
** Made by lucas duval
** Login   <duval_m@epitech.net>
**
** Started on  Wed Mar  9 11:11:55 2016 lucas duval
** Last update Wed Mar  9 12:40:19 2016 lucas duval
*/

#include "tetris.h"

void            ordre(t_tetri *files, int nbval)
{
  int           i;
  t_tetri	tmp;
  int           permutation;

  permutation = 1;
  while (permutation == 1)
    {
      permutation = 0;
      i = -1;
      while (++i < nbval - 1)
	if (my_strcmp(files[i].name, files[i + 1].name) > 0)
	  {
	    tmp = files[i];
	    files[i] = files[i + 1];
	    files[i + 1] = tmp;
	    permutation = 1;
	  }
    }
}
