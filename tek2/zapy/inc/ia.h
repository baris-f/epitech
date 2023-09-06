/*
** philo.h for philo in /home/baris_f/rendu/tek2/PSU_2016_philo
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Wed Mar  8 14:49:31 2017 baris_f
** Last update Sat Jul  1 17:29:13 2017 baris_f
*/

#ifndef PHILO_H_
# define PHILO_H_

#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_data
{
  char*			machine;
  char*			name;
  int			port;
  char*                 action;
  int                   clvl;
  int                   ate;
  int**                 needs;
  int*                  minerals;
  char**                sminerals;
  char*                 priority;
  char*                 rep;
  int*                  path;
  int                   found;
  int                   turns;
}		t_data;


int	parse(int, char**, t_data*);
void    act(t_data*);
void	*philo(void *);
void    getResponse(t_data *data);
void    init(t_data *data);
void    getLook(t_data *data);
void    setAction(t_data *data, char* action);
void    setPriority(t_data *data);
void    setPath(t_data *data, int tile);
void    move(t_data *data);
void    addObj(t_data *data);
void    take(t_data *data);
int     missingItem(t_data *data);

#endif /* !PHILO_H_ */
