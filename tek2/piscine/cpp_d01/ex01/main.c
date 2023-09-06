/*
** main.c for menger in /home/baris_f/rendu/tek2/cpp_d01/ex01
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Wed Jan  4 12:34:57 2017 baris_f
** Last update Wed Jan  4 13:57:34 2017 baris_f
*/

#include <stdio.h>

int     menger(int size, int depth);
int     gnb(char *str);

int	main(int ac, char** av)
{
  if (ac != 3 || gnb(av[1]) % 3 != 0 || gnb(av[1]) < gnb(av[2]))
    {
      printf("\n");
      return (0);
    }
  menger(gnb(av[1]), gnb(av[2]));
}
