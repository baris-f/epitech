#ifndef DRAWING_H_
# define DRAWING_H_

#include <stdint.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

typedef struct	s_point
{
  unsigned int	x;
  unsigned int	y;
}		t_point;
void                    draw_square(uint32_t **img, t_point *orig, size_t size, uint32_t col);

#endif /* !DRAWING_H_ */
