/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/baris_f/rendu/Piscine_C_J08/ex_04
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Wed Oct  7 12:40:10 2015 Florent Baris
** Last update Mon Oct 12 20:45:44 2015 Florent Baris
*/

#include <stdlib.h>

char	**mallocomotive(char *str, char **tab)
{
  int   k;
  int   j;
  int   i;

  k = -1;
  j = 0;
  i = -1;
  while (str[++i])
    {
      if ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'Z')
	  ||  (str[i] >= 'a' && str[i] <= 'z'))
	  tab[j][++k] = str[i];
      else if (!((str[i + 1] >= '0' && str[i + 1] <= '9') ||
	       (str[i + 1] >= 'A' && str[i + 1] <= 'Z')
		 ||  (str[i + 1] >= 'a' && str[i + 1] <= 'z')))
	k = -1;
      else
	{
	  j++;
	  k = -1;
	}
    }
}

char    **my_str_to_wordtab(char *str)
{
  int   i;
  char   **tab;
  int   nb_case;
  int   t_len;

  i = -1;
  nb_case = 1;
  t_len = my_strlen(str);
  while (str[++i] && str[i + 1] != '\0')
    {
      if (!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' &&
 str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9')) &&
((str[i + 1] >= 'A' && str[i + 1] <= 'Z') || (str[i + 1] >= 'a' &&
 str[i + 1] <= 'z') || (str[i + 1] >= '0' && str[i + 1] <= '9')))
	nb_case++;
    }
  if ((tab = malloc((nb_case + 1) * sizeof(char *) )) == NULL)
    return (NULL);
  i = -1;
  while (++i < nb_case)
      tab[i] = malloc(t_len * sizeof(char*));
  mallocomotive(str, tab);
  tab[nb_case] = 0;
  return (tab);
}
