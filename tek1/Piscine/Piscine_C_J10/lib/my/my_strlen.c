/*
** my_strlen.c for my_strlen in /home/baris_f/rendu/Piscine_C_J04
** 
** Made by Florent Baris
** Login   <baris_f@epitech.net>
** 
** Started on  Thu Oct  1 09:27:05 2015 Florent Baris
** Last update Tue Oct  6 09:52:08 2015 Florent Baris
*/

int	my_strlen(char *str)
{
  int i;

  i = 0;
  while (str[i])
      i++;
  return (i);
}
