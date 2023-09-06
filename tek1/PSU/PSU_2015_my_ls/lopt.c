/*
** lopt.c for lopt in /home/baris-f/rendu/PSU_2015_my_ls
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sun Nov 29 15:11:58 2015 Florent Baris
** Last update Thu Dec  3 12:39:52 2015 Florent Baris
*/

 #include <time.h>
 #include <fcntl.h>
 #include <dirent.h>
 #include <stdlib.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <unistd.h>
 #include <sys/types.h>
 #include <pwd.h>
 #include "my_ls.h"

void            my_ls(char *path, int arg);
char    *my_strcat(char *dest, char *src);

void            recur(t_chaine *list, int arg, char *path)
{
  t_chaine      *tmp;
  struct stat   info;
  char	*tmpe;

  tmp = list;
  while (tmp != NULL)
    {
      stat(tmp->name, &info);
      if (S_ISDIR(info.st_mode))
	{
	  tmpe = malloc(sizeof(char) * my_strlen(path) + my_strlen(tmp->name) + 1);
	  my_strcat(tmpe, path);
	  my_strcat(tmpe, "/");
	  my_strcat(tmpe, tmp->name);
	  my_putchar('\n');
	  my_ls(tmpe, arg);
	  free(tmpe);
	}
      tmp = tmp->next;
    }
}

void            typ(struct stat info)
{
  if (S_ISREG(info.st_mode))
    my_putchar('-');
  else if (S_ISDIR(info.st_mode))
    my_putchar('d');
  else if (S_ISCHR(info.st_mode))
    my_putchar('c');
  else if (S_ISLNK(info.st_mode))
    my_putchar('l');
  else if (S_ISBLK(info.st_mode))
    my_putchar('b');
  else if (S_ISFIFO(info.st_mode))
    my_putchar('f');
  else
    my_putchar('p');
  (S_IRUSR & info.st_mode) ? my_putchar('r') : my_putchar('-');
  (S_IWUSR & info.st_mode) ? my_putchar('w') : my_putchar('-');
  (S_IXUSR & info.st_mode) ? my_putchar('x') : my_putchar('-');
  (S_IRGRP & info.st_mode) ? my_putchar('r') : my_putchar('-');
  (S_IWGRP & info.st_mode) ? my_putchar('w') : my_putchar('-');
  (S_IXGRP & info.st_mode) ? my_putchar('x') : my_putchar('-');
  (S_IROTH & info.st_mode) ? my_putchar('r') : my_putchar('-');
  (S_IWOTH & info.st_mode) ? my_putchar('w') : my_putchar('-');
  (S_IXOTH & info.st_mode) ? my_putchar('x') : my_putchar('-');
}

void    ltime(char *time)
{
  int   i;

  i = 3;
  my_putchar((time[++i] + 32));
  while (isalph(time[++i]))
    my_putchar(time[i]);
  my_putstr(".  ");
    while (++i < 16)
      my_putchar(time[i]);
  my_putchar(' ');
}

void				lopt(char *path)
{
  char				*read;
  struct stat			info;
  register struct passwd	*pw;
  char				*time;

  read = path;
  if (stat(read, &info) != - 1)
    {
      typ(info);
      pw = getpwuid(info.st_uid);
      my_printf(" %d %s ", info.st_nlink, pw->pw_name);
      pw = getpwuid(info.st_gid);
      my_printf("%s %d ", pw->pw_name, info.st_size);
      time = my_strdup(ctime(&info.st_mtime));
      ltime(time);
    }
}
