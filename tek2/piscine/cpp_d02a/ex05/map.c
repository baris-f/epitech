/*
** map.c for map in /home/baris_f/rendu/tek2/cpp_d02a/ex05
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Thu Jan  5 22:13:29 2017 baris_f
** Last update Fri Jan  6 00:08:29 2017 baris_f
*/

#include <stdlib.h>
#include <stdio.h>
#include "map.h"
#include "generic_list.h"

t_key_comparator key_cmp;

unsigned int    map_get_size(t_map map)
{
  return (list_get_size(map));
}

t_bool          map_is_empty(t_map map)
{
  return (list_is_empty(map));
}

t_key_comparator    key_cmp_container(t_bool store, t_key_comparator new_key_cmp)
{
  if (store == TRUE)
    key_cmp = new_key_cmp;
  return (key_cmp);
}

int     pair_comparator(void *first, void *second)
{
  t_pair *f;
  t_pair *s;

  f = (t_pair*)first;
  s = (t_pair*)second;
  return(key_cmp(f->key, s->key));
}

t_bool  map_add_elem(t_map *map_ptr, void *key, void *value, t_key_comparator key_cmp)
{
  t_list	tmp;
  t_pair	*newnode;

  tmp = *map_ptr;
  if (key == NULL)
    return (FALSE);
  if (tmp != NULL)
    {
      while (tmp && tmp->next != NULL)
	{
	  if (key_cmp(key, ((t_pair *)(tmp->value))->key) == 0)
	    {
	      ((t_pair*)(tmp->value))->value = value;
	      return (TRUE);
	    }
	  tmp = tmp->next;
	}
    }
  if ((newnode = malloc(sizeof(t_node))) == NULL)
    return (FALSE);
  newnode->key = key;
  newnode->value = value;
  return (list_add_elem_at_back(map_ptr, newnode));
}

t_bool  map_del_elem(t_map *map_ptr, void *key, t_key_comparator key_cmp)
{
  t_list        tmp;

  if (map_ptr == NULL || key == NULL)
    return (FALSE);
  tmp = *map_ptr;
  while (tmp && tmp->next && key_cmp(((t_pair*)(tmp->value))->key, key))
    tmp = tmp->next;
  if (key_cmp(((t_pair*)(tmp->value))->key, key))
    return (FALSE);
  printf("apres\n");
  return (list_del_node(map_ptr, tmp));
}

void    *map_get_elem(t_map map, void *key, t_key_comparator key_cmp)
{
  t_node        *tmp;

  if (map == NULL || key == NULL)
    return (NULL);
  tmp = map;
  while (tmp && tmp->next && key_cmp(((t_pair*)(tmp->value))->key, key))
    tmp = tmp->next;
  if (key_cmp(((t_pair*)(tmp->value))->key, key))
    return (NULL);
  return (((t_pair*)(tmp->value))->value);

}
/*
int     int_comparator(void *first, void *second)
{
  int   val1;
  int   val2;

  val1 = *(int*)first;
  val2 = *(int*)second;
  return (val1 - val2);
}

int     main(void)
{
  t_map map=NULL;
  int   first_key=1;
  int   second_key=2;
  int   third_key=3;
  char  *first_value="first";
  char  *first_value_rw="first_rewrite_because_we_delete_it_beforelool";
  char  *second_value="second";
  char  *third_value="third";
  char  **data;

  map_add_elem(&map, &first_key, &first_value, &int_comparator);
  data=(char**)map_get_elem(map, &first_key, &int_comparator);
  printf("The [%d] key corresponds to the value [%s]\n", first_key, *data);
  map_add_elem(&map, &first_key, &first_value_rw, &int_comparator);
  map_add_elem(&map, &second_key, &second_value, &int_comparator);
  map_add_elem(&map, &third_key, &third_value, &int_comparator);
  data=(char**)map_get_elem(map, &second_key, &int_comparator);
  printf("The [%d] key corresponds to the value [%s]\n", second_key, *data);
  data=(char**)map_get_elem(map, &first_key, &int_comparator);
  printf("The [%d] key corresponds to the value [%s]\n", first_key, *data);
  data=(char**)map_get_elem(map, &third_key, &int_comparator);
  printf("The [%d] key corresponds to the value [%s]\n", third_key, *data);

  map_del_elem(&map, &third_key, &int_comparator);
  data=(char**)map_get_elem(map, &third_key, &int_comparator);
  printf("The [%d] key corresponds to the value [%s]\n", third_key, *data);
  return (0);
}
*/
