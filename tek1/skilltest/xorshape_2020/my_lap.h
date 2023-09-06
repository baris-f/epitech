#ifndef MY_LAP_H_
# define MY_LAP_H_

typedef struct s_pass
{
  t_bunny_window        *win;
  t_bunny_pixelarray    *img;
  t_bunny_position      *imgpos;
}               t_pass;

typedef struct
s_bunny_shape
{
  int x;
  int y;
  float  radius;
  unsigned int  border_color;
  unsigned int fill_color;
} t_bunny_shape;

t_bunny_response	update(void*);

#endif /* !MY_LAP_H_ */
