/*
** main.c for wolf in /home/fus/rendu/gfx_wolf3d/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Thu Dec 24 08:55:33 2015 Gaspard Thirion
** Last update Thu Feb 25 22:46:55 2016 Florent Baris
*/

#include <tool.h>

int		error(int type, char *msg, char *obj)
{
  my_printf("%s %s\n", obj, msg);
  return (type);
}

void		mfree(t_base *base)
{
  if (base->win)
    bunny_stop(base->win);
  if (base->img)
    bunny_delete_clipable(&(base->img->clipable));
}

t_resp		update(void *_v)
{
  t_base	*base;

  base = (t_base*)_v;
  bunny_set_mouse_position_window(base->win, WIN_WH, WIN_HH);
  if (CLEAR == TRUE)
    clear(base->img, 0xff303030);
  if (key_event(base) == 0)
    return (EXIT_ON_SUCCESS);
  display(base);
  if (UI == TRUE)
    mblit(base->img, base->prs[1].img, 0);
  if (BLIT == TRUE)
    {
      bunny_blit(&(base->win->buffer), &(base->img->clipable), &(base->mpos));
    }
  bunny_display(base->win);
  return (GO_ON);
}

t_resp          click(t_bunny_event_state               state,
		      t_bunny_mousebutton               button,
		      void                              *your_data)
{
  t_2D          *tmp;

  (void)your_data;
  tmp = (t_2D *)bunny_get_mouse_position();
  if (tmp->x > 420 && tmp->x < 820 && tmp->y > 520 && tmp->y < 650
      && button == BMB_LEFT && state == GO_DOWN)
    return (EXIT_ON_SUCCESS);
  else
    return (GO_ON);
}

t_resp          menu(void *_v)
{
  t_base        *base;
  t_2D          *tmp;

  base = (t_base*)_v;
  tmp = (t_2D *)bunny_get_mouse_position();
  if (tmp->x > 420 && tmp->x < 820 && tmp->y > 520 && tmp->y < 650)
    bunny_blit(&(base->win->buffer), &(base->prs[17].img->clipable), &(base->mpos));
  else
    bunny_blit(&(base->win->buffer), &(base->prs[16].img->clipable), &(base->mpos));
  bunny_display(base->win);
  return (GO_ON);
}

t_resp          clickf(t_bunny_event_state               state,
		       t_bunny_mousebutton               button,
		       void                              *your_data)
{
  t_base        *base;
  t_2D          *tmp;

  base = (t_base *)your_data;
  tmp = (t_2D *)bunny_get_mouse_position();
  if (tmp->x > 700 && tmp->x < 970 && tmp->y > 270 && tmp->y < 370
      && button == BMB_LEFT && state == GO_DOWN)
    {
      base->play.pos.x = -1;
      return (EXIT_ON_SUCCESS);
    }
  else
    return (GO_ON);
}

t_resp          menuf(void *_v)
{
  t_base        *base;
  t_2D          *tmp;

  base = (t_base*)_v;
  tmp = (t_2D *)bunny_get_mouse_position();
  if (tmp->x > 1570 && tmp->x < 970 && tmp->y > 670 && tmp->y < 800)
    bunny_blit(&(base->win->buffer), &(base->prs[22].img->clipable), &(base->mpos));
  else if (tmp->x > 700 && tmp->x < 970 && tmp->y > 270 && tmp->y < 370)
    bunny_blit(&(base->win->buffer), &(base->prs[19].img->clipable), &(base->mpos));
  else
  bunny_blit(&(base->win->buffer), &(base->prs[18].img->clipable), &(base->mpos));
  bunny_display(base->win);
  return (GO_ON);
}

