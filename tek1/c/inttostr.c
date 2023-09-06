#include <stdlib.h>

char	*tostr(int nb)
{
  int	len;
  int	cp;
  char	*str;

  cp = nb;
  len = 0;
  while (cp > 0)
    {
      len++;
      cp /= 10;
      printf("%d %d\n", len, cp);
    }
  if ((str = malloc(sizeof(char) * len + 1)) == NULL)
    return (NULL);
  while (nb > 0)
    {
      len--;
      str[len] = nb % 10 + 48;
      nb /= 10;
    }
  return(str);
}

/* int	main(char ac, char **av) */
/* { */
/*   printf("nb : %d tostr(%d) = %s\n", atoi(av[1]), atoi(av[1]), tostr(atoi(av[1]))); */
/* } */
