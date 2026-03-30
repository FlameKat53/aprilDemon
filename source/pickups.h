#ifndef PICKUPS_H
#define PICKUPS_H

typedef struct{
    int x, y;
    int type; // 0=health,1=ammo
    int active;
} Pickup;

#define MAX_PICKUPS 5
extern Pickup pickups[MAX_PICKUPS];

void initPickups();
void updatePickups();

#endif