#include <stdlib.h>

#include "person.h"

void destroy_person(struct person *person)
{
    free(person->physics);
    free(person);
}