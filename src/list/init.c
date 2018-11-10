#include <stdlib.h>

#include "list.h"

struct list *list_init(size_t capacity, void (*free_fnct)(void*))
{
    struct list *v = malloc(sizeof(struct list));
    if (!v)
        return NULL;

    v->capacity = capacity;
    v->index = 0;
    v->free_fnct = free_fnct;
    v->data = malloc(sizeof(void *) * capacity);

    if (!v->data)
    {
        free(v);
        return NULL;
    }

    return v;
}
