#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void    mpc(char c)
{
  write(1, &c, 1);
}

int	main(int ac, char** av)
{
  char a[] = "salut";
  char b[] = "salat";

  printf("%d\n", (int)strlen(a));
  printf("%d\n", strcmp(a, b));
  printf("[%s]\n", rindex(b, 'a'));
  //mpc((rindex(b, 0) - 1)[0]);
  mpc('\n');
  //mpc((rindex(b, 0) - 1)[0]);
  mpc('\n');
  printf("[%s]\n", strchr(b, 'a'));
  return (0);
}
