/*
** main.c for coucouduu in /home/grandma/PSU_2015_42sh
**
** Made by Corentin Grandmaire
** Login   <grandm_a@epitech.net>
**
** Started on  Mon May  2 13:00:37 2016 Corentin Grandmaire
** Last update	Mon Jun 06 15:25:56 2016 Aurélien Toussaint
*/

#include "42s.h"

int	verif_cmdt5(t_42 *base, int i)
{
  if ((VERIF(i, '>') && VERIF(i + 1, ' ') &&
       VERIF(i + 2, '&'))
      || (VERIF(i, '>') && VERIF(i + 1, ' ') &&
	  VERIF(i + 2, '|'))
      || (VERIF(i, '>') && VERIF(i + 1, ' ') &&
	  VERIF(i + 2, ';'))
      || (VERIF(i, '<') && VERIF(i + 1, ' ') &&
           VERIF(i + 2, '&'))
      || (VERIF(i, '<') && VERIF(i + 1, ' ') &&
	  VERIF(i + 2, '|'))
      || (VERIF(i, '<') && VERIF(i + 1, ' ') &&
	  VERIF(i + 2, ';')))
    {
      printf("Parsing Error\n");
      return (-1);
    }
  if (verif_cmdt6(base, i) == -1)
    return (-1);
  return (0);
}

int	verif_cmdt4(t_42 *base, int i)
{
  int	l;

  l = strlen(base->cmdt);
  if (l - 2 >= 0
      && ((VERIF(l - 2, '&')) || (VERIF(l - 2, '|'))))
    {
      return (2);
      printf("Parsing error\n");
    }
  return (0);
}

int	verif_cmdt3(t_42 *base, int i, int l)
{
  if ((VERIF(i, '<') && VERIF(i + 1, '>'))
      || (VERIF(i, '<') && VERIF(i + 1, '&'))
      || (VERIF(i, '<') && VERIF(i + 1, '|'))
      || (VERIF(i, '<') && VERIF(i + 1, ';'))
      || (VERIF(i, '&') && VERIF(i + 1, '>'))
      || (VERIF(i, '&') && VERIF(i + 1, '<'))
      || (VERIF(i, '&') && VERIF(i + 1, '|'))
      || (VERIF(i, '&') && VERIF(i + 1, ';'))
      || (VERIF(i, '|') && VERIF(i + 1, '>'))
      || (VERIF(i, '|') && VERIF(i + 1, '<'))
      || (VERIF(i, '|') && VERIF(i + 1, '&'))
      || (VERIF(i, '|') && VERIF(i + 1, ';'))
      || (VERIF(i, ';') && VERIF(i + 1, '>'))
      || (VERIF(i, ';') && VERIF(i + 1, '<'))
      || (VERIF(i, ';') && VERIF(i + 1, '|'))
      || (VERIF(i, ';') && VERIF(i + 1, '&'))
      || (l - 2 >= 0 && (VERIF(l - 2, '>')
      || (VERIF(l - 2, '<')))))
    {
      printf("Parsing Error\n");
      return (-1);
    }
  return (0);
}

int	verif_cmdt2(t_42 *base, int i)
{
  if ((VERIF(i, '>') && VERIF(i + 1, ' ') &&
       VERIF(i + 2, '>'))
      || (VERIF(i, '<') && VERIF(i + 1, ' ') &&
	  VERIF(i + 2, '<'))
      || (VERIF(i, '&') && VERIF(i + 1, ' ') &&
	  VERIF(i + 2, '&'))
      || (VERIF(i, '|') && VERIF(i + 1, ' ') &&
	  VERIF(i + 2, '|'))
      || (VERIF(i, ';') && VERIF(i + 1, ';'))
      || (VERIF(i, '>') && VERIF(i + 1, '<'))
      || (VERIF(i, '>') && VERIF(i + 1, '&'))
      || (VERIF(i, '>') && VERIF(i + 1, '|'))
      || (VERIF(i, '>') && VERIF(i + 1, ';')))
    {
      printf("Parsing Error\n");
      return (-1);
    }
 if (verif_cmdt3(base, i, strlen(base->cmdt)) == -1)
    return (-1);
  if (verif_cmdt5(base, i) == -1)
    return (-1);
  return (0);
}

int	verif_cmdt(t_42 *base, int i)
{
  while (base->cmdt[++i])
    {
      if ((VERIF(i, '>') && VERIF(i + 1, '>') &&
	   VERIF(i + 2, '>'))
	  || (VERIF(i, '<') && VERIF(i + 1, '<') &&
	      VERIF(i + 2, '<'))
	  || (VERIF(i, '&') && VERIF(i + 1, '&') &&
	      VERIF(i + 2, '&'))
	  || (VERIF(i, '|') && VERIF(i + 1, '|') &&
	      VERIF(i + 2, '|')))
	{
	  printf("Parsing Error\n");
	  return (-1);
	}
      else if (verif_cmdt2(base, i) == -1)
	return (-1);
      else if (VERIF(0, ';'))
	{
	  printf("Parsing Error\n");
	  return (-1);
	}
    }
  if (verif_cmdt4(base, i) == 2)
    return (2);
  return (0);
}
