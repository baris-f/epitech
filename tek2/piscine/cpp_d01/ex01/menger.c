/*
** menger.c for menger in /home/baris_f/rendu/tek2/cpp_d01/ex01
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Wed Jan  4 12:40:49 2017 baris_f
** Last update Wed Jan  4 13:54:35 2017 baris_f
*/

#include <stdio.h>

int     my_sign(char *str, int *i)
{
  int   sign;

  sign = 1;
  *i = 0;
  while (str[*i] && (str[*i] < '0' || str[*i] > '9'))
    {
      if (str[*i] != '-' && str[*i] != '+')
	return (0);
      if (str[*i] == '-')
	sign = sign * -1;
      (*i)++;
    }
  return (sign);
}

int     gnb(char *str)
{
  int   i;
  int   sign;
  int   tmp;

  tmp = 0;
  sign = my_sign(str, &i);
  while (str[i] && str[i] >= '0' && str[i] <= '9')
    {
      if (tmp * 10 + (str[i] - '0') < tmp)
	return (0);
      tmp = (tmp * 10) + (str[i] - '0');
      i++;
    }
  return (tmp * sign);
}

int	square(int size, int depth, int x, int y)
{
  int	curx;
  int	cury;

  curx = x - size + size / 3;
  cury = y - size + size / 3;
  while (curx <= x + size * 2)
    {
      while (cury <= y + size * 2)
	{
	  if (!(curx == x + size / 3  && cury == y + size / 3))
	    {
	      printf("%03d %03d %03d\n", size / 3, curx, cury);
	      if (depth - 1 > 0)
		square(size / 3, depth - 1, curx, cury);
	    }
	  cury += size;
	}
      cury = y - size + size / 3;
      curx += size;
    }
  return (0);
}

int	menger(int size, int depth)
{
  printf("%03d %03d %03d\n", size / 3, size / 3, size / 3);
  if (depth - 1 > 0)
    square(size / 3, depth - 1, size / 3, size / 3);
  return (0);
}
