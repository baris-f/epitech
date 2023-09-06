/*
** my_putnbr_base.c for my_putnbr_base in /home/baris_f/rendu/Piscine_C_J06/ex_16
** 
** Made by Florent Baris
** Login   <baris_f@epitech.net>
** 
** Started on  Mon Oct  5 16:56:07 2015 Florent Baris
** Last update Mon Oct  5 21:58:44 2015 Florent Baris
*/

int	my_putnbr_base (int nbr, char *base)
{
  int	nb_base;

  nb_base = 0;
  while (base[nb_base])
    nb_base++;
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
  if (nbr > nb_base - 1)
      my_putnbr_base(nbr / nb_base, base);
  my_putchar(base[nbr % nb_base]);
  return (nbr);
}
