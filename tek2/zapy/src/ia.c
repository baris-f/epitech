/*
** ia.c for ia in /home/baris_f/rendu/tek2/zapy
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Thu Jun 29 16:28:42 2017 baris_f
** Last update Sat Jul  1 17:36:39 2017 baris_f
*/

#include "ia.h"

void    setAction(t_data *data, char* action)
{
  if (data->action)
    free(data->action);
  data->action = strdup(action);
}

void    getResponse(t_data *data)
{
  read(0, data->rep, 256);
  data->rep[strlen(data->rep) - 1] = '\0';
//  printf("%s\n", data->rep);
}

int     missingItem(t_data *data)
{
  for (int i = 0; i < 7; i++)
    {
      if (data->minerals[i] != data->needs[data->clvl - 1][i])
        return (i);
    }
  return (-1);
}

void    setPriority(t_data *data)
{
  int   miss = missingItem(data);

  if ((data->ate + 1) < data->turns / 10)
    {
      free(data->priority);
      data->priority = strdup("food");
    }
  else if (miss != 1)
    {
      free(data->priority);
      //            printf("%s\n", data->sminerals[i]);
      data->priority = strdup(data->sminerals[miss]);
      return ;
    }
}

void    act(t_data *data)
{
  if (strcmp(data->action, "Look") == 0)
    getLook(data);
  if (missingItem(data) == -1)
    {
      data->clvl++;
      setAction(data, "Incantation");
    }
  else if (data->path[0] == 0 && data->path[1] == 0)
    {
      if (data->action[0] != 'T' && data->action[0] != 'I' && data->found)
        take(data);
      else
        {
          setPriority(data);
          setAction(data, "Look");
        }
    }
  else
    move(data);
  data->turns++;
  printf("%s\n", data->action); // socket envoi
}
