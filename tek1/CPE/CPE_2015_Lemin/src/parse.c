/*
** main.c for djo in /home/fus/rendu/cpe/CPE_2015_lemin
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Thu Mar 31 15:32:49 2016 Gaspard Thirion
** Last update Mon Apr 25 16:10:33 2016 lucas duval
*/

#include "lemin.h"

int	add_tab(t_base *base, int *j, int mode)
{
  char **tmp;
  char	*ttmp;
  int	k;

  if (mode == 1 || mode == 2)
    {
      ttmp = base->line;
      base->line = get_next_line(0);
    }
  if (base->line[0] == '#')
    return (0);
  k = -1;
  tmp = my_str_to_wordtab(base->line, ' ');
  if (tmp[0][0] == '#')
    return (0);
  if (tmp[0] && tmp[1] && tmp[2])
    {
      if (mode == 1)
	{
	  if (base->start != 0)
	    return (-1);
	  else
	    {
	      my_printf("%s\n", ttmp);
	      free(ttmp);
	      base->start = *j;
	    }
	}
      else if (mode == 2)
	{
	  if (base->end != 0)
	    return (-1);
	  else
	    {
	      my_printf("%s\n", ttmp);
	      free(ttmp);
	      base->end = *j;
	    }
	}
      base->node = my__realloc(base->node, sizeof(t_node) * (*j + 1),
			       sizeof(t_node) * *j);
      base->node[*j].mem = 0;
      base->node[*j].nb_link = 0;
      base->node[*j].link = malloc(sizeof(int *) * (base->node[*j].nb_link + 1));
      while (++k < *j)
	if (my_strcmp(tmp[0], base->node[k].name) == 0)
	  return (-1);
      base->node[*j].name = tmp[0];
      base->node[*j].pos.x = my_getnbr(tmp[1]);
      base->node[*j].pos.y = my_getnbr(tmp[2]);
      (*j)++;
    }
  free(tmp);
  return (0);
}

int	check_double(t_base *base, int dest, int src)
{
  int  i;

  i = -1;
  while (++i < base->node[dest].nb_link)
    if (base->node[dest].link[i] == src)
      return (0);
  return (1);
}

int	add_link(t_base *base, int k)
{
  char	**tmp;
  int	nA;
  int	nB;
  int	j;

  if (k == 0 || k == 1)
    return (0);
  tmp = my_str_to_wordtab(base->line, '-');
  if (tmp[0] && tmp[1])
    {
      j = -1;
      while (++j < k && (my_strcmp(tmp[0], base->node[j].name) != 0));
      nA = j;
      j = -1;
      while (++j < k && (my_strcmp(tmp[1], base->node[j].name) != 0));
      nB = j;
      if (nA >= k || nB >= k)
	return (-1);
      if (nA != nB)
	{
	  if (check_double(base, nA, nB))
	    {
	      base->node[nA].link = my__realloc(base->node[nA].link, sizeof(int *)
						* (base->node[nA].nb_link + 1),
						sizeof(int*) * (base->node[nA].nb_link));
	      base->node[nA].link[base->node[nA].nb_link] = nB;
	      base->node[nA].nb_link++;
	    }
	  if (check_double(base, nB, nA))
	    {
	      base->node[nB].link = my__realloc(base->node[nB].link, sizeof(int *)
						* (base->node[nB].nb_link + 1),
						sizeof(int*) * (base->node[nB].nb_link));
	      base->node[nB].link[base->node[nB].nb_link] = nA;
	      base->node[nB].nb_link++;
	    }
	}
    }
  free(tmp);
  return (0);
}

int	get_line(t_base *base)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  base->start = 0;
  base->end = 0;
  base->node = malloc(sizeof(t_node) * (j + 1));
  while ((base->line = get_next_line(0)) != 0)
    {
      if (i == 0)
	{
	  base->nb_four = my_getnbr(base->line);
	  if ((my_str_isnum(base->line) != 1) || (base->nb_four < 1))
	    {
	      my_printf("Erreur nombre fourmi\n");
	      return (-1);
	    }
	}
      if (match(base->line, "*start"))
	{
	  if (add_tab(base, &j, 1) == -1)
	    return (-1);
	}
      else if (match(base->line, "*end"))
	{
	  if (add_tab(base, &j, 2) == -1)
	    return (-1);
	}
      else if (match(base->line, "* * *"))
	{
	  if (add_tab(base, &j, 0) == -1)
	    return (-1);
	}
      else if (match(base->line, "*-*"))
	if (j != 1)
	  if (add_link(base, j) == -1)
	    return (-1);
      i++;
      my_printf("%s\n", base->line);
      free(base->line);
    }
  base->node = my__realloc(base->node, sizeof(t_node) * (j + 1),
			   sizeof(t_node) * j);
  base->node[j].name = NULL;
  base->nb_node = j;
  return (0);
}
