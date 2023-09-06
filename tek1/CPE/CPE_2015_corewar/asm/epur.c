/*
** utls.c for asm in /home/dudu/rendu/CPE_2015_corewar/asm
**
** Made by lucas duval
** Login   <duval_m@epitech.net>
**
** Started on  Wed Mar 23 10:26:56 2016 lucas duval
** Last update Sun Mar 27 22:47:26 2016 lucas duval
*/

#include "my.h"

char    *delete_tab(char *str)
{
  int   i;
  int   j;
  int   len;
  char  *tmp;

  i = 0;
  j = 0;
  len = my_strlen(str);
  tmp = my_malloc(sizeof(char) * len);
  while (str[i])
    {
      if (str[i] != '\t')
	{
	  tmp[j++] = str[i];
	}
      else
	tmp[j++] = ' ';
      i++;
    }
  tmp[j] = '\0';
  return (tmp);

}

char    *delete_space (char *str)
{
  int   i;
  int   j;
  int   len;
  char  *tmp;

  i = 0;
  j = 0;
  len = my_strlen(str);
  tmp = my_malloc(sizeof(char) * len);
  while (str[i])
    {
      if (str[i] != ' ')
	{
	  tmp[j++] = str[i];
	  if (str[i + 1] == ' ')
	    tmp[j++] = ' ';
	}
      i++;
    }
  tmp[j] = '\0';
  return (tmp);
}

void	check_arg2(t_base *base, int i, int j, int sel)
{
  while (op_tab[++j].mnemonique != NULL &&
	        base->file[i].instruct[0] != NULL &&
	 my_strcmp(op_tab[j].mnemonique,
		   base->file[i].instruct[sel]) != 0);
  check_exist(j, base->file[i].idx);
  correct_arg(base, i, j);
}
