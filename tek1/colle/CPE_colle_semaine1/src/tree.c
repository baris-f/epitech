/*
** tree.c for tree in /home/baris-f/rendu/colle/CPE_colle_semaine1
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Wed Apr 27 16:00:22 2016 Florent Baris
** Last update Wed Apr 27 17:50:06 2016 Florent Baris
*/

#include "tree.h"

int	affdir(t_tree *tree, char *path, int nb)
{
  DIR           *dir;
  struct dirent *ent;

  (void)path;
  dir = opendir(tree->path);
  if (my_putstr("\e[01;34m") == -1)
    return (-1);
  my_putstr(tree->path);
  my_putstr("\e[01;0m");
  my_putchar('\n');
  while ((ent = readdir(dir)) != NULL)
    if (ent->d_name[0] != '.' || tree->param[0])
      {
	if (--nb > 0)
	  my_putstr("├");
	else
	  my_putstr("└");
	my_putstr("── ");
	my_putstr("\e[01;34m");
	my_putstr(ent->d_name);
	my_putchar('\n');
	my_putstr("\e[01;0m");
      }
  return (0);
}

int	initdir(t_tree *tree, char *path)
{
  DIR           *dir;
  struct dirent *ent;
  struct stat   info;
  int           nb;

  if (path == NULL)
    return (-1);
  if (stat(path, &info) == -1)
    my_putstr("cant open this directory\n");
  if (S_ISDIR(info.st_mode) != 1)
    return (-1);
  if ((dir = opendir(tree->path)) == NULL)
    {
      if (stat(path, &info) == -1)
	my_putstr("cant open this directory\n");
      return (-1);
    }
  nb = 0;
  while ((ent = readdir(dir)) != NULL)
    if (ent->d_name[0] != '.' || tree->param[0])
      nb++;
  closedir(dir);
  return (affdir(tree, path, nb));
}

int		mtree(t_tree *tree)
{
  if (initdir(tree, tree->path) == -1)
    return (-1);
  return (0);
}
