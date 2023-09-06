/*
** white_rabbit.c for white_rabbit in /home/baris_f/rendu/tek2/cpp_d01/ex00
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Wed Jan  4 10:25:53 2017 baris_f
** Last update Thu Jan  5 08:31:40 2017 baris_f
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int	follow_the_white_rabbit(void)
{
  int	dice;
  int	sum;
  int	end;

  sum = 0;
  end = 0;
  while (end == 0)
    {
      dice = random() % 37 + 1;
      sum += dice;
      if (dice == 1 || dice == 37)
	{
	  printf("LAPIN !!!\n");
	  end = 1;
	}
      else if (dice == 26 || (float)((float)dice / (float)8) == (int)(dice / 8))
	printf("derriere\n");
      else if ((dice >= 4 && dice <= 6) || (dice >= 17 && dice <= 21) || dice == 28)
	printf("gauche\n");
      else if (dice == 10 || dice == 15 || dice == 23)
	printf("devant\n");
      else if (dice == 13 || dice >= 34)
	printf("droite\n");
      if (sum >= 397 || sum == 421)
	{
	  printf("LAPIN !!!\n");
	  end = 1;
	}
    }
  return (sum);
}

/*
int	main(int ac, char** av)
{
  if (ac == 2)
    srandom(atoi(av[1]));
  else
    srandom(time(NULL));
  printf("%d\n", follow_the_white_rabbit());
}
*/
