#include "common.h"

void		error(const char *error)
{
  perror(error);
  exit(EXIT_FAILURE);
}
