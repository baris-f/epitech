/*
** main.c for  in /home/fus/taff/PSU_2016_philo/src
**
** Made by fus
** Login   <fus@epitech.net>
**
** Started on  Mon Mar  6 10:42:43 2017 fus
** Last update Wed Mar  8 10:27:20 2017 baris_f
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

#define	NB_TRAINS	25
char	track[] = "=====-----=====";

typedef struct s_train
{
  int		id;
  int		*cb;
  pthread_mutex_t	*m;
  char		*map;
  pthread_t	thread;
}	t_train;

void	*draw_train(void* tmp)
{
  char	*map;

  map = (char*)tmp;
  while (1){
    usleep(100000);
    printf("\e[1;1H\e[2J");
    for (int i = 0; i < NB_TRAINS; i++)
      {
	printf("%d:\t", i);
	for (int j = 0; track[j]; j++)
	  {
	    if (j == 5 || j == 10)
	      printf("|");
	    if (j == map[i] - 1)
	      printf("#");
	    else
	      printf("%c", track[j]);
	  }
	printf("\n");
      }
  }
}

int	end(char *map)
{
  for (int i = 0; i < NB_TRAINS; i++)
    if (map[i] < 15)
      return (0);
  return (1);
}

void	*train(void *tmp)
{
  t_train	*this;

  this = (t_train*)tmp;
  while (this->map[this->id] < 16)
    {
      usleep(100000);
      pthread_mutex_lock(this->m);
      if (this->map[this->id] == 5){
	  if (this->cb[0] < 5)
	  {
	    this->cb[0]++;
	    this->map[this->id]++;
	  }
      }
      else
	this->map[this->id]++;
      if (this->map[this->id] == 10)
	this->cb[0]--;
      pthread_mutex_unlock(this->m);
    }
}

int	main()
{
  char		*map;
  t_train	*trains;
  int		*cb;
  pthread_mutex_t	*m;
  pthread_t		aff;

  map = malloc(sizeof(char) * NB_TRAINS);
  trains = malloc(sizeof(t_train) * NB_TRAINS);
  m = malloc(sizeof(pthread_mutex_t));
  cb = malloc(sizeof(int));
  cb[0] = 0;
  pthread_mutex_init(m, NULL);
  memset(map, 0, NB_TRAINS);
  pthread_create(&aff, NULL, draw_train, map);
  for (int i = 0; i < NB_TRAINS; i++)
    {
      trains[i].id = i;
      trains[i].cb = cb;
      trains[i].map = map;
      trains[i].m = m;
      pthread_create(&(trains[i].thread), NULL, train, &trains[i]);
    }
  for (int i = 0; i < NB_TRAINS; i++)
    pthread_join(trains[i].thread, NULL);
  return (0);
}
