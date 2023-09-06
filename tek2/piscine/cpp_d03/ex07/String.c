/*
** String.c for String in /home/baris_f/rendu/tek2/cpp_d03/ex00
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Fri Jan  6 09:06:48 2017 baris_f
** Last update Fri Jan  6 23:55:05 2017 baris_f
*/

#include "String.h"

static void    assign_c(String *this, char const *s);
static void    assign_s(String *this, String const *str);
static void    append_s(String *this, String const *ap);
static void    append_c(String *this, char const *aps);
static char    at(String *this, size_t pos);
static void    clear(String *this);
static int     size(String *this);
static int     compare_s(String *this, const String *str);
static int     compare_c(String *this, char const *str);
static size_t   copy(String *this, char *s, size_t n, size_t pos);
static char const       *c_str(String *this);
static int      empty(String *this);
static int      find_s(String* this, const String *str, size_t pos);
static int      find_c(String* this, char const *str, size_t pos);
static void     insert_c(String* this, size_t pos, char const *str);
static void     insert_s(String* this, size_t pos, const String *str);
static int      to_int(String* this);
static String   *split_s(String *this, char separator);
static char     **split_c(String *this, char separator);
static void	aff(String* this);

void	StringInit(String *this, char const *s)
{
  if (this == NULL || s == NULL)
    return ;
  this->str = strdup(s);
  this->StringDestroy = &StringDestroy;
  this->assign_s = &assign_s;
  this->assign_c = &assign_c;
  this->append_s = &append_s;
  this->append_c = &append_c;
  this->at = &at;
  this->clear = &clear;
  this->size = &size;
  this->compare_s = &compare_s;
  this->compare_c = &compare_c;
  this->copy = &copy;
  this->c_str = &c_str;
  this->empty = &empty;
  this->find_s = &find_s;
  this->find_c = &find_c;
  this->insert_s = &insert_s;
  this->insert_c = &insert_c;
  this->to_int = &to_int;
  this->split_s = &split_s;
  this->split_c = &split_c;
  this->aff = &aff;
}

