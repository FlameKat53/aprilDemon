#include "pickups.h"
#include "player.h"
#include "sound.h"
#include <stdlib.h>

Pickup pickups[MAX_PICKUPS];

void initPickups(){
    for(int i=0;i<MAX_PICKUPS;i++){
        pickups[i].x = rand()%224;
        pickups[i].y = rand()%144;
        pickups[i].type = rand()%2;
        pickups[i].active = 1;
    }
}

void updatePickups(){
    for(int i=0;i<MAX_PICKUPS;i++){
        if(!pickups[i].active) continue;
        if(abs(player.x - pickups[i].x)<12 && abs(player.y - pickups[i].y)<12){
            if(pickups[i].type==0) player.hp += 20;
            else player.ammo += 10;
            if(player.hp>100) player.hp=100;
            playPickupSound();
            pickups[i].active=0;
        }
    }
}