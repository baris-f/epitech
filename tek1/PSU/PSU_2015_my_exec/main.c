/*
** main.c for main in /home/baris-f/rendu/PSU/PSU_2015_my_exec
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Thu Jan  7 15:39:20 2016 Florent Baris
** Last update Thu Jan  7 17:42:40 2016 Florent Baris
*/

int	main(int ac, char **av, char **env)
{
  char	**truc;

  if (ac != 2)
    return(write(1, "nope\n", 5));
  truc = my_str_to_wordtab(av[1]);
  printf("%s\n", truc[0]);
  execve(truc[0], &truc[1], env);
  printf("hello\n");
}
