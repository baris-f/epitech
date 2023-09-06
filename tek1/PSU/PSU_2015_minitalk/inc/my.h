#ifndef MY_H_
# define MY_H_

#include "my_printf.h"

int	my_getnbr(char *str);
int	my_power_rec(int, int);
void	my_printf(char *, ...);
void	my_swap(int *a, int *b);
int     my_sq(int nb, int result);
void    my_memset(char *str, char c, int size);
char    *my_strdup(char *src);
void    nbr(int nbr, t_stock_par t);
void    charr(int nbr, t_stock_par t);
void    char_star(char *str, t_stock_par t);
void    my_puthexa(unsigned int nbr, char *base, char *bases, char x);
void    my_puthexal(long nbr, char *base);
void    my_hexa(unsigned int nbr, t_stock_par t, char x);
int     get_larg(char *s, int *i);
void    adress(long nbr, t_stock_par t);
int     my_puto(int nbr, char *base, int i, int getlen);
void	octal(unsigned int nbr, t_stock_par t);
void    my_putS(char *s);
int     my_nbrlenu(unsigned int nbr);
void    my_putu(unsigned int nb);
void	my_u(unsigned int nbr, t_stock_par t);
int	my_nbrlen(int nb);
void	my_putchar(char c);
void	my_putstr(char *str);
void	my_put_nbr(int nb);
void    my_puthexal(long nbr, char *base);
int     my_putnbr_base (int nbr, char *base);
int	my_strlen(char *str);
int     my_is_prime(int nombre);
int     my_isprimerec(int nb, int i);
int     my_powerrec(int nb, int power, int result);

#endif /* !MY_H_ */
