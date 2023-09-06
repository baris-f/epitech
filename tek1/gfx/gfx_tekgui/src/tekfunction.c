/*
** tekfunction.c for tekfunction in /home/baris-f/rendu/gfx/gfx_tekgui
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sun Feb 28 18:13:54 2016 Florent Baris
** Last update Sun Feb 28 23:25:10 2016 Florent Baris
*/

#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include "tool.h"

void		errfunc()
{
  my_printf("bad function\n");
}

void		*tekfunction(const char *funcname)
{
  void		*plugin;
  void		*test;

  test = 0;
  plugin = dlopen(NULL, RTLD_LAZY);
  if (!plugin)
    {
      my_printf("dlopen failed\n");
      return (test);
    }
  test = (void*)dlsym(plugin, funcname);
  if (!test)
    {
      my_printf("dlsym failed\n");
      return (test);
    }
  return (test);
}
