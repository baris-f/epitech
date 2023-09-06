/*
** corewar.h for sà in /home/fus/rendu/cpe/CPE_2015_corewar/corewar/gas
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Wed Mar 16 14:09:40 2016 Gaspard Thirion
** Last update Sun Mar 27 22:53:29 2016 Florent Baris
*/

#ifndef COREWAR_H_
# define COREWAR_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "op.h"
#include "my.h"

#define DF_DUMP		3000
#define RS		100

typedef struct  s_chpt
{
  char          *name;
  header_t	head;
  int           addr;
  int		live;
}               t_chpt;

typedef struct  s_ptr
{
  int           *reg;
  unsigned int  addr;
  int		nop;
  t_chpt	*champ;
  struct s_ptr  *nxt;
  struct s_ptr  *prv;
}               t_ptr;

typedef struct  s_vm
{
  unsigned char *map;
  int           cycle;
  int		cycdie;
  int		nb_cycles;
  int		nbl;
}               t_vm;

typedef struct	s_base
{
  t_chpt	*files;
  t_ptr		*ptr;
  t_vm		vm;
}		t_base;

int     parser(int ac, char **av, t_base *base);
int     init(t_base *base);
int     mfree(t_base *base);
int     create_liste(t_base *base);
int     aff_ptr(t_ptr *start, int v);
int     add_ptr(t_base *base, t_ptr *ptr);
int     opt(char **av);
int     initvm(t_vm *vm);
void	setchamps(t_vm *vm, t_chpt *files);
void    getinmap(t_ptr *ptr, t_base *base);
void    live(t_ptr *ptr, t_base *base);
int     isalive(t_base *base);
void    affvm(t_vm *vm);
int	dup_ptr(t_base *base, t_ptr *ptr, unsigned int na);

#endif /* !COREWAR_H_ */
