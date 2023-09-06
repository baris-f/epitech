#ifndef _SERVER_H_
# define _SERVER_H_

#include "common.h"
#include "network.h"

#define MAX_USERS		128
#define MAX_CONN		MAX_USERS + 5
#define MAX_CMD			12

typedef struct s_user		t_user;
typedef struct s_channel	t_channel;
typedef struct s_server		t_server;

struct				s_user
{
  char				auth;
  char				*chan;
  int				socket;
  char				*ip;
  char				*nick;
  char				*real;
  t_ring_buffer			*rb;
  t_user			*next;
  t_user			**list;
};

struct				s_channel
{
  char				*name;
  t_user			*users;
  t_channel			*next;
};

struct				s_server
{
  char				*port;
  int				socket;
  t_channel			*channels;
  t_user			*users_alone;
  t_user			*user_index[MAX_CONN];
  fd_set			master;
  char				*cmd[MAX_CMD];
  void				(*cmd_handler[MAX_CMD])(void *, t_user *,
							t_server *);
};

int8_t				g_run;
int				usage();
void				close_handler(int);
void				release_server(t_server *);
void				set_handler(t_server *);
void				set_server(t_server *, char *);
t_server			*init_server(char *);
void				refuse_new_connection(t_user *, t_server *);
void				handle_new_connection(int *, t_server *);
void				remove_connection(t_user *, t_server *);
void				interpret_command(char *, t_user *, t_server *);
int				substring_pattern(char *, char *);
void				input_interpret(t_user *, t_server *);
void				handle_io_connection(t_user *, t_server *);
void				watch_sockets(int *, int *, fd_set *,
					      t_server *);
void				handler_server(t_server *);
int				bind_local(struct addrinfo *, int*);
int				bind_port(char *);
void				channel_push(t_channel *, t_channel **);
void				channel_destroy(t_channel *);
void				channel_release(t_channel *);
void				user_push(t_user *, t_user **);
t_user				*user_pop(t_user *, t_user *);
void				user_destroy(t_user *);
void				user_release(t_user *);
void				user_transfer(t_user *, t_user **);
void				nick(void *, t_user *, t_server *);
void				send_greetings(t_user *);
void				user(void *, t_user *, t_server *);
void				list(void *, t_user *, t_server *);
void				join(void *, t_user *, t_server *);
void				part(void *, t_user *, t_server *);
void				names(void *, t_user *, t_server *);
void				msg(void *, t_user *, t_server *);
void				sendfile(void *, t_user *, t_server *);
void				acceptfile(void *, t_user *, t_server *);
void				quit(void *, t_user *, t_server *);
void				def(void *, t_user *, t_server *);
void				ping(void *, t_user *, t_server *);

#endif /* !_SERVER_H_ */
