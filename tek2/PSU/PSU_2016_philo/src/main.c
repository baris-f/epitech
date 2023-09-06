/*
** main.c for philo in /home/baris_f/rendu/tek2/PSU_2016_philo
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Wed Mar  8 12:20:35 2017 baris_f
** Last update Mon Mar 13 16:14:29 2017 baris_f
*/

#include "philo.h"

int	main(int ac, char **av)
{
  int		p;
  t_data	data;
  int		i;

  if (parse(ac, av, &p, &data.e) == -1)
    return (-1);
  if (RCFStartup(ac, av) == -1)
   return (-1);
  if ((data.mutex = malloc(sizeof(pthread_mutex_t) * p)) == NULL
      || (data.philos = malloc(sizeof(pthread_t) * p)) == NULL
      || (data.isLock = calloc(p, sizeof(int))) == NULL)
    return (-1);
  data.id = -1;
  data.p = p;
  i = -1;
  while (++i < p)
    {
      pthread_create(&(data.philos[i]), NULL, philo, &data);
      data.isLock[i] = 0;
      pthread_mutex_init(&(data.mutex[i]), NULL);
      usleep(100);
    }
  while (data.id >= 0);
  RCFCleanup();
  return (0);
}
