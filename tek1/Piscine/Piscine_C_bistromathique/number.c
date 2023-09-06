/*
** number.c for Piscine_C_Bistromathique in /home/linux/rendu/Piscine_C_bistromathique
**
** Made by thirion gaspard
** Login   <thirio_b@epitech.net>
**
** Started on  Wed Oct 28 00:14:12 2015 thirion gaspard
** Last update Sun Nov  1 21:15:14 2015 Gaspard Thirion
*/

#include <stdlib.h>

int	char_isnum(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  return (0);
}

int	char_isop(char c)
{
  if (c == '*' || c == '/' || c == '%' || c == '-' || c == '+'
 || c == '\0')
    return (1);
  return (0);
}

void	number(char **pstr, char *ret)
{
  int	i;

  if (!char_isnum(**pstr) && **pstr != '(')
    (*pstr)++;
  i = -1;
  while (char_isnum(**pstr) || **pstr == '-')
    {
      ret[++i] = **pstr;
      (*pstr)++;
    }
  ret[++i] = '\0';
}
