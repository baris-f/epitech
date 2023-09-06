/*
** p4.h for p4 in /home/baris-f/rendu/colle/CPE_colle_semaine2
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Wed May  4 14:51:22 2016 Florent Baris
** Last update Wed May  4 18:06:31 2016 Florent Baris
*/

#ifndef P4_H_
# define P4_H_

#include <stdlib.h>
#include <unistd.h>
#include <time.h>

typedef struct  s_2D
{
  int	x;
  int	y;
}               t_2D;

typedef struct  s_p4
{
  char  *map;
  t_2D	size;
  char	p1;
  char	p2;
  char	end;
  char	ia;
}               t_p4;

typedef struct  s_tmp
{
  int   x;
  int   y;
  char  p1;
  char  p2;
  char  end;
  char  ia;
}               t_tmp;

int     param(t_p4 *p4, int ac, char **av);
int     my_strlen(char *str);
int     my_strcmp(char *src, char *cmp);
int     my_putchar(char c);
int     my_putstr(char *str);
int	power4(t_p4 *p4);
int     over(t_p4 *p4);
int     aff(t_p4 *p4);
int     check_param(t_p4 *p4, t_tmp *tmp);
int     init_tmp_param(t_p4 *p4, char **av, t_tmp *tmp, int i);
int 	check_arb(char a, t_p4 *p4);
int     check_avatar(t_p4 *p4, char a, char b);
int     check_nbr(int x, int y, t_p4 *p4);
int     my_getnbr(char *str);
void    my_putnbr(int nb);
int     ia(t_p4 *p4);
int     insert(t_p4 *p4, int nb, char p);

#endif /* !P4_H_ */
