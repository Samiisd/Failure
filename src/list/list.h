#pragma once

#include <stddef.h>

struct list
{
    void **data;
    size_t index;
    size_t capacity;

    void (*free_fnct)(void*);
};

/**
 * Allocate and returns a list of the specified capacity.
 *
 * if 'free_fnct' is not NULL, then the function will be applied on elements
 * to destroy.
 *
 * Returns NULL if allocations failed.
 */
struct list *list_init(size_t capacity, void (*free_fnct)(void*));

/**
 * Free the list 'v' and applied the free_fnct, if not NULL, on each items
 */
void list_free(struct list *v);

/**
 * Insert the 'item' in the list 'v'
 * If insertion failed, returns 0
 * Else, returns 1
 */
int list_push(struct list *v, void *item);

/**
 * Pop the last pushed item in the list 'v'
 * If error occures, returns NULL
 * Else, returns the elem
 */
void *list_pop(struct list *v);

/**
 * Delete all elements of the list.
 * If 'free_fnct' != NULL, the function will be applied on all elems
 */
void list_reset(struct list *v);

/**
 * Returns the elem at the specified 'index'.
 * If 'index' is out of bounds, returns NULL
 */
static inline void *list_at(const struct list *v, size_t index)
{
    return index < v->index ? v->data[index] : NULL;
}

/**
 * Returns the size of the list
 */
static inline size_t list_size(const struct list *v)
{
    return v->index;
}
