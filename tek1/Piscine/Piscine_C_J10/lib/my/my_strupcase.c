/*
** my_strupcase.c for my_strupcase in /home/baris_f/rendu/Piscine_C_J06/ex_08
** 
** Made by Florent Baris
** Login   <baris_f@epitech.net>
** 
** Started on  Mon Oct  5 15:39:41 2015 Florent Baris
** Last update Mon Oct  5 16:01:40 2015 Florent Baris
*/

char	*my_strupcase(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] >= 'a' && str[i] <= 'z')
	str[i] -= 32;
      i++;
    }
  return (str);
}
