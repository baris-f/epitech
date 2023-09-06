/*
** bistro.h for Piscine_C_bistromathique in /home/linux/rendu/Piscine_C_bistromathique
**
** Made by thirion gaspard
** Login   <thirio_b@epitech.net>
**
** Started on  Tue Oct 27 23:45:17 2015 thirion gaspard
** Last update Sun Nov  1 21:27:15 2015 Gaspard Thirion
*/

#ifndef BISTRO_H_
#define BISTRO_H_

#define OP_OPEN_PARENT_IDX 0
#define OP_CLOSE_PARENT_IDX 1
#define OP_PLUS_IDX 2
#define OP_SUB_IDX 3
#define OP_NEG_IDX 3
#define OP_MULT_IDX 4
#define OP_DIV_IDX 5
#define OP_MOD_IDX 6

#define SYNT_ERR_MSG "syntax error"

struct  s_stock_char
{
  char  *tmp;
  char  *rest;
  char  *nbr;
  char  *div;
  int   i;
  int   pos;
  int   prevpos;
};

typedef struct s_stock_char t_stock_char;

char     *divinf(char *nbr, char *div);
int	char_isnum(char c);
int	char_isop(char c);
void	number(char **pstr, char *tmp);
void	spacesout(char *str, int i, int j);
void	factors(char **pstr, char *tmp, char **tot);
void	summands(char **pstr, char *ret, char **tot, char **tmp);
char	*eval_expr(char *base, char *op, char *str, unsigned int size);

#endif /* !BISTRO_H_ */
