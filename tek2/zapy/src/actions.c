/*
** actions.c for ia in /home/baris_f/rendu/tek2/zapy
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Sat Jul  1 17:10:00 2017 baris_f
** Last update Sat Jul  1 17:33:36 2017 baris_f
*/

#include "ia.h"

void    getLook(t_data *data)
{
  int i = 0;
  data->rep[strlen(data->rep) - 1] = '\0';
  char* res = strtok(data->rep, ",");
  while (res != NULL)
    {
      i++;
      if (res[0] != '\0')
        {
          if (res[0] == ' ' || res[0] == '[')
            res++;
//          printf("res[%d] = %s\n", i, res);
          if (strcmp(res, data->priority) == 0)
            {
              setPath(data, i);
              return ;
            }
        }
      res = strtok(NULL, ",");
    }
  data->path[0]++;
  if (rand() % 10 > 9)
    data->path[1]++;
}

void    setPath(t_data *data, int tile)
{
  int   lvl = 1;
  int   incr = 0;

  data->found = 1;
  while (tile >= (lvl + incr))
    {
      incr++;
      incr *= 2;
      lvl++;
    }
  data->path[0] = lvl - 1;
  data->path[1] = tile - incr;
}

void    move(t_data *data)
{
  if (data->path[0] > 0)
    {
      data->path[0]--;
      setAction(data, "Forward");
    }
  else if (data->path[1] < 0)
    {
      data->path[0] = -data->path[1];
      data->path[1] = 0;
      setAction(data, "Left");
    }
  else
    {
      data->path[0] = data->path[1];
      data->path[1] = 0;
      setAction(data, "Right");
    }
}

void    addObj(t_data *data)
{
  if (strcmp(data->priority, "linemate") == 0)
    data->minerals[0]++;
  else if (strcmp(data->priority, "deraumere") == 0)
    data->minerals[1]++;
  else if (strcmp(data->priority, "sibur") == 0)
    data->minerals[2]++;
  else if (strcmp(data->priority, "mendiane") == 0)
    data->minerals[3]++;
  else if (strcmp(data->priority, "phiras") == 0)
    data->minerals[4]++;
  else if (strcmp(data->priority, "thystame") == 0)
    data->minerals[5]++;
  else if (strcmp(data->priority, "food") == 0)
    data->ate++;
  else if (strcmp(data->priority, "player") == 0)
    data->minerals[6]++;
 // printf("clinemate :%d\n", data->minerals[0]);
}

void    take(t_data *data)
{
  char tmp[200];

  sprintf(tmp, "Take %s", data->priority);
  addObj(data);
  data->found = 0;
  setAction(data, tmp);
}
