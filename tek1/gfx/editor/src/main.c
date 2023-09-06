/*
1;2802;0c** main.c for main in /home/baris-f/rendu/gfx_wolf3d
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sat Dec 26 17:27:16 2015 Florent Baris
** Last update Mon Jan 25 13:38:21 2016 Florent Baris
*/

#include "wolf.h"

t_bunny_response        tekkey(t_bunny_event_state state, t_bunny_keysym key,
			       void *_void)
{
  t_base        *pass;

  pass = (t_base*)_void;
  (void)state;
  if (key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  else if (key == BKS_Q && state == GO_DOWN && pass->edit.scale > 1)
    pass->edit.scale--;
  else if (key == BKS_D && state == GO_DOWN && pass->edit.scale < 50)
    pass->edit.scale++;
  else if (key == BKS_UP && state == GO_DOWN)
    pass->edit.center.y += pass->edit.scale;
  else if (key == BKS_DOWN && state == GO_DOWN)
    pass->edit.center.y -= pass->edit.scale;
  else if (key == BKS_LEFT && state == GO_DOWN)
    pass->edit.center.x += pass->edit.scale;
  else if (key == BKS_RIGHT && state == GO_DOWN)
    pass->edit.center.x -= pass->edit.scale;
  else if (key == BKS_G && state == GO_DOWN)
    pass->edit.gridstate *= -1;
  else if (key == BKS_Z && state == GO_DOWN && pass->edit.menu.cur > 0)
    pass->edit.menu.cur--;
  else if (key == BKS_S && state == GO_DOWN && pass->edit.menu.cur < pass->edit.menu.but - 1)
    pass->edit.menu.cur++;
  else if (key == BKS_F1 && state == GO_DOWN)
    pass->edit.pal.cur = 0;
  else if (key == BKS_F2 && state == GO_DOWN)
    pass->edit.pal.cur = 1;
  else if (key == BKS_F3 && state == GO_DOWN)
    pass->edit.pal.cur = 2;
  else if (key == BKS_F4 && state == GO_DOWN)
    pass->edit.pal.cur = 3;
  else if (key == BKS_F5 && state == GO_DOWN)
    pass->edit.pal.cur = 4;
  else if (key == BKS_F6 && state == GO_DOWN)
    pass->edit.pal.cur = 5;
  else if (key == BKS_R && state == GO_DOWN)
    {
      tekfill(pass->edit.map, BLUE);
      pass->edit.center.x = WIN_WH;
      pass->edit.center.y = WIN_HH;
      pass->edit.scale = 10;
    }
  return (GO_ON);
}

void	gridcenter(t_base *pass)
{
  int		midlen;
  t_2D		m[2];

  midlen =  pass->edit.map->clipable.clip_height / 2 * pass->edit.scale;
  m[0].x = WIN_HH - midlen;
  m[0].y = WIN_WH - midlen;
  m[1].x = WIN_HH + midlen;
  m[1].y = WIN_WH + midlen;
  if (pass->edit.center.y > m[1].x)
    pass->edit.center.y = m[1].x;
  else if (pass->edit.center.y < m[0].x)
    pass->edit.center.y = m[0].x;
  else if (pass->edit.center.x > m[1].y)
    pass->edit.center.x = m[1].y;
  else if (pass->edit.center.x < m[0].y)
    pass->edit.center.x = m[0].y;
}

t_bunny_response	update(void *_void)
{
  t_base		*pass;

  pass = (t_base*)_void;
  pass->edit.col =  pass->edit.pal.bcol[pass->edit.pal.cur];
  mblit(pass->edit.tmp, pass->edit.map, 0);
  tekfill(pass->img, WHITE);
  gridcenter(pass);
  if (pass->edit.pixel == 1)
    addinmap(pass, pass->edit.lpos[1], pass->edit.map, pass->edit.col);
  if (pass->edit.ligne == 1)
    {
      if (pass->edit.menu.cur == 0)
	lineinmap(pass, pass->edit.lpos, pass->edit.tmp, pass->edit.col);
      else if (pass->edit.menu.cur == 1)
	draw_boxinmap(pass, pass->edit.lpos, pass->edit.col, 0, pass->edit.tmp);
      else if (pass->edit.menu.cur == 2)
	draw_boxinmap(pass, pass->edit.lpos, pass->edit.col, 1, pass->edit.tmp);
      else if (pass->edit.menu.cur == 3)
	circleinmap(pass, pass->edit.lpos, pass->edit.tmp, pass->edit.col);
    }
  fillmap(pass, pass->edit.tmp);
  if (pass->edit.gridstate == 1 && pass->edit.scale > 1)
    grid(pass);
  toolbar(pass, pass->edit.menu);
  palbar(pass, pass->edit.pal);
  bunny_blit(&(pass->win->buffer), &(pass->img->clipable), &pass->mpos);
  bunny_display(pass->win);
  return (GO_ON);
}

void		init(t_base *pass)
{
  pass->edit.menu.pos[0].x = WIN_W / 20;
  pass->edit.menu.pos[0].y = WIN_H / 8;
  pass->edit.menu.pos[1].x = WIN_W / 6;
  pass->edit.menu.pos[1].y = WIN_H - WIN_H / 8;
  pass->edit.menu.but = 4;
  pass->edit.menu.cur = 0;
  pass->edit.menu.col = 0xFF888888;
  pass->edit.menu.scol = 0xFFAAAAAA;
  pass->edit.menu.bcol[0] = 0xFFDDDDDD;
  pass->edit.menu.bscol[0] = 0xFFBBBBBB;
  pass->edit.pal.pos[0].x = WIN_W / 15;
  pass->edit.pal.pos[0].y = WIN_H / 40;
  pass->edit.pal.pos[1].x = WIN_W - WIN_H / 15;
  pass->edit.pal.pos[1].y = WIN_H / 10;
  pass->edit.pal.but = 6;
  pass->edit.pal.cur = 0;
  pass->edit.pal.col = 0xFF888888;
  pass->edit.pal.scol = 0xFFAAAAAA;
  pass->edit.pal.bcol[0] = YELLOW;
  pass->edit.pal.bscol[0] = WHITE;
  pass->edit.pal.bcol[1] = RED;
  pass->edit.pal.bscol[1] = WHITE;
  pass->edit.pal.bcol[2] = GREEN;
  pass->edit.pal.bscol[2] = WHITE;
  pass->edit.pal.bcol[3] = PINK;
  pass->edit.pal.bscol[3] = WHITE;
  pass->edit.pal.bcol[4] = WHITE;
  pass->edit.pal.bscol[4] = WHITE;
  pass->edit.pal.bcol[5] = BLUE;
  pass->edit.pal.bscol[5] = WHITE;
  pass->edit.col = RED;
  pass->edit.center.x = WIN_WH;
  pass->edit.center.y = WIN_HH;
  pass->mpos.x = 0;
  pass->mpos.y = 0;
  pass->edit.gridstate = 1;
  pass->edit.pixel = 0;
  pass->edit.ligne = 0;
  pass->edit.scale = 10;
}

int			main(int ac, char **av)
{
  t_base		pass[1];
  int	i;

  if  (ac != 2 && ac != 3)
    return (write(1, "Usage: ./editor [[x] [y]] || [bitmap]\n", 38) * 0 - 1);
  if (ac == 3)
    {
      if ((pass->edit.tmp = bunny_new_pixelarray(my_getnbr(av[1]),
						 my_getnbr(av[2]))) == NULL)
	return (0);
      if ((pass->edit.map = bunny_new_pixelarray(my_getnbr(av[1]),
						 my_getnbr(av[2]))) == NULL)
	return (0);
    }
  else if ((pass->edit.map = load_bitmap(av[1])) == NULL ||
	   (pass->edit.tmp = load_bitmap(av[1])) == NULL)
    {
      if ((pass->edit.map = prs_load(av[1], pass)) == NULL)
	return (write(1, "bitmap/prs non valide\n", 22) * 0 - 1);
    }
  (ac == 3) ? (tekfill(pass->edit.map, BLUE)) : (void)pass->edit.scale;
    if ((pass->win = bunny_start(WIN_W, WIN_H, 0, "editor")) == NULL)
    return (0);
  if ((pass->img = bunny_new_pixelarray(WIN_W, WIN_H)) == NULL)
    return (0);
  init(pass);
  bunny_set_loop_main_function(update);
  bunny_set_key_response(tekkey);
  bunny_set_click_response(mouse);
  bunny_set_move_response(mouse_move);
  bunny_loop(pass->win, 250, pass);
  bunny_delete_clipable(&pass->img->clipable);
  bunny_stop(pass->win);
  if (ac == 3)
    {
      write(1, "newmap.prs created\n", 19);
      tofile(pass->edit.map, "newmap.prs");
    }
  else
    {
      i = my_strlen(av[1]);
      while (av[1][--i] > 0 && av[1][i] != '.');
      av[1][++i] = 'p';
      av[1][++i] = 'r';
      av[1][++i] = 's';
      av[1][++i] = '\0';
      tofile(pass->edit.map, av[1]);
    }
  return (0);
}
