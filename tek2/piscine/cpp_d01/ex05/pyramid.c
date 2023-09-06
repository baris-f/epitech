/*
** pyramid.c for pyramid in /home/baris_f/rendu/tek2/cpp_d01/ex05
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Wed Jan  4 14:09:06 2017 baris_f
** Last update Wed Jan  4 23:13:30 2017 baris_f
*/

int	min(int a, int b)
{
  if (a > b)
    return (b);
  else
    return (a);
}

int	parse(int size, int **map, int y, int x)
{
  if (y + 1 < size)
    return(map[y][x] + min(parse(size, map, y + 1, x + 1), parse(size, map, y + 1, x)));
  else
    return(map[y][x]);
}

int	pyramid_path(int size, int **map)
{
  int sum;

  sum = parse(size, map, 0, 0);
  return (sum);
}

/*
int	main()
{
  int	**map;

  map = malloc(sizeof(int) * 4);
  int i = -1;
  while (++i < 4 )
    {
      map[i] = malloc(sizeof(int) * 4);
    }
  map[0][0] = 0;
  map[1][0] = 7;
  map[1][1] = 4;
  map[2][0] = 2;
  map[2][1] = 3;
  map[2][2] = 6;
  map[3][0] = 8;
  map[3][1] = 5;
  map[3][2] = 9;
  map[3][3] = 3;
  printf("%d\n", pyramid_path(4, map));
  return (0);
  }*/
