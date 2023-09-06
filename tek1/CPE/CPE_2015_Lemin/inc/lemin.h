/*
** lemin.h for zdko in /home/fus/rendu/cpe/CPE_2015_lemin/inc
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Thu Mar 31 15:34:01 2016 Gaspard Thirion
** Last update Mon Apr 25 19:55:07 2016 Florent Baris
*/

#ifndef LEMIN_H_
# define LEMIN_H_

#include "my.h"

typedef struct	s_2D
{
  int		x;
  int		y;
}		t_2D;

typedef struct s_ret
{
  int		*path;
  int		len;
}		t_ret;

typedef struct	s_node
{
  char		*name;
  t_2D		pos;
  int		mem;
  int		nb_link;
  int		*link;
}		t_node;

typedef struct	s_base
{
  t_node	*node;
  t_ret		*ret;
  int		nb_node;
  int		nb_path;
  int		start;
  int		end;
  int		nb_four;
  int		*room;
  t_2D		*four;
  char		*line;
}		t_base;

char	**my_str_to_wordtab(char *, char);
void	*my__realloc(void *,size_t, size_t);
char	*get_next_line(int);
int	match(char *, char *);
int	path(t_base *, int, int);
void	ordre(t_base *);
int	trait(t_base *);
void	print_debug(t_base *);
int	get_line(t_base *);
int	error(t_base *);
int	trait_err(int);
int	final(t_base *);
int	my_str_isnum(char *);
int	my_getnbr(char *);
int     notended(t_base *base);
void    sort(t_base *base);
void    setk(t_base *base, int i, int j, int k);
void    aff(int four, int room, int reset);
void	print_all(t_base *);
#endif /* !LEMIN_H_ */
