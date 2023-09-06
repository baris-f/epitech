/*
** affObj.c for affOBJ in /home/baris_f/rendu/tek2/PSU_2016_nmobjdump
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Sun Feb 26 21:55:43 2017 baris_f
** Last update Sun Feb 26 22:47:51 2017 baris_f
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <elf.h>

char     affByte(char c)
{
  if (c > 0)
    printf("%02x", c);
  else
    printf("00");
  if (isprint(c))
    return (c);
  else
    return ('.');
}

void     affSect(char *section, Elf64_Shdr *shdr)
{
  char          buf[16 + 1];
  size_t        s_off;
  size_t        i;
  size_t        j;

  s_off = 0;
  while (s_off < shdr->sh_size)
    {
      i = 0;
      printf(" %04x", (unsigned)(shdr->sh_addr + s_off));
      for (size_t k = 0; k < 16; k++)
	buf[k] = '\0';
      while (i < 16 && s_off + i < shdr->sh_size)
        {
          j = -1;
          printf(" ");
          while (++j < 4 && s_off + i + j < shdr->sh_size)
	    buf[i + j] = affByte(section[s_off + i + j]);
          i += j;
        }
      buf[16] = '\0';
      for (size_t k = 0; k < (16 - strlen(buf)) / 3; k++)
	printf("\t ");
      printf("  %s\n", buf);
      s_off += i;
    }
}

int     affContent(FILE *fp, Elf64_Ehdr *hdr, char *fn)
{
  Elf64_Shdr    *shdr;
  char          *strtab;

  if ((shdr = malloc(sizeof(Elf64_Shdr) * hdr->e_shnum)) == NULL)
    return (-1);
  fseek(fp, hdr->e_shoff, SEEK_SET);
  fread(shdr, sizeof(Elf64_Shdr), hdr->e_shnum, fp);
  if(hdr->e_shstrndx == SHN_UNDEF)
    return -1;
  strtab = malloc(sizeof(char) *  shdr[hdr->e_shstrndx].sh_size);
  strtab = (char *)((uint64_t)hdr + shdr[hdr->e_shstrndx].sh_offset);
  printf("%s:\t\tfile format elf64-x86-64\n", fn);
  printf("architecture: i386:x86-64, flags 0x00000150:\n");
  printf("HAS_SYMS, DYNAMIC, D_PAGED\n");
  printf("start address %#016x\n\n", (unsigned int)hdr->e_entry);
  for (int i = 0; i < hdr->e_shnum; i++)
    if (shdr[i].sh_size && shdr[i].sh_type != SHT_NOBITS
	&& shdr[i].sh_type != SHT_SYMTAB && i!= hdr->e_shstrndx
	&& strtab[shdr[i].sh_name] && i != hdr->e_shstrndx - 1)
      {
	printf("Contents of section %s:\n", &strtab[shdr[i].sh_name]);
	affSect((char*)((uint64_t)hdr + shdr[i].sh_offset), &shdr[i]);
      }
  return (0);
}
