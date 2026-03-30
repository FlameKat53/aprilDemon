#include "pickups.h"

Pickup pickups[MAX_PICKUPS];

void initPickups() {
    for(int i=0;i<MAX_PICKUPS;i++){
        pickups[i].x = 30 + i*40;
        pickups[i].y = 30;
        pickups[i].active = 1;
    }
}

void updatePickups() {
    // For now pickups are static
}