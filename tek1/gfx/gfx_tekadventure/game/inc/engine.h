/*
1;2802;0c** engine.h for spfji in /home/fus/tmp/fusgine
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Tue Mar 15 22:03:25 2016 Gaspard Thirion
** Last update Fri Apr 22 09:52:24 2016 Florent Baris
*/

#ifndef ENGINE_H_
# define ENGINE_H_

#include "util.h"

#define NB_BUT 20
typedef struct  s_path
{
  int		idx;
  float		dist;
}		t_path;

typedef struct  s_node
{
  char		*name;
  int		nb_link;
  t_sprite	*sprite;
  t_2D          pos;
  t_2D		scale;
  int		depth;
  int		type;
  int		full;
  int		*link;
}               t_node;

typedef	struct	s_map
{
char		*name;
  t_2D		pos;
  int		type;
  int		ln;
  int		nb_node;
  t_sprite	*back;
  t_node	*node;
}		t_map;

typedef struct  s_fight
{
  t_img         *img;
  t_img         *lb;
  t_sprite	*sky;
  t_sprite	*back;
  t_sprite	*bush;
  t_sprite	*idle;
  t_sprite	*atk;
  t_2D          size;
  t_2D          pos;
  int           life;
  int           dmg;
  int           lvl;
  int           turn;
  int           affdmg;
  int           end;
  int           blit;
  int		sens;
  int		init;
  int		tend;
}               t_fight;

typedef struct  s_player
{
  t_img         *img;
  t_sprite	*idle;
  t_sprite	*walk;
  t_sprite	*atk;
  t_2D          size;
  t_2D		scale;
  t_2D          pos;
  int		a;
  int           life;
  int           dmg;
  int           lvl;
  int           spe;
  int           pot;
  int           nod;
  int           mov;
  int           tocent;
  int		pnod;
  int		sens;
}               t_player;

typedef struct  s_button
{
  t_2D          pos[2];
  char          *text;
}               t_button;

typedef struct  s_gui
{
  t_2D          pos[2];
  t_2D          scale;
  t_button      but[NB_BUT];
  t_col         in;
  t_col         out;
  int           butt;
  t_2D		scroll[2];
  t_2D		ssize;
}               t_gui;

typedef struct	s_main
{
  t_win		*mwin;
  t_img		*mimg;
  t_2D		mpos;
  t_2D		s;
  t_2D		sh;
  t_2D		mouse[2];
  int		i;
  t_bunny_music	*mu;

  float		clock;
  t_key		keys[2];
  int		*path;

  int		nb_text;
  int		nb_font;
  int		nb_anim;
  int		nb_map;

  t_player	player;
  t_fight	fight;
  t_gui		gui;
  t_text	*text;
  t_font	*font;
  t_sprite	*anim;
  t_map		*map;
}		t_main;

/*
**T_RESPS
*/
t_resp	update(void*);
t_resp	keyboard(t_state, t_key, void*);
t_resp	click(t_state, t_click, void*);

/*
**LOADING
*/
int	loadproj(t_main*, char*);
int	anim(t_main*, t_ini*);
int	font(t_main*, t_ini*);
int	map(t_main*, t_ini*);

/*
**DRAWS
*/
void	draw(t_main*, t_sprite*, int, int);

/*
**UTILS
*/
void	mpixel(t_img*, t_2D, t_col);
void	fill(t_img*, t_col);
void	blit(t_img*, t_img*, t_2D);
void	invblit(t_img*, t_img*, t_2D);
void	printl(t_img*, t_font*, t_2D, char*, ...);

/*
**OTHER
*/
int     nmatch(char*, char*);
int     powere(int, int);
char    *nts(int);

/*
**GET/FIND
*/
t_img	*find_text(t_main*, char*);
t_col	get_col(t_scope*, char*, t_ini*, int);

void    init_fight(t_main *_m);
void    draw_life(t_main *_m);
int    draw_fight(t_main *_m);
void    draw_gui(t_main *_m);
t_2D    set2D(t_2D src, int difx, int dify, int create);
void                    tektabline(t_bunny_pixelarray *img, t_bunny_position *tab,
				   unsigned int col, int n);
void    line(t_img *img, t_2D start, t_2D stop, t_col col);
void    draw_box(t_img *img, t_2D *pos, t_col col, int full);
void            invblit(t_img *dest, t_img *src, t_2D start);
void            blit(t_img *dest, t_img *src, t_2D start);
void    aff_dmg(t_main *_m, int dmgg, int playerr);
void    setgui(t_main *_m);
void            printl(t_img *img, t_font *font, t_2D pos,
		       char *patt, ...);
void    draw_guys(t_main *_m);
t_img   *find_text(t_main *_m, char *id);
t_col    get_col(t_scope *scope, char *field, t_ini *ini, int k);
int     inbut(t_main *_m, t_2D pos);
int     managebut(t_main *_m, int but);
t_bunny_response        mouse(t_bunny_event_state               state,
			      t_bunny_mousebutton               button,
			      void                              *your_data);
t_bunny_response        mouse_move(const t_bunny_position *relative,
				 void *your_data);
int             path(t_main *_m, int start, int targ);
int     movout(t_main *_m);
int     movin(t_main *_m, t_2D pos);
void     move(t_main *_m);
void    draw_player(t_main *_m);
void    draw_nodes(t_main *_m);
void    draw_lines(t_main *_m);
int     innode(t_main *_m, t_2D pos);
int     inmap(t_main *_m, t_2D pos);
t_sprite        *new_sprite(t_main *_m, char *id);
void    paralax(t_main *_m);
void    affscroll(t_main *_m);
int     inscroll(t_main *_m);
t_sprite        *find_anim(t_main *_m, char *id);
#endif /* !ENGINE_H_ */
