#include "wave.h"
#include "zombie.h"
#include <stdlib.h>

// helper function declaration
static int anyActiveZombies();   // <<< add this

Wave currentWave;

void initWaveSystem() {
    currentWave.waveNumber = 1;
    currentWave.zombiesToSpawn = 3;
    currentWave.spawned = 0;
    currentWave.timer = 60; // 1 second delay (60 frames)
}

void spawnZombie(int x, int y) {
    for(int i=0; i<MAX_ZOMBIES; i++){
        if(!zombies[i].active){
            zombies[i].x = x;
            zombies[i].y = y;
            zombies[i].active = 1;
            break;
        }
    }
}

void updateWaveSystem() {
    if(currentWave.spawned >= currentWave.zombiesToSpawn){
        // Wave complete, increment next wave
        if(!anyActiveZombies()){ // Only start next wave when all zombies dead
            currentWave.waveNumber++;
            currentWave.zombiesToSpawn = 3 + currentWave.waveNumber; // increase difficulty
            currentWave.spawned = 0;
            currentWave.timer = 60;
        }
        return;
    }

    // Spawn zombies periodically
    if(currentWave.timer > 0){
        currentWave.timer--;
    } else {
        int x = rand() % 240;
        int y = rand() % 160;
        spawnZombie(x, y);
        currentWave.spawned++;
        currentWave.timer = 60; // next spawn in 1 second
    }
}

// Helper: check if any zombies active
static int anyActiveZombies(){
    for(int i=0; i<MAX_ZOMBIES; i++){
        if(zombies[i].active) return 1;
    }
    return 0;
}