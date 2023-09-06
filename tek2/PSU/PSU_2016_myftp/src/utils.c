/*
** function.c for lel in /home/baris_f/rendu/tek2/PSU/tmp/PSU_2016_myftp
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Sun May 21 22:53:11 2017 baris_f
** Last update Sun May 21 23:00:20 2017 baris_f
*/

#define _GNU_SOURCE

#include "function.h"

void    cwd(struct_client *clt)
{
  char  wd[2018];
  char  *path;

  if (checkLogStatus(clt))
    return;
  path = buildPath(clt);
  if (path == NULL){
    printf("NULL\n");
    return ;
  }
  if (chdir(path) == -1) {
    xwrite(clt, "550 ");
    xwrite(clt, strerror(errno));
    xwrite(clt, "\r\n");
    free(path);
    return ;
  }
  bzero(wd, 2048);
  getcwd(wd, 2048);
  if (strlen(wd) < strlen(clt->path)) {
    chdir(clt->path);
    xwrite(clt, "550 Acces denied\r\n");
  } else
    xwrite(clt, "250 CWD command successful\r\n");
  free(path);
}

int	checkLogStatus(struct_client *clt)
{
  if (clt->isLogged != AUTH)
    {
      xwrite(clt, "530 Not loogged in.\r\n");
      return (TRUE);
    } else
    return (FALSE);
}

void	help(struct_client *clt)
{
  if (checkLogStatus(clt))
    return;
  xwrite(clt, "214 No help sry :/ \r\n");
}

void	user(struct_client *clt)
{
  if (strcasestr(clt->buff, "anonymous"))
    {
      clt->isLogged = LOGGED;
      xwrite(clt, "331 Please send password.\r\n");
    }
  else
    xwrite(clt, "332 Anonymous only.\r\n");
}

void	pass(struct_client *clt)
{
  if (clt->isLogged != LOGGED)
    {
      xwrite(clt, "332 Send USER first.\r\n");
    } else {
    clt->isLogged = AUTH;
    xwrite(clt, "230 Login ok.\r\n");
  }
}
