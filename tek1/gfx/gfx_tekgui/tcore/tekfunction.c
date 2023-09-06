/*
** tekfunction.c for tekfunction in /home/baris-f/rendu/gfx/gfx_tekgui
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sun Feb 28 18:13:54 2016 Florent Baris
** Last update Sun Feb 28 22:45:27 2016 Florent Baris
*/

#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>

void		*tekfunction(const char *funcname)
{
  void		*plugin;
  void		*test;

  plugin = dlopen(NULL, RTLD_LAZY);
  if (!plugin)
    my_printf("dlopen failed\n");
  test = (void*)dlsym(plugin, funcname);
  if (!test)
    my_printf("dlsym failed\n");
  return (test);
}
