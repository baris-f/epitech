/*
** match.c for match in /home/thirio_b/rendu/Piscine_C_match-nmatch
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Sun Oct 11 09:53:49 2015 Gaspard Thirion
** Last update Tue Apr 19 19:29:11 2016 Gaspard Thirion
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

char    *nts(int nb)
{
  int	len;
  int	cp;
  char	*str;

  cp = nb;
  len = 0;
  while (cp > 0)
    {
      len++;
      cp /= 10;
    }
  (nb == 0) ? (len = 1) : (0);
  if ((str = malloc(sizeof(char) * len + 1)) == NULL)
    return (NULL);
  my_memset(str, '\0', len + 1);
  (nb == 0) ? (str[0] = '0') : (0);
  while (nb > 0)
    {
      len--;
      str[len] = nb % 10 + 48;
      nb /= 10;
    }
  return(str);
}
