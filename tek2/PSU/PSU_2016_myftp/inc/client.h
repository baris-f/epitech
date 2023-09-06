#ifndef CLIENT_H_
# define CLIENT_H_

#include <sys/time.h>
#include <sys/types.h>

enum boolean
  {
    FALSE = 0,
    TRUE
  };

enum client_status
  {
    NOT_LOG = 0,
    LOGGED,
    AUTH
  };

enum transfert_mode
  {
    UNSET = 0,
    PASV,
    PORT
  };

typedef	struct	s_data
{
  int		sock;
  int		port;
  char		ip[16];
  int		transfert_mode;
}		t_data;

typedef	struct	s_struct_client
{
  int		sock;
  t_data	data;
  int		isConnected;
  struct timeval tm;
  fd_set	fs;
  char		buff[4096];
  int		isLogged;
  char		path[2048];
}		struct_client;

#endif /* !CLIENT_H_ */
