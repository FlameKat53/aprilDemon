#ifndef ZOMBIE_H
#define ZOMBIE_H

typedef struct{
    int x, y;
    int hp;
    int speed;
    int type;
    int active;
    int animFrame;
} Zombie;

#define MAX_ZOMBIES 20
extern Zombie zombies[MAX_ZOMBIES];

void initZombies();
void updateZombies();

#endif