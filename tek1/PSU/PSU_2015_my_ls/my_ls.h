#ifndef MY_LS_H_
# define MY_LS_H_

typedef struct s_chain
{
  char			*name;
  struct s_chain	*next;
} t_chaine;

int		my_printf(char *s, ...);
void            my_rbubble(t_chaine *list);
void            my_bubble(t_chaine *list);
void		*my_strlowcase(char *str);
int		my_strlen(char *str);
int		isalph(char c);
int             isalphanum(char c);
void		my_putchar(char c);
void		my_putstr(char *str);
char		*my_strdup(char *src);
int		my_strcmpls(char *s1, char *s2);

#endif /* !MY_LS_H_ */
