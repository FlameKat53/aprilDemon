#include "wave.h"
#include "zombie.h"
#include <stdlib.h>

int currentWave=0;

void initWaves(){ currentWave=0; }

void spawnWave(){
    currentWave++;
    int numZombies = 3 + rand()%5;
    for(int i=0;i<numZombies;i++){
        for(int j=0;j<MAX_ZOMBIES;j++){
            if(!zombies[j].active){
                zombies[j].x = rand()%224;
                zombies[j].y = rand()%144;
                zombies[j].speed = 1 + rand()%2;
                zombies[j].hp = 10 + rand()%10;
                zombies[j].type = rand()%2;
                zombies[j].active = 1;
                break;
            }
        }
    }
}

void updateWave(){
    int active=0;
    for(int i=0;i<MAX_ZOMBIES;i++)
        if(zombies[i].active) active=1;
    if(!active) spawnWave();
}