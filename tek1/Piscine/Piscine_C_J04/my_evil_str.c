/*
** my_evil_str.c for my_evil_str in /home/baris_f/rendu/Piscine_C_J04
** 
** Made by Florent Baris
** Login   <baris_f@epitech.net>
** 
** Started on  Thu Oct  1 19:13:36 2015 Florent Baris
** Last update Fri Oct  2 18:15:49 2015 Florent Baris
*/

char    *my_evil_str(char *str)
{
  int   displayss;
  int   count;
  char  c;

  displayss = 0;
  count = 0;
  while (str[count] != '\0')
    count++;
  count--;
  while (displayss <= count)
    {
      c = str[displayss];
      str[displayss] = str[count];
      str[count] = c;
      displayss++;
      count--;
    }
  return (str);
}
