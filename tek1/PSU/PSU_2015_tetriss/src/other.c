/*
** other.c for tetris in /home/dudu/rendu/PSU_2015_tetris
**
** Made by lucas duval
** Login   <duval_m@epitech.net>
**
** Started on  Thu Feb 25 09:41:45 2016 lucas duval
** Last update Tue Mar  1 15:35:04 2016 Florent Baris
*/

#include "tetris.h"

void	set_help()
{
  my_printf("Usage: ./tetris [options]\n");
  my_printf("Options:\n");
  my_printf(" --help Display this help\n");
  my_printf(" -l --level={num} Start Tetris at level num\n");
  my_printf(" -kl --key-left={K} Move tetrimino on LEFT with key K\n");
  my_printf(" -kr --key-right={K} Move tetrimino on RIGHT with key K\n");
  my_printf(" -kt --key-turn={K} Turn tetrimino with key K\n");
  my_printf(" -kd --key-drop={K} Set default DROP on key K\n");
  my_printf(" -kq --key-quit={K} Quit program when press key K\n");
  my_printf(" -kp --key-pause={K} Pause and restart game when press key K\n");
  my_printf(" --map-size={row,col} Set game size at row, col\n");
  my_printf(" -w --without-next Hide next tetrimino\n");
  my_printf(" -d --debug Debug mode\n");
  exit(0);
}

void	set_level(char *lvl)
{
  my_printf("level: %s\n", lvl);
}

void	set_map_size(char *map)
{
  my_printf("map: %s\n", map);
}

void	set_hide_next()
{
  my_printf("hide next\n");
}

void	set_debug_mode()
{
  my_printf("debug mode\n");
}
