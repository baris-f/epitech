/*
** print.c for n4s in /home/baris-f/rendu/CPE/CPE_2015_n4s
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Wed May 25 14:52:28 2016 Florent Baris
** Last update Mon May 30 23:09:27 2016 Florent Baris
*/

#include "n4s.h"

char    *send(char *command)
{
  char  *tmp;

  my_printf("%s", command);
  tmp = get_next_line(0);
  return (tmp);
}

char	*turn(float rot, t_base *need)
{
  char	*tmp;
  int div = 500;

  if (rot < 0)
    my_printf("WHEELS_DIR:-0.%d\n", (int)(-rot / div * 100));
  else
    my_printf("WHEELS_DIR:0.%d\n", (int)(rot / div * 100));
  tmp = get_next_line(0);
  (void)need;
  return (tmp);
}

char	*move(int speed)
{
  char  *tmp;

  if (speed == 10)
    my_printf("CAR_FORWARD:1.0\n");
  else if (speed == 10)
    my_printf("CAR_BACKWARDS:1.0\n");
  else if (speed > 0)
    my_printf("CAR_FORWARD:0.%d\n", speed);
  else if (speed < 0)
    my_printf("CAR_BACKWARDS:0.%d\n", -1 * speed);
  else
    my_printf("CAR_FORWARD:0.0\n");
  tmp = get_next_line(0);
  return (tmp);
}
