/*
** isalphanum.c for isaphanum in /home/baris-f/rendu/c
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sun Nov 29 17:33:04 2015 Florent Baris
** Last update Sun Nov 29 17:33:17 2015 Florent Baris
*/

int     isalphanum(char c)
{
  if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') ||
      (c >= 'A' && c <= 'Z'))
    return (1);
  return (0);
}
