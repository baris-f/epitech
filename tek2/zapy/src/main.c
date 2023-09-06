/*
1;4402;0c** main.c for philo in /home/baris_f/rendu/tek2/PSU_2016_philo
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Wed Mar  8 12:20:35 2017 baris_f
** Last update Sat Jul  1 17:36:14 2017 baris_f
*/

#include "ia.h"

int	main(int ac, char **av)
{
  t_data	data;

  init(&data);
  if (parse(ac, av, &data) == -1)
    return (-1);
  while (strcmp(data.rep, "dead") != 0)
    {
      act(&data);
      getResponse(&data);
    }
  return (0);
}

void    initMinerals(t_data* data)
{
  data->sminerals[0] = strdup("linemate");
  data->sminerals[1] = strdup("deraumere");
  data->sminerals[2] = strdup("sibur");
  data->sminerals[3] = strdup("mendiane");
  data->sminerals[4] = strdup("phiras");
  data->sminerals[5] = strdup("thystame");
  data->sminerals[6] = strdup("player");
}

void    initNeeds(t_data *data)
{
  for (int i = 0; i < 7; i++)
    if ((data->needs[i] = malloc(7 * sizeof(int))) == NULL)
      return ;
  memcpy(data->needs[0], (int[]) { 1, 0, 0, 0, 0, 0, 0}, 7 * sizeof(int));
  memcpy(data->needs[1], (int[]) { 1, 1, 1, 0, 0, 0, 1}, 7 * sizeof(int));
  memcpy(data->needs[2], (int[]) { 2, 0, 1, 0, 2, 0, 1}, 7 * sizeof(int));
  memcpy(data->needs[3], (int[]) { 1, 1, 2, 0, 1, 0, 3}, 7 * sizeof(int));
  memcpy(data->needs[4], (int[]) { 1, 2, 1, 3, 0, 0, 3}, 7 * sizeof(int));
  memcpy(data->needs[5], (int[]) { 1, 2, 3, 0, 1, 0, 5}, 7 * sizeof(int));
  memcpy(data->needs[6], (int[]) { 2, 2, 2, 2, 2, 1, 5}, 7 * sizeof(int));
}

void    init(t_data *data)
{
  srand(time(NULL));
  data->clvl = 1;
  data->machine = NULL;
  data->name = NULL;
  data->port = -1;
  if ((data->rep = malloc(256 * sizeof(char))) == NULL)
   return ;
  if ((data->path = calloc(1, 2 * sizeof(int))) == NULL)
   return ;
  if ((data->minerals = calloc(1, 7 * sizeof(int))) == NULL)
   return ;
  if ((data->sminerals = calloc(1, 7 * sizeof(char*))) == NULL)
   return ;
  if ((data->needs = calloc(1, 7 * sizeof(int*))) == NULL)
   return ;
  initMinerals(data);
  initNeeds(data);
  data->priority = strdup("linemate");
  data->action = strdup("T");
  data->found = 0;
  data->turns = 0;
}
