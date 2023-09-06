/*
** bibi.h for pokfdgs in /home/fus/rendu/rush/sudoki-bi
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Sat Feb 27 10:30:27 2016 Gaspard Thirion
** Last update Sat Feb 27 17:39:54 2016 Gaspard Thirion
*/

#ifndef BIBI_H_
# define BIBI_H_

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define	RD_SIZE	4096

void	my_putnbr_base(int, int);
void    disptab(int*, int, int);
void    writab(int*, char*);

#endif /* !BIBI_H_ */
