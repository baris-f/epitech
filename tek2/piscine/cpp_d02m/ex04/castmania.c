/*
** castmania.c for castmania in /home/baris_f/rendu/tek2/cpp_d02m/ex04
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Thu Jan  5 13:24:00 2017 baris_f
** Last update Thu Jan  5 14:42:53 2017 baris_f
*/

#include <stdio.h>
#include "castmania.h"

void	exec_operation(t_instruction_type instruction_type, void *data)
{
  if (instruction_type == ADD_OPERATION)
    {
      t_instruction *datat;
      t_add *op;

      datat = (t_instruction*)data;
      op = (t_add *)(datat->operation);
      exec_add(op);
      if (datat->output_type == VERBOSE)
	printf("%d\n", op->add_op.res);
    }
  else if (instruction_type == DIV_OPERATION)
    {
      t_instruction *datat;
      t_div *op;

      datat = (t_instruction*)data;
      op = (t_div *)(datat->operation);
      exec_div(op);
      if (datat->output_type == VERBOSE)
	{
	  if (op->div_type == INTEGER)
	    printf("%d\n", ((t_integer_op*)op->div_op)->res);
	  else if (op->div_type == DECIMALE)
	    printf("%f\n", ((t_decimale_op*)op->div_op)->res);
	}
    }
}

void	exec_instruction(t_instruction_type instruction_type, void *data)
{
  if (instruction_type == PRINT_INT)
    printf("%d\n", *(int*)data);
  else if (instruction_type == PRINT_FLOAT)
    printf("%f\n", *(float*)data);
  else
    exec_operation(instruction_type, data);
}
