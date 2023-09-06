#include "server.h"

int		usage()
{
  fprintf(stderr, "[USAGE]: ./server [PORT]\n");
  return (1);
}

int		main(int ac, char **av)
{
  t_server	*serv;

  if (ac != 2)
    return (usage());
  serv = init_server(av[1]);
  handler_server(serv);
  release_server(serv);
  return (0);
}
