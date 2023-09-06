/*
** my.h for my in /home/baris-f/rendu/PSU/PSU_2015_minishell1
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sun Jan 24 22:19:56 2016 Florent Baris
** Last update Sun Jan 31 23:24:27 2016 Florent Baris
*/

#ifndef MY_H_
# define MY_H_

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

typedef struct	s_list
{
  char	*env_name;
  char	*env_variable;
  struct s_list *prec;
}		t_env ;

typedef struct s_min
{
  char	*cmd;
  char	**argv;
  t_env	*env;
  char	*user;
  char	*path;
  char	*oldpath;
  int	ret;
  int	status;
  int	cur;
  char	buffer[4096];
  pid_t	pid;
  pid_t	wpid;
}	t_min;

int	my_getnbr(char *str);
int	isalph(char c);
void	freee(t_min *ishell);
void    cd(t_min *ishell, char **argv);
void    get_env(t_min *ishell, char **env);
void    unsetenv(t_min *ishell, char *argv);
void    make_env(t_min *ishell, char **env);
char    *get_var(t_min *ishell, char *var);
void    getuser(t_min *ishell);
void    my_memset(char *str, char c, int size);
void    handle_exit_signal(int status);
void    set_signal(void);
void    sign();
void    own_command(t_min *ishell, char **argv);
void    check_cmd(t_min *ishell, char **env);
void    check(t_min *ishell);
void    checko(t_min *ishell);
char**	my_str_to_wordtab(char*);
char	*my_strncpy(char *, char *, int);
void    get_env(t_min *ishell, char **env);
void    getuser(t_min *ishell);
void    set_signal(void);
void    getcmd(t_min *ishell);
int	my_strlen(char *);
void	my_printf(char *, ...);
char	*my_strcpy(char *, char *);
char	*my_strcat(char *, char *);
int	my_strcmp(char *, char *);
int     my_strncmp(char *s1, char *s2, int n);
void    handle_exit_signal(int status);
void            push(t_env **p, char *name, char *var);
void            clear(t_env **p);
int             length(t_env *p);
void            view(t_env *p);
char	*my_strdup(char *);

#endif /* !MY_H_ */
