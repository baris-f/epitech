/*
** chaine.c for pfijs in /home/fus/rendu/cpe/CPE_2015_corewar/corewar/gas/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Wed Mar 16 16:48:06 2016 Gaspard Thirion
** Last update Sun Mar 27 23:04:12 2016 Florent Baris
*/

#include "gas.h"

int		aff_ptr(t_ptr *start, int v)
{
  t_ptr		*cur;

  cur = start;
  if (v)
    my_printf("#########################################""\n");
  while (cur->champ)
    {
      if (v)
	{
	  my_printf("prv=%s\t",
		    (cur->prv->champ) ? (cur->prv->champ->name) : ("NULL"));
	  my_printf("cur=%s\t",
		    (cur->champ) ? (cur->champ->name) : ("NULL"));
	  my_printf("nxt=%s\n",
		    (cur->nxt->champ) ? (cur->nxt->champ->name) : ("NULL"));
	  /* my_printf("prv=%d\t", (cur->prv) ? (cur->prv) : (0)); */
	  /* my_printf("cur=%d\t", (cur) ? (cur) : (0)); */
	  /* my_printf("nxt=%d\n\n", (cur->nxt) ? (cur->nxt) : (0)); */
	}
      else
	my_printf("%s\n", cur->champ->name);
      cur = cur->nxt;
    }
  return (0);
}

int		dup_ptr(t_base *base, t_ptr *ptr, unsigned int na)
{
  t_ptr		*last;
  t_ptr		*tmp;

  if ((tmp = malloc(sizeof(t_ptr))) == NULL)
    return (-1);
  last = base->ptr->prv->prv;
  tmp->champ = ptr->champ;
  tmp->addr = na;
  tmp->nop = 0;
  tmp->nxt = base->ptr->prv;
  tmp->prv = last;
  last->nxt = tmp;
  base->ptr->prv->prv = tmp;
  return (0);
}

int		create_liste(t_base *base)
{
  t_ptr		*tmp;
  t_ptr		*nxt;
  int		i;

  if ((base->ptr = malloc(sizeof(t_ptr))) == NULL)
    return (-1);
  tmp = base->ptr;
  i = CHP_NB;
  while (--i >= 0)
    if (base->files[i].name)
      {
	nxt = tmp;
	if ((tmp = malloc(sizeof(t_ptr))) == NULL)
	  return (-1);
	tmp->champ = &(base->files[i]);
	tmp->nop = 1;
	tmp->nxt = nxt;
	nxt->prv = tmp;
      }
  tmp->prv = base->ptr;
  base->ptr->nxt = tmp;
  base->ptr = tmp;
  return (0);
}
