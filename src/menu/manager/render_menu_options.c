#include "menu.h"

void render_menu_options(struct menu_manager *mm)
{
    int winH;
    int winW;
    SDL_GetWindowSize(mm->window, &winW, &winH);

    render_text(mm, "Pause :", winW / 2 - 265, 20);

    render_text(mm, "- Press R to Resume", 30, 200);
    render_text(mm, "- Press B to back", 30, 260);
    render_text(mm, "- Press E to Exit", 30, 320);
}