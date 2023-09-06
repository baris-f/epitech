/*
** sum_params.c for sum_params in /home/baris_f/rendu/Piscine_C_J08/ex_02
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Wed Oct  7 10:17:48 2015 Florent Baris
** Last update Wed Oct  7 11:20:14 2015 Florent Baris
*/

#include<stdlib.h>

char	*sum_params(int argc, char **argv)
{
  int	i;
  int	t_len;
  char	*str;

  t_len = 0;
  i = 0;
  while (argv[i])
    {
      t_len += my_strlen(argv[i]);
      i++;
    }
  t_len += argc;
  str = malloc(t_len);
  i = 0;
  while (i < argc)
    {
      my_strcat(str, argv[i]);
      my_strcat(str, "\n");
      i++;
    }
  str[t_len - 1] = '\0';
  return (str);
}
