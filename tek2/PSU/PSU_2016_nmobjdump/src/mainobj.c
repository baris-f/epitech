/*
** mainnm.c for nm in /home/baris_f/rendu/tek2/PSU_2016_nmobjdump
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Mon Feb 20 13:55:54 2017 baris_f
** Last update Sun Feb 26 22:57:09 2017 baris_f
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <elf.h>

int	checkMagic(Elf64_Ehdr *hdr) {
  if (!hdr)
    return -1;
  if ((hdr->e_ident[EI_MAG0] != ELFMAG0) ||
	   (hdr->e_ident[EI_MAG1] != ELFMAG1) ||
	   (hdr->e_ident[EI_MAG2] != ELFMAG2) ||
	   (hdr->e_ident[EI_MAG3] != ELFMAG3))
    {
      printf("Incorrect magic number.\n");
      return -1;
    }
  return 0;
}

int	affContent(FILE *fp, Elf64_Ehdr *hdr, char *fn);

int	readfile(char *fn)
{
  Elf64_Ehdr	*hdr;
  FILE		*fp;
  int		size;

  if ((fp = fopen(fn, "rb")) == NULL)
  {
    printf("my_nm: '%s': No such file\n", fn);
    return (-1);
  }
  if ((size = fseek(fp, 0, SEEK_END)) == -1){
    printf("my_nm: '%s' error fseek\n", fn);
    return -1;
  }
  size = ftell(fp);
  if ((hdr = malloc(size)) == NULL)
    return -1;
  rewind(fp);
  fread(hdr, size, 1, fp);
  if (checkMagic(hdr) == -1)
    return (-1);
  if (affContent(fp, hdr, fn) == -1)
    return (-1);
  free(hdr);
  return (0);
}

int	main(int ac, char **av)
{
  int		i = 0;

  if (ac == 1)
    {
      if (readfile("a.out") == -1)
	return (-1);
    }
  else
    while (++i < ac)
      {
	readfile(av[i]);
      }
  return 0;
}
