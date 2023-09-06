/*
** set_key.c for tetris in /home/dudu/rendu/PSU_2015_tetris
**
** Made by lucas duval
** Login   <duval_m@epitech.net>
**
** Started on  Thu Feb 25 09:38:29 2016 lucas duval
** Last update Sun Mar 20 14:20:53 2016 lucas duval
*/

#include "tetris.h"

void	set_key_left(char *kl, int sel, t_tetris *tet)
{
  if (sel)
      tet->keys.left = kl[my_strlen(kl) - 1];
  else
    tet->keys.left = kl[0];
}

void	set_key_right(char *kr, int sel, t_tetris *tet)
{
  if (sel)
    tet->keys.right = kr[my_strlen(kr) - 1];
  else
    tet->keys.right = kr[0];
}

void	set_key_turn(char *kt, int sel, t_tetris *tet)
{
  if (sel)
    tet->keys.turn = kt[my_strlen(kt) - 1];
  else
    tet->keys.turn = kt[0];
}

void	set_key_drop(char *kd, int sel, t_tetris *tet)
{
  if (sel)
    tet->keys.drop = kd[my_strlen(kd) - 1];
  else
    tet->keys.drop = kd[0];
}

void	set_key_quit(char *kq, int sel, t_tetris *tet)
{
  if (sel)
    tet->keys.quit = kq[my_strlen(kq) - 1];
  else
    tet->keys.quit = kq[0];
}

void	set_key_pause(char *kp, int sel, t_tetris *tet)
{
  if (sel)
    tet->keys.pause = kp[my_strlen(kp) - 1];
  else
    tet->keys.pause = kp[0];
}
