#ifndef MAP_H
#define MAP_H

#include <gba.h>

#define MAP_WIDTH 32
#define MAP_HEIGHT 32

extern unsigned short mapTiles[MAP_WIDTH*MAP_HEIGHT];

void initMap();
void updateMapScrolling(int playerX, int playerY);

#endif