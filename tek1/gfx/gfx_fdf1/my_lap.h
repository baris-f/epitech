#ifndef MY_LAP_H_
# define MY_LAP_H_

typedef struct s_pass
{
  t_bunny_window        *win;
  t_bunny_pixelarray    *img;
  t_bunny_position      *imgpos;
}               t_pass;

 typedef struct s_line
 {
   int                   dx;
   int                   dy;
   int                   xinc;
   int                   yinc;

 }               t_line;

int	main(int ac, char **av);
t_bunny_response	update(void*);

void            tekpixel(t_bunny_pixelarray *pix,
                         t_bunny_position *pos,
                         unsigned int color);
void                    tekline(t_bunny_pixelarray *pix,
                                t_bunny_position *pos,
                                unsigned int color);
int                     my_abs(int num);
void    my_fill(t_bunny_pixelarray *pix, unsigned int color);
void    tekllproject(t_bunny_position *out,
		     int x,
		     int y,
		     int z);
void    grid(t_pass  *pass, t_bunny_ini *ini, unsigned int color);

#endif /* !MY_LAP_H_ */
