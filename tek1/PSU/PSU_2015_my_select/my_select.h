#ifndef MY_SELECT_H_
# define MY_SELECT_H_

#include <ncurses.h>

typedef struct s_info
{
  char  *name;
  int   hlight;
} t_info;

typedef struct s_size
{
  int	row;
  int   col;
  int   trow;
  int   tcol;
  int   lcol;
} t_size;

typedef struct s_all
{
  int		i;
  int		j;
  int		key;
  int		row;
  int		col;
  int		cur;
  t_info        *tab;
  int		tmp;
  int		max;
  int		nb_col_full;
  int		nb_elem_last_col;
  int		lmax;
  char		*search;
  int		nb_ocur;
  int		selected;
  FILE		*file;
  SCREEN	*screen;
} t_all;

int             my_printf(char *s, ...);
int             my_strlen(char *str);
int             isprintable(char c);
void            my_putchar(char c);
char            *my_strdup(char *src);
int     matchselect(char *s1, char *s2);
void    controls(t_all *s);
int     keyexit(t_all *s);
void    aff(t_all *s);
char    *my_strcat(char *dest, char *src);
int     recmatch(char *s1, char *s2);
void    search(t_all *s);
void    opt(t_all *s);

#endif /* !MY_SELECT_H_ */
