/*
** my_aff_colle3.c for my_aff_colle3 in /home/baris_f/rendu/Dansloriginal
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sat Oct 24 22:58:02 2015 Florent Baris
** Last update Sat Oct 24 23:08:13 2015 Florent Baris
*/

void	norme_andie(int x, int y)
{
  my_put_nbr(x);
  my_putchar(' ');
  my_put_nbr(y);
  my_putchar(' ');
}

void	aff_colle3(int x, int y, int colle, int pipe)
{
  if (colle == 3)
    {
      my_putstr("[colle1-3] ");
      norme_andie(x, y);
    }
  if (pipe == 1)
    my_putstr("|| ");
  if (colle == 4)
    {
      my_putstr("[colle1-4] ");
      norme_andie(x, y);
    }
  if (pipe == 2)
    my_putstr("|| ");
  if (colle == 5)
    {
      my_putstr("[colle1-5] ");
      norme_andie(x, y);
    }
}

int	check_colle3(char *buff)
{
  int	x;
  int	i;
  int	len;

  x = 0;
  i = 0;
  len = my_strlen(buff);
  while (buff[i])
    {
      if (buff[i] == 'A' || buff[i] == ' ' || buff[i] == 'B'
	  || buff[i] == 'C' || buff[i] == '\n')
	x++;
      i++;
    }
  if (i != len)
    return (1);
  return (0);
}

int	count_colle_3bis(char *buff, int colle)
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
  if (check_colle3(buff) == 1)
    return (1);
  aff_colle3(x, y, colle, 0);
  my_putchar('\n');
  return (0);
}

int	count_colle_3(char *buff, int c1, int c2, int c3)
{
  int	i;
  int	x;
  int	y;

  x = 0;
  while (buff[x++ + 1] != '\n');
  y = 0;
  i = 0;
  while (buff[i++])
      if (buff[i] == '\n')
	y++;
  if (check_colle3(buff) == 1)
    return (1);
  if (c1 == 3 && c2 == 4)
    aff_colle3(x, y, 3, 1);
  else if (c1 == 3 && c2 == 0 && c3 == 0)
    aff_colle3(x, y, 3, 0);
  if (c2 != 0 && c3 != 0)
    aff_colle3(x, y, 4, 2);
  else if (c2 != 0 && c3 == 0)
    aff_colle3(x, y, 4, 0);
  if (c3 != 0)
    aff_colle3(x, y, 5, 0);
  my_putchar('\n');
  return (0);
}
