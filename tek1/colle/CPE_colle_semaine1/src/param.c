/*
** param.c for tree in /home/baris-f/rendu/colle/CPE_colle_semaine1
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Wed Apr 27 15:55:30 2016 Florent Baris
** Last update Wed Apr 27 17:43:41 2016 Florent Baris
*/

#include "tree.h"

int	usage()
{
  my_putstr("usage: tree [-acdfghilnpqrstuvxACDFJQNSUX] [-H baseHREF] ");
  my_putstr("[-T title ]\n");
  my_putstr("\t[-L level [-R]] [-P pattern] [-I pattern] [-o filename]");
  my_putstr("[--version]\n");
  my_putstr("\t[--help] [--inodes] [--device] [--noreport] [--nolinks] ");
  my_putstr("[--dirsfirst]\n");
  my_putstr("\t[--charset charset] [--filelimit[=]#] [--si] ");
  my_putstr("--timefmt[=]<f>]\n");
  my_putstr("\t[--sort[=]<name>] [--matchdirs] [--ignore-case] [--] ");
  my_putstr("[<directory list>]\n");
  return (0);
}

int	check_param(t_tree *tree, char c)
{
  if (c == 'a')
    tree->param[0] = 1;
  else if (c == 'd')
    tree->param[1] = 1;
  else if (c == 'L')
    tree->param[2] = 1;
  else if (c == 'f')
    tree->param[3] = 1;
  else
    {
      if (my_putstr("tree: Invalid argument - `") == -1)
	return (-1);
      my_putchar(c);
      my_putstr("'.\n");
      usage();
      return (-1);
    }
  return (0);
}

int     param(t_tree *tree, int ac, char **av)
{
  int   i;
  int   j;

  tree->path = NULL;
  i = 0;
  while (++i < ac)
    if (av[i][0] != '-')
      tree->path = av[i];
    else if (my_strlen(av[i]) > 1)
      {
	j = 0;
	if (av[i][0] == '-')
	  {
	    if (av[i][1] == '-' && (*av[i] += 2) != -1)
	      {
		if (my_strcmp(av[i], "charset=ASCII"))
		  tree->param[4] = 1;
	      }
	    else
	      while (av[i][++j])
		if (check_param(tree, av[i][j]) == -1)
		  return (-1);
	  }
      }
  return (0);
}
