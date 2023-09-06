/*
** sapin.c for sapin in /home/baris_f/rendu/Piscine_C_Sapin
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Fri Oct  2 18:03:14 2015 Florent Baris
** Last update Wed Nov 25 18:58:18 2015 Florent Baris
*/

int	my_tronc(int taille)
{
  int	nb_espace;
  int	width;
  int	i;
  int	j;

  i = 0;
  width = taille;
  if (taille % 2 == 0)
    width += 1;
  nb_espace = (my_last_row_size(taille) - 1) / 2 - width / 2;
  while (i < taille)
    {
      j = 0;
      while (j < nb_espace)
	{
	  my_putchar(' ');
	  j++;
	}
      j = 0;
      while (j < width)
	{
	  my_putchar('|');
	  j++;
	}
      my_putchar('\n');
      i++;
    }
}

int	my_display(int nb_rows, int nb_espace, int nb_star, int cur_lin)
{
  int	i;
  int	cur_espace;

  cur_espace = nb_espace;
  i = 0;
  while (nb_espace > 0)
    {
      my_putchar(' ');
      nb_espace--;
    }
  while (i < nb_star)
    {
      my_putchar('*');
      i++;
    }
  if (nb_star < my_last_row_size(nb_rows - 3))
    nb_star += 2;
  my_putchar('\n');
  if (cur_lin < nb_rows)
    my_display(nb_rows, cur_espace - 1, nb_star, cur_lin + 1);
}

int	my_last_row_size(int taille)
{
  int	i;
  int	yn;
  int	dn;
  int	minus_dn;

  minus_dn = 0;
  dn = 1;
  yn = 3 * 2;
  i = 0;
  while (i < taille)
    {
      dn = dn - minus_dn;
      if (i > 0)
	yn = yn + (i + 3) * 2;
      if (i % 2 == 0)
	minus_dn += 2;
      i++;
    }
  return (yn + dn);
}

void	sapin(int taille)
{
  int   last_row_size;
  int   nb_espace;
  int   nb_rows;
  int	nb_star;
  int	cur_lin;
  int	cur_tri;
  int	minus_nb_esp;

  minus_nb_esp = 2;
  cur_lin = 1;
  cur_tri = 1;
  nb_rows = 4;
  last_row_size = my_last_row_size(taille);
  nb_espace = (last_row_size - 1) / 2;
  while (cur_tri <= taille)
    {
      nb_star = my_last_row_size(cur_tri) - (nb_rows - 1) * 2;
      my_display(nb_rows, nb_espace, nb_star, cur_lin);
      cur_tri++;
      nb_rows++;
      if (cur_tri % 2 == 1)
	minus_nb_esp++;
      nb_espace -= minus_nb_esp;
    }
  my_tronc(taille);
}

int	main(int ac, char **av)
{
  sapin(my_getnbr(av[1]));
}
