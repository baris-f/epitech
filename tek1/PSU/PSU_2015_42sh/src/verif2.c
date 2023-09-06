/*
** verif2.c for src
**
** Made by	Aurélien Toussaint
** Login	<toussa_a@epitech.eu>
**
** Started on	Sat Jun 04 18:58:55 2016 Aurélien Toussaint
** Last update	Mon Jun 06 15:26:03 2016 Aurélien Toussaint
*/

#include "42s.h"

int	verif_cmdt6(t_42 *base, int i)
{
  if ((VERIF(i, '&') && VERIF(i + 1, ' ') &&
	  VERIF(i + 2, '|'))
      || (VERIF(i, '&') && VERIF(i + 1, ' ') &&
	  VERIF(i + 2, ';'))
      || (VERIF(i, '|') && VERIF(i + 1, ' ') &&
	  VERIF(i + 2, '&'))
      || (VERIF(i, '|') && VERIF(i + 1, ' ') &&
	  VERIF(i + 2, ';'))
      || (VERIF(i, ';') && VERIF(i + 1, ' ') &&
	  VERIF(i + 2, '&'))
      || (VERIF(i, ';') && VERIF(i + 1, ' ') &&
	  VERIF(i + 2, '|')))
    {
      printf("Parsing Error\n");
      return (-1);
    }
    if ((VERIF(0, '<')) || (VERIF(0, '>')) ||
	(VERIF(0, '&')) || (VERIF(0, '|')))
    {
      printf("Parsing Error\n");
      return (-1);
    }
  return (0);
}
