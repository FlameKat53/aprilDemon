#ifndef ZOMBIE_H
#define ZOMBIE_H

#define MAX_ZOMBIES 8
#define ZOMBIE_SPEED 1

typedef struct {
    int x, y;
    int active;
} Zombie;

extern Zombie zombies[MAX_ZOMBIES];

void initZombies();
void updateZombies();

#endif