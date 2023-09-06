/*
** my_strcat.c for my_strcat in /home/baris_f/rendu/Piscine_C_J07
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Tue Oct  6 12:30:40 2015 Florent Baris
** Last update Wed Oct  7 10:45:07 2015 Florent Baris
*/

char	*my_strcat(char *dest, char *src)
{
  int	j;
  int	i;

  j = 0;
  while (dest[j])
    j++;
  i = 0;
  while (src[i])
    {
    dest[i + j] = src[i];
    i++;
    }
  return (dest);
}
