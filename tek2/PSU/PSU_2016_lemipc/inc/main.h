/*
** main.h for main in /home/baris_f/rendu/tek2/PSU_2016_lemipc
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Sat Apr  1 19:02:15 2017 baris_f
** Last update Sat Apr  1 19:02:17 2017 baris_f
*/

#ifndef MAIN
#define MAIN

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/msg.h>
#include <math.h>
#include <time.h>

#define MAP_SIZE	30

typedef enum e_dir
{
	BUG = -1,
	RIGHT,
	LEFT,
	UP,
	DOWN
} t_dir;

typedef struct s_map
{
	int nb_player;
	int map[MAP_SIZE][MAP_SIZE];
} t_map;

typedef struct s_dat
{
	key_t key;
	int draw;
	int shmId;
	int	semId;
	int msqId;

    struct sembuf sbuff;
	t_map* map;

	int teamId;
	int x;
	int y;
} t_dat;

typedef struct s_v2
{
  int	x;
  int	y;
}	t_v2;

typedef struct s_team
{
  t_v2	*allies;
  int	nbAllies;
  t_v2	*ennemies;
  int	nbEnnemies;
}	t_team;

int     isAlone(t_dat *dat);
void update(t_dat*);
int cli_draw(t_map*);
t_dir	getDir(t_dat*);
int	move(t_dat *dat, t_dir dir);
#endif
