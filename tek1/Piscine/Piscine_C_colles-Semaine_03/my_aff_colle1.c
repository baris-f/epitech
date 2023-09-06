/*
** my_aff_colle.c for my_aff_colle1 in /home/baris_f/rendu/Dansloriginal
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sat Oct 24 16:09:30 2015 Florent Baris
** Last update Sat Oct 24 22:38:31 2015 Florent Baris
*/

void	aff_colle1(int x, int y)
{
  my_putstr("[colle1-1] ");
  my_put_nbr(x);
  my_putchar(' ');
  my_put_nbr(y);
  my_putchar('\n');
}

int	check_colle1(char *buff)
{
  int	x;
  int	i;
  int	len;

  x = 0;
  i = 0;
  len = my_strlen(buff);
  while (buff[i])
    {
      if (buff[i] == 'o' || buff[i] == ' ' || buff[i] == '-'
	  || buff[i] == '|' || buff[i] == '\n')
	x++;
      i++;
    }
  if (i != len)
    return (1);
  return (0);
}

int	count_colle_1(char *buff)
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
  if (check_colle1(buff) == 1)
    return (1);
  aff_colle1(x, y);
  return (0);
}
