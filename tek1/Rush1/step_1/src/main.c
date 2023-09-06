/*
** main.c for main in /home/baris-f/rendu/Rush1
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sat Jan  9 12:09:54 2016 Florent Baris
** Last update Sun Jan 10 23:25:40 2016 Florent Baris
*/

#include "my.h"

char	*get_name(char *str)
{
  int   i;
  int   j;

  j = 0;
  i = 0;
  while (str[i])
    {
      if (str[i] == '/')
	j = i;
      i++;
    }
  if (j == 0)
    return (str);
  j++;
  i = 0;
  while (str[j - 1] != '\0')
    str[i++] = str[j++];
  return (str);
}

void	fill(int ac, char *file, FILE *ar)
{
  FILE	*cur;
  int	max;
  int	j;

  j = -1;
  if ((cur = fopen(file, "r")) == NULL)
    {
      perror("fopen failed");
      return ;
    }
  fseek(cur, 0, SEEK_END);
  max = ftell(cur);
  fprintf(ar, "%s|%d\n", get_name(file), max);
  rewind(cur);
  while (++j < max)
    fputc(fgetc(cur), ar);
  printf("%s archived\n", file);
  fclose(cur);
}

int	main(int ac, char **av)
{
  FILE	*ar;
  int	i;

  i = 1;
  if (ac <= 2)
    {
      printf("Usage:./my_archive archive [file1..fileN]\n");
      return (-1);
    }
  if ((ar = fopen(av[1], "wb")) == NULL || (ar = fopen(av[1], "a")) == NULL)
    {
      perror("fopen failed");
      exit(0);
    }
 while (++i < ac)
  fill(ac, av[i], ar);
  fclose(ar);
}
