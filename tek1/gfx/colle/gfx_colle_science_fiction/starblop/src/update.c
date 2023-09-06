/*
** update.c for flo in /home/baris-f/rendu/gfx/colle/gfx_colle_science_fiction/starblop
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Fri May 20 11:07:37 2016 Florent Baris
** Last update Fri May 20 11:57:31 2016 Florent Baris
*/

#include "engine.h"

void	stretch(t_main *_m)
{
  int	i;
  int	j;
  t_2D	tmp;
  t_2D	get;

  i = _m->spos.x + _m->idx;
  _m->idx--;
  while (++i < _m->fpos.x + _m->idx)
    {
      j = -1;
      while (++j < _m->fond->clipable.clip_height)
	{
	  tmp.x = i;
	  tmp.y = j + 400 - _m->fond->clipable.clip_height / 2;
	  get.x = _m->idx;
	  get.y = j;
	  mpixel(_m->mimg, tmp, getpixel(_m->fond, get));
	}
    }
}

void                    starfield(t_bunny_pixelarray *pix,
				  t_bunny_star *star,
				  size_t      nstar)
{
  t_bunny_position      cur;
  int                   i;

  i = -1;
  while (++i < (int)nstar)
    {
      star[i].x += star[i].x_speed;
      if (star[i].x < 0)
	{
	  star[i].y = rand()% pix->clipable.clip_height;
	  star[i].x +=  pix->clipable.clip_width - 1;
	}
      cur.y = star[i].y;
      cur.x = star[i].x;
      mpixel(pix, cur, WHITE);
    }
}

t_resp		update(void *_v)
{
  t_main	*_m;

  _m = (t_main *)_v;
  _m->clock += 0.4;
  if (bunny_music_get_cursor(_m->mu) >= _m->mu->duration)
    bunny_sound_play(&_m->mu->sound);
  fill(_m->mimg, BLACK);
  starfield(_m->mimg, _m->star, 50);
  _m->spos.x++;
  _m->fpos.x += 2;
  if (_m->idx <= 0)
    _m->fpos.x += 4;
  _m->fond->clipable.clip_width = _m->idx;
  if (_m->idx > 0)
    blit(_m->mimg, _m->fond, _m->spos);
  /* _m->fond->clipable.clip_width = _m->dpos.x; */
  if (_m->spos.x > 0)
    {
      /* _m->fond->clipable.clip_width = _m->idx; */
      /* _m->fond->clipable.clip_x_position = _m->dpos.x - _m->idx; */
      _m->epos = set2D(_m->fpos, _m->idx, 0, 0);
      _m->fond->clipable.clip_width = _m->dpos.x;
      blit(_m->mimg, _m->fond, _m->fpos);
      _m->fond->clipable.clip_width = _m->dpos.x;
      if (_m->idx > 0)
	stretch(_m);
    }
  _m->fond->clipable.clip_width = _m->dpos.x;
  bunny_blit(&(_m->mwin->buffer), &(_m->mimg->clipable), &(_m->mpos));
  bunny_display(_m->mwin);
  return (GO_ON);
}
