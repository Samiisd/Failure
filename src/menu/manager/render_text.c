#include "menu.h"

void render_text(struct menu_manager *mm, const char *txt, int x, int y)
{
    SDL_Color color;
    color.r = 255;
    color.g = 255;
    color.b = 255;

    SDL_Surface *surface = TTF_RenderText_Solid(mm->text_font, txt, color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(mm->renderer, surface);

    int texW = 0;
    int texH = 0;

    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect = { x, y, texW, texH };

    SDL_RenderCopy(mm->renderer, texture, NULL, &dstrect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}
