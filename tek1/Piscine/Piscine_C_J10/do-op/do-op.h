/*
** do-op.h for do-op in /home/baris_f/rendu/Piscine_C_J10/do-op
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Fri Oct  9 14:16:59 2015 Florent Baris
** Last update Wed Nov  4 18:06:38 2015 Florent Baris
*/

#ifndef DO_OP_H_
# define DO_OP_H_

typedef struct s_struct
{
  char	op;
  int	(*fct)(int a, int b);
} t_struct;

int	add(int a, int b);
int	sub(int a, int b);
int	mul(int a, int b);
int	div(int a, int b);
int	mod(int a, int b);
void	init(t_struct ptr[5]);
char	findop(char *str);
int	do_op(int a, int b, char opt, t_struct ptr[5]);

#endif /* !DO-OP_H_ */
