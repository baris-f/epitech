/*
** my_ls.c for my_ls in /home/baris-f/rendu/PSU_2015_my_ls
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Tue Nov 24 11:07:08 2015 Florent Baris
** Last update Thu Dec  3 00:17:26 2015 Florent Baris
*/

#include <fcntl.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include "my_ls.h"

void	push(t_chaine **list, char *name);
void	lopt(char *path);
void	my_ls(char *path, int arg);
void	recur(t_chaine *list, int arg, char *path);

void	my_show_list(t_chaine *list, int arg, char *path)
{
  t_chaine *tmp;
  struct stat   info;

  tmp = list;
  while (tmp != NULL)
    {
      if (arg & 0b100000)
	{
	  if (arg & 0b10)
	    lopt(".");
	  my_printf(".\n");
	  exit(0);
	}
      if (arg & 0b10)
	lopt(tmp->name);
      my_printf("%s\n", tmp->name);
      tmp = tmp->next;
    }
  if (arg & 0b100)
    recur(list, arg, path);
}

void		my_ls(char *path, int arg)
{
  DIR		*dir;
  struct dirent	*ent;
  struct stat	info;
  t_chaine	*list;

  stat(path, &info);
  if (arg & 0b100 && S_ISDIR(info.st_mode))
    my_printf("%s:\n", path);
  list = NULL;
  if ((dir = opendir(path)) == NULL)
    {
      if (stat(path, &info) == -1)
	my_printf("my_ls: cannot access %s: No such file or directory\n", path);
      else
	my_printf("%s\n", path);
      return ;
    }
  while (ent = readdir(dir))
    if (ent->d_name[0] != '.' || arg & 0b1)
      push(&list, ent->d_name);
  if (list == NULL)
      return ;
  if (arg & 0b1000)
    my_rbubble(list);
  else
    my_bubble(list);
  my_show_list(list, arg, path);
}

void	add_arg(char *str, int *arg)
{
  int	i;

  i = 0;
  while (str[++i])
    {
      (str[i] == '1') ? 0 :
      (str[i] == 'a') ? ((*arg & 0b1) ? 0 : (*arg += 0b1)) :
      (str[i] == 'l') ? ((*arg & 0b10) ? 0 : (*arg += 0b10)) :
      (str[i] == 'R') ? ((*arg & 0b100) ? 0 : (*arg += 0b100)) :
      (str[i] == 'r') ? ((*arg & 0b1000) ? 0 : (*arg += 0b1000)) :
      (str[i] == 't') ? ((*arg & 0b10000) ? 0 : (*arg += 0b10000)) :
      (str[i] == 'd') ? ((*arg & 0b100000) ? 0 : (*arg += 0b100000)) :
      (exit(my_printf("my_ls: invalid option -- '%c'\n", str[i])));
    }
}

int	main(int ac, char **av)
{
  int	arg;
  int   i;
  int	ls;

  ls = 0;
  arg = 0;
  i = 0;
  while (av[++i])
      if (av[i][0] == '-')
	add_arg(av[i], &arg);
  i = 0;
  if (ac == 1)
    my_ls(".", arg);
  else
    while (av[++i])
      if (av[i][0] != '-')
	{
	  my_ls(av[i], arg);
	  ls = 1;
	}
  if (ls == 0 && ac != 1)
    my_ls(".", arg);
  return (0);
}

void	push(t_chaine **list, char *name)
{
  t_chaine *temp;

  temp = malloc(sizeof(t_chaine));
  temp->name = name;
  temp->next = *list;
  *list = temp;
}
