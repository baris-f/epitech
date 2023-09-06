/*
** main.c for okd in /home/fus/rendu/cpe/CPE_2015_corewar/gas/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Tue Mar 15 10:09:40 2016 Gaspard Thirion
** Last update Thu Mar 31 15:15:13 2016 Florent Baris
*/

#include "gas.h"

int		chklist(t_base *base)
{
  t_ptr		*ptr;

  ptr = base->ptr;
  while (ptr->champ)
    {
      if (--(ptr->nop) <= 0)
	{
	  getinmap(ptr, base);
	}
      ptr = ptr->nxt;
    }
  return (0);
}

int		main(int ac, char **av)
{
  t_base	base;

  if (ac < 3)
    return (-1);
  if (init(&base) == -1 || parser(ac, av, &base) == -1
      || create_liste(&base) == -1 || initvm(&(base.vm)) == -1)
    return (-1);
  setchamps(&(base.vm), base.files);
  while (++(base.vm.cycle) < base.vm.nb_cycles)
    {
      affvm(&base);
      chklist(&base);
      if (isalive(&base) == 0)
	{
	  my_printf("Le joueur %s a gagné.\n",
		    base.files[isalive(&base) - 1].name);
	  base.vm.nb_cycles = -1;
	}
      if (base.vm.nbl >= NBR_LIVE)
  	{
  	  base.vm.nbl -= NBR_LIVE;
  	  base.vm.cycdie -= CYCLE_DELTA;
  	}
    }
  return (0);
}
