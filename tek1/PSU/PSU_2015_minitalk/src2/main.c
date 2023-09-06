/*
** main.c for client in /home/baris-f/rendu/PSU/PSU_2015_minitalk
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Feb  1 10:58:03 2016 Florent Baris
** Last update Sun Feb 21 19:05:06 2016 Florent Baris
*/

#include "minitalk.h"
#include "my.h"

void	sendchar(char c, int pid)
{
  int	nb;

  nb = 8;
  while (--nb >= 0)
    {
      if  (1 & c >> nb)
	  kill(pid, SIGUSR2);
      else
	  kill(pid, SIGUSR1);
      usleep(2000);
    }
}

void	sendmsg(char *str, int pid)
{
  int	i;

  i = -1;
  while (str[++i])
    sendchar(str[i], pid);
  sendchar('\n', pid);
}

int			main(int ac, char **av)
{
  if (ac != 3)
    {
      my_printf("Usage: ./client serverpid msg\n");
      return (0);
    }
  sendmsg(av[2], my_getnbr(av[1]));
  return (0);
}
