/*
** error.c for lemin in /home/dudu/rendu/CPE_2015_Lemin
**
** Made by lucas duval
** Login   <duval_m@epitech.net>
**
** Started on  Sun Apr 24 19:27:09 2016 lucas duval
** Last update Mon Apr 25 15:17:29 2016 lucas duval
*/

#include "lemin.h"

int	error(t_base *base)
{
  int	start;
  int	end;
  int	i;

  start = 0;
  i = -1;
  end = 0;
  if (my_str_isnum(base->lines[0]) != 1)
    return (-1);
  while (base->lines[++i])
    if (match(base->lines[i], "*start"))
      if (start == 0)
	start = 1;
      else
	return (-2);
    else if (match(base->lines[i], "*end"))
      {
	if (end == 0)
	  end = 1;
	else
	  return (-3);
      }
  if (my_getnbr(base->lines[0]) == 0)
    return (-4);
  if (end == 0)
    return (-5);
  if (start == 0)
    return (-6);
  return (0);
}

void	print_all(t_base *base)
{
  int	i;

  i = -1;
  while (base->lines[++i])
    my_printf("%s\n", base->lines[i]);
}

int	trait_err(int err)
{
  if (err == -1 || err == -4)
    my_printf("Erreur nombre de fourmi\n");
  if (err == -2)
    my_printf("Erreur double start\n");
  if (err == -3)
    my_printf("Erreur double end\n");
  if (err == -4)
    my_printf("Erreur no start\n");
  if (err == -5)
    my_printf("Erreur no end\n");
  if (err != 0)
    return (-1);
  return (0);
}
