/*
** cd.c for cd in /home/baris-f/rendu/PSU/PSU_2015_minishell1
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sun Jan 24 22:17:15 2016 Florent Baris
** Last update Sun Apr 10 02:43:50 2016 Florent Baris
*/

#include "my.h"

void	cd_dotdot(char *str)
{
  int	i;

  i = my_strlen(str) - 1;
  while (str[--i] != '/' && i > 0);
  str[i] = '\0';
}

void	new_pwd(t_min *ishell, char **pwd)
{
  t_env *tmp;

  tmp = ishell->env;
  while (tmp)
    {
      if (my_strcmp(tmp->env_name, "PWD") == 0)
	{
	  free(tmp->env_variable);
	  tmp->env_variable = malloc(sizeof(char)
				     * my_strlen(*pwd) + 1);
	  my_strcpy(tmp->env_variable, *pwd);
	  return ;
	}
      tmp = tmp->prec;
    }
}

void	get_pwd(t_min *ishell, char **pwd)
{
  t_env *tmp;
  t_env	*start;

  tmp = ishell->env;
  start = ishell->env;
  while (tmp)
    {
      if (my_strcmp(tmp->env_name, "PWD\0") == 0)
	{
	  *pwd = malloc(sizeof(char) * my_strlen(tmp->env_variable) + 2);
	  my_strcpy(*pwd, tmp->env_variable);
	  return ;
	}
      tmp = tmp->prec;
    }
  ishell->env = start;
}

char	*casecd(char **argv, char *pwd)
{
  char *newpwd;

  if (my_strncmp(argv[1], "..", 2) == 0)
    {
      newpwd = malloc(sizeof(char) * (my_strlen(pwd) + my_strlen(argv[1])));
      my_strcpy(newpwd, pwd);
      cd_dotdot(newpwd);
      my_strcat(newpwd, "/");
      my_strcat(newpwd, argv[1] + 3);
    }
  else
    {
      newpwd = malloc(sizeof(char) * (my_strlen(pwd) + my_strlen(argv[1])));
      my_strcpy(newpwd, pwd);
      my_strcat(newpwd, "/");
      my_strcat(newpwd, argv[1]);
    }
  return (newpwd);
}

void	cd(t_min *ishell, char **argv)
{
  char	*pwd;
  char	*newpwd;

  pwd = get_var(ishell, "PWD");
  if (argv[1] == NULL)
    {
      newpwd = malloc(sizeof(char) * (6 + my_strlen(ishell->user)));
      my_strcat(newpwd, "/");
      my_strcat(newpwd, "home/");
      my_strcat(newpwd, ishell->user);
    }
  else if (argv[1][0] == '/')
    {
      newpwd =  malloc(sizeof(char) * (my_strlen(argv[1])));
      my_strcat(newpwd, argv[1]);
    }
  else
    newpwd = casecd(argv, pwd);
  if (chdir(newpwd) == -1)
    my_printf("cd error\n");
  else
    new_pwd(ishell, &newpwd);
  free(newpwd);
}
