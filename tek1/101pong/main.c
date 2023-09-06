/*
** main.c for pong in /home/fus/rendu/101pong
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Mon Nov 23 12:41:50 2015 Gaspard Thirion
** Last update Fri Nov 27 00:25:11 2015 Florent Baris
*/

#include	<math.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"pong.h"

t_v3		time(t_v3 vit, t_v3 org, float time)
{
  t_v3		ret;

  ret.x = vit.x * time + org.x;
  ret.y = vit.y * time + org.y;
  ret.z = vit.z * time + org.z;
  return (ret);
}

t_v3		vitesse(t_v3 from, t_v3 to)
{
  t_v3		ret;

  ret.x = to.x - from.x;
  ret.y = to.y - from.y;
  ret.z = to.z - from.z;
  return (ret);
}

t_v3		get(char **av, int i)
{
  t_v3		ret;

  ret.x = atof(av[i]);
  ret.y = atof(av[i + 1]);
  ret.z = atof(av[i + 2]);
  return (ret);
}

float		getang(t_v3 org, t_v3 now)
{
  float		ang;

  AFF(org);
  AFF(now);
  ang = asin((abs(org.z - now.z)) / (sqrt(powf(now.x - org.x, 2)
					  + powf(now.y - org.y, 2)
					  + powf(now.z-org.z, 2))));

  /* if ( == ) */
  /*   return (-1); */
  AFF(now);
  printf("%f \n", ang);
  return (ang * (180 / M_PI));
}

int		main(int ac, char **av)
{
  t_v3		from;
  t_v3		to;
  t_v3		vit;
  t_v3		now;
  float		tmax;
  float		ang;

  if (ac != 8 || atof(av[7]) < 0)
    {
      fprintf(stderr, "Usage : %s x0 y0 z0 x1 y1 z1 n\n", av[0]);
      exit(84);
    }
  tmax = atof(av[7]);
  vit = vitesse(from = get(av, 1), to = get(av, 4));
  ang = getang(from, now = time(vit, to, tmax));
  printf("The speed vector coordinates are :\n");
  AFF(vit);
  printf("At time t+%.0f, ball coordinates will be :\n", tmax);
  AFF(now);
  if (ang != -1)
    printf("The incidence angle is :\n%.2f degrees\n", ang);
  else
    printf("The ball won't reach the bat.\n");
  return (0);
}
