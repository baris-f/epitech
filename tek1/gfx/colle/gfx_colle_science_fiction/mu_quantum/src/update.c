/*
** update.c for ejoz in /home/fus/tmp/fusgine/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Mon Mar 21 22:35:51 2016 Gaspard Thirion
** Last update Tue May 17 16:17:12 2016 Florent Baris
*/

#include "engine.h"

void	handler(t_main *_m)
{
  t_2D  pos;
  t_2D  npos;
  t_2D  tmp;

  pos.x = 407;
  while (--pos.x > 0)
    {
      pos.y = 342;
      while (--pos.y > 0)
	{
	  npos.x = pos.x + 1;
	  npos.y = pos.y;
	  tmp.x = _m->spos.x + pos.x;
	  tmp.y = _m->spos.y + pos.y;
	  if (getpixel(_m->mimg, tmp) == 0xffffffff
	      && (getpixel(_m->scott, npos) & 0xff000000) != 0)
	    {
	      tmp.x = _m->spos.x + pos.x + 1;
	      tmp.y = _m->spos.y + pos.y;
	      mpixel(_m->mimg, tmp, WHITE);
	    }
	  npos.x = pos.x - 1;
	  npos.y = pos.y;
	  if (getpixel(_m->mimg, tmp) == 0xffffffff
	      && (getpixel(_m->scott, npos) & 0xff000000) != 0 && pos.x > 1)
	    {
	      tmp.x = _m->spos.x + pos.x - 1;
	      tmp.y = _m->spos.y + pos.y;
	      mpixel(_m->mimg, tmp, WHITE);
	    }
	  npos.x = pos.x;
	  npos.y = pos.y + 1;
	  if (getpixel(_m->mimg, tmp) == 0xffffffff
	      && (getpixel(_m->scott, npos) & 0xff000000) != 0)
	    {
	      tmp.x = _m->spos.x + pos.x;
	      tmp.y = _m->spos.y + pos.y + 1;
	      mpixel(_m->mimg, tmp, WHITE);
	    }
	}
    }
}

void	handle(t_main *_m)
{
  t_2D	pos;
  t_2D	npos;
  t_2D	tmp;

  pos.x = -1;
  while (++pos.x < 407)
    {
      pos.y = -1;
      while (++pos.y < 343)
	{
	  npos.x = pos.x + 1;
	  npos.y = pos.y;
	  tmp.x = _m->spos.x + pos.x;
	  tmp.y = _m->spos.y + pos.y;
	  if ((getpixel(_m->scott, pos) & 0xff000000) == 0
	      && (getpixel(_m->scott, npos) & 0xff000000) != 0)
	    {
	      tmp.x = _m->spos.x + pos.x + 1;
	      tmp.y = _m->spos.y + pos.y;
	      mpixel(_m->mimg, tmp, WHITE);
	    }
	  npos.x = pos.x - 1;
	  npos.y = pos.y;
	  if ((getpixel(_m->scott, pos) & 0xff000000) == 0
	      && (getpixel(_m->scott, npos) & 0xff000000) != 0 && pos.x > 1)
	    {
	      tmp.x = _m->spos.x + pos.x - 1;
	      tmp.y = _m->spos.y + pos.y;
	      mpixel(_m->mimg, tmp, WHITE);
	      pos.y = 400;
	    }
	  npos.x = pos.x;
	  npos.y = pos.y + 1;
	  if ((getpixel(_m->scott, pos) & 0xff000000) == 0
	      && (getpixel(_m->scott, npos) & 0xff000000) != 0)
	    {
	      tmp.x = _m->spos.x + pos.x;
	      tmp.y = _m->spos.y + pos.y + 1;
	      mpixel(_m->mimg, tmp, WHITE);
	      pos.y = 400;
	    }
	}
    }
}

t_resp		update(void *_v)
{
  t_main	*_m;

  _m = (t_main *)_v;
  _m->clock += 0.4;
  if (bunny_music_get_cursor(_m->mu) >= _m->mu->duration)
    bunny_sound_play(&_m->mu->sound);
  if (_m->clock < 0.5)
    blit(_m->mimg, _m->fond, _m->mpos);
  if (_m->clock < 1)
    handle(_m);
  else
    handler(_m);
  if (_m->clock > 60)
    blit(_m->mimg, _m->scott, _m->spos);
  bunny_blit(&(_m->mwin->buffer), &(_m->mimg->clipable), &(_m->mpos));
  bunny_display(_m->mwin);
  return (GO_ON);
}
