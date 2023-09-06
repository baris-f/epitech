/*
** process.c for process in /home/baris_f/rendu/tek2/PSU_2016_lemipc
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Sat Apr  1 19:02:25 2017 baris_f
** Last update Sat Apr  1 19:14:09 2017 baris_f
*/

typedef struct s_dat
{
    long mtype;
    int id;
} t_dat;

int	main(int ac, char **av)
{
    key_t		key;
    int			shmid;
    t_dat		*dat;
    int			semid;
    struct sembuf	*sbuff;
    int			msqid;

    if (ac != 2 || (key = ftok(av[1], 0)) == -1 ||
        (shmid = shmget(key, sizeof(t_dat),
			IPC_CREAT | SHM_R | SHM_W)) == -1 ||
        (dat = (t_dat *)shmat(shmid, NULL, SHM_R | SHM_W)) == NULL ||
        (semid = semget(key, NB_PLACES, IPC_CREAT | SHM_R | SHM_W)) == -1 ||
        semctl(semid, 0, SETVAL, NB_PLACES) == -1 ||
        (msqid = msgget(key, SHM_R | SHM_W | IPC_CREAT)) == -1)
        return (printf("errno %d\n", errno) * 0 - 1);
    printf("path %s key %d shm %d addr %p sem %d -> %d msg %d\n",
           av[1], key, shmid, dat, semid, semctl(semid, 0, GETVAL), msqid);
    system("ipcs");
    shmctl(shmid, IPC_RMID, NULL);
    semctl(semid, 0, IPC_RMID);
    return (0);
}
