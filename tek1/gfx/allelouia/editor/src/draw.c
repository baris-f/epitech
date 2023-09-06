/*
** draw.c for zod in /home/fus/rendu/gfx_tekadventure/gas/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Tue Apr 12 12:41:35 2016 Gaspard Thirion
** Last update Thu Apr 14 11:40:46 2016 Gaspard Thirion
*/

#include "engine.h"

void		blitext(t_img *img, t_sprite *sp)
{
  t_clip	*clip;

  clip = &(sp->img->clipable);
  clip->clip_x_position = sp->start.x;
  clip->clip_y_position = sp->start.y;
  clip->clip_width = sp->dim.x;
  clip->clip_height = sp->dim.y;
  clip->scale.x = sp->scale.x;
  clip->scale.y = sp->scale.y;
  if (sp->sens)
    blit(img, sp->img, sp->pos);
  else
    invblit(img, sp->img, sp->pos);
}

void		animate(t_main *_m, t_sprite *anim)
{
  if (anim->time.y == -1 || anim->time.y + anim->time.x < _m->clock)
    {
      if (anim->num.y >= anim->num.x || anim->num.y == -1)
	{
	  anim->num.y = 0;
	  anim->start.x = anim->fstart.x - anim->dim.x;
	  anim->time.y = _m->clock;
	}
      anim->num.y += 1;
      anim->time.y = _m->clock;
      anim->start.x += anim->dim.x;
    }
  blitext(_m->mimg, anim);
}

void		draw(t_main *_m, t_sprite *sprite)
{
  if (sprite->anim == NULL)
    blitext(_m->mimg, sprite);
  else
    animate(_m, sprite);
}
