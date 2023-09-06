/*
** my_factorielle_it.c for my_factorielle_it in /home/baris_f/rendu/Piscine_C_J05
** 
** Made by Florent Baris
** Login   <baris_f@epitech.net>
** 
** Started on  Fri Oct  2 09:38:29 2015 Florent Baris
** Last update Fri Oct  2 12:12:03 2015 Florent Baris
*/

int	my_factorielle_it(int nb)
{
  int	result;

  result = 1;
  if (nb == 0)
    return (1);
  if (nb < 0)
    return (0);
  if (nb >= 13)
    return (0);
  while (nb > 0)
    {
      result *= nb;
      nb--;
    }
  return (result);
}

