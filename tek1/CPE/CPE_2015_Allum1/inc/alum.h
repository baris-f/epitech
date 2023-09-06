#ifndef ALUM_H_
# define ALUM_H_

#include "stdlib.h"
#include "my.h"

typedef struct  s_board
{
  int		width;
  int		line;
  int		*alum;
}               t_board;

void    ais_turn(t_board *bd);
int     nbalum(t_board *bd);
#endif /* !ALUM_H_ */
