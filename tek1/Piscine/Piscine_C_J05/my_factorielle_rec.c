/*
** my_factorielle_rec.c for my_factorielle_it in /home/baris_f/rendu/Piscine_C_J05
** 
** Made by Florent Baris
** Login   <baris_f@epitech.net>
** 
** Started on  Fri Oct  2 09:50:44 2015 Florent Baris
** Last update Tue Oct  6 15:16:53 2015 Florent Baris
*/

int     my_factorielle_rec(int nb)
{
  int result;

  result = 1;
  if (nb == 0)
    return (1);
  if (nb < 0)
    return (0);
  if (nb >= 13)
    return (0);
  result = my_rec(nb, result);
  return (result);
}

int	my_rec(int nb, int result)
{
  if (nb < 2)
    return (result);
  result *= nb;
  my_rec(nb - 1, result);
}
