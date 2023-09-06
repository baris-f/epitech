/*
** colle1-3.c for colle1-3 in /home/baris_f/rendu/Piscine_C_colles-Semaine_01
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sat Oct  3 14:42:48 2015 Florent Baris
** Last update Sat Oct 24 17:17:24 2015 Florent Baris
*/

int	my_putchar(char c)
{
  write(1, &c, 1);
}

int	exeption_third(int x, int y)
{
  int   line;
  int   column;

  line = 1;
  while (line <= y)
    {
      column = 1;
      while (column <= x)
        {
	  my_putchar('B');
          column++;
        }
      my_putchar('\n');
      line++;
    }
}

int	display_third(int x, int y)
{
  int	line;
  int	column;

  line = 1;
  while (line <= y)
    {
      column = 1;
      while (column <= x)
        {
          if (line == 1 && (column == 1 || column == x))
            my_putchar('A');
          if ((line == y && (column == 1 || column == x)))
            my_putchar('C');
          if ((column == 1 || column == x) && line > 1  && line < y)
            my_putchar('B');
          if ((line == 1 || line == y) && column > 1 && column < x)
            my_putchar('B');
          if (line > 1 && line < y && column > 1 && column < x)
            my_putchar(' ');
          column++;
        }
      my_putchar('\n');
      line++;
    }
}

int	colle3(int x, int y)
{
  if (x <= 0 || y <= 0)
    {
      my_putchar('\n');
      return (0);
    }
  if (x == 1 || y == 1)
    exeption_third(x, y);
  else
    display_third(x, y);
}

int	main(int ac, char **av)
{
  colle3(my_getnbr(av[1]),my_getnbr(av[2]));
  return (0);
}
