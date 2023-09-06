/*
** main.c for main in /home/baris_f/rendu/tek2/PSU/tmp/PSU_2016_myftp
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Sun May 21 22:49:43 2017 baris_f
** Last update Sun May 21 22:50:03 2017 baris_f
*/

#define _DEFAULT_SOURCE

#include "function.h"

int			main(int ac, char **av)
{
  if (ac != 3)
    printf("Usage: %s port path\n", av[0]);
  else
    server(atoi(av[1]), av[2]);
  return (0);
}

char			*buildPath(struct_client *clt)
{
  char			*dist_path;
  char			*real_path;

  dist_path = strstr(clt->buff, " ");
  if (dist_path == NULL)
    return (NULL);
  ++dist_path;
  if (dist_path[0] != '/')
    return (strdup(dist_path));
  real_path = (char*)malloc(2048);
  bzero(real_path, 2048);
  real_path = strcat(real_path, dist_path);
  real_path = strcat(real_path, clt->path);
  return (real_path);
}

void			client(int socket, char *path)
{
  struct_client		clt;
  int			ret;

  initClient(&clt, socket, path);
  while (clt.isConnected == TRUE)
    {
      initSelect(&clt);
      if ((ret = select(clt.sock + 1, &(clt.fs), NULL, NULL, &(clt.tm))) == -1)
	clt.isConnected = FALSE;
      else if (ret > 0)
	request(&clt);
      else
	clt.isConnected = FALSE;
    }
  printf("Client disconnected on socket {%d}.\n", clt.sock);
  close(clt.sock);
}

void			server(int portno, char *path)
{
  int			sockfd;
  int			newsockfd;
  int			clilen;
  struct sockaddr_in	cli_addr;
  int			pid;

  sockfd = initSocket(portno);
  clilen = sizeof(cli_addr);
  while (1) {
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr,
		       (socklen_t *) &clilen);
    if (newsockfd > 0)
      {
	pid = fork();
	if (pid == 0){
	  client(newsockfd, path);
	  exit(0);
	}
	else if (pid > 0)
	  close(newsockfd);
	else
	  error("ERROR on fork");
      } else
      error("ERROR on accept");
  }
}
