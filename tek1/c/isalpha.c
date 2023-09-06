/*
** isalpha.c for isalpha in /home/baris-f/rendu/c
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sat Nov 28 18:12:16 2015 Florent Baris
** Last update Sun Nov 29 17:38:51 2015 Florent Baris
*/

int	isalph(char c)
{
  if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
    return (1);
  return (0);
}
