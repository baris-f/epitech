#include "server.h"

void		list(void *params, t_user *user, t_server *serv)
{
  t_channel	*tmp;
  char		*niddle;

  if (!user->nick)
    return ;
  niddle = NULL;
  if (strlen(params) > 1)
    {
      params++;
      niddle = strdup(params);
    }
  ssend(user->socket, "321 List Start: Channel:Users Name\r\n");
  for (tmp = serv->channels; tmp; tmp = tmp->next)
    {
      if ((niddle && strstr(tmp->name, niddle)) || !niddle)
	{
	  ssend(user->socket, "322 ");
	  ssend(user->socket, tmp->name);
	  ssend(user->socket, "\r\n");
	}
    }
  if (niddle)
    free(niddle);
  ssend(user->socket, "323 :End of LIST\r\n");
}

void		names(void _UNUSED_*params, t_user *user, t_server _UNUSED_*serv)
{
  t_user	*tmp;

  if (!user->nick)
    return ;
  if (!user->chan)
    {
      ssend(user->socket, "442 NAMES : You're not on that channel\r\n");
      return ;
    }
  ssend(user->socket, ":localhost 353 ");
  ssend(user->socket, user->nick);
  ssend(user->socket, " = ");
  ssend(user->socket, user->chan);
  ssend(user->socket, " : ");
  for (tmp = *user->list; tmp; tmp = tmp->next)
    {
      ssend(user->socket, tmp->nick);
      if (tmp->next)
	ssend(user->socket, " ");
    }
  ssend(user->socket, "\r\n");
  ssend(user->socket, ":localhost 366 ");
  ssend(user->socket, user->nick);
  ssend(user->socket, " ");
  ssend(user->socket, user->chan);
  ssend(user->socket, " :End of NAMES list\r\n");
}

void		quit(void *params, t_user *user, t_server *serv)
{
  char		*msg;
  t_user	*u;

  msg = NULL;
  if (strlen(params) > 1)
    msg = strdup(params + 2);
  if (msg && user->chan && user->list)
    {
      for (u = *user->list; u; u = u->next)
	{
	  if (u == user)
	    continue ;
	  ssend(u->socket, user->nick);
	  ssend(u->socket, " has quit (\"");
	  ssend(u->socket, msg);
	  ssend(u->socket, "\")\r\n");
	}
    }
  FD_CLR(user->socket, &serv->master);
  remove_connection(user, serv);
  if (msg)
    free(msg);
}
