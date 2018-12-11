#include "utils.h"
#include <stdio.h>

static int LoadMedia(char path[])
{

    SDL_LockSurface(screen);
    /* load image*/
    image_to_load = SDL_LoadBMP(path);
    if (image_to_load == NULL)
    {
        SDL_Log("Failed to load image %s ", SDL_GetError());
        return -1;
    }
    SDL_BlitSurface(image_to_load, NULL, screen, NULL);
    SDL_UnlockSurface(screen);

    return 0;
}

int main(int argc, char const **argv)
{
    int ret = 0;

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO))
    {
        SDL_Log("unable to inizialize sdl: %s", SDL_GetError());
        ret = -1;
        goto cleanup;
    }

    SDL_Window *window = SDL_CreateWindow("Image loader 3000", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);
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

    screen = SDL_GetWindowSurface(window);

    printf("Insert Image Path \n");
    char pathString[256];
    fgets(&pathString,sizeof(pathString),stdin);

    SDL_Log("%s",pathString);

    if (LoadMedia(pathString) == -1)
    {
        SDL_Log("Error in loading img");
    }

   if(SDL_UpdateWindowSurface(window) != 0)
   {
        SDL_Log("Error in loading img to window %s",SDL_GetError());
   }
    for (;;)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                goto cleanup4;
            }
        }
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
