/*
** my_str_isprintable.c for my_str_isprintable.c in /home/baris_f/rendu/Piscine_C_J06/ex_15
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Oct  5 16:50:58 2015 Florent Baris
** Last update Thu Oct  8 08:47:41 2015 Florent Baris
*/

int     my_str_isprintable(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    {
      if (str[i] < ' ' || str[i] > '~')
        return (0);
      i++;
    }
  return (1);
}
