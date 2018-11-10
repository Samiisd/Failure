#ifndef PHYSICS_H
#define PHYSICS_H

#define GRAVITY 9.81

struct physic_info
{
    struct vector *speed;
    struct vector *position;
    float mass;
    int collison;
};

void physics_update(void);
void add_speed(struct physic_info *info, struct vector *vect);


#endif /* ! PHYSICS_H */
