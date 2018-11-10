#ifndef MAP_H
#define MAP_H

#include <SDL.h>

enum tilde
{
    EMPTY,
    BLOCK
};

struct map
{
    unsigned width;
    unsigned height;
    enum tilde *tilde;
};

struct map *create_map(char *file_map);
enum tilde get_block_type(struct map *map, int x, int y);
void display_map(SDL_Window *window, struct map *map);
#endif /* ! MAP_H */
