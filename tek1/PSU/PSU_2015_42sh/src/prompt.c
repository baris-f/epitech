/*
** prompt.c for prompt in /home/grandma/PSU_2015_42sh
**
** Made by Corentin Grandmaire
** Login   <grandm_a@epitech.net>
**
** Started on  Tue May 17 13:20:21 2016 Corentin Grandmaire
** Last update Sun Jun  5 21:20:46 2016 Corentin Grandmaire
*/

#include "42s.h"

char		*getstr(char *str, char **env)
{
  int		i;
  int		j;
  int		cursor;
  char		*temp;

  cursor = 0;
  i = 0;
  while (env[i])
    {
      j = 0;
      while (str[j] && env[i][j] == str[j])
	j++;
      if (!str[j])
	{
	  if ((temp = malloc(sizeof(char) * my_strlen(env[i]) + 1)) == NULL)
	    return (NULL);
	  while (env[i][j])
	    temp[cursor++] = env[i][j++];
	  temp[cursor] = '\0';
	  return (temp);
	}
      i++;
    }
  return (NULL);
}

int		welcome(t_42 *base)
{
  char		*user;
  int		ustmp;

  ustmp = 0;
  if ((user = getstr("USER=", base->env)) == NULL)
    {
      user = "user";
      ustmp++;
    }
  printf(CYAN "Hi"YELLOW" %s"CYAN", welcome to RS-SH ! \n" NORMAL, user);
  if (ustmp == 0)
      free(user);
  return (0);
}

int		prompt(t_42 *base)
{
  char		*user;
  char		*comp;
  int		cmtmp;
  int		ustmp;

  ustmp = 0;
  cmtmp = 0;
  if ((user = getstr("USER=", base->env)) == NULL)
    {
      user = "USER";
      ustmp++;
    }
  if ((comp = getstr("PWD=", base->env)) == NULL)
    {
      comp = "PWD";
      cmtmp++;
    }
  printf(YELLOW"%s"NORMAL"@"PWD"%s"NORMAL" #%d> "
	 , user, comp, base->idx);
  if (ustmp == 0)
    free(user);
  if (cmtmp == 0)
    free(comp);
  return (0);
}
