/*
** utils2.c for asm in /home/dudu/rendu/CPE_2015_corewar/asm
**
** Made by lucas duval
** Login   <duval_m@epitech.net>
**
** Started on  Fri Mar 25 08:55:33 2016 lucas duval
** Last update Sun Mar 27 21:45:09 2016 lucas duval
*/

#include "my.h"

void	*my_memset(char *str, int value, int size)
{
  int	i;

  i = -1;
  while (str[++i] && i < size)
    str[i] = value;
  return (str);
}

char    *get_filename(char *str)
{
  int   i;
  int   len;
  char  *name;

  i = my_strlen(str);
  while (str[--i] && str[i] != '/');
  i++;
  len = my_strlen(str + i);
  name = my_malloc(sizeof(char) * len);
  my_strncpy(name, str + i, len - 2);
  return (name);
}

char    *get_label(char *line)
{
  int   i;
  char  *label;

  i = 0;
  while (line[i] != ' ' && line[i] != '\0')
    i++;
  if (line[i - 1] == LABEL_CHAR)
    {
      label = my_malloc(sizeof(char) * (i + 1));
      label[0] = '\0';
      my_strncpy(label, line, i - 1);
      return (label);
    }
  return (NULL);
}

void    cut_line(t_base *base, int max)
{
  int   i;

  i = 1;
  while (++i < max)
    base->file[i].instruct = my_str_to_wordtab(base->file[i].line, ' ');
}
