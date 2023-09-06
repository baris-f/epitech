/*
** trait.c for asm in /home/dudu/rendu/CPE_2015_corewar/asm
**
** Made by lucas duval
** Login   <duval_m@epitech.net>
**
** Started on  Sun Mar 27 21:43:18 2016 lucas duval
** Last update Thu Mar 31 14:58:57 2016 Florent Baris
*/

#include "my.h"

int     trait3(t_base *base, int max, int i)
{
  cut_line(base, max);
  i = 1;
  while (++i < max)
    base->file[i].label = get_label(base->file[i].instruct[0]);
  get_arg(base, max);
  check_arg(base, max, 1, 0);
  i = 1;
  while (++i < max)
    if (base->file[i].label != NULL)
      if (check_label(base->file[i].label, LABEL_CHARS))
	{
	  my_printf("Error label on line %d\n", base->file[i].idx);
	  exit(1);
	}
  printf("Name: %s\nComment:%s\n", base->header.prog_name, base->header.comment);
  return (0);
}

int     trait2(t_base *base, int max, int i, int j)
{
  while (++i < max)
    {
      j = -1;
      while (base->file[i].line[++j] && base->file[i].line[j] != COMMENT_CHAR);
      base->file[i].line[j] = '\0';
    }
  ordre(base, &max);
  if (!match(base->file[0].line, ".name*"))
    {
      my_printf("%s.s line 1 : No name specified\n", base->filename);
      exit(1);
    }
  my_memset(base->header.prog_name, '\0' , PROG_NAME_LENGTH + 1);
  my_strncpy(base->header.prog_name, base->file[0].line + 7,
	     my_strlen(base->file[0].line) - 8);
  if (!match(base->file[1].line, ".comment*"))
    {
      my_printf("%s.s line 2 : No comment specified\n", base->filename);
      exit(1);
    }
  my_memset(base->header.comment, '\0' , COMMENT_LENGTH + 1);
  my_strncpy(base->header.comment, base->file[1].line + 10,
	     my_strlen(base->file[1].line) - 11);
  return (trait3(base, max, i));
}

int     trait(t_base *base)
{
  char  *line;
  int   i;
  int max;

  i = 0;
  base->file = my_malloc(sizeof(*base->file) * (i + 1));
  while ((line = get_next_line(base->fd)))
    {
      base->file[i++].line = line;
      base->file[i - 1].idx = i;
      base->file = realloc(base->file, sizeof(*base->file) *( i + 1));
    }
  max = i;
  while (--i >= 0)
    {
      base->file[i].line = delete_tab(base->file[i].line);
      base->file[i].line = delete_space(base->file[i].line);
    }
  return (trait2(base, max, i, 0));
}
