/*
** signal.c for ok in /home/grandma/PSU_2015_42sh
**
** Made by Corentin Grandmaire
** Login   <grandm_a@epitech.net>
**
** Started on  Wed Jun  1 15:28:07 2016 Corentin Grandmaire
** Last update Sun Jun  5 19:48:36 2016 Corentin Grandmaire
*/

#include "42s.h"

void	sign()
{
  return ;
}

int	set_signal()
{
  if (signal(SIGTSTP, &sign) == SIG_ERR)
    return (-1);
  if (signal(SIGINT, &sign) == SIG_ERR)
    return (-1);
  if (signal(SIGQUIT, &sign) == SIG_ERR)
    return (-1);
  return (0);
}
