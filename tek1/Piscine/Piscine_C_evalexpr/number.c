/*
** number.c for evalexpr in /home/thirio_b/rendu/Piscine_C_evalexpr
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Tue Oct 20 09:55:33 2015 Gaspard Thirion
** Last update Thu Oct 22 18:15:10 2015 Florent Baris
*/

int	char_isnum(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  return (0);
}

int	char_isop(char c)
{
  if (c == '*' || c == '/' || c == '%' || c == '-' || c == '+'
 || c == '\0' || c == '(' || c == ')')
    return (1);
  return (0);
}

int	number(char **str)
{
  int	res;
  while (!char_isnum(**str))
    (*str)++;
  res = my_getnbr(*str);
  printf("tmp : %d\n", res);
  while (!char_isop(**str))
      (*str)++;
  return (res);
}
