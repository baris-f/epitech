/*
** my_getnbr.c for my_getnbr in /home/baris_f/rendu/Piscine_C_J04
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Thu Oct  1 10:43:04 2015 Florent Baris
** Last update Sun Oct 11 11:01:17 2015 Florent Baris
*/

int	plus_number(char *str)
{
  int	i;
  int	nb_plus;
  int	c;

  c = 0;
  i = 0;
  nb_plus = 0;
  while (str[i])
    {
      if (str[i] >= '0' && str[i] <= '9')
	c = 1;
      if ((str[i] == '-' || str[i] == '+') && c == 1)
	return (nb_plus);
      if (str[i] == '+')
	  nb_plus++;
      i++;
    }
  return (nb_plus);
}

int	minus_number(char *str)
{
  int	i;
  int	nb_minus;
  int	c;

  c = 0;
  i = 0;
  nb_minus = 0;
  while (str[i])
    {
      if (str[i] >= '0'&& str[i] <= '9')
        c = 1;
      if ((str[i] == '-' || str[i] == '+') && c == 1)
	return (nb_minus);
      if (str[i] == '-')
	  nb_minus++;
      i++;
    }
  return (nb_minus);
}

int	check_alpha(char *str, int decal)
{
  while (str[decal])
    {
      if (!(str[decal] >= '0' && str[decal]  <= '9'))
	  return (decal);
      if (str[decal] == '-' || str[decal] == '+')
	  return (decal);
      decal++;
    }
  return (decal);
}

int		calc_display(char *str, int begin, int end, int i)
{
  int		result;
  int		current_unit;
  double	born;

  current_unit = 1;
  result = 0;
  if (end == -1)
    i = my_strlen(str);
  else
    i = end;
  while (i > begin)
    {
      i--;
      if (current_unit == 1000000000)
	born = ((str[i] - '0') * 100000000);
      if (current_unit == 1000000000)
	born = born * 10 + result;
      if (born == 2147483648 && (minus_number(str) % 2) == 0)
        return (0);
      if (born > 2147483648)
	return (0);
      result += (str[i] - '0') * current_unit;
      current_unit *= 10;
    }
  return (result);
}

int	my_getnbr(char *str)
{
  int	result;
  int	end;
  int	begin;
  int	plus;
  int	minus;
  int	i;

  minus = minus_number(str);
  plus = plus_number(str);
  begin = plus + minus;
  end = check_alpha(str, begin);
  if ((end - begin) > 10)
    return (0);
  result = calc_display(str, begin, end, i);
  if ((minus_number(str) % 2) > 0)
    result *= -1;
  return (result);
}
