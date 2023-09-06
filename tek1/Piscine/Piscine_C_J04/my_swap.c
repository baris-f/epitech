/*
** my_swap.c for my_swap in /home/baris_f/rendu/Piscine_C_J04
** 
** Made by Florent Baris
** Login   <baris_f@epitech.net>
** 
** Started on  Thu Oct  1 08:55:32 2015 Florent Baris
** Last update Fri Oct  2 17:22:41 2015 Florent Baris
*/

int	my_swap(int *a, int *b)
{
  int	swap;

  swap = *a;
  *a = *b;
  *b = swap;
}
