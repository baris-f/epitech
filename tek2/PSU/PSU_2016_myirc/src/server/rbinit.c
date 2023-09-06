#include "common.h"

t_ring_buffer		*rb_init()
{
  t_ring_buffer		*buffer;

  if (!(buffer = malloc(sizeof(t_ring_buffer))))
    error("malloc");
  memset(buffer->rb, 0, RB_SIZE);
  buffer->rrb = buffer->rb;
  buffer->wrb = buffer->rb;
  buffer->available = RB_SIZE;
  return (buffer);
}

void			rb_free(t_ring_buffer *ring)
{
  if (ring)
    free(ring);
}

int			rb_available(t_ring_buffer *ring)
{
  return ((ring->wrb >= ring->rrb)
	  ? (RB_SIZE - (int)(ring->wrb - ring->rrb))
	  : (int)(ring->rrb - ring->wrb));
}

void			rb_write(t_ring_buffer *ring, char *str)
{
  int			i;

  ring->wrb = (ring->wrb) ? ring->wrb : ring->rb;
  for (i = 0; str[i]; i++)
    {
      *ring->wrb = str[i];
      ring->wrb = &ring->rb[(((size_t)ring->wrb + 1)
			     - (size_t)ring->rb) % RB_SIZE];
    }
}

char			*rb_read(t_ring_buffer *ring)
{
  char			*str;
  int			size;
  int			i;

  size = ((ring->wrb >= ring->rrb)
	  ? (int)(ring->wrb - ring->rrb)
	  : (RB_SIZE - (int)(ring->rrb - ring->wrb)));
  if (!(str = malloc(size + 1)))
    error("malloc");
  memset(str, 0, size + 1);
  for (i = 0; i < size; i++)
    {
      str[i] = *ring->rrb;
      ring->rrb = &ring->rb[(((size_t)ring->rrb + 1)
			     - (size_t)ring->rb) % RB_SIZE];
    }
  return (str);
}
