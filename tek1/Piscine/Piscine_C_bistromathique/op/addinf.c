/*
** addinf.c for operation in /home/grandm_a/Piscine_C_infinadd
**
** Made by Corentin Grandmaire
** Login   <grandm_a@epitech.net>
**
** Started on  Fri Oct 23 11:19:01 2015 Corentin Grandmaire
** Last update Sun Nov  1 18:54:57 2015 Gaspard Thirion
*/

#include <stdlib.h>

char    *makeadd(char *nb1, char *nb2)
{
  char  *res;
  int   len;
  int   i;
  int   tmp;
  int   in1;
  int   in2;

  len = spe_len(my_strlen(nb1), my_strlen(nb2));
  if ((res = malloc(sizeof(*res) * len + 1)) == NULL)
    return (NULL);
  my_memset(res, len, '0');
  i = len;
  in1 = my_strlen(nb1);
  in2 = my_strlen(nb2);
  while (--i > 0)
    {
      tmp = (res[i] - '0') + carspe(nb1, &in1) + carspe(nb2, &in2) ;
      res[i - 1] = tmp / 10 + '0';
      res[i] = tmp % 10 + '0';
    }
  my_strcpy(nb1, res);
  free(res);
}

char	*my_addinf(char *tot, char *ret)
{
  if (tot[0] != '-' && ret[0] != '-')
    {
      makeadd(tot, ret);
      spe_put_str(tot, 0);
    }

  else if (tot[0] == '-' && ret[0] == '-')
    {
      makeadd(tot, ret);
      spe_put_str(tot, 1);
    }
  else
    {
      my_strcpy(tot, "X");
    }
}
