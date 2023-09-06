/*
** simple_btree.c for tree in /home/baris_f/rendu/tek2/cpp_d02a/ex01
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Thu Jan  5 17:39:38 2017 baris_f
** Last update Thu Jan  5 20:01:09 2017 baris_f
*/

#include <stdlib.h>
#include <stdio.h>
#include "simple_btree.h"

t_bool          btree_is_empty(t_tree tree)
{
  if (tree == NULL)
    return (TRUE);
  return (FALSE);
}

unsigned int    btree_get_size(t_tree tree)
{
  unsigned int	nb;

  nb = 1;
  if (tree == NULL)
    return (0);
  if (tree->left != NULL)
    nb += btree_get_size(tree->left);
  if (tree->right != NULL)
    nb += btree_get_size(tree->right);
  return (nb);
}

unsigned int    btree_get_depth(t_tree tree)
{
  unsigned int  left;
  unsigned int	right;

  left = 1;
  right = 1;
  if (tree == NULL)
    return (0);
  if (tree->left != NULL)
    left += btree_get_depth(tree->left);
  if (tree->right != NULL)
    right += btree_get_depth(tree->right);
  if (left > right)
    return (left);
  else
    return (right);
}

t_bool  btree_create_node(t_tree *root_ptr, double value)
{
  t_node	*newnode;

  if ((newnode = malloc(sizeof(t_node))) == NULL)
    return (FALSE);
  newnode->value = value;
  newnode->left = NULL;
  newnode->right = NULL;
  *root_ptr = newnode;
  return (TRUE);
}

t_bool  btree_delete(t_tree *root_ptr)
{
  if (*root_ptr == NULL)
    return (FALSE);
  if ((*root_ptr)->left != NULL)
    btree_delete(&((*root_ptr)->left));
  if ((*root_ptr)->right != NULL)
    btree_delete(&((*root_ptr)->right));
  return (TRUE);
}

double  btree_get_max_value(t_tree tree)
{
  unsigned int  left;
  unsigned int  right;

  if (tree == NULL)
    return (0);
  left = tree->value;
  right = tree->value;
  if (tree->left != NULL)
    left = btree_get_max_value(tree->left);
  if (tree->right != NULL)
    right = btree_get_max_value(tree->right);
  if (left > right && left > tree->value)
    return (left);
  else if (right > left && right > tree->value)
    return (right);
  else
    return (tree->value);
}

double  btree_get_min_value(t_tree tree)
{
  unsigned int  left;
  unsigned int  right;

  if (tree == NULL)
    return (0);
  left = tree->value;
  right = tree->value;
  if (tree->left != NULL)
    left = btree_get_min_value(tree->left);
  if (tree->right != NULL)
    right = btree_get_min_value(tree->right);
  if (left < right && left < tree->value)
    return (left);
  else if (right < left && right < tree->value)
    return (right);
  else
    return (tree->value);
}
/*
int     main()
{
  t_tree        tree = NULL;
  t_tree        left_sub_tree;
  unsigned int  size;
  unsigned int  depth;
  double        max;
  double        min;

  btree_create_node(&tree, 42.5);
  btree_create_node(&(tree->right), 100);
  btree_create_node(&(tree->left), 20);
  left_sub_tree = tree->left;
  btree_create_node(&(left_sub_tree->left), 30);
  btree_create_node(&(left_sub_tree->right), 5);
  size = btree_get_size(tree);
  depth = btree_get_depth(tree);
  printf("The tree is the size of %u\n", size);
  printf("the tree's depteh is %u\n", depth);
  max = btree_get_max_value(tree);
  min = btree_get_min_value(tree);
  printf("The values of the tree goind from %f to %f\n", min, max);
  btree_delete(&left_sub_tree);
  return (0);
}
*/
