/*
** match.c for match in /home/duval_m/rendu/Piscine_C_match-nmatch
**
** Made by lucas duval
** Login   <duval_m@epitech.net>
**
** Started on  Sun Oct 11 13:57:34 2015 lucas duval
** Last update Sun Oct 11 17:26:16 2015 lucas duval
*/

int	check_match(char *s1, char *s2)
{
  if (*s1 == *s2 && *s1 == '\0')
    return (1);
  if (*s1 == *s2 && *s1 != '\0')
    return (check_match(s1 + 1, s2 + 1));
  if (*s2 == '*' && *s1 != '\0')
    return (check_match(s1 + 1, s2) || check_match(s1, s2 + 1));
  if (*s2 == '*' && *s1 == '\0')
    return (check_match(s1, s2 + 1));
  return (0);
}

int	match(char *s1, char *s2)
{
  return (check_match(s1, s2));
}
