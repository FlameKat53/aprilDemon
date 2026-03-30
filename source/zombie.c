#include "zombie.h"
#include "player.h"
#include "sound.h"
#include <stdlib.h>

Zombie zombies[MAX_ZOMBIES];

int zombieFrameCounter=0;

void initZombies(){
    for(int i=0;i<MAX_ZOMBIES;i++) zombies[i].active=0;
}

void updateZombies(){
    zombieFrameCounter++;
    if(zombieFrameCounter>10){
        for(int i=0;i<MAX_ZOMBIES;i++)
            zombies[i].animFrame = (zombies[i].animFrame+1)%2;
        zombieFrameCounter=0;
    }

    for(int i=0;i<MAX_ZOMBIES;i++){
        if(!zombies[i].active) continue;

        int dx = player.x - zombies[i].x;
        int dy = player.y - zombies[i].y;

        if(dx>0) zombies[i].x += zombies[i].speed;
        else if(dx<0) zombies[i].x -= zombies[i].speed;
        if(dy>0) zombies[i].y += zombies[i].speed;
        else if(dy<0) zombies[i].y -= zombies[i].speed;

        if(abs(dx)<12 && abs(dy)<12){
            player.hp -= 1;
            playHitSound();
        }
    }
}