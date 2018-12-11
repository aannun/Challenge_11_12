#include "gfx.h"

void _draw_internal(SDL_Renderer *renderer, SDL_Rect *rect, int size, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderFillRect(renderer, rect);
}

void tile_draw(tile_t *tile, SDL_Renderer *renderer, int size, Uint8 r, Uint8 g, Uint8 b)
{
    SDL_Rect rect;
    rect.x = size * tile->x;
    rect.y = size * tile->y;
    rect.w = size;
    rect.h = size;
    _draw_internal(renderer, &rect, size, r, g, b, 255);
}