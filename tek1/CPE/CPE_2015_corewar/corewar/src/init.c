/*
** init.c for isj in /home/fus/rendu/cpe/CPE_2015_corewar/gas/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Tue Mar 15 10:47:15 2016 Gaspard Thirion
** Last update Sat Mar 26 16:30:23 2016 Gaspard Thirion
*/

#include "gas.h"

int		init(t_base *base)
{
  int		i;

  base->vm.nb_cycles = CYCLE_TO_DIE;
  base->vm.cycdie = CYCLE_TO_DIE;
  base->vm.cycle = -1;
  base->vm.nbl = 0;
  if ((base->files = malloc(sizeof(t_chpt) * 4)) == NULL)
    return (-1);
  i = -1;
  while (++i < CHP_NB)
    {
      base->files[i].name = NULL;
      base->files[i].addr = -1;
    }
  return (0);
}

int		mfree(t_base *base)
{
  int		i;

  i = -1;
  while (++i < 4)
    if (base->files)
      free(base->files);
  return (0);
}
