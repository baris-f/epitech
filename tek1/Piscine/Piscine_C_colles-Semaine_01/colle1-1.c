/*
** colle1-3.c for colle1-3 in /home/baris_f/rendu/Piscine_C_colles-Semaine_01
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sat Oct  3 14:42:48 2015 Florent Baris
** Last update Sat Oct 24 17:17:36 2015 Florent Baris
*/

int	exeption_first(int x, int y)
{
  int   line;
  int   column;

  line = 1;
  while (line <= y)
    {
      column = 1;
      while (column <= x)
        {
	  if (column == 1 || column == x)
	    my_putchar('o');
	  else
	    my_putchar('-');
          column++;
        }
      my_putchar('\n');
      line++;
    }
}

int	display_first(int x, int y)
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
            my_putchar('o');
          if (line == y && (column == 1 || column == x))
            my_putchar('o');
          if ((column == 1 || column == x) && line > 1 && line < y)
            my_putchar('|');
          if ((line == 1 || line == y) && column > 1 && column < x)
            my_putchar('-');
          if (line > 1 && line < y && column > 1 && column < x)
            my_putchar(' ');
          column++;
        }
      my_putchar('\n');
      line++;
    }
}

int	colle(int x, int y)
{
  if (x <= 0 || y <= 0)
    {
      my_putchar('\n');
      return (0);
    }
  if (y == 1)
    exeption_first(x, y);
  else
    display_first(x, y);
}

/* int	main(int ac, char **av) */
/* { */
/*   colle(my_getnbr(av[1]),my_getnbr(av[2])); */
/*   return (0); */
/* } */
