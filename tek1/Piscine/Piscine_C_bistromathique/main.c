/*
** main.c for Piscine_C_Bistromathique in /home/linux/rendu/Piscine_C_bistromathique
**
** Made by thirion gaspard
** Login   <thirio_b@epitech.net>
**
** Started on  Wed Oct 28 00:13:07 2015 thirion gaspard
** Last update Wed Oct 28 10:19:28 2015 thirion gaspard
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "include/bistro.h"

int		my_atoi(char *);
void		my_putstr(char *);
int		my_strlen(char *);
static void	check_base(char *base);
static void	check_ops(char *ops);
static char	*get_expr(unsigned size);

int		main(int ac, char **av)
{
  char		*expr;
  unsigned int	size;

  if (ac != 4)
    {
      my_putstr("Usage : ");
      my_putstr(av[0]);
      my_putstr(" base ops\"()+-*/%\" exp_len\n");
      return (1);
    }
  check_base(av[1]);
  check_ops(av[2]);
  size = my_getnbr(av[3]);
  expr = get_expr(size);
  eval_expr(av[1], av[2], expr, size);
  free (expr);
  return (0);
}

static void	check_base(char *b)
{
  if (my_strlen(b) < 2)
    {
      my_putstr("Bad base\n");
      exit(1);
    }
}

static char	*get_expr(unsigned int size)
{
  char		*expr;

  if (size <= 0)
    {
      my_putstr("Bad expr len\n");
      exit(2);
    }
  expr = malloc(size + 1);
  if (expr == 0)
    {
      my_putstr("could not alloc\n");
      exit(3);
    }
  if (read(0, expr, size) != size)
    {
      my_putstr("could not read\n");
      exit(4);
    }
  expr[size] = 0;
  return (expr);
}

static void	check_ops(char *ops)
{
  if (my_strlen(ops) != 7)
    {
      my_putstr("Bad ops\n");
      exit(5);
    }
}
