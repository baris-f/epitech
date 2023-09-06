/*
** print.c for n4s in /home/baris-f/rendu/CPE/CPE_2015_n4s
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Wed May 25 14:52:28 2016 Florent Baris
** Last update Wed Jun  1 14:41:50 2016 Florent Baris
*/

#include "n4s.h"

char    *send(char *command)
{
  char  *tmp;

  my_printf("%s", command);
  tmp = get_next_line(0);
  return (tmp);
}

char	*turn(t_base *need, int rot)
{
  char	*tmp;
  char  **lidar;

  if (rot == 10)
    my_printf("WHEELS_DIR:1.0\n", rot);
  else if (rot == -10)
    my_printf("WHEELS_DIR:-1.0\n", rot);
  else if (rot > 0)
    my_printf("WHEELS_DIR:0.%d\n", rot);
  else if (rot < 0)
    my_printf("WHEELS_DIR:-0.%d\n", -1 * rot);
  else
    my_printf("WHEELS_DIR:0\n");
  tmp = get_next_line(0);
  lidar = my_str_to_wordtab(tmp, ':');
  if (lidar[3] && match(lidar[3], "Track Cleared") != 0)
    need->ret = 1;
  free(lidar);
  return (tmp);
}

char	*move(t_base *need, int speed)
{
  char  *tmp;
  char  **lidar;

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
  lidar = my_str_to_wordtab(tmp, ':');
  if (lidar[3] && match(lidar[3], "Track Cleared") != 0)
    need->ret = 1;
  free(lidar);
  return (tmp);
}
