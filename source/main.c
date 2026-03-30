#include <gba.h>
#include <gba_console.h>
#include <gba_input.h>
#include "graphics.h"
#include "map.h"
#include "player.h"
#include "zombie.h"
#include "bullet.h"
#include "pickups.h"
#include "wave.h"
#include "render.h"

int main(void){
    irqInit();
    irqEnable(IRQ_VBLANK);
    consoleDemoInit();

    REG_DISPCNT = MODE_0 | BG0_ON | OBJ_ON | OBJ_1D_MAP;

// Background palette (16 colors)
BG_PALETTE[0] = RGB5(0,0,0);     // black
BG_PALETTE[1] = RGB5(31,0,0);    // red
BG_PALETTE[2] = RGB5(0,31,0);    // green
BG_PALETTE[3] = RGB5(31,31,0);   // yellow
BG_PALETTE[4] = RGB5(0,0,31);    // blue
BG_PALETTE[5] = RGB5(31,31,31);  // white

// Object palette
SPRITE_PALETTE[0] = RGB5(0,0,0);
SPRITE_PALETTE[1] = RGB5(31,0,0);   // player
SPRITE_PALETTE[2] = RGB5(0,31,0);   // zombie
SPRITE_PALETTE[3] = RGB5(31,31,0);  // bullet
SPRITE_PALETTE[4] = RGB5(0,0,31);   // pickup

// Load tiles into VRAM
unsigned short* charBase = (unsigned short*)CHAR_BASE_BLOCK(0);

// Player, zombie, bullet, pickup
for(int i=0;i<32;i++) charBase[i] = playerTile[i];
for(int i=0;i<32;i++) charBase[32+i] = zombieTile[i];
for(int i=0;i<32;i++) charBase[64+i] = bulletTile[i];
for(int i=0;i<32;i++) charBase[96+i] = pickupTile[i];

// Background tiles (optional: fill first 128 tiles)
for(int i=0;i<32;i++) charBase[128+i] = bgTile0[i];

    initMap();
    initPlayer();
    initZombies();
    initBullets();
    initPickups();
    initWaveSystem();

    while(1){
        VBlankIntrWait();

        updatePlayer();
        updateBullets();
        updateWaveSystem();
        updateZombies();
        updatePickups();
        updateMapScrolling(player.x, player.y);

        renderSprites();
        updateHUD();
    }

    return 0;
}