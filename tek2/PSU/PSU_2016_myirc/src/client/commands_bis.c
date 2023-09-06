#include "client.h"

char		*list_users(void *a, void __attribute__((unused))*b)
{
  t_client	*c;

  c = (t_client *)a;
  if (!c->connected)
    return (strdup("00PS: Connect to IRC server first."));
  return (strdup("NAMES\r\n"));
}

char		*send_msg_to_user(void __attribute__((unused))*a, void *b)
{
  int		i;
  int		s;
  char		*f;
  t_request	*r;

  r = (t_request *)b;
  if (r->arg && r->arg[0] && r->arg[1])
    {
      !(f = malloc(256)) ? error("malloc") : bzero(f, 256);
      sprintf(f, "PRIVMSG %s %s ", r->arg[0], r->arg[1]);
      if (s = strlen(f), r->arg[2])
	{
	  for (i = 2; r->arg[i]; i++)
	    {
	      !(f = realloc(f, s + strlen(r->arg[i]) + 2)) ? error("realloc") : 0;
	      !(f = strcat(f, r->arg[i])) ? error("strcat") : 0;
	      f[s += strlen(r->arg[i])] = 0;
	      r->arg[i + 1] ? strcat(f, " ") : 0;
	      f[s += 1] = 0;
	    }
	}
      !(f = realloc(f, s + 3)) ? error("realloc") : 0;
      return (f = strcat(f, "\r\n\0"));
    }
  return (strdup("PRIVMSG\r\n"));
}

char		*send_file_to_user(void *a, void *b)
{
  char		*ret;
  t_client	*c;
  t_request	*r;

  ret = NULL;
  c = (t_client *)a;
  r = (t_request *)b;
  if (!c->connected)
    return (strdup("00PS: Connect to IRC server first."));
  if (r->arg && r->arg[0] && r->arg[1])
    {
      !(ret = malloc(256)) ? error("malloc") : bzero(ret, 256);
      sprintf(ret, "SENDFILE %s %s\r\n", r->arg[0], r->arg[1]);
      return (ret);
    }
  return (strdup("SENDFILE\r\n"));
}

char		*accept_file_from_user(void *a, void *b)
{
  char		*ret;
  t_client	*c;
  t_request	*r;

  ret = NULL;
  c = (t_client *)a;
  r = (t_request *)b;
  if (!c->connected)
    return (strdup("00PS: Connect to IRC server first."));
  if (r->arg && r->arg[0])
    {
      !(ret = malloc(256)) ? error("malloc") : bzero(ret, 256);
      sprintf(ret, "ACCEPTFILE %s\r\n", r->arg[0]);
      return (ret);
    }
  return (strdup("ACCEPTFILE\r\n"));
}

char		*quit_client(void __attribute__((unused))*a, void *req)
{
  int		i;
  int		s;
  char		*f;
  t_request	*r;

  r = (t_request *)req;
  !(f = malloc(256)) ? error("malloc") : bzero(f, 256);
  if (r->arg && r->arg[0] && index(r->arg[0], ':'))
    {
      f = strdup("QUIT ");
      s = strlen(f);
      for (i = 0; r->arg[i]; i++)
	{
	  !(f = realloc(f, s + strlen(r->arg[i]) + 2)) ? error("realloc") : 0;
	  !(f = strcat(f, r->arg[i])) ? error("strcat") : 0;
	  f[s += strlen(r->arg[i])] = 0;
	  r->arg[i + 1] ? strcat(f, " ") : 0;
	  f[s += 1] = 0;
	}
      !(f = realloc(f, s + 3)) ? error("realloc") : 0;
      f = strcat(f, "\r\n\0");
      return (f);
    }
  return (strdup("QUIT\r\n"));
}
