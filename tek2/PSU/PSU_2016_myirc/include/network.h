#ifndef _NETWORK_H_
# define _NETWORK_H_

# include <sys/types.h>
# include <sys/socket.h>
# include <sys/types.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>

# define BACKLOG	5

void		ssend(int, char *);
void		snd(char *, int *, int);

#endif /* !_NETWORK_H_ */
