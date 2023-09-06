/*
** main.c for main in /home/baris-f/rendu/Rush1
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sat Jan  9 12:09:54 2016 Florent Baris
** Last update Sun Jan 10 23:22:25 2016 Florent Baris
*/

#include "my.h"

char	*get_name(char *st)
{
  int   i;
  int   j;
  char	*str;

  str = strdup(st);
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

void	filldir(char *file, FILE *ar)
{
  DIR	*dir;
  struct dirent *ent;
  int	max;
  char	tmp[255];

  if (file[strlen(file) - 1] == '/')
    file[strlen(file) - 1] = '\0';
  if ((dir = opendir(file)) == NULL)
    return (perror("opendir failed "));
  max = -2;
  while ((ent = readdir(dir)) && max++);
  fprintf(ar, "%s!%d\n", get_name(file), max);
  closedir(dir);
  if ((dir = opendir(file)) == NULL)
    return (perror("second opendir failed "));
  while (ent = readdir(dir))
    {
      memset(tmp, '\0', 255);
      strcat(tmp, file);
      strcat(tmp, "/");
      strcat(tmp, ent->d_name);
      if (ent->d_name[0] != '.' && ent->d_name[strlen(ent->d_name) - 1] != '.');
	fill(tmp, ar);
    }
  printf("%s archived\n", file);
}

void	fill(char *file, FILE *ar)
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
  if (max == -1)
    (file[0] != '.' && file[strlen(file) - 1] != '.') ? (filldir(file, ar)) : 0;
  else
    {
      fprintf(ar, "%s|%d\n", get_name(file), max);
      rewind(cur);
      while (++j < max)
	fputc(fgetc(cur), ar);
      printf("%s archived\n", file);
    }
  fclose(cur);
}

int	main(int ac, char **av)
{
  DIR   *dir;
  struct dirent *ent;
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
  fill(av[i], ar);
 fclose(ar);
}
