/*
** arg.c for asm in /home/dudu/rendu/CPE_2015_corewar/asm
**
** Made by lucas duval
** Login   <duval_m@epitech.net>
**
** Started on  Sun Mar 27 21:41:28 2016 lucas duval
** Last update Sun Mar 27 22:47:24 2016 lucas duval
*/

#include "my.h"

void    check_exist(int j, int i)
{
  if (op_tab[j].code == 0)
    {
      my_printf("Unkown instruction on ligne %d \n", i);
      exit(1);
    }
}

void    correct_arg(t_base *base, int i, int j)
{
  if (op_tab[j].nbr_args != count_arg(base->file[i].arg))
    {
      my_printf("Bad number of parameters on line %d\n", base->file[i].idx);
      exit(1);
    }
}

void    check_arg(t_base *base, int max, int i, int j)
{
  int   count;

  while (++i < max)
    {
      j = -1;
      if ((count = count_arg(base->file[i].instruct)) > 1)
	{
	  if (count == 2)
	    check_arg2(base, i, j, 0);
	  else
	    check_arg2(base, i, j, 1);

	}
    }
}

void    get_arg(t_base *base, int max)
{
  int   i;
  int   j;

  i = 1;
  while (++i < max)
    {
      j = -1;
      while (base->file[i].instruct[++j]);
      base->file[i].arg = recuparg(base->file[i].instruct[j - 1],
				   SEPARATOR_CHAR);
    }
}

int     count_arg(char **arg)
{
  int   i;

  i = -1;
  while (arg[++i]);
  return (i);
}
