#include "main.h"

int	mapInit(t_dat *dat)
{
  int	i = 0;

  printf("\e[?25l");
  while (++i < MAP_SIZE)
    memset(dat->map->map[i], 0, MAP_SIZE);
  dat->draw = 1;
  dat->sbuff.sem_num = 0;
  dat->sbuff.sem_flg = 0;
  return (1);
}

int	sem_msqInit(t_dat *dat)
{
  dat->semId = semget(dat->key, 1, SHM_R | SHM_W);
  if (dat->semId == -1)
  {
    printf("creating semaphore\n");
    if ((dat->semId = semget(dat->key, 1, SHM_R | SHM_W | IPC_CREAT)) == -1)
      return (0);
  }
  else
    printf("using existant semaphore\n");
  dat->msqId = msgget(dat->key, SHM_R | SHM_W);
  if (dat->msqId == -1)
  {
    printf("creating message queue\n");
    if ((dat->msqId = msgget(dat->key, SHM_R | SHM_W | IPC_CREAT)) == -1)
      return (0);
  }
  else
    printf("using existant message queue\n");
  if (dat->draw)
    semctl(dat->semId, 0, SETVAL, 1);
  return (1);
}

int	shmInit(t_dat *dat)
{
  dat->draw = 0;
  dat->shmId = shmget(dat->key, sizeof(t_map), SHM_R | SHM_W);
  if (dat->shmId == -1)
  {
    printf("creating map\n");
    if ((dat->shmId = shmget(dat->key,
			     sizeof(t_map), SHM_R | SHM_W | IPC_CREAT)) == -1)
      return (0);
  }
  else
    printf("using existant map\n");
  if ((dat->map = shmat(dat->shmId, NULL, SHM_R | SHM_W)) == NULL)
    return (0);
  if (dat->map->nb_player == 0)
    mapInit(dat);
  dat->map->nb_player++;
  return (1);
}

void	clean(t_dat *dat)
{
  shmdt(dat->map);
  shmctl(dat->shmId, IPC_RMID, NULL);
  semctl(dat->semId, 0, IPC_RMID);
  msgctl(dat->msqId, IPC_RMID, NULL);
  printf("\e[?25h");
  printf("\e[1;1H\e[2J");
}

int	main(int ac, char **av)
{
  t_dat	dat;

  srand(time(NULL));
  if (ac != 3 || !(av[1]) || !(av[2]) || (dat.teamId = atoi(av[2])) <= 0)
    return ((int)printf("Usage : %s path_to_key team_number\n",
			av[0]) * 0 - 1);
  if ((dat.key = ftok(av[1], 0)) == -1)
    return ((int)printf("unable to get key for map [%s]\n", av[1]) * 0 - 1);
  printf("succesfuly got key %d from path [%s]\n", (int)dat.key, av[1]);
  if (!shmInit(&dat))
    return ((int)printf("unable to get/create map\n") * 0 - 1);
  if (!sem_msqInit(&dat))
    return ((int)printf("unable to get/create semaphore\n") * 0 - 1);
  printf("player %d  draw? : %d\n", dat.map->nb_player, dat.draw);
  update(&dat);
  if (dat.draw)
    clean(&dat);
  return (0);
}
