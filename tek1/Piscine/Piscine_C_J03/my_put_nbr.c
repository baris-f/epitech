/*
** my_put_nbr.c for my_put_nbr in /home/baris_f/rendu/Piscine_C_J03
** 
** Made by Florent Baris
** Login   <baris_f@epitech.net>
** 
** Started on  Wed Sep 30 16:02:29 2015 Florent Baris
** Last update Thu Oct  1 20:13:55 2015 Florent Baris
*/

int	my_count(int nbr)
{
  int	i;
  int	nb_digit;

  i = 1;
  nb_digit = nbr;
  while (nb_digit > 9)
    {
      nb_digit = nb_digit / 10;
      ++i;
    }
  return (i);
}

int	my_pow(int i)
{
  int	pow;

  pow = 1;
  while (i > 1)
    {
      pow = pow * 10;
      --i;
    }
  return (pow);
}

int	my_put_nbr(int nbr)
{
  int	i;
  int	current_nbr;
  int	divisor;

  if (nbr == -2147483648)
    {
      write(1, "-2147483648", 11);
      return (0);
    }
  if (nbr < 0)
    {
      my_putchar('-');
      nbr *= -1;
    }
  i = my_count(nbr);
  while (i > 0)
    {
      divisor = my_pow(i);
      current_nbr = nbr / divisor;
      nbr -= current_nbr * divisor;
      my_putchar(current_nbr + '0');
      --i;
    }
  return (0);
}
