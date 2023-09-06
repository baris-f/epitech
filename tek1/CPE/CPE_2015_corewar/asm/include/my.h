/*
** my.h for asm in /home/dudu/rendu/CPE_2015_corewar/asm/include
**
** Made by lucas duval
** Login   <duval_m@epitech.net>
**
** Started on  Tue Mar 15 11:07:57 2016 lucas duval
** Last update Sun Mar 27 22:49:28 2016 lucas duval
*/
#ifndef MY_H_
# define MY_H_

#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include "op.h"

typedef struct	s_key
{
  char		*name;
  int		value;
}		t_key;

typedef struct	s_file
{
  char	*line;
  int	idx;
  char	**instruct;
  char	**arg;
  char	*label;
  int	len;
}		t_file;

typedef struct	s_base
{
  t_key		*keys;
  char		*filename;
  t_file	*file;
  header_t	header;
  int		fd;
  int		newfd;
}		t_base;

char    *delete_tab(char *str);
char    *delete_space (char *str);
int	match(char *s1, char *s2);
int	my_strlen(char *);
char	*my_strncpy(char *, char *, int);
void    my_printf(char *str, ...);
char	*get_next_line(int);
int	my_strcmp(char *, char *);
void    *my_malloc(unsigned int size);
void    *my_memset(char *str, int value, int size);
char	*get_filename(char *);
int	trait(t_base *);
char	**my_str_to_wordtab(char *, char);
int	count_arg(char **);
char	**recuparg(char *, char);
void	cut_line(t_base *, int);
char	*get_label(char *);
void	get_arg(t_base *, int);
void	check_arg(t_base *, int, int, int);
void	ordre(t_base *, int *);
int	check_label(char *, char *);
void	check_exist(int, int);
void	correct_arg(t_base *, int, int);
void	check_arg2(t_base *, int, int, int);

#endif /* !MY_H_ */
