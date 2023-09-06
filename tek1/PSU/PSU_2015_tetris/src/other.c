/*
** other.c for tetris in /home/dudu/rendu/PSU_2015_tetris
**
** Made by lucas duval
** Login   <duval_m@epitech.net>
**
** Started on  Thu Feb 25 09:41:45 2016 lucas duval
** Last update Sun Mar 20 18:55:20 2016 lucas duval
*/

#include "tetris.h"

void	set_help()
{
  my_printf("Usage: ./tetris [options]\n");
  my_printf("Options:\n");
  my_printf(" --help Display this help\n");
  my_printf(" -l --level={num} Start Tetris at level num\n");
  my_printf(" -kl --key-left={K} Move tetrimino on LEFT with key K\n");
  my_printf(" -kr --key-right={K} Move tetrimino on RIGHT with key K\n");
  my_printf(" -kt --key-turn={K} Turn tetrimino with key K\n");
  my_printf(" -kd --key-drop={K} Set default DROP on key K\n");
  my_printf(" -kq --key-quit={K} Quit program when press key K\n");
  my_printf(" -kp --key-pause={K} Pause and restart game when press key K\n");
  my_printf(" --map-size={row,col} Set game size at row, col\n");
  my_printf(" -w --without-next Hide next tetrimino\n");
  my_printf(" -d --debug Debug mode\n");
  exit(0);
}

void	set_level(char *lvl, int sel, t_tetris *tet)
{
  if (sel)
    tet->lvl = my_getnbr(lvl + (my_strlen(lvl) - 1));
  else
    tet->lvl = my_getnbr(lvl);
}

void	set_map_size(char *map, t_tetris *tet)
{
  char	**siz;

  siz = my_str_to_wordtab(map+11, ',');
  tet->size_map.x = my_getnbr(siz[0]);
  tet->size_map.y = my_getnbr(siz[1]);
}


void	print_debug(t_tetris *tet)
{
  char	next[4];
  char	*wait;

  if (tet->aff_next)
    my_strcpy(next, "Yes");
  else
    my_strcpy(next, "No");
  my_printf("*** DEBUG MODE ***\nKey Left : %c\nKey Right : %c\nKey Turn : %c\n\
Key Drop : %c\nKey Quit : %c\nKey Pause : %c\nNext : %s\nLevel : %d\n\
Size : %d*%d\n", tet->keys.left, tet->keys.right, tet->keys.turn,
	    tet->keys.drop, tet->keys.quit, tet->keys.pause, next, tet->lvl,
	    tet->size_map.x, tet->size_map.y);
  draw_tetri(tet);
  my_printf("Press enter to start Tetris\n");
  wait = get_next_line(0);
  free(wait);
}
