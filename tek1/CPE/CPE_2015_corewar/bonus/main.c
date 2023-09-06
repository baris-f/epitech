/*
** main.c for SDL in /home/shiroi-shi/rendu/corewar/CPE_2015_corewar/SDL
**
** Made by Aurélien Toussaint
** Login   <toussa_a@epitech.net>
**
** Started on  Wed Mar 16 14:10:55 2016 Shiroi-shi
** Last update Mar 27 19:46:57 2016 Aurélien Toussaint
*/
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "inc/corewar.h"

SDL_Surface		*print_grid(SDL_Surface *win)
{
  SDL_Surface	*grid;
  SDL_Rect	pos;
  SDL_Rect	pos2;
  int		i;

  pos.x = 5;
  pos.y = 5;
  i = -1;
  grid = SDL_LoadBMP("img/tiles.bmp");
  while (pos.x < 1005)
    {
      pos.y = 5;
      while (pos.y < 615)
	{
	  SDL_BlitSurface(grid, NULL, win, &pos);
	  pos.y += 10;
	}
      pos.x += 10;
    }
  return (grid);
}

SDL_Surface	*cursor(SDL_Surface *win, SDL_Event event)
{
  SDL_Surface	*curs;
  SDL_Rect	pos;
  curs = IMG_Load("img/aperture.cur");
  if (event.type == SDL_MOUSEMOTION)
  {
    pos.x = event.motion.x;
    pos.y = event.motion.y;
  }
  SDL_BlitSurface(curs, NULL, win, &pos);
  return (curs);
}

void	texte(SDL_Surface *win, TTF_Font *police)
{
  SDL_Surface	*txt;
  SDL_Rect	pos;

  pos.x = 1015;
  pos.y = 50;
  txt = TTF_RenderText_Blended(police, "Champions:", TXT_BLACK);
  SDL_BlitSurface(txt, NULL, win, &pos);
}
void		update(SDL_Surface *win, TTF_Font *police)
{
  SDL_Event	event;
  SDL_Surface	*curs;
  SDL_Surface	*grid;
  int		alive;

  alive = 1;

  while (alive)
    {
      SDL_WaitEvent(&event);
      if (event.type == SDL_QUIT)
	alive = 0;
      if (event.key.keysym.sym == SDLK_ESCAPE)
	  alive = 0;

      SDL_FillRect(win, NULL, ROYAL_BLUE(win));
      grid = print_grid(win);
      curs = cursor(win, event);
      texte(win, police);
      SDL_Flip(win);
    }
  SDL_FreeSurface(curs);
  SDL_FreeSurface(grid);
}

int	main(int ac, char **av)
{
  SDL_Surface	*win;
  TTF_Font	*police;
  Mix_Music	*musique;

  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) == -1)
    SDL_Quit();
  TTF_Init();
  SDL_WM_SetIcon(IMG_Load("img/epitech-logo.png"), NULL);
  if ((win = SDL_SetVideoMode(WIN_WIDTH, WIN_HEIGHT, 32,
			      SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
    return (-1);
  SDL_WM_SetCaption("Corewar", NULL);
  SDL_ShowCursor(SDL_DISABLE);
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) ==-1)
    return (-1);
  musique = Mix_LoadMUS("sounds/SNES_Guile.mp3");
  Mix_PlayMusic(musique, -1);
  police = TTF_OpenFont("fonts/Korean_Calligraphy.ttf", 64);
  update(win, police);
  Mix_FreeMusic(musique);
  Mix_CloseAudio();
  TTF_CloseFont(police);
  TTF_Quit();
  SDL_Quit();
  return (0);
}
