/*
** sampleparse.c for sdfho in /home/fus/rendu/gfx/gfx_scroller/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Sun Mar 20 18:41:47 2016 Gaspard Thirion
** Last update Sun Mar 20 22:16:55 2016 Florent Baris
*/

#include "tool.h"

int	mreader(t_base *base)
{

  /* bunny_compute_effect(bunny_new_effect(base->bsf.dur[base->bsf.idx])); */
  bunny_sound_play(base->bsf.sample);
  if (!base->bsf.dur[base->bsf.idx++])
    base->bsf.idx = 0;
}

int	mparser(t_base *base, char *name)
{
  struct stat buf;
  int	fd;
  int	i;
  int	j;
  char	*buff;
  char	prout[] = "res/modlike/                                   ";

  if ((fd = open(name, O_RDONLY)) == -1
      || stat(name, &buf)
      || (buff = malloc(sizeof(char) * (buf.st_size + 1))) == NULL
      || read(fd, buff, buf.st_size) == -1
      || (base->bsf.dur = malloc(sizeof(float) * 10000)) == NULL
      || (base->bsf.freq = malloc(sizeof(float) * 10000)) == NULL)
    return (-1);
  i = 0;
  while (buff[++i] && buff[i] != '"');
  j = 11;
  while (buff[++i] && buff[i] != '"')
    prout[++j] = buff[i];
  prout[++j] = '\0';
  base->bsf.sample = bunny_load_effect(prout);
  j = -1;
  while (buff[++i] && buff[i] != '"');
  while (buff[i] && buff[i] != 'f')
    {
      while (buff[++i] && buff[i] == '"' || buff[i] == ',');
      base->bsf.dur[++j] = atof(&buff[i]);
      while (buff[++i] && buff[i] != '"' && buff[i] != 'f');
    }
  while (buff[i])
    {
      while (buff[++i] && buff[i] == '"' || buff[i] == ',');
      base->bsf.dur[++j] = atof(&buff[i]);
        while (buff[++i] && buff[i] != '"');
    }
  base->bsf.idx = 0;
  /* base->bsf.effect = bunny_new_effect(1); */
  /* base->bsf.effect.sound = base->bsf.sample; */
  free(buff);
  close(fd);
}
