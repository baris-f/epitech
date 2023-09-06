/*
** subinf.c for my_subinf in /home/thirio_b/rendu/Piscine_C_bistromathique
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Sun Nov  1 16:33:31 2015 Gaspard Thirion
** Last update Sun Nov  1 18:55:36 2015 Gaspard Thirion
*/

#include <stdlib.h>

int     ishigher(char *nb1, char *nb2)
{
  if (my_strlen(nb1) > my_strlen(nb2))
    return (1);
  else if (my_strlen(nb2) > my_strlen(nb1))
    return (-1);
  else
    return (my_strcmp(nb1, nb2));
}

char    *makesub(char *dest, char *nb1, char *nb2)
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
      tmp = carspe(nb1, &in1) - (carspe(nb2,&in2) + (res[i] - '0'));
        if (tmp < 0)
	{
	  res[i - 1] = 1 + '0';
	  res[i] = 10 + tmp + '0';
	}
      else
	res[i] = tmp + '0';
    }
  my_strcpy(dest, res);
  free(res);
}

char	*my_subinf(char *tot, char *ret)
{
  if (tot[0] != '-' && ret[0] != '-')
    {
      if (ishigher(tot, ret) >= 0)
	{
	  makesub(tot, tot, ret);
	  spe_put_str(tot, 0);
	}
      else
	{
	  makesub(tot, ret, tot);
	  spe_put_str(tot, 1);
	}
    }
  else  if (tot[0] == '-' && ret[0] == '-')
    {
      my_strcpy(tot, "N");
    }
  else
    {
      my_strcpy(tot, "B");
    }
}
