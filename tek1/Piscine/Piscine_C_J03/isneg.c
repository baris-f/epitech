void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	main()
{
  char	c;

  c = 'a';
  if (c >= 97 && c <= 122)
    my_putchar('a');
  else if (c > 48 && c <=57)
    my_putchar('0');
  else
    my_putchar('?');
  return (0);
}
