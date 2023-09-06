/*
** getnbr.c for getnbr in /home/baris-f/rendu/c
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Thu Dec 31 16:44:29 2015 Florent Baris
** Last update Fri Feb 26 15:31:41 2016 Florent Baris
*/


int	is_neg(char *str)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (str[i] > '9' || str[i] < '0')
    {
      if (str[i] == '-')
	count++;
      i++;
    }
  if (count % 2 != 0)
    return (1);
  else
    return (0);
}

int	is_num(char l)
{
  if (l >= '0' && l <= '9' || l == '-'|| l == '+')
    return (1);
  else
    return (0);
}

int	my_getnbr(char *str)
{
  int	i;
  int	nbr;

  nbr = 0;
  i = -1;
  /* while (is_num(str[i]) == 0) */
  /*   i++; */
  /* if (i - 1 == my_strlen(str)) */
  /*   return (0); */
  while (is_num(str[++i]) == 1)
    {
      if (str[i] != '-' && str[i] != '+')
	nbr = ((nbr * 10) + (str[i] - '0'));
    }
  if (is_neg(str) == 1)
    nbr = -nbr;
  return (nbr);
}
