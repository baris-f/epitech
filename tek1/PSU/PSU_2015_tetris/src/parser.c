/*
** parser.c for tetris in /home/dudu/rendu/PSU_2015_tetris
**
** Made by lucas duval
** Login   <duval_m@epitech.net>
**
** Started on  Thu Feb 25 09:10:58 2016 lucas duval
** Last update Sun Mar 20 22:29:00 2016 lucas duval
*/

#include "tetris.h"

void	arg_parser(char **av, t_tetris *tet)
{
  int	i;
  int	j;

  i = 0;
  while (av[++i])
    {
      j = 0;

      if (av[i][j] == '-')
	{
	  if (av[i][++j] == '-')
	    {
	      if (my_strncmp(av[i] + 2, "help", 3) == 0)
		set_help();
	      else if (my_strncmp(av[i] + 2, "level", 4) == 0)
		set_level(av[i], 1, tet);
	      else if (my_strncmp(av[i] + 2, "key-left", 7) == 0)
		set_key_left(av[i], 1, tet);
	      else if (my_strncmp(av[i] + 2, "key-right", 8) == 0)
		set_key_right(av[i], 1, tet);
	      else if (my_strncmp(av[i] + 2, "key-turn", 7) == 0)
		set_key_turn(av[i], 1, tet);
	      else if (my_strncmp(av[i] + 2, "key-drop", 7) == 0)
		set_key_drop(av[i], 1, tet);
	      else if (my_strncmp(av[i] + 2, "key-quit", 7) == 0)
		set_key_quit(av[i], 1, tet);
	      else if (my_strncmp(av[i] + 2, "key-pause", 8) == 0)
		set_key_pause(av[i], 1, tet);
	      else if (my_strncmp(av[i] + 2, "map-size", 7) == 0)
		set_map_size(av[i], tet);
	      else if (my_strncmp(av[i] + 2, "debug", 4) == 0)
		tet->debug = 1;
	      else if (my_strncmp(av[i] + 2, "without-next", 11) == 0)
		tet->aff_next = 0;
	      else
		{
		  my_printf("Error ./tetris --help\n");
		  exit(0);
		}
	    }
	  else
	    {
	      if (my_strcmp(av[i], "-l") == 0)
		set_level(av[i + 1], 0, tet);
	      else if (my_strcmp(av[i], "-w") == 0)
		tet->aff_next = 0;
	      else if (my_strcmp(av[i], "-d") == 0)
		tet->debug = 1;
	      else if (my_strcmp(av[i] + j, "kl") == 0)
		set_key_left(av[i + 1], 0, tet);
	      else if (my_strcmp(av[i] + j, "kr") == 0)
		set_key_right(av[i + 1], 0, tet);
	      else if (my_strcmp(av[i] + j, "kt") == 0)
		set_key_turn(av[i + 1], 0, tet);
	      else if (my_strcmp(av[i] + j, "kd") == 0)
		set_key_drop(av[i + 1], 0, tet);
	      else if (my_strcmp(av[i] + j, "kq") == 0)
		set_key_quit(av[i + 1], 0, tet);
	      else if (my_strcmp(av[i] + j, "kp") == 0)
		set_key_pause(av[i + 1], 0, tet);
	      else
		set_help();
	    }
	}
    }
}

char	*get_name(char *name)
{
  int	len;
  char	*rname;

  len = my_strlen(name);
  len -= 10;
  rname = malloc(sizeof(char) * len + 1);
  my_strncpy(rname, name, len);
  return (rname);
}

int	count_file()
{
  struct dirent *lecture;
  DIR *rep;
  int	nb;

  nb = 0;
  rep = opendir("./tetriminos");
  if (rep == NULL)
    {
      my_printf("Error can't find tetriminos folder\n");
      exit(-1);
    }
  while ((lecture = readdir(rep)))
    if (match(lecture->d_name, "*.tetrimino"))
      nb++;
  closedir(rep);
  return (nb);
}

void	get_tetrimino(t_tetris *tet)
{
  struct dirent *lecture;
  DIR *rep;
  char	*folder;
  int	fd;
  int	nbfile;
  int	i;

  nbfile = count_file();
  if (nbfile == 0)
    {
      my_printf("Error can't find any tetriminos in the folder\n");
      exit(-1);
    }
  tet->tetriminos = malloc(sizeof(t_tetri) * nbfile);
  tet->nb_tetri = nbfile;
  rep = opendir("./tetriminos");
  if (rep == NULL)
    {
      my_printf("Error can't find tetriminos folder\n");
      exit(-1);
    }
  i = 0;
  while ((lecture = readdir(rep)))
    if (match(lecture->d_name, "*.tetrimino"))
      {
	folder = malloc((sizeof(char) * 13 + my_strlen(lecture->d_name) + 1));
	my_strcpy(folder, "./tetriminos/");
	fd = open(my_strcat(folder, lecture->d_name), O_RDONLY);
	if (fd == -1)
	  {
	    tet->tetriminos[i].name = get_name(lecture->d_name);
	    tet->tetriminos[i++].ok = 0;
	  }
	else
	  tetrimo_parser(fd, &tet->tetriminos[i++], lecture->d_name);
	free(folder);
      }
  closedir(rep);
}

int	count_star(char	*line)
{
  int	i;
  int	j;

  i = -1;
  j = 0;
  while (line[++i])
    if (line[i] == '*')
      j++;
  return (j);
}

void	tetrimo_parser(int fd, t_tetri *tetrimos, char *name)
{
  int	i;
  char	*line;
  char	**words;
  char	**tetri;

  tetrimos->name = get_name(name);
  line = get_next_line(fd);
  words = my_str_to_wordtab(line, ' ');
  free(line);
  if (words[0] && words[1] && words[2])
    {
      tetrimos->ok = 1;
      tetrimos->size.x = my_getnbr(words[0]);
      tetrimos->size.y = my_getnbr(words[1]);
      tetrimos->color = my_getnbr(words[2]);
      tetri = malloc(sizeof(char *) * tetrimos->size.y + 1);
      i = -1;
      while (++i < tetrimos->size.y)
	tetri[i] = malloc(sizeof(char) * tetrimos->size.x + 2);
      i = -1;
      while (++i < tetrimos->size.y)
	{
	  line = get_next_line(fd);
	  if (count_star(line) > tetrimos->size.x)
	    tetrimos->ok = 0;
	  my_strncpy(tetri[i], line, tetrimos->size.x);
	  free(line);
	}
      tetrimos->shape = tetri;
    }
  else
    tetrimos->ok = 0;
}
