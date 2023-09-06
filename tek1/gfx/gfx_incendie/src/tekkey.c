/*
** tekkey.c for fdf in /home/fus/rendu/gfx_fdf1/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Wed Nov 18 22:15:24 2015 Gaspard Thirion
** Last update Sat Dec  5 12:08:09 2015 Florent Baris
*/

#include		<lapin.h>
#include		<lapin_enum.h>
#include		<unistd.h>
#include	        "../my_lap.h"

t_bunny_response		tekkey(t_bunny_event_state state, t_bunny_keysym key,
				       void *_void)
{
  (void)_void;
  (void)state;
  if (key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}
