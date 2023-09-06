/*
** 42s.h for 42sh in /home/dudu/rendu/PSU_2015_42sh
**
** Made by lucas duval
** Login   <duval_m@epitech.net>
**
** Started on  Tue May 10 08:51:11 2016 lucas duval
** Last update	Mon Jun 06 15:25:28 2016 Aurélien Toussaint
*/

#ifndef H42S_H_
# define H42S_H_
# define _DEFAULT_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

#define	OP_SIZE	7

#define 	VERIF(v, t)	(base->cmdt[v] && base->cmdt[v] == t)

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define CYAN "\033[1;36m"
# define BLUE "\033[1;34m"
# define YELLOW "\033[0;33m"
# define PURPLE "\e[0;35m"
# define PWD "\033[0;94m"
# define UNDERLINED "\033[04m"
# define NORMAL "\033[00m"

typedef		struct s_ptr
{
  char		*op;
  int		(*fct)();
}		t_ptr;

typedef struct	s_ast
{
  char		*cur;
  struct s_ast	*right;
  struct s_ast	*left;
}		t_ast;

typedef struct	s_42
{
  char		**env;
  int		nb_env;
  int		idx;
  char		*cmd;
  char		*cmdt;
  t_ast		*ast;
  char          **argv;
  int           status;
  int           pid;
  t_ptr		*opt;
  int		redir;
  int		fd[2];
  char		*file;
  int		ret;
  int		i[3];
}		t_42;

typedef struct  s_fonc
{
  char          *name;
  int           (*func)(t_42 *);
}               t_fonc;

t_ptr		*ope();
int		what_ope(char*, char*);
int		doast(t_ast*, t_ptr*, t_42*);
t_ast		*build_ast(char*, t_ast*, t_42*);
int		prompt(t_42*);
char		*epur_str(char*);
int		init(t_42*, char**);
int		welcome(t_42*);
void		free_tab(char**);
void		print_tab(char**);
int		print_err(int);
int		count_env(char**);
int		catch_signal();
int		leftredir(t_ast*, t_42*);
int		rightredir(t_ast*, t_42*);
int		d_rightredir(t_ast*, t_42*);
char		**my_str_to_wordtab(char *, char);
int		exec(t_42 *);
char		*getstr(char*, char**);
int		endpoint(t_ast*, t_42*);
int		intast(t_ast*, t_ptr*, t_42*);
int		env_builtin(t_42*);
int		print_env(t_42*);
int		check_env(t_42*, char*, char*);
int		del_env(t_42*, char*);
int		cd_builtin(t_42 *);
int		my_strncmp(char *, char *, int);
int		my_strncpy(char *, char *, int);
int		ex(t_42 *);
int		my_str_isnum(char *);
int             and(t_ast*, t_42*);
int             or(t_ast*, t_42*);
int             pipe_exec(t_ast*, t_42*);
int		echo_builtin(t_42*);
int		verif_cmdt6(t_42*, int);
int		verif_cmdt(t_42*, int);
int		intast(t_ast*, t_ptr*, t_42*);
int		exec_ast(t_ast*, t_ptr*, t_42*, int);
int		set_signal();
void		del_ast(t_ast*, int);
char		*check(t_42 *, char **);

#endif /* !H42S_H_ */
