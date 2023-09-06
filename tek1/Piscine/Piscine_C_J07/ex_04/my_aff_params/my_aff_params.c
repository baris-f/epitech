/*
** my_aff_params.c for my_aff_params in /home/baris_f/rendu/Piscine_C_J07/ex_04/my_aff_params
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Tue Oct  6 13:52:33 2015 Florent Baris
** Last update Thu Oct  8 09:24:46 2015 Florent Baris
*/

int     main(int argc, char **argv)
{
  int   i;

  i = 0;
  while (i < argc)
    {
      my_putstr(argv[i]);
      my_putchar('\n');
      i++;
    }
}
