#include <gba.h>
#include "map.h"

unsigned short mapTiles[MAP_WIDTH*MAP_HEIGHT];

// Initialize map with colored tiles
void initMap() {
    // Simple gradient background
    for(int y=0;y<MAP_HEIGHT;y++)
        for(int x=0;x<MAP_WIDTH;x++)
            mapTiles[y*MAP_WIDTH + x] = (x+y)%5; // use tile index 0–4

    unsigned short* screen = (unsigned short*)SCREEN_BASE_BLOCK(31);
    for(int y=0;y<MAP_HEIGHT;y++)
        for(int x=0;x<MAP_WIDTH;x++)
            screen[y*MAP_WIDTH + x] = mapTiles[y*MAP_WIDTH + x];

    REG_BG0CNT = BG_16_COLOR | BG_SIZE_0 | CHAR_BASE(0) | SCREEN_BASE(31);
    REG_BG0HOFS = 0;
    REG_BG0VOFS = 0;
}

void updateMapScrolling(int playerX, int playerY){
    // center BG0 on player (simple)
    REG_BG0HOFS = playerX - 120;
    REG_BG0VOFS = playerY - 80;
}