void	StringDestroy(String *this)
{
  if (this->str)
    free(this->str);
  this->str = NULL;
}

 void	assign_s(String *this, String const *str)
{
  if (this == NULL || str == NULL || str->str == NULL)
    return;
  if (this->str)
    free(this->str);
  this->str = strdup(str->str);
}

 void	assign_c(String *this, char const *s)
{
  if (this == NULL || s == NULL)
    return ;
  if (this->str)
    free(this->str);
  this->str = strdup(s);
}

 void	append_s(String *this, String const *ap)
{
  if (!this || (!this && !ap))
    return;
  else if (!this->str)
    this->assign_s(this, ap);
  else if (!ap && this->str)
    return;
  else if (this->str && ap->str) {
    this->str = realloc(this->str, strlen(this->str)+strlen(ap->str)+1);
    if (this->str)
      strcat(this->str, ap->str);
  }
}

 void    append_c(String *this, char const *aps)
{
  char  *str;
  int   nb;

  if (this == NULL || aps == NULL)
    return ;
  nb = 0;
  if (this->str != NULL)
    nb += strlen(this->str);
  nb += strlen(aps);
  if ((str = malloc(nb + 1)) == NULL)
    return ;
  if (this->str == NULL)
    strcpy(str, aps);
  else
    {
      strcpy(str, this->str);
      strcat(str, aps);
      free(this->str);
    }
  this->str = str;
  return ;
}

 char    at(String *this, size_t pos){
  if (this == NULL || this->str == NULL || pos >= strlen(this->str))
    return (-1);
  return (this->str[pos]);
}

 void    clear(String *this)
{
  if (this == NULL || this->str == NULL)
    return ;
  memset(this->str, 0, this->size(this));
}

 int	size(String *this)
{
  if (this == NULL || this->str == NULL)
    return (-1);
  return (strlen(this->str));
}

 int     compare_s(String *this, const String *str)
{
  if (this == NULL || this->str == NULL || str == NULL || str->str == NULL)
    return (0);
  return (strcmp(this->str, str->str));
}

 int     compare_c(String *this, char const *str)
{
  if (this == NULL || this->str == NULL || str == NULL)
    return (0);
  return (strcmp(this->str, str));
}

 size_t	copy(String *this, char *s, size_t n, size_t pos)
{
  if (this == NULL || s == NULL || pos + n > (size_t)this->size(this))
    return (0);
  return (strlen(strncpy(s, this->str + pos, n)));
}

 char const       *c_str(String *this)
{
  if (this == NULL || this->str == NULL)
    return (NULL);
  return (this->str);
}

 int	empty(String *this)
{
  if (this == NULL || this->str == NULL)
    return (-1);
  if (this->str[0] == 0)
    return (1);
  return (-1);
}

 int      find_s(String* this, const String *str, size_t pos)
{
  char	*tmp;

  if (this == NULL || str == NULL || str->str == NULL || pos >= (size_t)this->size(this))
    return (-1);
  tmp = strstr(this->str + pos, str->str);
  if (tmp)
    return (tmp - this->str);
  return (-1);
}

 int      find_c(String* this, char const *str, size_t pos)
{
  char  *tmp;

  if (this == NULL || str == NULL || pos >= (size_t)this->size(this))
    return (-1);
  tmp = strstr(this->str + pos, str);
  if (tmp)
    return (tmp - this->str);
  return (-1);
}

 void     insert_c(String* this, size_t pos, char const *str)
{
  char *newstr;

  if (this == NULL || str == NULL)
    return ;
  if (this->str == NULL)
    assign_c(this, str);
  else if (pos > (size_t)this->size(this))
    append_c(this, str);
  else if ((newstr = malloc(sizeof(char) * (this->size(this) + strlen(str) + 1))) == NULL)
    return ;
  newstr[0] = '\0';
  strncat(newstr, this->str, pos);
  strcat(newstr, str);
  strcat(newstr, this->str + pos);
  free(this->str);
  this->str = newstr;
}

 void     insert_s(String* this, size_t pos, const String *str)
{
  char *newstr;

  if (this == NULL || str == NULL || str->str == NULL)
    return ;
  if (this->str == NULL)
    assign_c(this, str->str);
  else if (pos > (size_t)this->size(this))
    append_c(this, str->str);
  else if ((newstr = malloc(sizeof(char) * (this->size(this) + strlen(str->str) + 1))) == NULL)
    return ;
  newstr[0] = '\0';
  strncat(newstr, this->str, pos);
  strcat(newstr, str->str);
  strcat(newstr, this->str + pos);
  free(this->str);
  this->str = newstr;
}

 int      to_int(String* this)
{
  if (this == NULL || this->str == NULL)
    return (0);
  return (atoi(this->str));
}

 String   *split_s(String *this, char separator)
{
  String  *tab;
  char	*tmp;
  char	sep[2];
  int   i;

  if (this == NULL || this->str == NULL)
    return (NULL);
  i = 0;
  sep[0] = separator;
  sep[1] = '\0';
  if ((tab = malloc(sizeof(String *) * strlen(this->str))) == NULL)
    return (NULL);
  StringInit(&tab[0], strtok(this->str, sep));
  while ((tmp = strtok(NULL, sep)) != NULL)
    StringInit(&tab[++i], "salut");
  return (tab);
}

char     **split_c(String *this, char separator)
{
  char	**tab;
  char  sep[2];
  int	i;

  if (this == NULL || this->str == NULL)
    return (NULL);
  i = 0;
  sep[0] = separator;
  sep[1] = '\0';
  if ((tab = malloc(sizeof(char *) * strlen(this->str))) == NULL)
    return (NULL);
  tab[0] = strtok(this->str, sep);
  while ((tab[++i] = strtok(NULL, sep)) != NULL);
  return (tab);
}

void	aff(String *this)
{
  if (this == NULL || this->str == NULL)
    return ;
  write(1, this->str, strlen(this->str));
}
