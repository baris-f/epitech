/*
** pitch.c for pitch in /home/baris_f/rendu/PSU_2015_my_printf
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Thu Nov 19 00:20:24 2015 Florent Baris
** Last update Thu Nov 19 02:18:52 2015 Florent Baris
*/

#include <stdio.h>
#include <stdlib.h>

void	main(int ac, char **av)
{
  char*	stest = "Hello World !";
  int	dtest = 42;
  char	Stest[6] = "coucou";
  unsigned int utest = 3000000000;
  char *ntest = NULL;

  Stest[3] = 24;
  Stest[5] = 7;
  if (my_getnbr(av[1]) == 1)
    {
      printf("\ntest : Hello World !\n\n");
      printf("real : Hello World !\n");
      my_printf("mine : Hello World !\n");
      printf("\ntest : %%s %%c\n\n");
      printf("real : %s %c\n", stest, stest[0]);
      my_printf("mine : %s %c\n", stest, stest[0]);
      printf("\ntest : %%d %%u\n\n");
      printf("real :%d %u \n", dtest, utest);
      my_printf("mine :%d %u\n", dtest, utest);
      printf("\ntest : %%i %%o %%b %%x %%X\n\n");
      printf("real : %i %o %b %x %X\n", dtest, dtest, dtest, dtest);
      my_printf("mine : %i %o %b %x %X\n", dtest, dtest, dtest, dtest, dtest);
      printf("\ntest : %%p %%S\n\n");
      printf("real : %p %S\n", &dtest);
      my_printf("mine : %p %S\n", &dtest, Stest);
      printf("\n\ntest : %%%%\n\n");
      printf("real : %%\n");
      my_printf("mine : %%\n");
    }
  else if (my_getnbr(av[1]) == 2)
    {
      printf("\ntest : %%+d %%+d %% d %% d\n\n");
      printf("real : %+d %+d % d % d\n", dtest, -dtest, dtest, -dtest);
      my_printf("mine : %+d %+d % d % d\n", dtest, -dtest, dtest, -dtest);
      printf("\ntest : |%%10d| |%%-10d| |%%010d| |%%-010d|\n\n");
      printf("real : |%10d| |%-10d| |%010d| |%-010d|\n", dtest, dtest, dtest, dtest);
      my_printf("mine : |%10d| |%-10d| |%010d| |%-010d|\n", dtest, dtest, dtest, dtest);
      printf("\ntest : |%%*d| |%%-*d|\n\n");
      printf("real : |%*d| |%-*d|\n", dtest, dtest, dtest, dtest);
      my_printf("mine : |%*d| |%-*d|\n", dtest, dtest, dtest, dtest);
      printf("\ntest : %%#o %%#x %%#X\n\n");
      printf("real : %#o %#x %#X\n", dtest, dtest, dtest);
      my_printf("mine : %#o %#x %#X\n", dtest, dtest, dtest);
      printf("\ntest : %%%%d %D %%S %%s %%-022p\n");
      printf("\nreal : %%d %D %%S %s %-022p\n", ntest, &ntest);
      my_printf("mine : %%d %D %S %s %-022p\n", ntest, ntest, &ntest);
    }
  else if (my_getnbr(av[1]) == 3)
    {
      printf("\ntest :\n\n");
      printf("real :\n");
      my_printf("mine :\n");
      printf("\ntest :\n\n");
      printf("real :\n");
      my_printf("mine :\n");
    }
}
