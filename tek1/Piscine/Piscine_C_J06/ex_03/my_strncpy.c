/*
** my_strncpy.c for my_strncpy in /home/baris_f/rendu/Piscine_C_J06/ex_03
** 
** Made by Florent Baris
** Login   <baris_f@epitech.net>
** 
** Started on  Mon Oct  5 09:58:15 2015 Florent Baris
** Last update Mon Oct  5 10:25:39 2015 Florent Baris
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (i < n && src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
