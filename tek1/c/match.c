/*
** match.c for match in /home/baris_f/rendu/Piscine_C_match-nmatch
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sun Oct 11 13:57:41 2015 Florent Baris
** Last update Tue Dec  1 15:56:04 2015 Florent Baris
*/

int	recmatch(char *s1, char *s2)
{
  if (*s1 == *s2 && *s1 == '\0')
    return (1);
  if (*s2 == '*' && *s1 != '\0')
    return (recmatch(s1 + 1, s2) || recmatch(s1, s2 + 1));
  if (*s2 == '*' && *s1 == '\0')
    return (recmatch(s1, s2 + 1));
  if (*s1 == *s2 && *s1 != '\0')
    return (recmatch(s1 + 1, s2 + 1));
  return (0);
}

int	match(char *s1, char *s2)
{
  return (recmatch(s1, s2));
}
