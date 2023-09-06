/*
** my_str_islower.c for my_str_islower in /home/baris_f/rendu/Piscine_C_J06/ex_13
** 
** Made by Florent Baris
** Login   <baris_f@epitech.net>
** 
** Started on  Mon Oct  5 16:46:04 2015 Florent Baris
** Last update Mon Oct  5 16:47:09 2015 Florent Baris
*/

int     my_str_isalpha(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    {
      if ((str[i] < 'a' || str[i] > 'z'))
        return (0);
      i++;
    }
  return (1);
}
