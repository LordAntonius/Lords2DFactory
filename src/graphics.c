#include "graphics.h"
#include "errors.h"

int init_graphic(graphic_handle_t** ppGraphic_handle) {
	int ret;
	*ppGraphic_handle = (graphic_handle_t*) malloc(sizeof(graphic_handle_t));
	if(!*ppGraphic_handle)
		return UNKNOWN_ERROR;
	(*ppGraphic_handle)->pWindow = NULL;
	
	if (SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stdout,"Echec de l'initialisation de la SDL (%s)\n",SDL_GetError());
		ret = SDL_ERROR;
		goto freeStruct;
    }

    /* Creation de la fenetre */
    (*ppGraphic_handle)->pWindow = 
		SDL_CreateWindow("Ma premiere application SDL2",SDL_WINDOWPOS_UNDEFINED,
                                                        SDL_WINDOWPOS_UNDEFINED,
                                                        640,
                                                        480,
                                                        SDL_WINDOW_SHOWN);
    if( !(*ppGraphic_handle)->pWindow ) {
    	fprintf(stderr,"Erreur de creation de la fenetre: %s\n",SDL_GetError());
		ret = SDL_ERROR;
		goto quit;
    }
 	
	(*ppGraphic_handle)->pRenderer = SDL_CreateRenderer((*ppGraphic_handle)->pWindow,-1,SDL_RENDERER_ACCELERATED);

	if(!((*ppGraphic_handle)->pRenderer)) {
    	fprintf(stderr,"Erreur de creation du render : %s\n",SDL_GetError());
		ret = SDL_ERROR;
		goto destroyWindow;
	}

	return SUCCESS;
	
destroyRenderer:
	SDL_DestroyRenderer((*ppGraphic_handle)->pRenderer);
destroyWindow:
	SDL_DestroyWindow((*ppGraphic_handle)->pWindow);
quit:
    SDL_Quit();
freeStruct:
	free(*ppGraphic_handle);

	return ret;
}

int destroy_graphic(graphic_handle_t* pGraphic_handle) {
	SDL_DestroyRenderer(pGraphic_handle->pRenderer);
	SDL_DestroyWindow(pGraphic_handle->pWindow);
    SDL_Quit();
	free(pGraphic_handle);
	return SUCCESS;
}
