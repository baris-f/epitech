/*
** utils.c for asm in /home/dudu/rendu/CPE_2015_corewar/asm
**
** Made by lucas duval
** Login   <duval_m@epitech.net>
**
** Started on  Wed Mar 16 16:16:13 2016 lucas duval
** Last update Sun Mar 27 22:17:37 2016 lucas duval
*/

#include "my.h"

int	check_label(char *label, char *label_chars)
{
  int	i;
  int	j;
  int	ok;

  i = -1;
  while (label[++i])
    {
      j = -1;
      ok = 0;
      while (label_chars[++j])
	if (label[i] == label_chars[j])
	  ok = 1;
      if (ok == 0)
	return (1);
    }
  return (0);
}

int	check_name_len(char *name)
{
  if (my_strlen(name) > PROG_NAME_LENGTH)
    return (1);
  return (0);
}

int	check_comment_len(char *comment)
{
  if (my_strlen(comment) > COMMENT_LENGTH)
      return (1);
  return (0);
}

void	*my_malloc(unsigned int size)
{
  void	*ptr;

  ptr = malloc(size);
  if (ptr == NULL)
    {
      my_printf("Can't perform malloc\n");
      exit(0);
    }
  return (ptr);
}

void            ordre(t_base* base, int *nbval)
{
  int           i;
  int           permutation;
  int		j;

  permutation = 1;
  while (permutation == 1)
    {
      permutation = 0;
      i = -1;
      while (++i <= (*nbval - 1))
	if ((base->file[i].line[0] == '\0'
	     || my_strlen(base->file[i].line) == 0) && ((i + 1) <= *nbval))
	  {
	    j = i - 1;
	    while (++j <= (*nbval - 1))
	      base->file[j] = base->file[j + 1];
	    permutation = 1;
	    (*nbval)--;
	  }
    }
}
