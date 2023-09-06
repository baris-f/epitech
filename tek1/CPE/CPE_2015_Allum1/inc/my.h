#ifndef MY_H_
# define MY_H_

#include <unistd.h>

char	*get_next_line(const int fd);
int	my_getnbr(char *str);
int	my_str_isnum(char *str);
void	my_printf(char *str, ...);
void	my_swap(int *a, int *b);
int     my_sq(int nb, int result);
void    my_memset(char *str, char c, int size);
char    *my_strdup(char *src);
void    my_puthexa(unsigned int nbr, char *base, char *bases, char x);
void    my_puthexal(long nbr, char *base);
int     get_larg(char *s, int *i);
int     my_puto(int nbr, char *base, int i, int getlen);
void    my_putS(char *s);
int     my_nbrlenu(unsigned int nbr);
void    my_putu(unsigned int nb);
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
