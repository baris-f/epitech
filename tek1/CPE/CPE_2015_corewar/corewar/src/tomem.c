/*
** main.c for okd in /home/fus/rendu/cpe/CPE_2015_corewar/gas/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Tue Mar 15 10:09:40 2016 Gaspard Thirion
** Last update Sun Mar 27 22:30:59 2016 Florent Baris
*/

#include "corewar.h"

unsigned char    *get_cor(char *filepath);

typedef struct	s_put
{
  unsigned char *buff;
  int           idx;
  int           max;
}		t_put;

void		putin2(t_vm *vm, t_put *put, t_chpt *files, int i)
{
  i--;
  files->head.prog_size = 0;
  put->max += sizeof(files->head.prog_size) + 4;
  while (++i < put->max)
    {
          files->head.prog_size += put->buff[i] * 1 <<
	    (32 - ((i - (put->max - sizeof (files->head.prog_size))) + 1) * 8);
    }
  my_printf("prog_size : %d\n", files->head.prog_size);
  i--;
  put->max += COMMENT_LENGTH;
  while (++i < put->max)
    files->head.comment[i - (put->max - COMMENT_LENGTH)] = put->buff[i];
  my_printf("comment : %s\n", files->head.comment);
  i--;
  while (++i < put->max + files->head.prog_size)
    vm->map[(put->idx + i - put->max) % MEM_SIZE] = put->buff[i];
  my_printf("\n");
}

void		putin(t_vm *vm, int idx, t_chpt *files)
{
  int		i;
  t_put		put;

  put.buff = get_cor(files->name);
  put.idx = idx;
  free(files->name);
  files->name = NULL;
  i = -1;
  files->head.magic = 0;
  put.max = sizeof(files->head.magic);
  while (++i < put.max)
    files->head.magic += put.buff[i] * 1 << (32 - (i + 1) * 8);
  my_printf("\n\nmagic number : %x\n", files->head.magic);
  if (files->head.magic != COREWAR_EXEC_MAGIC)
    return ;
  put.max += PROG_NAME_LENGTH;
  i--;
  while (++i < put.max)
    files->head.prog_name[i - sizeof(files->head.magic)] = put.buff[i];
  files->name = files->head.prog_name;
  my_printf("prog name : %s\n", files->head.prog_name);
  putin2(vm, &put, files, i);
}

void		setchamps(t_vm *vm, t_chpt *files)
{
  int		i;
  int		nbm;

  nbm = 0;
  i = -1;
  while (++i < 4)
    if (files[i].name != NULL)
      nbm++;
  i = -1;
  while (++i < 4)
    if (files[i].name != NULL)
      {
	printf("%s\n", files[i].name);
	files[i].addr = (MEM_SIZE / nbm) * i;
	putin(vm, files[i].addr % MEM_SIZE, &files[i]);
      }
  sleep(1);
}

void	affvm(t_vm *vm)
{
  int	i;

  i = -1;
  while (++i < MEM_SIZE)
    my_printf("%X ", vm->map[i]);
  my_printf("\n");
}

int	initvm(t_vm *vm)
{
  int   i;

  vm->cycle = -1;
  if ((vm->map = malloc(sizeof(unsigned char) * MEM_SIZE)) == NULL)
    return (-1);
  i = -1;
  while (++i < MEM_SIZE)
    vm->map[i] = 0;
  return (0);
}
