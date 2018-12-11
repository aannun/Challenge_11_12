#define SDL_MAIN_HANDLED
#include <SDL.h>

typedef struct tile
{
    int x;
    int y;
}tile_t;

void init_tile(tile_t *tile, int posX, int posY);