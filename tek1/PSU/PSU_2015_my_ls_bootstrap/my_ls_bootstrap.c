/*
** main.c for ls in /home/grandma/PSU_2015_my_ls_bootstrap
**
** Made by Corentin Grandmaire
** Login   <grandm_a@epitech.net>
**
** Started on  Thu Nov 19 09:33:20 2015 Corentin Grandmaire
** Last update Sat Nov 28 16:16:05 2015 Florent Baris
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void		affname(char *str)
{
  int		i;

  my_putstr("Name: ");
  i = (my_strlen(str) - 1);
  while (str[--i] != '/' && str[i]);
  while (str[++i] != '/' && str[i])
    my_putchar(str[i]);
  my_putstr("\n");
}

void		typ(struct stat info)
{
  my_putstr("Type: ");
  if (S_ISREG(info.st_mode))
    my_putchar('f');
  else if (S_ISDIR(info.st_mode))
    my_putchar('d');
  else if (S_ISCHR(info.st_mode))
    my_putchar('s');
  else if (S_ISLNK(info.st_mode))
    my_putchar('l');
  else
    my_printf("Other");
  my_putstr("\n");
}

int		main(int ac, char **av)
{
  char		*read;
  struct stat	info;

  read = av[1];
  if (ac != 2)
    {
      my_printf("Usage: %s <pathname>\n", av[0]);
      return;
    }
  if (stat(read, &info) != - 1)
  {
    affname(read);
    typ(info);
    my_printf("Inode: %d\nHard Link: %d\nSize: %d\nAllocated space: %d\n protection : %o\n",
	      info.st_ino, info.st_nlink, info.st_size, info.st_blocks * 512, info.st_mode);
    if (S_ISLNK(info.st_mode) || S_ISCHR(info.st_mode))
      my_printf("Minor: %d\nMajor: %d\n", minor(info.st_rdev),
		major(info.st_rdev));
    else
      my_printf("Minor: N/A\nMajor: N/A\n");
    my_printf("UID: %d\nGID: %d\n", info.st_uid, info.st_gid);
  }
  else if (stat(read, &info) == - 1)
    my_printf("File not found\n");
}
