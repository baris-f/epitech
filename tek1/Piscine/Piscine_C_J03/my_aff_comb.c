/*
** my_aff_comb.c for my_aff_comb in /home/baris_f/rendu/Piscine_C_J03
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Wed Sep 30 10:17:19 2015 Florent Baris
** Last update Wed Oct  4 12:44:33 2017 baris_f
*/

int	my_combchar(int hundred, int decade, int unit)
{
  my_putchar(hundred);
  my_putchar(decade);
  my_putchar(unit);
  if (hundred == '7' && decade == '8' && unit == '9')
    {

    }
  else
    {
      my_putchar(',');
      my_putchar(' ');
    }
  return (0);
}

int	my_aff_comb()
{
  int	hundred;
  int	decade;
  int	unit;

  hundred = '0';
  decade = '1';
  unit = '2';
  while (hundred <= '7')
    {
      decade = hundred + 1;
      while (decade <= '8')
	{
	  unit  = decade + 1;
	  while (unit <= '9')
	    {
	      my_combchar(hundred, decade, unit);
	      unit++;
	    }
	  decade++;
	}
      hundred++;
    }
  return (0);
}
