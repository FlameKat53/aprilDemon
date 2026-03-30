#ifndef PICKUPS_H
#define PICKUPS_H

#define MAX_PICKUPS 4

typedef struct {
    int x, y;
    int active;
} Pickup;

extern Pickup pickups[MAX_PICKUPS];

void initPickups();
void updatePickups();

#endif