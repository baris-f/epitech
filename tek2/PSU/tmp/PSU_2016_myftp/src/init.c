/*
** init.c for k in /home/baris_f/rendu/tek2/PSU/tmp/PSU_2016_myftp
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Sun May 21 23:04:23 2017 baris_f
** Last update Sun May 21 23:04:53 2017 baris_f
*/

#define _DEFAULT_SOURCE

#include "function.h"

int                     initSocket(int portno)
{
  int                   sockfd;
  struct sockaddr_in    serv_addr;

  if (!(sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)))
    error("ERROR opening socket");
  bzero((void *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(portno);
  if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    error("ERROR on binding");
  if (listen(sockfd, 5) == -1)
    error("ERROR on listen");
  return (sockfd);
}

void			initData(struct_client *clt)
{
  char			ac[256];
  struct hostent	*phe;
  struct in_addr	locaddr;

  gethostname(ac, sizeof(ac));
  phe = gethostbyname(ac);
  memcpy(&locaddr, phe->h_addr_list[0], sizeof(struct in_addr));
  strcpy(clt->data.ip, inet_ntoa(locaddr));
  clt->data.port = -1;
  clt->data.sock = -1;
  clt->data.transfert_mode = UNSET;
}

void			initPath(struct_client *clt, char *path){
  if (access(path, F_OK | R_OK | W_OK) == -1){
    clt->isConnected = FALSE;
    return ;
  }
  if (chdir(path) == -1)
    error("CHDIR ");
  bzero(clt->path, 2048);
  if (getcwd(clt->path, 2048) == NULL)
    clt->isConnected = FALSE;
}

void			initClient(struct_client *clt, int socket, char * path){
  initData(clt);
  clt->isLogged = NOT_LOG;
  clt->sock = socket;
  if (socket >= 0)
    clt->isConnected = TRUE;
  else
    clt->isConnected = FALSE;
  initPath(clt, path);
  xwrite(clt, "220 Coucou.\r\n");
  printf("New client connected on socket {%d}.\n", socket);
}

void			initSelect(struct_client *clt)
{
  FD_ZERO(&(clt->fs));
  FD_SET(clt->sock, &(clt->fs));
  clt->tm.tv_sec = 300;
  clt->tm.tv_usec = 0;
}
