/*
** marvin.h for marvin in /home/baris-f/rendu/marvin_baris_f
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sun May 15 15:15:13 2016 Florent Baris
** Last update Sun May 15 23:35:21 2016 Florent Baris
*/

#ifndef MARVIN_H_
# define MARVIN_H_

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct	s_marvin
{
  char	*type;
  char	*name;
  int	func;
}		t_marvin;

char    *get_func(char *str);
char    *get_param(char *str, char **av);
#endif /* !MARVIN_H_ */
