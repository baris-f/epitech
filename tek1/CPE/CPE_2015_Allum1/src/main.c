/*
** main.c for main in /home/baris-f/rendu/CPE/CPE_2015_Allum1
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Thu Feb 11 09:59:19 2016 Florent Baris
** Last update Sun Feb 21 15:23:27 2016 Florent Baris
*/

#include "alum.h"

void	print_line(t_board *bd, int j)
{
  int	i;
  int	k;

  i = -1;
  while (++i < (bd->width / 2 - j))
    write(1, " ", 1);
  k = -1;
  while (++k < bd->alum[j])
    {
      write(1, "|", 1);
      i++;
    }
  while (++i <= bd->width)
    write(1, " ", 1);
}

void	draw_game(t_board *bd)
{
  int	i;
  int	j;

  j = -1;
  i = -1;
  while (++i < bd->width + 2)
    write(1, "*", 1);
  write(1, "\n", 1);
  while (++j < bd->line)
    {
      i = -1;
      write(1, "*", 1);
      print_line(bd, j);
      write(1, "*\n", 2);
    }
  i = -1;
  while (++i < bd->width + 2)
    write(1, "*", 1);
  write(1, "\n", 1);
  write(1, "\n", 1);
}

int	get_nbr_noerror(t_board *bd, char *str, int t, int line)
{
  int	ret;

  if (str[0] == '\n' || str[0] == '\0' || str == NULL || !(my_str_isnum(str)))
    {
      my_printf("Error: invalid input (positive number expected)\n");
      return (-1);
    }
  ret = my_getnbr(str);
  if (ret <= 0 && t == 1)
    my_printf("Error: you have to remove at least one match\n");
  else if ((ret <= 0 || ret > bd->line) && t != 1)
      my_printf("Error: this line is out of range\n");
  else if (ret > bd->alum[line] && t == 1)
      my_printf("Error: not enought matches on this line\n");
  else if (bd->alum[ret - 1] == 0 && t != 1)
      my_printf("Error: this line is empty\n");
  else
    return (ret);
  return (-1);
}

void	play_loop(t_board *bd)
{
  int	line;
  int	matches;
  int	match;

  while (nbalum(bd) > 0)
    {
      draw_game(bd);
      my_printf("Your turn:\n");
      match = 0;
      while (match != 1)
	{
	  my_printf("Line: ");
	  while ((line = get_nbr_noerror(bd, get_next_line(0), 0, 0)) == -1)
	    my_printf("Line: ");
	  my_printf("Matches: ");
	  ((matches = get_nbr_noerror(bd, get_next_line(0), 1, line - 1))
	   == -1) ? (match = 0) : (match = 1);
	}
      bd->alum[line - 1] -= matches;
      my_printf("Player removed %d match(es) from line %d\n", matches, line);
      draw_game(bd);
      (nbalum(bd) > 0) ? (ais_turn(bd)) : (my_printf("You lost, too bad..\n"));
    }
}

int		main(int ac, char **av)
{
  t_board	bd;
  int		i;

  bd.line = 0;
  if (ac == 2)
    {
      if (av[1][0] == '\n' || av[1][0] == '\0' || av[1] == NULL
	  || !(my_str_isnum(av[1])))
	bd.line = 4;
      else
	bd.line = my_getnbr(av[1]);
    }
  else
    bd.line = 4;
  if (bd.line <= 0)
    bd.line = 4;
  bd.width = bd.line * 2 - 1;
  if ((bd.alum = malloc(sizeof(int) * bd.line)) == NULL)
    return (write(1, "malloc error\n", 13) * 0 - 1);
  i = -1;
  while (++i < bd.line)
    bd.alum[i] = 1 + i * 2;
  play_loop(&bd);
  free(bd.alum);
  return (0);
}