int			main()
{
  t_base		base;
  int			i;

  base.win = bunny_start(WIN_W, WIN_H, FS, "LibLapin");
  base.img = bunny_new_pixelarray(WIN_W, WIN_H);

  base.mpos.x = 0;
  base.mpos.y = 0;
  bunny_set_click_response(&click);
  bunny_set_key_response(&keys);
  base.prs = malloc(sizeof(t_text) * NB_TEXT + 2);
  base.prs[16].img = load_bitmap("prs/play0.bmp");
  base.prs[17].img = load_bitmap("prs/play1.bmp");
  base.prs[18].img = load_bitmap("prs/fin1.bmp");
  base.prs[19].img = load_bitmap("prs/fin2.bmp");

  base.music = bunny_load_music("sound/menu.ogg");
  bunny_sound_play(base.music);
  base.swtch = 0;

  base.prs[0].ref = 0x2;
  base.prs[0].map = 2;
  base.prs[0].img = prs_load("map/map2.prs");
  base.prs[1].ref = 0x2;
  base.prs[1].map = 1;
  base.prs[1].img = prs_load("map/map1.prs");
  base.prs[22].map = 3;
  base.prs[22].ref = 0x2;
  base.prs[22].img = prs_load("map/lvl2.prs");
  base.prs[21].map = 4;
  base.prs[21].ref = 0x2;
  base.prs[21].img = prs_load("map/lvl3.prs");
  base.prs[2].ref = TEAL;
  base.prs[2].img = prs_load("prs/cadre.prs");
  base.prs[3].ref = RED;
  base.prs[3].img = prs_load("prs/biblio.prs");
  base.prs[4].ref = YELLOW;
  base.prs[4].img = prs_load("prs/mur-pierre.prs");
  base.prs[5].ref = GREEN;
  base.prs[5].img = prs_load("prs/prison22.prs");
  base.prs[6].ref = 0xFF00A316;
  base.prs[6].img = prs_load("prs/prison21.prs");
  base.prs[7].ref = DF_COL;
  base.prs[7].img = prs_load("prs/prison2.prs");
  base.prs[8].ref = PURPLE;
  base.prs[8].img = prs_load("prs/prison1.prs");
  base.prs[9].ref = 0xFFFFB300;
  base.prs[9].img = prs_load("prs/garde.prs");
  base.prs[10].ref = 0xFF00B7FF;
  base.prs[10].img = prs_load("prs/banner.prs");
  base.prs[11].ref = 0xFF777777;
  base.prs[11].img = prs_load("prs/prisonvide.prs");
  base.prs[12].ref = BLACK;
  base.prs[12].img = prs_load("prs/sorti1.prs");
  base.prs[13].ref = WHITE;
  base.prs[13].img = prs_load("prs/sorti2.prs");
  base.prs[14].ref = 0x1;
  base.prs[14].img = prs_load("prs/maindroite.prs");
  base.prs[15].ref = 0x1;
  base.prs[15].img = prs_load("prs/maingauche.prs");
  base.prs[20].ref = 0xFF004A0A;
  base.prs[20].img = prs_load("prs/bedel.prs");
  if (!(base.img) || !(base.win))
    return (error (-1, "initialisation failed", ""));
  i = -1;
  while (++i < NB_TEXT)
    if (!base.prs[i].img)
      {
	my_printf("%d\n", i);
	return (error (-1, "initialisation failed", ""));
      }
  bunny_set_loop_main_function(&menu);
  bunny_loop(base.win, 60, &(base));

  while (1)
    {
      base.play.pos.x = 2;
      base.play.pos.y = 2;
      base.play.pos.z = 2;
      base.play.ang.x = M_PI * 1.5;
      base.play.ang.y = M_PI / 2;

      base.keys.k_z = 0;
      base.keys.k_q = 0;
      base.keys.k_s = 0;
      base.keys.k_d = 0;
      base.keys.k_up = 0;
      base.keys.k_down = 0;
      base.keys.k_left = 0;
      base.keys.k_right = 0;

      bunny_sound_loop(base.music, 1);
      bunny_set_move_response(&mouse_move);
      bunny_set_mouse_visibility(base.win, 0);
      bunny_set_loop_main_function(&update);
      bunny_loop(base.win, 60, &(base));

      bunny_set_mouse_visibility(base.win, 1);
      bunny_set_click_response(&clickf);
      bunny_set_loop_main_function(&menuf);
      bunny_loop(base.win, 60, &(base));

      if (base.play.pos.x != -1)
	{
	  mfree(&base);
	  return (0);
	}
    }
}
