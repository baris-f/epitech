/*
** divinf.h for divinfh in /home/baris_f/rendu/Piscine_C_J09/ex_03
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Thu Oct  29 20:38:41 2015 Florent Baris
** Last update Sun Nov  1 17:09:12 2015 Florent Baris
*/

#ifndef DIVINF_H_
# define DIVINF_H_

struct	s_stock_char
{
  char	*tmp;
  char	*rest;
  char	*nbr;
  char	*div;
  int	i;
  int	pos;
  int	prevpos;
};

typedef struct s_stock_char t_stock_char;

char	 *divinf(char *nbr, char *div);
#endif
