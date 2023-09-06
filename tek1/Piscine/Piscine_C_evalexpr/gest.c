/*
** gest.c for evalexpr in /home/thirio_b/rendu/Piscine_C_evalexpr
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Tue Oct 20 10:50:04 2015 Gaspard Thirion
** Last update Thu Oct 22 18:14:09 2015 Florent Baris
*/

int     factors(char **str)
{
  int   tmp;

  tmp = number(str);
  while (**str == '*' || **str == '/' || **str == '%')
    {
      if (**str == '*')
	if ((*str + 1)[0] == '(')
	  tmp *= summands(str);
	else
	  tmp *= number(str);
      else if (**str == '/')
	if ((*str + 1)[0] == '(')
	  tmp /= summands(str);
	else
	  tmp /= number(str);
      else if (**str == '%')
	if ((*str + 1)[0] == '(')
	  tmp %= summands(str);
	else
	  tmp %= number(str);
      else
        number(str);
    }
  return (tmp);
}

int	summands(char **str)
{
  int	tmp;

  tmp = factors(str);
  while (**str != '\0')
    if (**str == '+')
      if ((*str + 1)[0] == '(')
	{
	  printf("caca");
	  tmp += summands(str);
	  while ((*str)[0] != ')')
	    (*str)++;
	  printf("truc : %s\n", str);
	}
      else
	tmp += factors(str);
    else if (**str == '-')
      if ((*str + 1)[0] == '(')
	{
	  tmp -= summands(str);
	  (*str)++;
	}
      else
	tmp -= factors(str);
    else if (**str == ')')
      {
	(*str)++;
	while (!char_isop(**str))
	  (*str)++;
	return (tmp);
      }
    else
      number(str);
  return (tmp);
}

int	eval_expr(char *str)
{
  char	**pstr;

  pstr = &str;
  if (str[0] == '\0')
    return (0);
  return (summands(pstr));
}

int main(int ac, char **av)
{
  if (ac > 1)
    {
      my_put_nbr(eval_expr(av[1]));
      my_putchar('\n');
    }
  return (0);
}
