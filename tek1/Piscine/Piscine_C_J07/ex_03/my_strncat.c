/*
** my_strncat.c for my_strncat in /home/baris_f/rendu/Piscine_C_J07/ex_03
** 
** Made by Florent Baris
** Login   <baris_f@epitech.net>
** 
** Started on  Tue Oct  6 13:09:57 2015 Florent Baris
** Last update Tue Oct  6 13:18:20 2015 Florent Baris
*/

char	*my_strncat(char *dest, char *src, int nb)
{
  int   j;
  int   i;

  j = 0;
  while (dest[j])
    j++;
  i = 0;
  while (src[i] && i  < nb)
    {
      dest[i + j] = src[i];
      i++;
    }
  return (dest);
}
