#include <utils.h>





void main(int argc, char const **argv)
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


    printf("Insert Image Path");
    char pathString[]= scanf();

   for (;;)
	{
        
    }



cleanup3:
cleanup2:
cleanup1:
cleanup:

    SDL_Quit();

    return 0;
}
