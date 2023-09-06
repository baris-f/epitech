#ifndef MY_H_
# define MY_H_

typedef struct s_var
{
  char  *buff;
  int   rows;
  char  **map;
  int   i;
  int   fd;
  int   size;
  int   sizedif;
  int   fpos[2];
  int	j;
  struct stat   info;
} t_var;

char            *getnextline(const int fd, int size);
int	my_getnbr(char*);
void    applyx(int x, int y, int size, char **map);
int     check(int x, int y, int size, char **map);
int     bsq(char **map, int rows, int size, int *fpos);
#endif /* !MY_H_ */
