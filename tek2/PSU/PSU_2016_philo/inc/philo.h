/*
** philo.h for philo in /home/baris_f/rendu/tek2/PSU_2016_philo
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Wed Mar  8 14:49:31 2017 baris_f
** Last update Mon Mar 13 14:37:58 2017 baris_f
*/

#ifndef PHILO_H_
# define PHILO_H_

#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include "extern.h"

typedef struct	s_data
{
  int			id;
  int			e;
  int			p;
  pthread_mutex_t	*mutex;
  pthread_t		*philos;
  int			*isLock;
}		t_data;

int	parse(int, char**, int*, int*);
void	*philo(void *);

#endif /* !PHILO_H_ */
