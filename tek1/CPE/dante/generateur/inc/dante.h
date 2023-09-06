/*
** dante.h for s in /home/fus/taff/dante/inc
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Tue May  3 21:23:23 2016 Gaspard Thirion
** Last update Fri Jun  3 13:22:30 2016 Florent Baris
*/

#ifndef DANTE_H_
# define DANTE_H_

/*
**INCLUDES
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include "my.h"

#define	PRCT		85

/*
**CELLULAR_CONFIG
*/
#define	NB_TURN		50
#define	INITIAL_CHANCE	60
#define	BIRTH_LIM	4
#define	KILL_LIM	3
/*
**MAZ_STRUCT
*/
typedef struct	s_maz
{
  int		type;
  int		x;
  int		y;
  int		size;
  unsigned long	seed;
  char		*tab;
  int		*prev;
}		t_maz;

/*
**PROTOTYPES
*/
int		mrand(int, int, unsigned long);
void		affmaz(t_maz*, int);
int		outmaz(t_maz*, char*);
int		perfect(t_maz*);
int		imperfect(t_maz*);
int		cellular(t_maz*);
int		initmaz(t_maz*);
int		match(char*, char*);
#endif /* !DANTE_H_ */
