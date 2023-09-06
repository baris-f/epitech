/*
** corewar.h for SDL in /home/shiroi-shi/rendu/corewar/CPE_2015_corewar/SDL/inc
**
** Made by Aurélien Toussaint
** Login   <toussa_a@epitech.net>
**
** Started on  Wed Mar 16 15:05:35 2016 Shiroi-shi
** Last update Mar 27 15:58:14 2016 Aurélien Toussaint
*/

#define	WIN_WIDTH		1300
#define	WIN_HEIGHT		850
#define ROYAL_BLUE(screen)	SDL_MapRGB(screen->format, 58, 70, 205)
#define BLACK(screen)		SDL_MapRGB(screen->format, 0, 0, 0)
#define TXT_BLACK 		(SDL_Color){0,0,0}
#define TXT_RED 		(SDL_Color){150,0,0}


void	update(SDL_Surface*, TTF_Font*);
