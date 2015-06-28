#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>

typedef struct {
	SDL_Window* pWindow;
	SDL_Renderer *pRenderer;
} graphic_handle_t;

int init_graphic(graphic_handle_t** ppGraphic_handle);
int destroy_graphic(graphic_handle_t* pGraphic_handle);

#endif
