/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/baris_f/rendu/Piscine_C_J08/ex_04
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Wed Oct  7 12:40:10 2015 Florent Baris
** Last update Fri Jan 29 14:06:39 2016 Florent Baris
*/

#include <stdlib.h>
#include "my.h"

char    *my_strdup(char *src)
{
  char  *str;
  int   length;

  length  = my_strlen(src);
  str = malloc(length);
  str = src;
  return (str);
}

int     get_cara(char *str, int *i)
{
  int   compt;

  compt = 0;
  while (str[*i] >= '!' && str[*i] <= '~')
    {
      compt++;
      (*i)++;
    }
  return (compt);
}

char    **my_str_to_wordtab(char *s)
{
  int   i;
  int   j;
  int   nb;
  char  **tab;

  i = -1;
  nb = 2;
  j = 0;
  while (s[++i])
    if (!(s[i] >= '!' && s[i] <= '~'))
      nb++;
  if ((tab = malloc(nb * sizeof(char*))) == NULL)
    return (NULL);
  i = -1;
  while (s[++i] && nb > 0)
    if (s[i] >= '!' && s[i] <= '~')
      {
	tab[j] = my_strdup(&s[i]);
	tab[j++][get_cara(s, &i)] = '\0';
	nb--;
      }
  tab[i + 1] = NULL;
  return (tab);
}

/* void	mallocomotive(char *str, char **tab, int size) */
/* { */
/*   int   i; */
/*   int	j; */
/*   int	nb_case; */

/*   i = -1; */
/*   j = -1; */
/*   nb_case = 0; */
/*   my_memset(tab[nb_case], '\0', size); */
/*   while (str[++i]) */
/*     { */
/*       tab[nb_case][++j] = str[i]; */
/*       if (str[i + 1] == ' ' || str[i + 1] == '\n') */
/* 	{ */
/* 	  nb_case++; */
/* 	  while (str[++i] == ' ' || str[i] == '\n'); */
/* 	  j = -1; */
/* 	  if (str[i] != '\0') */
/* 	    my_memset(tab[nb_case], '\0', size); */
/* 	  i--; */
/* 	} */
/*     } */
/* } */

/* char    **my_str_to_wordtab(char *str) */
/* { */
/*   int   i; */
/*   char   **tab; */
/*   int   nb_case; */

/*   i = -1; */
/*   nb_case = 1; */
/*   while (str[++i]) */
/*     if (str[i] == ' ' || str[i] == '\n') */
/*       { */
/* 	nb_case++; */
/* 	while (str[i + 1] == ' ' || str[i + 1] == '\n') */
/* 	  i++; */
/* 	if (str[i + 1] == '\0') */
/* 	  nb_case--; */
/*       } */
/*   if ((tab = malloc((nb_case + 1) * sizeof(char *))) == NULL) */
/*     return (0); */
/*   i = -1; */
/*   while (++i < nb_case) */
/*     if ((tab[i] = malloc(my_strlen(str) * sizeof(char) + 1)) == NULL) */
/*       return (0); */
/*   mallocomotive(str, tab, my_strlen(str)); */
/*   tab[nb_case - 1] = NULL; */
/*   return (tab); */
/* } */

/* void	main(int ac, char **av) */
/* { */
/*   char	**tab; */

/*   tab = my_str_to_wordtab(av[1]); */
/*   my_show_wordtab(tab); */
/* } */
