/*
** ins.c for ins in /home/baris-f/rendu/CPE/CPE_2015_corewar/corewar/gas
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Thu Mar 24 16:18:28 2016 Florent Baris
** Last update Sun Mar 27 22:15:26 2016 Florent Baris
*/

#include "gas.h"

void	getinmap(t_ptr *ptr, t_base *base)
{
  char	c;

  c = base->vm.map[ptr->addr % MEM_SIZE];
  if (c == 1)
    {
      live(ptr, base);
      ptr->nop = 6;
      ptr->addr += 2;
    }
  else if (0)
    {
      dup_ptr(base, ptr, ptr->addr + base->vm.map[(ptr->addr + 1) % MEM_SIZE]);
      ptr->nop = 801;
      ptr->addr += 2;
    }
  else
    ptr->addr += 1;
}

int	isalive(t_base *base)
{
  int	i;

  i = -1;
  while (++i < 4)
    if (base->files[i].name != NULL)
      if (base->files[i].live > base->vm.cycle - base->vm.cycdie)
	return (i + 1);
  return (0);
}

void    live(t_ptr *ptr, t_base *base)
{
  base->vm.nbl++;
  ptr->champ->live = base->vm.cycle;
  my_printf("Le joueur %s est en vie.\n", ptr->champ->name);
}
