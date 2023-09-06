#ifndef MY_MALLOC_H_
# define MY_MALLOC_H_

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void*	malloc(size_t size);
void    show_alloc_mem();
void*   realloc(void *ptr, size_t size);
void*	calloc(size_t nmemb, size_t size);
void	free(void *ptr);

typedef struct s_mem {
  size_t	sob;
  void*	adr;
  unsigned char isFree;
  struct s_mem *next;
}		t_mem;

static t_mem *first = NULL;

#endif /* !MY_MALLOC_H_ */
