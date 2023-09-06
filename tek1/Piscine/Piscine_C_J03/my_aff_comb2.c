/*
** my_aff_comb2.c for my_aff_comb2 in /home/baris_f/rendu/Piscine_C_J03
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Wed Sep 30 13:00:11 2015 Florent Baris
** Last update Wed Oct  4 12:45:46 2017 baris_f
*/

int	my_compchaar(int thousand, int hundred, int decade, int unit)
{
      my_putchar(thousand);
      my_putchar(hundred);
      my_putchar(' ');
      my_putchar(decade);
      my_putchar(unit);
      if (thousand == '9' && hundred == '8' && decade == '9' && unit == '9')
	{

	}
      else
	{
	  my_putchar(',');
	  my_putchar(' ');
	}
  return (0);
}

int	init(int *thousand, int *hundred, int *decade, int *unit)
{
  if (*unit <='8')
    {
      *unit = *hundred + 1;
      *decade = *thousand;
    }
  else
    {
      *decade = *thousand + 1;
      *unit = '0';
    }
  return (0);
}

int	itteration(int thousand, int hundred, int decade, int unit)
{
  while (decade <= '9')
    {
      while (unit <= '9')
	{
	  my_compchaar(thousand, hundred, decade, unit);
	  unit++;
	}
      unit = '0';
      decade++;
    }
  return (0);
}

int	my_aff_comb2()
{
  int	thousand;
  int	hundred;
  int	decade;
  int	unit;

  thousand = '0';
  hundred = '0';
  decade = '0';
  unit = '0';
  while (thousand <= '9')
    {
      hundred = '0';
      while (hundred <= '9')
        {
          init(&thousand, &hundred, &decade, &unit);
          itteration(thousand, hundred, decade, unit);
	  hundred++;
	}
      thousand++;
    }
  return (0);
}
