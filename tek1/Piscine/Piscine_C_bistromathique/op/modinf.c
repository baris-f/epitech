/*
** modinf.c for divinf3 in /home/thirio_b/rendu/Piscine_C_bistromathique
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Sun Nov  1 22:05:32 2015 Gaspard Thirion
** Last update Sun Nov  1 22:11:17 2015 Gaspard Thirion
*/

#include <stdlib.h>
#include "../include/bistro.h"

char    *subinf_de_clochard(char *nb1, char *nb2)
{
  int   res;
  int   i;
  char  *tmp;
  int   k;

  k = -1;
  i = 0;
  res = my_getnbr(nb1) - my_getnbr(nb2);
  while (tmp[++k])
    tmp[k] = '0';
  tmp[k] = '\0';
  while (res > 0)
    {
      tmp[my_strlen(nb2) - i] = (res % 10 + '0');
      res = res / 10;
      i++;
    }
  i = 0;
  while (tmp[i] == '0')
    *tmp++;
  return (tmp);
}

void	my_modinf(char *nb1, char *nb2)
{

}
