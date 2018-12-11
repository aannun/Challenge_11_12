#define SDL_MAIN_HANDLED
#include <SDL.h>
#include "gfx.h"
#include <stdlib.h>
#include <math.h>

#define PI_2 (M_PI * 2)
#define CENTER_X 35
#define CENTER_Y 30

static void init_clock(tile_t *tiles, int length, int radius, int centerX, int centerY)
{
    float ang = 0;
    float inc = PI_2 / length;

    int i;
    for(i = 0; i < length; i++)
    {
        tiles[i].x = cos(ang) * radius + centerX;
        tiles[i].y = sin(ang) * radius + centerY;
        ang += inc;
    }
}

static void draw_clock(tile_t *tiles, int length, int size, SDL_Renderer *renderer)
{
    int i;
    for(i = 0; i < length; i++)
    {
        tile_draw(&tiles[i], renderer, size, 255, 0, 0);
    }
}

static void draw_lancet(tile_t *tiles, int length, int size, int radius, float ang, int posX, int posY, SDL_Renderer *renderer)
{
    float inc = radius / length;
    int i;
    for(i = 0; i < length; i++)
    {
        tiles[i].x = cos(ang) * (i * inc) + posX;
        tiles[i].y = sin(ang) * (i * inc) + posY;
        tile_draw(&tiles[i], renderer, size, 255, 255, 255);
    }
}

int main(int argc, char const *argv[])
{
    int ret = 0;

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO))
	{
		SDL_Log("unable to inizialize sdl: %s", SDL_GetError());
		ret = -1;
		goto cleanup;
	}

	SDL_Window *window = SDL_CreateWindow("tetris", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);
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

    int centerX = 35;
    int centerY = 30;
    int radius = 20;
    int size = 10;

    int length = 360;
    tile_t *tiles = malloc(sizeof(tile_t) * length);
    init_clock(tiles, length, radius, centerX, centerY);

    int length_lancet = 20;
    tile_t *tiles_lancet = malloc(sizeof(tile_t) * length_lancet);
    float ang = 0;
    float inc = 0;

    Uint32 last_count = SDL_GetTicks();
    Uint32 curr_count = 0;

    for (;;)
	{
        curr_count = SDL_GetTicks() - last_count;
        last_count = SDL_GetTicks();
        inc = curr_count * (PI_2) / (1000 * 60);
        ang += inc;

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				goto cleanup4;
		}

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);

        draw_clock(tiles, length, size, renderer);

        draw_lancet(tiles_lancet, length_lancet, size, radius, ang, centerX, centerY, renderer);

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
