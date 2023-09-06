/*
** evalexpr.c for Piscine_C_Bistromathique in /home/linux/rendu/Piscine_C_bistromathique
**
** Made by thirion gaspard
** Login   <thirio_b@epitech.net>
**
** Started on  Tue Oct 27 23:51:52 2015 thirion gaspard
** Last update Fri Nov  6 09:33:31 2015 Florent Baris
*/

#include <stdlib.h>
#include "include/bistro.h"

void	spacesout(char *str, int i, int j)
{
  while (str[++i])
    if (char_isnum(str[i]) || char_isop(str[i]))
	str[++j] = str[i];
  str[++j] = '\0';
}

void	factors(char **pstr, char *ret, char **tot)
{
  number(pstr, ret);
  my_strcpy(*tot, ret);
  while (**pstr)
    {
      if (**pstr == '*')
	{
	  number(pstr, ret);
	  mult(tot, ret);
  	}
      else if (**pstr == '/')
      	{
      	  number(pstr, ret);
	  divinf(*tot, ret);
      	}
      else if (**pstr == '%')
      	{
      	  number(pstr, ret);
      	  my_modinf(tot, ret);
      	}
      else
	return;
    }
}

void	summands(char **pstr, char *ret, char **tot, char **tmp)
{
  factors(pstr, ret, tmp);
  my_strcpy(*tot, *tmp);
  while (**pstr)
    {
      if (**pstr == '+')
	{
	  factors(pstr, ret, tmp);
	  my_addinf(*tot, *tmp);
	}
      else if (**pstr == '-')
      	{
	  factors(pstr, ret, tmp);
      	  my_subinf(*tot, *tmp);
      	}
    }
}

char	*eval_expr(char *base, char *op, char *str, unsigned int size)
{
  char  **pstr;
  char	*ret;
  char	*tot;
  char	*tmp;

  if ((ret = malloc(sizeof(char) * (size + 1))) == NULL
      || (tot = malloc(sizeof(char) * (size + 1))) == NULL
      || (tmp = malloc(sizeof(char) * (size + 1))) == NULL)
    return (NULL);
  pstr = &str;
  spacesout(str, -1, -1);
  summands(pstr, ret, &tot, &tmp);
    my_putstr(tot);
  free(ret)
  free (tot);
  free(tmp);
}
