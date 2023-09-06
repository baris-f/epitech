/*
** my_strcat.c for my_strcat in /home/baris_f/rendu/c
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Tue Oct  6 10:12:56 2015 Florent Baris
** Last update Tue Oct 13 19:04:50 2015 Florent Baris
*/

char    *my_strcat(char *dest, char *src)
{
  int   j;
  int   i;

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
