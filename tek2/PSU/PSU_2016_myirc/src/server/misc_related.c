#include "server.h"

void send_to_user(char **args, t_user *user, t_server *serv)
{
  int	i;
  int	x;

  for (i = 3; i < MAX_CONN; i++)
    if (serv->user_index[i] && serv->user_index[i]->nick
	&& !strcmp(serv->user_index[i]->nick, args[0]))
      {
	ssend(serv->user_index[i]->socket, user->nick);
	ssend(serv->user_index[i]->socket, ": ");
	for (x = 1; args[x]; x++)
	  {
	    ssend(serv->user_index[i]->socket, args[x]);
	    if (args[x + 1])
	      ssend(serv->user_index[i]->socket, " ");
	  }
	ssend(serv->user_index[i]->socket, "\r\n");
	break ;
      }
  if (i == MAX_CONN)
    ssend(user->socket, "401 No such nick\r\n");
}

int send_to_chan(char **args, t_user *user, t_server *serv)
{
  int x;
  t_channel *tmp;
  t_user *tmp_user;

  tmp = serv->channels;
  while(tmp)
    if (tmp &&tmp->name && !strcmp(tmp->name, args[0]))
      {
	tmp_user = tmp->users;
	while(tmp_user){
	  if (strcmp(tmp_user->nick, user->nick))
	    {
	      ssend(tmp_user->socket, ":");
	      ssend(tmp_user->socket, user->nick);
	      ssend(tmp_user->socket, " PRIVMSG ");
	      ssend(tmp_user->socket, tmp->name);
	      ssend(tmp_user->socket, " ");
	      for (x = 1; args[x]; x++)
		{
		  ssend(tmp_user->socket, args[x]);
		  if (args[x + 1])
		    ssend(tmp_user->socket, " ");
		}
	      ssend(tmp_user->socket, "\r\n");
	    }
	  tmp_user = tmp_user->next;
	}
	return (0);
      }
    else
      tmp = tmp->next;
  return (1);
}

void	check_and_send_private(char **args, t_user *user, t_server *serv)
{
  int x;

  if (send_to_chan(args,user, serv))
    send_to_user(args,user, serv);
  for (x = 0; args[x]; x++)
    free(args[x]);
  free(args);
}

void	msg(void *params, t_user *user, t_server *serv)
{
  char	**args;

  if (!strlen(params) || !++params || !(args = str_to_tab(params, ' ')))
    {
      ssend(user->socket, "461 PART : Not enough parameters\r\n");
      return ;
    }
  if (!args[1])
    {
      ssend(user->socket, "412 No text to send\r\n");
      return ;
    }
  check_and_send_private(args, user, serv);
}

void		in_chat_response(char *params, t_user *user)
{
  t_user	*u;

  if (((char *)params)[0] == '/')
    ssend(user->socket, "421 Unknown command\r\n");
  else
    {
      for (u = *user->list; u; u = u->next)
	{
	  if (u == user)
	    continue ;
	  ssend(u->socket, user->nick);
	  ssend(u->socket, ": ");
	  ssend(u->socket, ((char *)params));
	  ssend(u->socket, "\r\n");
	}
    }
}

void		def(void *params, t_user *user, t_server _UNUSED_*serv)
{
  if (!user->chan)
    {
      if (((char *)params)[0] == '/')
	ssend(user->socket, "421 Unknown command\r\n");
      else
	ssend(user->socket, "441 User not in channel\r\n");
    }
  else
    in_chat_response(params, user);
}

void            ping(void _UNUSED_*params, t_user *user, t_server _UNUSED_*serv)
{
  ssend(user->socket, "PONG\r\n");
}
