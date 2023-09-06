/*
** cat.c for cat in /home/baris_f/rendu/Piscine_C_J12/cat
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Tue Oct 13 10:46:33 2015 Florent Baris
** Last update Wed Oct 14 20:24:33 2015 Florent Baris
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	norm(char **av, int i)
{
  int	fd;
  char	buffer[128];

  j = 0;
  while (av[i])
    {
      fd = open(av[i], O_RDONLY);
      if (fd == -1)
	{
	  my_putstr("cat: ");
	  my_putstr(av[i]);
	  my_putstr(": No such file or directory\n");
	}
      else
	{
	  while (read(fd, buffer, 127))
	    my_putstr(buffer);
	}
      close(fd);
      i++;
    }
  return (0);
}

int	main(int ac, char **av)
{
  char	buffer[30000];
  int	i;
  int	ret;

  i = 1;
  if (ac == 1)
      while (1)
	{
	  ret = read(0, buffer, 30000);
	  if (ret == 0)
	    return (0);
	  my_putstr(buffer);
	  buffer[0] = '\0';
	}
  norm(av, i);
}
