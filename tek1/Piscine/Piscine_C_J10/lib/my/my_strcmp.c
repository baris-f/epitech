/*
** my_strcmp.c for my_strcmp in /home/baris_f/rendu/Piscine_C_J06/ex_06
** 
** Made by Florent Baris
** Login   <baris_f@epitech.net>
** 
** Started on  Mon Oct  5 14:48:08 2015 Florent Baris
** Last update Mon Oct  5 21:30:09 2015 Florent Baris
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
    i++;
  if (s1[i - 1] == s2[i - 1] && s1[i] == '\0' && s2[i] == '\0')
    return (0);
  return (s1[i] - s2[i]);
}
