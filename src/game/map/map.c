#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include "map.h"

static enum tilde type_blk(char blk)
{
    switch(blk)
    {
    case 'b':
        return BLOCK;
    default:
        return EMPTY;
    }
}

static void fill_map(FILE *map_file, struct map *map)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    size_t h = 0;
    while ((nread = getline(&line, &len, map_file)) != -1) {
        if (h >= map->height)
            break;
        for (ssize_t x = 0; x < map->width && x < nread; x++)
        {
            if(line[x] == '.' || line[x] == 'b')
            {
                size_t index = x + map->width * (map->height - h - 1);
                map->tilde[index] = type_blk(line[x]);
            }
        }
        h++;
    }
    free(line);

}

struct map *create_map(char *file_map)
{
    FILE *file = fopen(file_map, "r");
    if (!file)
        return NULL;

    int w = 640;
    int h = 480;
    struct map *map = calloc(sizeof(map), 1);
    if (!map)
    {
        fclose(file);
        errx(1, "failed calloc map");
    }
    enum tilde *map_tildes = calloc(sizeof(enum tilde), (w / 16) * (h/16));
    if (!map)
    {
        fclose(file);
        free(map);
        errx(1, "failed calloc map->tilde");
    }
    map->tilde = map_tildes;
    map->width = w / 16;
    map->height = h / 16;
    fill_map(file, map);
    fclose(file);
    return map;
}


enum tilde get_block_type(struct map *map, int x, int y)
{
    return map->tilde[x + map->width * y];
}

void display_map(SDL_Window *window, struct map *map)
{
    SDL_Surface* sprite = SDL_LoadBMP("./res/maps/img/blk.bmp");
    if ( sprite )
    {
        SDL_Rect blk = {sprite->w - 16, sprite->h - 16, 16, 16};
        SDL_Rect empty = {200, 200, 16, 16};

        for (size_t y = 0; y < map->height; y++)
            for (size_t x = 0; x < map->width; x++)
                if (get_block_type(map, x, y) == BLOCK)
                {
                    SDL_Rect dest = {x*16, (map->height-y-1)*16, 16, 16};
                    SDL_BlitSurface(sprite, &blk, SDL_GetWindowSurface(window),
                                    &dest);
                }
                else
                {
                    SDL_Rect dest = {x*16, (map->height-y-1)*16, 16, 16};
                    SDL_BlitSurface(sprite, &empty, SDL_GetWindowSurface(window),
                                    &dest);

                }
    }
    else
        err(1,"failed loading sprite (%s)\n",SDL_GetError());
}
