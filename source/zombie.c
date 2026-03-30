#include "zombie.h"
#include "player.h"

Zombie zombies[MAX_ZOMBIES];

void initZombies() {
    for(int i=0;i<MAX_ZOMBIES;i++){
        zombies[i].x = 50 + i*20;
        zombies[i].y = 50;
        zombies[i].active = 1;
    }
}

void updateZombies() {
    for(int i=0;i<MAX_ZOMBIES;i++){
        if(!zombies[i].active) continue;

        // Simple AI: move toward player
        if(zombies[i].x < player.x) zombies[i].x += ZOMBIE_SPEED;
        if(zombies[i].x > player.x) zombies[i].x -= ZOMBIE_SPEED;
        if(zombies[i].y < player.y) zombies[i].y += ZOMBIE_SPEED;
        if(zombies[i].y > player.y) zombies[i].y -= ZOMBIE_SPEED;
    }
}