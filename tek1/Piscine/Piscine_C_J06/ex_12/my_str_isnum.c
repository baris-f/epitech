/*
** my_str_isnum.c for my_str_isnum in /home/baris_f/rendu/Piscine_C_J06/ex_12
** 
** Made by Florent Baris
** Login   <baris_f@epitech.net>
** 
** Started on  Mon Oct  5 16:43:47 2015 Florent Baris
** Last update Mon Oct  5 16:44:21 2015 Florent Baris
*/

int     my_str_isalpha(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    {
      if ((str[i] < '0' || str[i] > '9'))
        return (0);
      i++;
    }
  return (1);
}
