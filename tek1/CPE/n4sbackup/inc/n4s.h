/*
** n4s.h for n4s in /home/baris-f/rendu/CPE/CPE_2015_n4s
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Wed May 25 14:50:58 2016 Florent Baris
** Last update Sat May 28 23:03:11 2016 Florent Baris
*/

#ifndef LEMIN_H_
# define LEMIN_H_

#include "my.h"

typedef struct	s_angle
{
  int		dist;
  int		ang;
}		t_angle;

typedef struct	s_base
{
  int		speed;
  int		rot;
  int		left;
  int		right;
  int		limit;
  int		*lidar;
  t_angle	angle[4];
}		t_base;

char    *turn(int rot);
char    *move(int speed);
char	*send(char *command);
int     calc(t_base *need);
void    handle_turn(t_base *need, int left, int right);
void    calc_turn(t_base *need, int left, int right);
void    get_lidar(t_base *need);
char	**my_str_to_wordtab(char *, char);
char	*get_next_line(int);
int	my_getnbr(char *);
#endif /* !LEMIN_H_ */
