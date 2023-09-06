/*
** nmatch.c for nmatch in /home/baris_f/rendu/Piscine_C_match-nmatch
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sun Oct 11 16:38:08 2015 Florent Baris
** Last update Sun Oct 11 21:08:34 2015 Florent Baris
*/

int     recnmatch(char *s1, char *s2)
{
  if (*s1 == *s2 && *s1 == '\0')
    return (1);
  if (*s2 == '*' && *s1 != '\0')
    return (recnmatch(s1 + 1, s2) + recnmatch(s1, s2 + 1));
  if (*s2 == '*' && *s1 == '\0')
    return (recnmatch(s1, s2 + 1));
  if (*s1 == *s2 && *s1 != '\0')
    return (recnmatch(s1 + 1, s2 + 1));
  return (0);
}

int     nmatch(char *s1, char *s2)
{
  return (recnmatch(s1, s2));
}
