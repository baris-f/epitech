/*
** main.c for server in /home/baris-f/rendu/PSU/PSU_2015_minitalk
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Feb  1 10:53:40 2016 Florent Baris
** Last update Sun Feb 21 19:09:38 2016 Florent Baris
*/

#include "minitalk.h"
#include "my.h"

void	handler1();
void	handler2();

void		handle(int sig)

{
  static int	i = 0;
  static char	c = 0;


  signal(SIGUSR1, handler1);
  signal(SIGUSR2, handler2);
  i++;
  if (sig == 2)
    c = c + my_power_rec(2, 8 - i);
  if (i == 8)
    {
      write(1, &c, 1);
      c = 0;
      i = 0;
    }
  usleep(500);
}

void	handler1()
{
  signal(SIGUSR1, handler1);
  signal(SIGUSR2, handler2);
  handle(1);
}

void	handler2()
{
  signal(SIGUSR1, handler1);
  signal(SIGUSR2, handler2);
  handle(2);
}

int			main()
{
  my_printf("%d\n", getpid());
   signal(SIGUSR1, handler1);
   signal(SIGUSR2, handler2);
  while (1)
    {
      signal(SIGUSR1, handler1);
      signal(SIGUSR2, handler2);
      pause();
      signal(SIGUSR1, handler1);
      signal(SIGUSR2, handler2);

    }
  return (0);
}
