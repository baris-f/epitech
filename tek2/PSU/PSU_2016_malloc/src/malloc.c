#include <stdio.h>
#include "my_malloc.h"

void*	malloc(size_t size)
{
  t_mem *tmp;
  t_mem *mem;

  if ((mem = sbrk(sizeof(t_mem))) == (void*)-1)
    return (NULL);
  mem->sob = size;
  mem->isFree = 0;
  mem->next = NULL;
  tmp = first;
  if (first == NULL)
    first = mem;
  else
    {
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = mem;
    }
  if ((mem->adr = sbrk(size)) == (void*)-1)
    return NULL;
  return (mem->adr);
}

void	show_alloc_mem()
{
   t_mem *tmp;

   if (!first)
     return ;
   tmp = first;
   while (tmp->next)
     tmp = tmp->next;
   printf("break : %p\n", sbrk(0));
   tmp = first;
   while (tmp)
     {
       if (tmp->isFree == 0)
       printf("%p - %p : %lu bytes\n", tmp, tmp + sizeof(t_mem)+ tmp->sob, tmp->sob);
       tmp = tmp->next;
     }
}


void    free(void *ptr)
{
 t_mem *tmp;
 int    i;

 if (!first)
   return ;
 tmp = first;
 i = 0;
 while (tmp)
   {
     if (tmp->adr == ptr)
       {
         if (tmp->next == NULL)
           {
             brk(tmp);
             tmp = first;
             while (0 < --i)
               tmp = tmp->next;
             tmp->next = NULL;
           }
         else
           tmp->isFree = 1;
       }
     tmp = tmp->next;
     i++;
   }
}

void*   calloc(size_t nmemb, size_t size)
{
  void  *tmp;

  if (nmemb == 0 || size == 0)
    return (NULL);
  tmp = malloc(nmemb * size);
  memset(tmp, '\0', nmemb * size);
  return (tmp);
}

void*   realloc(void *ptr, size_t size)
{
  t_mem *tmp;
  void  *ret;

  if (ptr == NULL)
    return (malloc(size));
  else if (size == 0)
    {
      free(ptr);
      return (NULL);
    }
  tmp = first;
  while (tmp)
    {
      if (tmp->adr == ptr)
        {
	  if (tmp->sob > size)
	    return (NULL);
          ret = malloc(size);
          memcpy(ret, tmp->adr, tmp->sob);
          free(tmp->adr);
          tmp = NULL;
          return (ret);
        }
      tmp = tmp->next;
    }
  return (NULL);
}
