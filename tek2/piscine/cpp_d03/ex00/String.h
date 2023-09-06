#ifndef STRING_H_
# define STRING_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_String
{
  char *str;
  void	(*StringInit)(struct s_String *, char const *);
  void	(*StringDestroy)(struct s_String *);
}		String;

void    StringInit(String *this, char const *s);
void    StringDestroy(String *this);
#endif /* !STRING_H_ */
