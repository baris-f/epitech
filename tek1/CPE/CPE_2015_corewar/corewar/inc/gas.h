/*
** corewar.h for dgh in /home/fus/rendu/cpe/CPE_2015_corewar/gas/inc
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Tue Mar 15 10:13:38 2016 Gaspard Thirion
** Last update Fri Mar 18 18:40:23 2016 Gaspard Thirion
*/

#ifndef GAS_H_
# define GAS_H_

#include "corewar.h"

#define	EXT	"*.cor"
#define	CHP_NB	4

typedef struct	s_mem
{
  int		i;
  int		d;
  int		idx;
  unsigned int	addr;
}		t_mem;

#endif /* !GAS_H_ */
