#include "server.h"

void	sendfile(void _UNUSED_*params, t_user *user, t_server _UNUSED_*serv)
{
  ssend(user->socket, "421 Unknown command\r\n");
}

void	acceptfile(void _UNUSED_*params, t_user *user, t_server _UNUSED_*serv)
{
  ssend(user->socket, "421 Unknown command\r\n");
}
