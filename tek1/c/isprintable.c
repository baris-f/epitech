/*
** isprintable.c for isprintable in /home/baris-f/rendu/c
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Wed Dec  9 14:51:57 2015 Florent Baris
** Last update Fri Dec 11 14:40:59 2015 Florent Baris
*/

int     isprintable(char c)
{
   if (c <= ' ' || c > '~')
    return (0);
   return (1);
}
