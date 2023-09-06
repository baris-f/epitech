/*
** my_aff_chiffre.c for my_aff_chiffre in /home/baris_f/rendu/Piscine_C_J03
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Wed Sep 30 09:55:54 2015 Florent Baris
** Last update Wed Jan  6 14:28:28 2016 Florent Baris
*/

int	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_aff_chiffre()
{
  int	i;

  i = '0';
  while (i <= '9')
    {
      my_putchar(i);
      i++;
    }
  return (0);
}

int	main()
{
  int i;

  i = 34;
  printf("zejgfuzehfioqzef %d", i);
}
