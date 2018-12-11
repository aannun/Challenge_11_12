#define SDL_MAIN_HANDLED
#include <SDL.h>
#include "gfx.h"
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int ret = 0;

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO))
	{
		SDL_Log("unable to inizialize sdl: %s", SDL_GetError());
		ret = -1;
		goto cleanup;
	}

	SDL_Window *window = SDL_CreateWindow("tetris", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1024, 768, 0);
	if (!window)
	{
		SDL_Log("unable to create window: %s", SDL_GetError());
		ret = -1;
		goto cleanup2;
	}

	SDL_Renderer *renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!renderer)
	{
		SDL_Log("unable to create renderer: %s", SDL_GetError());
		ret = -1;
		goto cleanup3;
	}

    tile_t *tile = malloc(sizeof(tile_t));
    init_tile(tile, 10, 10);

    for (;;)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				goto cleanup4;
		}

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);

        tile_draw(tile, renderer, 10);

		SDL_RenderPresent(renderer);
	}

cleanup4:
	SDL_DestroyRenderer(renderer);
cleanup3:
	SDL_DestroyWindow(window);
cleanup2:
	SDL_Quit();
cleanup:
	return ret;
}
