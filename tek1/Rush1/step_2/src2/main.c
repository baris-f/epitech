/*
** main2.c for main2 in /home/baris-f/rendu/Rush1
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sat Jan  9 14:55:47 2016 Florent Baris
** Last update Sun Jan 10 23:34:37 2016 Florent Baris
*/

#include "my.h"

char	*gethead(char *head, FILE *ar, int opt, int *i)
{
  *i = -1;
  memset(head, '\0', 255);
  if (opt == 0)
    {
      while ((head[++(*i)] = fgetc(ar)) != '|' && head[*i] != '!')
	if (head[*i] == EOF)
	  {
	    fclose(ar);
	    return (0);
	  }
    }
  else
    while ((head[++(*i)] = fgetc(ar)) != '\n');
  return (head);
}

void	refill(char *head, FILE *ar, FILE *cur)
{
  int	i;

  memset(head, '\0', 255);
  i = -1;
  while ((head[++i] = fgetc(ar)) != '\n');
  i = -1;
  while (++i < atoi(head))
    fputc(fgetc(ar), cur);
}

int	testfile(char *head, FILE *ar, FILE *cur, char *file)
{
  int	i;

  if (gethead(head, ar, 0, &i) == NULL)
    return (0);
  printf("%s unarchived\n", head);
  if (head[i] == '!')
    {
      head[i] = '\0';
      mkdir(head, 0755);
      strcat(file, "/");
      strcat(file, head);
      gethead(head, ar, 1, &i);
      i = atoi(head);
      while (--i > 0)
	testfile(head, ar, cur, file);
    }
  else
    {
      head[i] = '\0';
      ((cur = fopen(head, "wb")) == NULL) ? (perror("fopen failed")) : 0;
      ((cur = fopen(head, "wb")) == NULL) ? exit(0) : 0;
      refill(head, ar, cur);
    }
  return (1);
}

int	main(int ac, char **av)
{
  FILE  *ar;
  FILE	*cur;
  char	head[255];
  char	file[255];

  if (ac != 2)
    return (write(1, "Usage:./my_unarchive archive\n", 29) * 0 - 1);
  if ((ar = fopen(av[1], "rb")) == NULL)
    {
      perror("fopen failed");
      exit(0);
    }
  memset(file, '\0', 255);
  strcat(file, ".");
  while (1)
    if (testfile(head, ar, cur, file) == 0)
      return (0);
}
