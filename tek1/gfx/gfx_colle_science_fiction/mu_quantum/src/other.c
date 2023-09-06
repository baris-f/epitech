/*
** match.c for match in /home/thirio_b/rendu/Piscine_C_match-nmatch
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Sun Oct 11 09:53:49 2015 Gaspard Thirion
** Last update Tue Apr 12 12:55:38 2016 Gaspard Thirion
*/

#include "engine.h"

int     powere(int nb, int power)
{
  if (power == 0)
    return (1);
  else if (power == 1)
    return (nb);
  else if (power > 1)
    {
      nb *= powere(nb, power - 1);
      return (nb);
    }
  else
    return (-1);
}

int	nrecmatch(char *s1, char *s2, int i, int j)
{
  if (s1[i] == '\0' && s2[j] == '\0')
    return (1);
  if (s1[i] == s2[j])
    return (nrecmatch(s1, s2, i + 1, j + 1));
  if (s1[i] && s2[j] == '*')
    return (nrecmatch(s1, s2, i + 1, j) + nrecmatch(s1, s2, i, j + 1));
  if (s1[i] == '\0' && s2[j] == '*')
    return (nrecmatch(s1, s2, i, j + 1));
  return (0);
}

int	nmatch(char *s1, char *s2)
{
  return (nrecmatch(s1, s2, 0, 0));
}

char	*nts(int c)
{
  char	*tmp;

  if (c < 0
      || (tmp = malloc(sizeof(char) * 3)) == NULL)
    return (NULL);
  tmp[0] = c / 10 % 10 + '0';
  tmp[1] = c % 10 + '0';
  tmp[2] = '\0';
  return (tmp);
}
