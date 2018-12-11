#include "tile.h"

void init_tile(tile_t *tile, int posX, int posY)
{
    tile = malloc(sizeof(tile_t));
    memset(tile, 0, sizeof(tile_t));
    tile->x = posX;
    tile->y = posY;
}