/*
** n4s.h for n4s in /home/baris-f/rendu/CPE/CPE_2015_n4s
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Wed May 25 14:50:58 2016 Florent Baris
** Last update Mon May 30 21:40:25 2016 Florent Baris
*/

#ifndef LEMIN_H_
# define LEMIN_H_

#include <math.h>
#include "my.h"

#define	PI	3.1459


typedef	struct	s_ray
{
  float	dist;
  float	ang;
  float	x;
  float	y;
}		t_ray;

typedef struct	s_angle
{
  int		dist;
  int		ang;
}		t_angle;

typedef struct	s_base
{
  int		speed;
  float		rotspeed;
  int		rot;
  int		left;
  int		right;
  int		limit;
  int		pturn;
  int		pspeed;
  int		*lidar;
  float		lefta;
  float		righta;
  t_ray		angle[4];
  FILE          *fp;
}		t_base;

void    calculate(t_base *need, t_ray *tab);
char	*match(char *s1, char *s2);
char    *turn(float rot, t_base *need);
char    *move(int speed);
char	*send(char *command);
int     calc(t_base *need);
void    calc_prct(t_base *need);
void    handle_turn(t_base *need);
void    set_turn(t_base *need);
int	get_lidar(t_base *need);
char	**my_str_to_wordtab(char *, char);
char	*get_next_line(int);
int	my_getnbr(char *);

#endif /* !LEMIN_H_ */
