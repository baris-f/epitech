/*
** my_str_isalpha.c for my_str_isalpha in /home/baris_f/rendu/Piscine_C_J06/ex_11
** 
** Made by Florent Baris
** Login   <baris_f@epitech.net>
** 
** Started on  Mon Oct  5 16:33:50 2015 Florent Baris
** Last update Mon Oct  5 16:40:44 2015 Florent Baris
*/

int	my_str_isalpha(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
	return (0);
      i++;
    }
  return (1);
}
