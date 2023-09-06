#ifndef STRING_H_
# define STRING_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_String
{
  char	*str;
  void	(*StringInit)(struct s_String *, char const *);
  void	(*StringDestroy)(struct s_String *);
  void	(*assign_s)(struct s_String *, struct s_String const *);
  void  (*assign_c)(struct s_String *, char const *);
  void  (*append_s)(struct s_String *, struct s_String const *);
  void  (*append_c)(struct s_String *, char const *);
  char  (*at)(struct s_String *, size_t);
  void  (*clear)(struct s_String *);
  int   (*size)(struct s_String *);
  int   (*compare_s)(struct s_String *, const struct s_String *);
  int   (*compare_c)(struct s_String *, char const *);
  size_t (*copy)(struct s_String *, char *, size_t, size_t);
  char const*       (*c_str)(struct s_String *);
  int      (*empty)(struct s_String *);
  int	(*find_s)(struct s_String*, const struct s_String *, size_t);
  int	(*find_c)(struct s_String*, char const *, size_t);
  void     (*insert_c)(struct s_String*, size_t, char const *);
  void     (*insert_s)(struct s_String*, size_t, const struct s_String *);
  int      (*to_int)(struct s_String*);
  struct s_String   *(*split_s)(struct s_String *, char);
  char     **(*split_c)(struct s_String *, char);
  void	(*aff)(struct s_String*);
}		String;

void    StringInit(String *this, char const *s);
void    StringDestroy(String *this);
#endif /* !STRING_H_ */
