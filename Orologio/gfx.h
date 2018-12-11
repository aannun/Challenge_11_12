#include "tile.h"

void _draw_internal(SDL_Renderer *renderer, SDL_Rect *rect, int size, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

void tile_draw(tile_t *tile, SDL_Renderer *renderer, int size, Uint8 r, Uint8 g, Uint8 b);