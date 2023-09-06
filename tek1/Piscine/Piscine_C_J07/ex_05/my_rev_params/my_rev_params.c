/*
** my_rev_params.c for my_rev_params in /home/baris_f/rendu/Piscine_C_J07/ex_05/my_rev_params
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Tue Oct  6 13:56:26 2015 Florent Baris
** Last update Thu Oct  8 09:25:33 2015 Florent Baris
*/

int     main(int argc, char **argv)
{
  int   i;

  i = argc;
  while (i > 0)
    {
      my_putstr(argv[i - 1]);
      my_putchar('\n');
      i--;
    }
}
