#ifndef TREE_H_
# define TREE_H_

#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct	s_tree
{
  char	*path;
  int	*param;
}		t_tree;

int	mtree(t_tree *tree);
int     param(t_tree *tree, int ac, char **av);
int     my_strlen(char *str);
int     my_strcmp(char *src, char *cmp);
int     my_putchar(char c);
int     my_putstr(char *str);
#endif /* !TREE_H_ */
