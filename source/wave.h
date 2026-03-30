#ifndef WAVE_H
#define WAVE_H

#include <gba.h>
#include "zombie.h"

// Wave configuration
typedef struct {
    int waveNumber;
    int zombiesToSpawn;
    int spawned;
    int timer; // frames until next spawn
} Wave;

extern Wave currentWave;

void initWaveSystem();
void updateWaveSystem();

#endif