/*
** my_put_nbr.c for my_put_nbr in /home/baris_f/rendu/Piscine_C_J03
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Wed Sep 30 16:02:29 2015 Florent Baris
** Last update Fri Oct  9 12:45:53 2015 Florent Baris
*/

int     my_put_nbr (int nb)
{
  if (nb == -2147483648)
    {
      write(1, "-2147483648", 11);
      return (0);
    }
  if (nb < 0)
    {
      my_putchar('-');
      nb *= -1;
    }
  if (nb > 10 - 1)
    my_put_nbr(nb / 10);
  my_putchar(nb % 10 + '0');
  return (nb);
}
