/*
** philo.c for phlo in /home/baris_f/rendu/tek2/PSU_2016_philo
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Wed Mar  8 14:45:33 2017 baris_f
** Last update Mon Mar 13 16:31:11 2017 baris_f
*/

#include "philo.h"

int	check(t_data* data, int id, int dir)
{
  int	r;

  r = 0;
  id = (id + dir) % data->p;
  if (id < 0)
    id += data->p;
  usleep(200);
  pthread_mutex_lock(&(data->mutex[id]));
  if (data->isLock[id] == 0)
    {
      r = 1;
      data->isLock[id] = 1;
      usleep(200);
      lphilo_take_chopstick(&(data->mutex[id]));
    }
  pthread_mutex_unlock(&(data->mutex[id]));
  return (r);
}

void	release(t_data* data, int id, int dir)
{
  id = (id + dir) % data->p;
  if (id < 0)
    id += data->p;
  pthread_mutex_lock(&(data->mutex[id]));
  if (data->isLock[id] == 1)
    {
      lphilo_release_chopstick(&(data->mutex[id]));
      data->isLock[id] = 0;
    }
  pthread_mutex_unlock(&(data->mutex[id]));
}

void	tryTake(t_data* data, int id)
{
  while (1)
    {
      if (check(data, id, 0))
	{
	  if (check(data, id, 1))
	    {
	      lphilo_think();
	      lphilo_eat();
	      return ;
	    }
	  release(data, id, 0);
	  usleep(300);
	}
      usleep(300);
    }
}
void	*philo(void* tmp)
{
  int		id;
  int		ce;
  t_data	*data;

  data = (t_data*)tmp;
  ce = 0;
  id = ++data->id;
  while (data->id != data->p - 1);
  while (ce < data->e)
    {
      lphilo_sleep();
      tryTake(data, id);
      release(data, id, 0);
      release(data, id, 1);
      usleep(300);
      ce++;
    }
  --(data->id);
  pthread_exit(0);
}
