/*
** oldia.c for old in /home/baris_f/rendu/tek2/PSU_2016_lemipc
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Sat Apr  1 19:03:10 2017 baris_f
** Last update Sat Apr  1 19:10:41 2017 baris_f
*/

int	countAllies(t_dat *dat, t_team *team)
{
  int	i;
  int	j;
  int	m;

  i = -1;
  m = 0;
  m = (team->nbAllies == 0) ? 1 : 0;
  team->nbAllies = 0;
  while (++i < MAP_SIZE)
    {
      j = -1;
      while (++j < MAP_SIZE)
        if (dat->map->map[i][j] == dat->teamId)
          team->nbAllies++;
    }
  if (m && (team->allies = malloc(sizeof(t_v2) * team->nbAllies)) == NULL)
    return ;

}

void	fillAllies(t_dat *dat, t_team *team)
{
  int	i;
  int	j;
  int	k;

  i = -1;
  k = -1;
  countAllies(dat, team);
  while (++i < MAP_SIZE)
    {
      j = -1;
      while (++j < MAP_SIZE)
        if (dat->map->map[i][j] == dat->teamId)
          {
            team->allies[++k]->x = i;
            team->allies[k]->y = j;
          }
    }
}
