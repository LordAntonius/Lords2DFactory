#include "errors.h"
#include <stdio.h>
#include <stdlib.h>

#include "graphics.h"

int main(int argc, char** argv)
{
	printf("%d", n);

	graphic_handle_t *pGraphic_handle;
	int ret;
	SDL_Event event;
	int quit = 0;

	UNUSED(argc);
	UNUSED(argv);


	ret = init_graphic(&pGraphic_handle);
	if(ret)
		return ret;


	while(!quit) {
		while (SDL_PollEvent(&event)) {
			switch(event.type) {
				case SDL_QUIT:
					quit=1;
					break;
				default :
					break;
			}
		}
		SDL_Delay(100);
    }

	destroy_graphic(pGraphic_handle);

    return SUCCESS;
}
