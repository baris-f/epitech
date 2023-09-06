/*
** mul_div.c for mul_div in /home/baris_f/rendu/tek2/cpp_d02m/ex00
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Thu Jan  5 09:08:04 2017 baris_f
** Last update Thu Jan  5 09:17:32 2017 baris_f
*/

void	add_mul_4param(int first, int second, int *add, int *mul)
{
  *add = first + second;
  *mul = first * second;
}

void	add_mul_2param(int *first, int *second)
{
  int	add;
  int	mul;

  add = *first + *second;
  mul = *first * *second;
  *first = add;
  *second = mul;
}
/*
#include <stdio.h>

int main ( void )
{
  int first ;
  int second ;
  int add_res ;
  int mul_res ;
  first = 5 ;
  second = 6 ;
  add_mul_4param ( first , second , &add_res , &mul_res ) ;
  printf ( "%d + %d = %d\n " , first , second , add_res ) ;
  printf ( "%d * %d = %d\n " , first , second , mul_res ) ;
  add_res = first ;
  mul_res = second ;
  add_mul_2param (&add_res , &mul_res ) ;
  printf ( "%d + %d = %d\n " , first , second , add_res ) ;
  printf ( "%d * %d = %d\n " , first , second , mul_res ) ;
  return (0) ;
}
*/
