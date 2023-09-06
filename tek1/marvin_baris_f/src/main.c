/*
** main.c for marbvin in /home/baris-f/rendu/marvin_baris_f
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sun May 15 15:10:17 2016 Florent Baris
** Last update Sun May 15 23:34:43 2016 Florent Baris
*/

#include "marvin.h"

void	get_name(t_marvin *marv, char **av, int	i)
{
  int	j;

  j = 0;
  while (av[1][++i] != ';')
    j++;
  if ((marv->name = malloc(sizeof (char) * j + 1)) == NULL)
    exit(printf("malloc fail\n"));
  i -= j + 1;
  j = -1;
  while (av[1][++i] != ';')
    marv->name[++j] = av[1][i];
  marv->name[j + 1] = '\0';
}

char	*french(char *str)
{
  if (strcmp(str, "int") == 0)
    return ("entier");
  else if (strcmp(str, "float") == 0)
    return ("nombre flottant");
  else if (strcmp(str, "long") == 0)
    return ("entier long");
  else if (strcmp(str, "double") == 0)
    return ("flottant a précision double");
  else if (strcmp(str, "char") == 0)
    return ("caractère");
  else if (strcmp(str, "void") == 0)
    return ("vide");
  else
    return (str);
}

void	get_type(t_marvin *marv, char **av)
{
  char	*tmp;
  int	i;

  i = -1;
  while (av[1][++i] != ' ' && av[1][i] != '\0');
  if (i == (int)strlen(av[1]))
    exit(printf("expression invalide\n"));
  if ((tmp = malloc(sizeof (char) * i + 1)) == NULL)
    exit(printf("malloc fail\n"));
  i = -1;
  while (av[1][++i] != ' ')
    tmp[i] = av[1][i];
  tmp[i] = '\0';
  marv->type = french(tmp);
  get_name(marv, av, i--);
}

void	error(t_marvin *marv, char **av)
{
  int	i;
  int	nb;

  if (av[1] == NULL || strlen(av[1]) == 0)
    exit(printf("erreur en accédant à l'expression\n"));
  if (av[1][strlen(av[1]) - 1] != ';')
    exit(printf("point-virgule manquant\n"));
  get_type(marv, av);
  i = -1;
  nb = 0;
  marv->func = 0;
  while (av[1][++i] && nb >= 0)
    if (av[1][i] == '(')
      {
	nb++;
	marv->func = 1;
      }
    else if (av[1][i] == ')')
      nb--;
  if (nb != 0)
    exit(printf("parenthèse non fermée\n"));
}

int		main(int ac, char **av)
{
  t_marvin	marv;

  if (ac != 2)
    {
      printf("Usage : ./marvin \"expression\"""\n");
      return (-1);
    }
  error(&marv, av);
  printf("Déclaration ");
  if (marv.func == 0)
    printf("%s ", "de la variable de type");
  else
    printf("de la fonction %s qui prend en paramètre un %s ",
	   get_func(marv.name), french(get_param(marv.name, av)));
  printf("%s %s", marv.type, "nommé ");
  if (marv.func == 0)
    printf("%s", marv.name);
  else
    printf("et renvoyant un %s", french(marv.type));
  printf(".\n");
  return (0);
}
