/*
** dante.h for s in /home/fus/taff/dante/inc
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Tue May  3 21:23:23 2016 Gaspard Thirion
** Last update Thu May 26 03:26:55 2016 Gaspard Thirion
*/

#ifndef DANTE_H_
# define DANTE_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include "my.h"

#define	SIZE		2048
#define	TIME		10000000
#define	VERB		0
#define	VVERB		0

#define	GET(n, m)	(((n) >> (m)) & 1)
#define	SET(n, m)	((n) |= (1 << (m)))
#define	UNSET(n, m)	((n) &= ~(1 << (m)))

#define	ABS(v)		((v < 0) ? (v * -1) : (v))
#define CUR             maz->map[list[(*cur)]]

typedef enum	e_mask
  {
    FREE	= 0,
    OK		,
    KO		,

    CAN_DOWN	,
    CAN_RIGHT	,
    CAN_LEFT	,
    CAN_UP	,

    PREV_DOWN	,
    PREV_RIGHT	,
    PREV_LEFT	,
    PREV_UP	,

    LOCK
  }		t_mask;

typedef struct	s_ast
{
  int		i;
  int		k;
  int		sofar;
}		t_ast;

typedef struct	s_maz
{
  int		x;
  int		y;
  int		size;
  unsigned int	*map;
}		t_maz;

int		affmaz(t_maz*, int);
int		parser(t_maz*, int);
char		*recup(int);
int		solver(t_maz*, int);
void		clean(t_maz*, int, int);
void		addnode(t_ast*, int, int, int);

#endif /* !DANTE_H_ */
