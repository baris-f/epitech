#include "client.h"

int			connect_it(t_socket *s, const char *hostname, const char *port){
  char			**pointer_pointer;
  char			answer[INET_ADDRSTRLEN];
  struct hostent	*returned_host;
  struct sockaddr_in	outgoing_address;
  size_t		len;

  returned_host = gethostbyname(hostname);
  if(returned_host == NULL)
    return (0);
  pointer_pointer=returned_host->h_addr_list;
  inet_ntop(AF_INET,(void *)*pointer_pointer,answer,sizeof(answer));
  s->fd=socket(AF_INET,SOCK_STREAM,0);
  if(s->fd < 0)
    return (0);
  memset(&outgoing_address,0,sizeof(outgoing_address));
  outgoing_address.sin_family=AF_INET;
  outgoing_address.sin_port=htons(atoi(port));
  len = sizeof(&outgoing_address.sin_addr);
  memmove(&outgoing_address.sin_addr, *pointer_pointer, len);
  if(connect(s->fd,(struct sockaddr*)&outgoing_address,sizeof(outgoing_address)))
    return (0);
  return (1);
}

char		*connect_server_handler(t_client *c)
{
  char		*ret;

  ret = NULL;
  c->connected = 1;
  *c->fdmax = c->client->fd + 1;
  FD_SET(c->client->fd, c->rfds);
  !(ret = malloc(256)) ? error("malloc") : bzero(ret, 256);
  sprintf(ret, "%s %s\r\n", "NICK", c->nickname);
  ssend(c->client->fd, ret);
  free(ret);
  !(ret = malloc(256)) ? error("malloc") : bzero(ret, 256);
  sprintf(ret, "%s %s 0 * :%s\r\n", "USER", c->nickname, c->nickname);
  return (ret);
}

char		*connect_server(void *this, void *request)
{
  char		*ret;
  char		**tmp;
  t_client	*c;
  t_request	*r;

  ret = NULL;
  c = (t_client *)this;
  r = (t_request *)request;
  if (!r->arg || !r->arg[0])
    return (strdup("00PS: Error [/server] invalid cmd.\r\nCf help."));
  if (!(tmp = str_to_tab(r->arg[0], ':')))
    return (strdup("00PS: str_to_tab() failed :(."));
  r->arg = tmp;
  free_arrays("t", tmp);
  if (!r->arg[1])
    {
      if (!(r->arg = realloc(r->arg, sizeof(r->arg) + sizeof(char *) * 2)))
	error("realloc");
      r->arg[1] = strdup("6667");
      r->arg[2] = NULL;
    }
  if (!connect_it(c->client, r->arg[0], r->arg[1]))
    return (strdup("00PS: Error cannot connect specifed IP/PORT :(."));
  ret = connect_server_handler(c);
  return (ret);
}
