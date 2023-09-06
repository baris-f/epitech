/*
** my.h for my in /home/fus/rendu/PSU_2015_my_printf
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Sat Nov 21 08:33:28 2015 Gaspard Thirion
** Last update Sat Dec  5 12:21:04 2015 Gaspard Thirion
*/

#ifndef MY_H_
# define MY_H_

#include <stdarg.h>

typedef struct s_attr
{
  int	flag;
  int	len;
  char	compl;
  int	prec;
  char	hexa;
}		t_attr;

typedef struct s_fcts
{
  char	*chk;
  void	(*fct)();
}		t_fcts;

int	my_str_isalpha(char*);
int	my_strlen(char*);
int	my_nbrlen(int);
void	my_putchar(char);
void	my_putstr(char*);
void	my_put_nbr(int);
int	my_power_rec(int, int);
int	my_getnbr(char*);
void	my_putnbr_base(int, int, char);
void	my_putnbr_base_long(unsigned long, unsigned int, char);
void	my_strcat(char*, char*);
void	my_strcpy(char*, char*);
char	*my_strdup(char*);
int	my_strcmp(char*, char*);
void	chkflag(va_list, char*, int*, t_attr*);
void	chklen(va_list, char*, int*, t_attr*);
void	chkprec(va_list, char*, int*, t_attr*);
int	chkchar(char);
void	print_int(int, t_attr*);
void	print_str(char*, t_attr*);
void	print_char(int, t_attr*);
void	print_hex(unsigned int, t_attr*);
void	print_oct(unsigned int, t_attr*);
void	print_bin(unsigned int, t_attr*);
void	print_impr(char*, t_attr*);
void	print_point(unsigned long, t_attr*);
void	my_printf(char*, ...);

#endif /* !MY_H_ */
