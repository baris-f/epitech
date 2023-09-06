#ifndef PLAT_H_
# define PLAT_H_

#include "tool.h"

t_img           *prs_load(char *name, t_base *pass);
void            tofile(t_img *bmp, char *name);
void		palbar(t_base *pass, t_menu menu);
void	    draw_box(t_img *img, t_2D *pos, t_col col, int full);
void		draw_boxinmap(t_base *pass, t_2D *lpos, t_col col, int full, t_img *tmp);
void            circleinmap(t_base *pass, t_2D *lpos, t_img *map, t_col col);
void		tekcircle(t_img *img, t_2D pos, int R, t_col col);
void		toolbar(t_base *pass, t_menu menu);
void            lineinmap(t_base *pass, t_2D *pos, t_img *map, t_col col);
void            addinmap(t_base *pass, t_2D pos, t_img *map, t_col col);
void            fillmap(t_base *pass, t_img *map);
void            mblit(t_img *dest, t_img *src, t_col alpha);
t_bunny_response        mouse_move(const t_bunny_position          *relative,
				   void                            *your_data);
t_bunny_response        mouse(t_bunny_event_state              state,
                              t_bunny_mousebutton               button,
			      void                             *your_data);
void    grid_square(t_base *pass, t_img *tmp);
void    grid(t_base *pass);
void	my_printf(char *str, ...);
int	my_getnbr(char *str);
void	tekpixel(t_bunny_pixelarray *img, t_bunny_position pos,
				 unsigned int col);
void    polcar(t_bunny_position *out, int ang, int len);
void    carpol(t_bunny_position pos, float *ang, float *len);
void                    proj(t_base *pass);
void                    tekfill(t_bunny_pixelarray *img, unsigned int col);
int	wolfini(t_base *pass);
char	*my_strdup(char*);
void                    tektabline(t_bunny_pixelarray *img, t_bunny_position *tab,
				   unsigned int col, int n);

void                    tekline(t_bunny_pixelarray *img, t_bunny_position *tab,
				unsigned int col);
int     whereami(t_base *pass, int side);
void                    tekfillhalf(t_bunny_pixelarray *img,
				    unsigned int col, int side);
void    raycast(t_base *pass);
void    map(t_base *pass);
#endif /* !PLAT_H_ */
