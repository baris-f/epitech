/*
** utils2.c for  in /home/grandma/PSU_2015_42sh/src
**
** Made by Corentin Grandmaire
** Login   <grandm_a@epitech.net>
**
** Started on  Fri May 27 14:25:38 2016 Corentin Grandmaire
** Last update Sun Jun  5 21:23:53 2016 Corentin Grandmaire
*/

#include "42s.h"

int		what_ope(char *s1, char *s2)
{
  int		i;
  int		j;
  int		k;

  i = strlen(s2);
  j = 1;
  k = 0;
  while (--i >= 0 && s1[--j] == s2[i])
    k++;
  if (k == (int)strlen(s2))
    return (1);
  return (0);
}

t_ptr		*ope()
{
  t_ptr		*reference;

  if ((reference = malloc(sizeof(t_ptr) * (OP_SIZE + 1))) == NULL)
    return (NULL);
  reference[0].fct = &(or);
  reference[0].op = "||";
  reference[1].fct = &(leftredir);
  reference[1].op = "<<";
  reference[2].fct = &(leftredir);
  reference[2].op = ">>";
  reference[3].fct = &(and);
  reference[3].op = "&&";
  reference[4].fct = &(pipe_exec);
  reference[4].op = "|";
  reference[5].fct = &(leftredir);
  reference[5].op = "<";
  reference[6].fct = &(leftredir);
  reference[6].op = ">";
  reference[7].fct = &(endpoint);
  reference[7].op = ";";
  return (reference);
}

char		*epur_str(char *str)
{
  char		*rtn;
  int		i;
  int		j;

  if (str == NULL ||
      (rtn = malloc(sizeof(char) * (my_strlen(str) + 100))) == NULL)
    return (NULL);
  memset(rtn, 0, my_strlen(str) + 1);
  i = 0;
  while (str[i] == ' ' || str[i] == '\t')
    i++;
  j = 0;
  while (str[i] != '\0')
    {
      if (str[i] != ' ' && str[i] != '\t')
	rtn[j++] = str[i];
      else if (str[i] == ' ' || str[i] == '\t')
	{
	  if ((str[i] == ' ' || str[i] == '\t') && str[i + 1] != ' '
	      && str[i + 1] != '\t' && str[i + 1] != '\0')
	    rtn[j++] = ' ';
	}
      i++;
    }
  return (rtn);
}
