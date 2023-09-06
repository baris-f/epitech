#ifndef PLAT_H_
# define PLAT_H_

#include "igraph.h"

#define FOV	66
#define FOVHALF	FOV / 2
#define FOVANG	FOV / 1500

void    mort(t_pass *pass, t_pos *pos, int side, float size);
void    triangle(t_pass *pass, t_pos *pos, int side, float size);
void	my_printf(char *str, ...);
int	my_getnbr(const char *str);
void	tekpixel(t_bunny_pixelarray *img, t_bunny_position *pos,
				 unsigned int col);
void    polcar(t_bunny_position *out, int ang, int len);
void    carpol(t_bunny_position pos, float *ang, float *len);
void                    proj(t_pass *pass);
void                    tekfill(t_bunny_pixelarray *img, unsigned int col);
int	wolfini(t_pass *pass);
char	*my_strdup(char*);
void                    tektabline(t_bunny_pixelarray *img, t_bunny_position *tab,
				   unsigned int col, int n);

void                    tekline(t_bunny_pixelarray *img, t_bunny_position *tab,
				unsigned int col);
int     whereami(t_pass *pass, int side);
void                    tekfillhalf(t_bunny_pixelarray *img,
				    unsigned int col, int side);
void    raycast(t_pass *pass);
void    map(t_pass *pass);
#endif /* !PLAT_H_ */
