/*
** my_power_it.c for my_power_it in /home/baris_f/rendu/Piscine_C_J05
** 
** Made by Florent Baris
** Login   <baris_f@epitech.net>
** 
** Started on  Fri Oct  2 10:07:26 2015 Florent Baris
** Last update Sun Oct  4 18:07:02 2015 Florent Baris
*/

int	my_power_it(int nb, int power)
{
  int	result;

  result = 1;
  if (power == 0)
    return (1);
  while (power > 0)
    {
      if ((result * nb) < result)
	return (0);
      if (-((result * nb) < result) && result < 0)
	return (0);
      result *= nb;
      power--;
    }
  return (result);
}
