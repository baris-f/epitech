/*
** xfunc.c for m in /home/baris_f/rendu/tek2/PSU/tmp/PSU_2016_myftp
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Sun May 21 23:05:35 2017 baris_f
** Last update Sun May 21 23:05:36 2017 baris_f
*/


#include "function.h"

int	xread(struct_client *clt)
{
  int	r;
  int	i;

  bzero(clt->buff, 2048);
  if ((r = read(clt->sock, clt->buff, 2048)) <= 0)
    {
      clt->isConnected = FALSE;
      return (r);
    }
  for (i = 0; i < r; i++)
    if (clt->buff[i] == '\n' || clt->buff[i] == '\r')
      clt->buff[i] = '\0';
  return (r);
}

void	xwrite(struct_client *clt, char *msg)
{
  if (write(clt->sock, msg, strlen(msg)) == -1)
    clt->isConnected = FALSE;
}

void    error(char *s)
{
  perror(s);
  exit(1);
}
