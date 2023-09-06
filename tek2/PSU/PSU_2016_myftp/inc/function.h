#ifndef FUNCTION_H_
# define FUNCTION_H_

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <strings.h>


#include "client.h"

typedef struct	s_func {
  char		*cmd;
  void		(*fct)(struct_client *);
}		t_func;

void		user(struct_client *);
void		pass(struct_client *);
void		quit(struct_client *);
void		noop(struct_client *);
void		cwd(struct_client *);
void		pwd(struct_client *);
void		delete(struct_client *);
void		help(struct_client *);
void		cdup(struct_client *);
void		xwrite(struct_client *, char *);
int		xread(struct_client *);
char		*buildPath(struct_client *);
void		error(char *);
void		request(struct_client *);
int             initSocket(int);
void            initData(struct_client *);
void            initPath(struct_client *, char *);
void            initClient(struct_client *, int, char *);
void            initSelect(struct_client *);
void            server(int, char *);
int		checkLogStatus(struct_client *);

#endif /* !FUNCTION_H_ */
