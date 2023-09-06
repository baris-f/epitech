/*
1;2802;0c** engine.h for spfji in /home/fus/tmp/fusgine
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Tue Mar 15 22:03:25 2016 Gaspard Thirion
** Last update Thu Apr 21 12:31:29 2016 Gaspard Thirion
*/

#ifndef ENGINE_H_
# define ENGINE_H_

#include "util.h"

#define	CONF_FILE	"configuration.ini"
#define	NAME		"baslap"

#define WIN_W		1600
#define WIN_H		900
#define WIN_WH		WIN_W / 2
#define WIN_HH		WIN_H / 2

#define NB_NODE		99
#define SIZE_NODE	14
#define SIZE_NODEH	SIZE_NODE / 2

#define NB_BUT		20

#define ABS(v)          ((v < 0) ? (-1 * v) : (v))
#define MIN(a, b)       (a < b) ? (a) : (b)
#define MAX(a, b)       (a < b) ? (b) : (a)
#define NBOOL(a)	(a == 0) ? (1) : (0)
#define get_field       (char*)bunny_ini_get_field
#define set		bunny_ini_set_field


typedef struct	s_button
{
  t_2D		pos[2];
  char		*text;
}		t_button;

typedef struct	s_node
{
  int		act_text;
  int		nb_link;
  t_2D		pos;
  t_2D		scale;
  int		link[NB_NODE];
  int		type;
  int		depth;
  int		full;
}		t_node;

typedef	struct	s_map
{
  char		*name;
  t_sprite	*img;
  t_2D		pos;
  t_node	node[NB_NODE];
  t_2D		curlin;
  int		mov;
  int		nb_node;
}		t_map;

typedef struct  s_gui
{
  t_2D          pos[2];
  t_2D		scale;
  t_button	but[NB_BUT];
  t_col		in;
  t_col		out;
  int		butt;
}               t_gui;


typedef struct	s_main
{
  t_win		*mwin;
  t_img		*mimg;
  t_map		map;
  t_gui		gui;
  t_2D		mpos;
  t_2D		mouse[3];

  float         clock;
  t_key         keys[3];

  int           nb_text;
  int           nb_font;
  int           nb_anim;
  int		nb_map;
  t_text        *text;
  t_font        *font;
  t_sprite      *anim;
  /* t_map		*map; */
}		t_main;

int	nmatch(char *s1, char *s2);
void            draw(t_main *_m, t_sprite *sprite);
t_resp	clean(t_main *_main);
t_resp	update(void *_v);
t_resp  keyboard(t_state state, t_key key, void *_v);
void            blit(t_img *dest, t_img *src, t_2D start);
void            invblit(t_img *dest, t_img *src, t_2D start);
void	mpixel(t_img *img, t_2D pos, t_col col);
void            printl(t_img *img, t_font *font, t_2D pos, char *patt, ...);
void	fill(t_img *img, t_col col);

t_bunny_response        mouse_move(const t_bunny_position *relative,
				   void *your_data);
t_bunny_response        mouse(t_bunny_event_state               state,
			      t_bunny_mousebutton               button,
			      void                              *your_data);
void                    tekpixel(t_bunny_pixelarray *img, t_bunny_position pos,
				 unsigned int col);
void                    tekline(t_bunny_pixelarray *img, t_bunny_position *tab,
				unsigned int col);
void                    tektabline(t_bunny_pixelarray *img, t_bunny_position *tab,
				   unsigned int col, int n);
void    draw_box(t_img *img, t_2D *pos, t_col col, int full);
t_resp          update(void *_v);
void    draw_nodes(t_main *_m);
void    draw_lines(t_main *_m);
int     inmap(t_main *_m, t_2D pos);
int     innode(t_main *_m, t_2D pos);
t_2D    tomap(t_main *_m, t_2D pos, int decal);
void    addlink(t_main *_m, int node, int tolink);
int     managebut(t_main *_m, int but);
t_sprite        *new_sprite(t_main *_m, char *id);
void    delete_node(t_main *_m, int nod);
int     inbut(t_main *_m, t_2D pos);
void    draw_gui(t_main *_m);
void    setgui(t_main *_m);
int             loadproj(t_main *_m, char *path);
char    *nts(int c);
int             anim(t_main *_m, t_ini *proj);
int             font(t_main *_m, t_ini *proj);
t_col    get_col(t_scope *scope, char *field, t_ini *ini, int k);
t_img   *find_text(t_main *_m, char *id);
int	find_i_text(t_main *_m, char *id);
int     powere(int nb, int power);

int             export(t_main *_m, char *path);
int             gmap(t_main *_m, t_map *map, char *file);
#endif /* !ENGINE_H_ */
