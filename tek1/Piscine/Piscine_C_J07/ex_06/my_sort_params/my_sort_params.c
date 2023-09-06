/*
** my_sort_params.c for my_sort_params in /home/baris_f/rendu/Piscine_C_J07/ex_06/my_sort_params
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Tue Oct  6 14:04:13 2015 Florent Baris
** Last update Thu Oct  8 09:24:02 2015 Florent Baris
*/

void    piggypiggy(int **tab, int size, int swap)
{
  int   i;
  int	j;
  char	*temp;

  j = 0;
  while (j < size)
    {
      i = 1;
      while (i < size - j)
	{
	  if (my_strcmp(tab[i] > tab[i - 1]) < 0)
	    {
	      temp = tab[i];
	      tab[i] = tab[i - 1];
	      tab[i - 1] = temp;
	    }
	  i++;
	}
      j++;
    }
}

int     main(int argc, char **argv)
{
  int   i;

  piggypiggy(argv, argc);
  i = 0;
  while (argv[i])
    {
      my_putstr(argv[i]);
      my_putchar('\n');
      i++;
    }
}
