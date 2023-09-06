/*
** key.c for doom in /home/fus/tmp/2plaquage/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Tue Jan 19 19:58:14 2016 Gaspard Thirion
** Last update Tue Jan 26 03:03:24 2016 charles-elie taupin
*/

#include "tool.h"

t_resp		keys(t_bunny_event_state state, t_bunny_keysym key, void *v)
{
  t_base	*base;

  base = (t_base*)v;
  if (key == BKS_ESCAPE && state == GO_UP)
    return (EXIT_ON_SUCCESS);
  (key == BKS_Z && state == GO_DOWN) ? (base->keys.k_z = 1) : (0);
  (key == BKS_Z && state == GO_UP) ? (base->keys.k_z = 0) : (0);
  (key == BKS_Q && state == GO_DOWN) ? (base->keys.k_q = 1) : (0);
  (key == BKS_Q && state == GO_UP) ? (base->keys.k_q = 0) : (0);
  (key == BKS_S && state == GO_DOWN) ? (base->keys.k_s = 1) : (0);
  (key == BKS_S && state == GO_UP) ? (base->keys.k_s = 0) : (0);
  (key == BKS_D && state == GO_DOWN) ? (base->keys.k_d = 1) : (0);
  (key == BKS_D && state == GO_UP) ? (base->keys.k_d = 0) : (0);
  (key == BKS_UP && state == GO_DOWN) ? (base->keys.k_up = 1) : (0);
  (key == BKS_UP && state == GO_UP) ? (base->keys.k_up = 0) : (0);
  (key == BKS_DOWN && state == GO_DOWN) ? (base->keys.k_down = 1) : (0);
  (key == BKS_DOWN && state == GO_UP) ? (base->keys.k_down = 0) : (0);
  (key == BKS_LEFT && state == GO_DOWN) ? (base->keys.k_left = 1) : (0);
  (key == BKS_LEFT && state == GO_UP) ? (base->keys.k_left = 0) : (0);
  (key == BKS_RIGHT && state == GO_DOWN) ? (base->keys.k_right = 1) : (0);
  (key == BKS_RIGHT && state == GO_UP) ? (base->keys.k_right = 0) : (0);
  return (GO_ON);
}

int		key_event(t_base *base)
{
  int	brk;

  brk = 1;
  if (base->keys.k_z == 1 && base->keys.k_s != 1)
    brk = move(base, MV_SENSI, 180);
  if (base->keys.k_s == 1 && base->keys.k_z != 1)
    brk = move(base, - MV_SENSI, 180);
  if (base->keys.k_q == 1 && base->keys.k_d != 1)
    brk = move(base, MV_SENSI, 270);
  if (base->keys.k_d == 1 && base->keys.k_q != 1)
    brk = move(base, - MV_SENSI, 270);
  if (base->keys.k_up == 1 && base->keys.k_down != 1)
    base->play.ang.y += Y_SENSI;
  if (base->keys.k_down == 1 && base->keys.k_up != 1)
    base->play.ang.y -= Y_SENSI;
  if (base->keys.k_left == 1 && base->keys.k_right != 1)
    base->play.ang.x += X_SENSI;
  if (base->keys.k_right == 1 && base->keys.k_left != 1)
    base->play.ang.x -= X_SENSI;
  return (brk);
}

t_resp		mouse_move(const t_2D *relative, void *your_data)
{
  t_base	*base;

  base = (t_base *)your_data;

  /* base->play.pos.z -= Y_SENSI * relative->y * 10; */
  base->play.ang.x -= X_SENSI * relative->x / 10;
  return (GO_ON);
}
