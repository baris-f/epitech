/*
** load2.c for zosjfo in /home/fus/rendu/gfx_tekadventure/gas/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Mon Apr 11 09:58:14 2016 Gaspard Thirion
** Last update Thu Apr 14 11:40:16 2016 Gaspard Thirion
*/

#include "engine.h"

int		gfont(t_main *_m, t_font *font, t_ini *proj, char *scp)
{
  char		*tmp;

  while ((font->col = get_col(scp, "col", proj, 0)) == 0x12345678)
    bunny_ini_set_field(proj, scp, "col", 0, "0xff0000ff");
  while ((tmp = get_field(proj, scp, "size", 0)) == NULL
	 || (font->size = my_getnbr(tmp)) <= 0)
    bunny_ini_set_field(proj, scp, "size", 0, "1");
  while ((tmp = get_field(proj, scp, "marge", 0)) == NULL
	 || (font->marge.x = my_getnbr(tmp)) <= 0)
    bunny_ini_set_field(proj, scp, "marge", 0, "1");
  while ((tmp = get_field(proj, scp, "marge", 1)) == NULL
	 || (font->marge.y = my_getnbr(tmp)) <= 0)
    bunny_ini_set_field(proj, scp, "marge", 1, "1");
  while ((tmp = get_field(proj, scp, "scale", 0)) == NULL
	 || (font->scale.x = my_getnbr(tmp)) <= 0)
    bunny_ini_set_field(proj, scp, "scale", 0, "5");
  while ((tmp = get_field(proj, scp, "scale", 1)) == NULL
	 || (font->scale.y = my_getnbr(tmp)) <= 0)
    bunny_ini_set_field(proj, scp, "scale", 1, "7");
  if ((tmp = get_field(proj, scp, "img", 0)) == NULL)
      font->img = _m->text[0].img;
  else if ((font->img = find_text(_m, tmp)) == NULL)
      return (-1);
  return (0);
}

int             font(t_main *_m, t_ini *proj)
{
  char          *tmp;
  int           i;

  while ((tmp = get_field(proj, "font", "size", 0)) == NULL
	 || (_m->nb_font = my_getnbr(tmp)) <= 0)
    bunny_ini_set_field(proj, "font", "size", 0, "1");
  if ((_m->font = malloc(sizeof(t_font) * _m->nb_font)) == NULL)
    return (-1);
  i = -1;
  while (++i < _m->nb_font)
    {
      while ((_m->font[i].id
	      = get_field(proj, "font", "list", i)) == NULL)
	bunny_ini_set_field(proj, "font", "list", i, nts(i + 1));
      if (gfont(_m, &(_m->font[i]), proj, _m->font[i].id) == -1)
	return (-1);
    }
  return (0);
}

int		ganim2(t_main *_m, t_sprite *anim, t_ini *proj, char *scp)
{
  char		*tmp;

  while ((tmp = get_field(proj, scp, "time", 0)) == NULL
	 || (anim->time.x = my_getnbr(tmp)) <= 0)
    bunny_ini_set_field(proj, scp, "time", 0, "1");
  if ((tmp = get_field(proj, scp, "text", 0)) == NULL)
    anim->img = _m->text[0].img;
  else if ((anim->img = find_text(_m, tmp)) == NULL)
    return (-1);
  anim->start.x = anim->fstart.x - anim->dim.x;
  anim->start.y = anim->fstart.y;
  anim->time.y = -1;
  anim->num.y = -1;
  anim->pos.x = 0;
  anim->pos.y = 0;
  anim->sens = 1;
  return (0);
}

int		ganim(t_main *_m, t_sprite *anim, t_ini *proj, char *scp)
{
  char		*tmp;

  anim->anim = scp;
  while ((tmp = get_field(proj, scp, "grid", 0)) == NULL
	 || (anim->dim.x = my_getnbr(tmp)) <= 0)
    bunny_ini_set_field(proj, scp, "grid", 0, "1");
  while ((tmp = get_field(proj, scp, "grid", 1)) == NULL
	 || (anim->dim.y = my_getnbr(tmp)) <= 0)
    bunny_ini_set_field(proj, scp, "grid", 1, "1");
  while ((tmp = get_field(proj, scp, "scale", 0)) == NULL
	 || (anim->scale.x = my_getnbr(tmp)) <= 0)
    bunny_ini_set_field(proj, scp, "scale", 0, "1");
  while ((tmp = get_field(proj, scp, "scale", 1)) == NULL
	 || (anim->scale.y = my_getnbr(tmp)) <= 0)
    bunny_ini_set_field(proj, scp, "scale", 1, "1");
  while ((tmp = get_field(proj, scp, "start", 0)) == NULL
	 || (anim->fstart.x = my_getnbr(tmp)) <= 0)
    bunny_ini_set_field(proj, scp, "start", 0, "1");
  while ((tmp = get_field(proj, scp, "start", 1)) == NULL
	 || (anim->fstart.y = my_getnbr(tmp)) <= 0)
    bunny_ini_set_field(proj, scp, "start", 1, "1");
  while ((tmp = get_field(proj, scp, "num", 0)) == NULL
	 || (anim->num.x = my_getnbr(tmp)) <= 0)
    bunny_ini_set_field(proj, scp, "num", 0, "1");
  return (ganim2(_m, anim, proj, scp));
}

int		anim(t_main *_m, t_ini *proj)
{
  char		*tmp;
  int		i;

  while ((tmp = get_field(proj, "anims", "size", 0)) == NULL
	 || (_m->nb_anim = my_getnbr(tmp)) <= 0)
    bunny_ini_set_field(proj, "anims", "size", 0, "1");
  if ((_m->anim = malloc(sizeof(t_sprite) * _m->nb_anim)) == NULL)
    return (-1);
  i = -1;
  while (++i < _m->nb_anim)
    {
      while ((tmp = get_field(proj, "anims", "list", i)) == NULL)
	bunny_ini_set_field(proj, "anims", "list", i, nts(i + 1));
      if (ganim(_m, &(_m->anim[i]), proj, tmp) == -1)
	return (-1);
    }
  return (0);
}
