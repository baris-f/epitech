/*
** div.c for div in /home/baris_f/rendu/tek2/cpp_d02m/ex04
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Thu Jan  5 10:58:05 2017 baris_f
** Last update Thu Jan  5 15:07:56 2017 baris_f
*/

#include <stdio.h>
#include "castmania.h"

int	integer_div(int a, int b)
{
  if (b == 0)
    return (0);
  return (a / b);
}

float	decimal_div(int a, int b)
{
  if (b == 0)
    return (0);
  return ((float)((float)a / (float)b));
}


void	exec_div(t_div *operation)
{
  t_integer_op *iop;
  t_decimale_op *dop;

  if (operation->div_type == INTEGER)
    {
      iop = (t_integer_op*)operation->div_op;
    iop->res = integer_div(iop->a, iop->b);
    }
  else if (operation->div_type == DECIMALE)
    {
      dop = (t_decimale_op*)operation->div_op;
      dop->res = decimal_div(dop->a, dop->b);
    }
}
/*
int  main (void)
 {
   int i = 5;
   float f = 42.5;
   t_instruction inst;
   t_add add;
   t_div div;
   t_integer_op int_op;

   printf("Display i: ");
   exec_instruction(PRINT_INT, &i);
   printf("Display f: ");
   exec_instruction(PRINT_FLOAT, &f);
   printf("\n");
   int_op.a = 10;
   int_op.b = 3;
   add.add_type = ABSOLUTE;
   add.add_op = int_op;
   inst.output_type = VERBOSE;
   inst.operation = &add;
   printf("10 + 3 = ");
   exec_operation(ADD_OPERATION, &inst);
   printf("Indeed, 10 + 3 = %d\n\n", add.add_op.res);
   div.div_type = INTEGER;
   div.div_op = &int_op;
   inst.operation= &div;
   printf("10 / 3 = ");
   exec_operation(DIV_OPERATION, &inst);
   printf("Indeed, 10 / 3 = %d\n\n", int_op.res);
   return(0);
}
*/
