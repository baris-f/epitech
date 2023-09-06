/*
** main.c for main in /home/baris_f/rendu/Piscine_C_colles-Semaine_03
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sat Oct 24 15:50:13 2015 Florent Baris
** Last update Sat Oct 24 20:14:46 2015 Tandrayen Anil
*/

#include <unistd.h>
# define BUFF_SIZE (4096)

int	mycheck_colle3(char *buff)
{
  int	i;

  i = my_strlen(buff);
  if (buff[i - 2] == 'C')
    return (4);
  else if (buff[i - 2] == 'A')
    return (5);
}

int	what_is_this_glue(char *buff)
{
  int	i;
  int	r;

  i = 0;
  if (buff[0] == 'o')
    r = count_colle_1(buff);
  else if (buff[0] == '/' || buff[i] == '*')
    r = count_colle_2(buff);
  else if (buff[i] == 'A')
    {
      while (buff[++i] == 'B');
      if (buff[i] == 'A')
	r = count_colle_3(buff, 3, 0, 0);
      else if (buff[i] == 'C')
	r = count_colle_3bis(buff, mycheck_colle3(buff));
    }
  else if (buff[0] == 'B')
    r = count_colle_3(buff, 3, 4, 5);
  else
    my_putstr("aucune\n");
  if (r == 1)
    my_putstr("aucune\n");
  return (0);
}

int	main(int ac, char **av)
{
  char	buff[BUFF_SIZE + 1];
  int	len;
  int	i;

  i = 0;
  while (i < 10000000)
    i++;
  while ((len = read(0, buff, BUFF_SIZE)) > 0)
    {
      if (len != 0)
	{
	  buff[len] = 0;
	  what_is_this_glue(buff);
	}
    }
  return (0);
}
