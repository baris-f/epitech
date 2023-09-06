void     my_putchar(char c)
{
  write(1, &c, 1);
}

int	affalpha()
{
  int a;

  a = 97;
  while (a <=122)
    {
      my_putchar(a);
	a++;
    }
  return (0);
}

int     main()
{
  affalpha();
}
