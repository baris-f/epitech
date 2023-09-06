/*
** main.c for wolf in /home/fus/rendu/gfx_wolf3d/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Thu Dec 24 08:55:33 2015 Gaspard Thirion
** Last update Tue Jan 19 10:25:00 2016 Gaspard Thirion
*/

#include <tool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

t_img		*prs_load(char *name)
{
  t_img		*ret;
  int		fd;
  int		x;
  int		y;
  t_col		*buff;
  t_col		*dest;
  int		i;
  int		size;

  fd = open(name, O_RDONLY);
  buff = malloc(sizeof(t_col*) * 2);
  read(fd, buff, 2);
  x = (int)buff[0];
  read(fd, buff, 2);
  y = (int)buff[0];
  printf("%d	%d\n", x, y);
  ret = bunny_new_pixelarray(x, y);
  size = x * y * 4;
  buff = malloc(sizeof(t_col*) * size);
  read(fd, buff, size);
  dest = (t_col*)ret->pixels;
  i = -1;
  while (++i < size)
    dest[i] = buff[i];
  return (ret);
}

void		tofile(t_img *bmp, char *name)
{
  int		fd;
  t_col		*buff;
  t_2D		dim;

  buff = (t_col*)bmp->pixels;
  fd = open(name, O_CREAT | O_RDWR, S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH);
  dim.x = bmp->clipable.clip_width;
  dim.y = bmp->clipable.clip_height;
  write(fd, &dim.x, 2);
  write(fd, &dim.y, 2);
  write(fd, buff, dim.x * dim.y * 4);
  close(fd);
}

int		error(int type, char *msg, char *obj)
{
  my_printf("%s %s\n", obj, msg);
  return (type);
}

int		main(int ac, char **av)
{
  t_img		*bmp;
  t_2D		pos = {0, 0};
  t_win		*win;
  int		i;
  int		avc;

  if (ac < 3)
    return(error(-1, "[0 = load_illustrator, 1 = load_gimp, 2 = affichage .prs] [file]", av[0]));
  avc = my_getnbr(av[1]);
  if (avc == 2)
    {
      bmp = prs_load(av[2]);
      win = bunny_start(bmp->clipable.clip_width, bmp->clipable.clip_height, 0, "LibLapin");
      bunny_blit(&(win->buffer), &(bmp->clipable), &(pos));
      bunny_display(win);
      sleep(4);
      bunny_stop(win);
    }
  else
    {
      if (avc == 0)
	bmp = load_bitmap(av[2]);
      else
	{
	  return(error(-1, "currently not working", "load_gimp"))
	bmp_load(av[2], bmp);
	}
      i = my_strlen(av[2]);
      while (av[2][--i] > 0 && av[2][i] != '.');
      av[2][++i] = 'p';
      av[2][++i] = 'r';
      av[2][++i] = 's';
      av[2][++i] = '\0';
      tofile(bmp, av[2]);
    }
  bunny_delete_clipable(&(bmp->clipable));
  return (0);
}
