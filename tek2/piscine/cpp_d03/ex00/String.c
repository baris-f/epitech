/*
** String.c for String in /home/baris_f/rendu/tek2/cpp_d03/ex00
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Fri Jan  6 09:06:48 2017 baris_f
** Last update Fri Jan  6 09:37:38 2017 baris_f
*/

#include "String.h"

void	StringInit(String *this, char const *s)
{
  this->str = strdup(s);
}

void	StringDestroy(String *this)
{
  if (this->str)
    free(this->str);
}
/*
int	main()
{
  String test;

  StringInit(&test, "enculé");
  printf("%s\n", test.str);
  StringDestroy(&test);
  printf("%s\n", test.str);
  return (0);
}
*/
