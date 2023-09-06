/*
** my_strlowcase.c for my_strlowcase in /home/baris_f/rendu/Piscine_C_J06/ex_09
** 
** Made by Florent Baris
** Login   <baris_f@epitech.net>
** 
** Started on  Mon Oct  5 15:58:47 2015 Florent Baris
** Last update Mon Oct  5 16:02:40 2015 Florent Baris
*/

char	*my_strlowcase(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    {
      if (str[i] <= 'Z' && str[i] >= 'A')
	str[i] += 32;
      i++;
    }
  return (str);
}
