/*
** my_show_wordtab.c for my_show_wordtab in /home/baris_f/rendu/Piscine_C_J08/ex_03
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Wed Oct  7 12:28:18 2015 Florent Baris
** Last update Wed Oct  7 21:47:03 2015 Florent Baris
*/

int	my_show_wordtab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      i++;
    }
}

int main()
{
  char *my_array[] =
    {
      "The",
      "Answer",
      "to",
      "the",
      "Great",
      "Question...",
      "Of",
      "Life,",
      "the",
      "Universe",
      "and",
      "Everything...",
      "Is...",
      "Forty-two,",
      "said",
      "Deep",
      "Thought",
    };
  my_show_wordtab(my_array);
}
