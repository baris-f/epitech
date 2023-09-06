/*
** display.c for doom in /home/fus/tmp/2plaquage/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Tue Jan 19 22:09:54 2016 Gaspard Thirion
** Last update Tue Jan 26 09:26:16 2016 Gaspard Thirion
*/

#include "tool.h"

void		draw_sky(t_base *base, t_f2D pos, float ang, float height)
{
  t_2D		tmp;
  t_col		col;

  pos.y = R_D(ang) + 30;
  tmp.x = (int)pos.x;
  tmp.y = -1;
  col = -1219999672;
  while (++(tmp.y) < WIN_HH - height / 2 + base->play.pos.z)
    {
      if (tmp.y % 5 == 1)
	col -= 0xff010101;
      mpixel(base->img, tmp, col);
    }
}

void		main_ray(t_base *base, t_f2D tmp, float ang)
{
  t_f2D		hit_x;
  t_f2D		hit_y;
  t_f2D		dist;
  t_col		col;
  t_col		vcol;
  float		height;
  float		distchoice;

  hit_x = chk_hori(base, base->play.pos, ang, &col);
  hit_y = chk_verti(base, base->play.pos, ang, &vcol);
  dist.x = NORM(hit_x, base->play.pos);
  dist.y = NORM(hit_y, base->play.pos);
  if (dist.y <= dist.x)
    {
      col = vcol;
      distchoice = dist.y;
      tmp.y = hit_y.y;
    }
  else
    {
      distchoice = dist.x;
      tmp.y = hit_x.x;
    }
  height = distchoice * cos(base->play.ang.x - ang);
  height = (DF_W_HEIGHT / height) * D_PROJ / 2;
  if (col == 0xFF004A0A && base->swtch == 0)
    {
      bunny_sound_stop(base->music);
      bunny_delete_sound(base->music);
      base->music = bunny_load_music("sound/bedel.ogg");
      bunny_sound_play(base->music);
      bunny_sound_loop(base->music, 1);
      base->swtch = 1;
    }
  draw_sky(base, tmp, ang, height);
  text_wall(base, tmp, col, height, distchoice);
}

void		display(t_base *base)
{
  t_f2D		tmp;
  float		ang;

  if (base->play.ang.x < 0)
    base->play.ang.x = DOUBLE;
  else if (base->play.ang.x > DOUBLE)
    base->play.ang.x = 0;
  tmp.x = WIN_W + 1;
  ang = base->play.ang.x - FOV_H;
  while (--(tmp.x) >= 0)
    {
      main_ray(base, tmp, ang);
      ang += PAS;
    }
}
