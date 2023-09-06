/*
** tab_to_2dtab.c for tab in /home/baris_f/rendu/tek2/cpp_d02m/ex02
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Thu Jan  5 09:45:53 2017 baris_f
** Last update Thu Jan  5 10:13:55 2017 baris_f
*/

#include <stdlib.h>
#include <stdio.h>

void	tab_to_2dtab(int *tab, int lenght, int width, int ***res)
{
  if (!(*res = malloc(sizeof(int*) * (lenght + 1))))
      return ;
  for (int y = 0; y < lenght; y++)
    if (((*res)[y] = malloc(sizeof(int) * (width + 1))))
      for (int x = 0; x < width; x++)
	(*res)[y][x] = tab[y * width + x];
}
/*
int main(void)
{
  int **tab_2d ;
  int tab[42] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41};

  tab_to_2dtab(tab, 7, 6, &tab_2d);
  printf("tab2 [%d ][%d ] = %d\n " , 0, 0, tab_2d[0][0]);
  printf("tab2 [%d ][%d ] = %d\n " , 6, 5, tab_2d[6][5]);
  printf("tab2 [%d ][%d ] = %d\n " , 4, 4, tab_2d[4][4]);
  printf("tab2 [%d ][%d ] = %d\n " , 0, 3, tab_2d[0][3]);
  printf("tab2 [%d ][%d ] = %d\n " , 3, 0, tab_2d[3][0]);
  printf("tab2 [%d ][%d ] = %d\n " , 4, 2, tab_2d[4][2]);
  return(0);
}
*/
