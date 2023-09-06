/*
** my_revstr.c for my_revstr in /home/baris_f/rendu/Piscine_C_J06/ex_04
** 
** Made by Florent Baris
** Login   <baris_f@epitech.net>
** 
** Started on  Mon Oct  5 10:27:01 2015 Florent Baris
** Last update Mon Oct  5 10:37:27 2015 Florent Baris
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

char	*my_revstr(char *str)
{
  char	temp;
  int	len;
  int	i;

  i = 0;
  len = my_strlen(str);
  while (i < len / 2)
    {
      temp = str[i];
      str[i] = str[len - i - 1];
      str[len - i - 1] = temp;
      i++;
    }
  return (str);
}
