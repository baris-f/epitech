/*
** tekkey.c for keys in /home/baris-f/rendu/gfx_fdf2/src
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Dec 21 21:15:36 2015 Florent Baris
** Last update Sat Dec 26 17:41:38 2015 Florent Baris
*/

#include "../inc/wolf.h"

t_bunny_response       	tekkey(t_bunny_event_state state, t_bunny_keysym key,
				       void *_void)
{
  (void)_void;
  (void)state;
  if (key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}
