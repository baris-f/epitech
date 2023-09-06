/*
** opt.c for pzo in /home/fus/rendu/cpe/CPE_2015_corewar/gas/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Tue Mar 15 10:11:34 2016 Gaspard Thirion
** Last update Sun Mar 27 20:05:51 2016 Florent Baris
*/

#include "gas.h"

void		debug(t_base *base)
{
  int		i;

  my_printf("***DEBUG***\n");
  my_printf("nb_cycles = %d\n", base->vm.nb_cycles);
  i = -1;
  while (++i < CHP_NB)
    if (base->files[i].name)
      my_printf("###name = %s\nindex = %d\naddresse = %d\n",
		base->files[i].name, i, base->files[i].addr);
  my_printf("***DEBUG***\n");
}

int		get_info(char *s, int i)
{
  int		ret;

  if (i == 0 && (!s
		 || (ret = my_getnbr(s)) <= 0))
    {
      my_printf("invalid size to -dump\n");
      return (-1);
    }
  if (i == 1 && (!s
		 || (ret = my_getnbr(s)) <= 0
		 || ret > CHP_NB))
    {
      my_printf("invalid index to -n [1..CHP_NB]\n");
      return (-1);
    }
  if (i == 2 && (!s
		 || (ret = my_getnbr(s)) <= 0))
    {
      my_printf("invalid adress for -a\n");
      return (-1);
    }
  return (ret);
}

int		get_file(t_mem *mem, t_base *base, char *name)
{
  int		i;

  if (mem->idx > CHP_NB || mem->idx <= 0)
    {
      i = -1;
      while (base->files[++i].name && i < CHP_NB);
      mem->idx = i + 1;
    }
  if (base->files[mem->idx - 1].name)
    {
      my_printf("invalid index : there is already a champion\n");
      return (-1);
    }
  base->files[mem->idx - 1].name = my_strdup(name);
  base->files[mem->idx - 1].addr = mem->addr;
  mem->idx = 0;
  return (0);
}

int		check(t_mem *mem, t_base *base, char **av)
{
  if (nmatch(av[mem->i], "-dump") > 0)
    return (base->vm.nb_cycles = get_info(av[++(mem->i)], 0));
  else if (nmatch(av[mem->i], "-n") > 0)
    return (mem->idx = get_info(av[++(mem->i)], 1));
  else if (nmatch(av[mem->i], "-a") > 0)
    return (mem->addr = get_info(av[++(mem->i)], 2));
  else if (nmatch(av[mem->i], "-d") > 0)
    mem->d = 1;
  else if (nmatch(av[mem->i], EXT) > 0)
    return (get_file(mem, base, av[mem->i]));
  else
    {
      my_printf("invalid command : %s\n", av[mem->i]);
      return (-1);
    }
  return (0);
}

int		parser(int ac, char **av, t_base *base)
{
  t_mem		mem;

  mem.i = 0;
  mem.d = 0;
  mem.idx = 0;
  mem.addr = 0;
  while (++(mem.i) < ac)
    {
    if (check(&mem, base, av) == -1)
      return (-1);
    }
  if (mem.d)
    debug(base);
  return (0);
}
