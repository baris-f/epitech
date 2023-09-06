/*
** main2.c for main2 in /home/baris-f/rendu/Rush1
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sat Jan  9 14:55:47 2016 Florent Baris
** Last update Sun Jan 10 23:30:46 2016 Florent Baris
*/

#include "my.h"

void     tfile(char *head, FILE *ar, FILE *cur)
{
  int	i;

  i = -1;
  memset(head, '\0', 255);
  while ((head[++i] = fgetc(ar)) != '|')
    if (head[i] == EOF)
      {
	fclose(ar);
	return ;
      }
  head[i] = '\0';
  printf("%s unarchived\n", head);
  if ((cur = fopen(head, "wb")) == NULL)
    {
      perror("fopen failed");
      exit (0);
    }
  memset(head, '\0', 255);
  i = -1;
  while ((head[++i] = fgetc(ar)) != '\n');
  i = -1;
  while (++i < atoi(head))
    fputc(fgetc(ar), cur);
}

int	main(int ac, char **av)
{
  FILE  *ar;
  FILE	*cur;
  char	head[255];
  int	i;

  if (ac != 2)
    return (write(1, "Usage:./my_unarchive archive\n", 29) * 0 - 1);
  if ((ar = fopen(av[1], "rb")) == NULL)
    {
      perror("fopen failed : \n");
      return (-1);
    }
  while (1)
    tfile(head, ar, cur);
}
