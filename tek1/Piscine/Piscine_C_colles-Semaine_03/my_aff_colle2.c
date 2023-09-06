/*
** my_aff_colle2.c for my_aff_colle2 in /home/baris_f/rendu/Dansloriginal
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sat Oct 24 22:56:49 2015 Florent Baris
** Last update Sat Oct 24 22:56:51 2015 Florent Baris
*/

void	aff_colle2(int x, int y)
{
  my_putstr("[colle1-2] ");
  my_put_nbr(x);
  my_putchar(' ');
  my_put_nbr(y);
  my_putchar('\n');
}

int	check_colle2(char *buff)
{
  int	x;
  int	i;
  int	len;

  x = 0;
  i = 0;
  len = my_strlen(buff);
  while (buff[i])
    {
      if (buff[i] == '*' || buff[i] == ' ' || buff[i] == '/'
	  || buff[i] == '\\' || buff[i] == '\n')
	x++;
      i++;
    }
  if (i != len)
    return (1);
  return (0);
}

int	count_colle_2(char *buff)
{
  int	i;
  int	x;
  int	y;

  i = 0;
  x = 0;
  while (buff[i++] != '\n')
    x++;
  y = 0;
  i = 0;
  while (buff[i++])
    {
      if (buff[i] == '\n')
	y++;
    }
  if (check_colle2(buff) == 1)
    return (1);
  aff_colle2(x, y);
  return (0);
}
