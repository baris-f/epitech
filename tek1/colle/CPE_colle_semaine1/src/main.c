/*
** main.c for tree in /home/baris-f/rendu/colle/CPE_colle_semaine1
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Wed Apr 27 15:09:55 2016 Florent Baris
** Last update Wed Apr 27 17:35:13 2016 Florent Baris
*/

#include "tree.h"

int	init(t_tree *tree)
{
  int	i;

  if ((tree->param = malloc(sizeof(int) * 5)) == NULL)
    return (-1);
  i = -1;
  while (++i < 5)
    tree->param[i] = 0;
  return (0);
}

int	end(t_tree *tree)
{
  free(tree->param);
  return (0);
}

int		main(int ac, char **av)
{
  t_tree	tree;

  if (init(&tree) == -1)
    return (-1);
  if (param(&tree, ac, av) == -1)
    return (-1);
  if (tree.path == NULL)
    {
      if ((tree.path = malloc(sizeof(char) * 2)) == NULL)
	return (-1);
      tree.path[0] = '.';
      tree.path[1] = '\0';
    }
  mtree(&tree);
  end(&tree);
  return (0);
}
