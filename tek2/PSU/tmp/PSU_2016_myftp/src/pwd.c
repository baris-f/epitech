/*
** pwd.c for ned in /home/baris_f/rendu/tek2/PSU/tmp/PSU_2016_myftp
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Sun May 21 22:59:08 2017 baris_f
** Last update Sun May 21 23:04:06 2017 baris_f
*/

#include "function.h"


void    noop(struct_client *clt)
{
  if (checkLogStatus(clt))
    return;
  xwrite(clt, "200 :)\r\n");
}

void    cdup(struct_client *clt)
{
  char  wd[2018];

  if (checkLogStatus(clt))
    return;
  if (chdir("..") == -1) {
    xwrite(clt, "550 ");
    xwrite(clt, strerror(errno));
    xwrite(clt, "\r\n");
    return ;
  }
  bzero(wd, 2048);
  getcwd(wd, 2048);
  if (strlen(wd) < strlen(clt->path)) {
    chdir(clt->path);
    xwrite(clt, "550 Acces denied\r\n");
  } else
    xwrite(clt, "250 CWD command successful\r\n");
}

void quit(struct_client *clt)
{
  xwrite(clt, "221 byebye :) \r\n");
  clt->isConnected = FALSE;
}

void    delete(struct_client *clt)
{
  char  *file;

  if (checkLogStatus(clt))
    return;
  if ((file = buildPath(clt)) == NULL){
    xwrite(clt, "550 Pleasse specify a file to remove");
    return;
  }
  if (remove(file) == -1){
    xwrite(clt, "550 ");
    xwrite(clt, strerror(errno));
    xwrite(clt, "\r\n");
  } else
    xwrite(clt, "255 DELE command successful\r\n");
  free(file);
}

void    pwd(struct_client *clt)
{
  char  wd[2048];
  char  *distPath;

  if (checkLogStatus(clt))
    return;
  bzero(wd, 2048);
  distPath = (char *)malloc(2048);
  bzero(distPath, 2048);
  if ((distPath = getcwd(wd, 2048)) == NULL)
    xwrite(clt, "550 ERRORs\r\n");
  else
    {
      distPath += strlen(clt->path);
      if (distPath[0] == '\0')
        distPath[0] = '/';
      xwrite(clt, "257 \"");
      xwrite(clt, distPath);
      xwrite(clt, "\" is the current directory\r\n");
    }
}
