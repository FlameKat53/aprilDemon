#include <gba.h>
#include <gba_console.h>
#include <gba_input.h>
#include "graphics.h"
#include "map.h"
#include "player.h"
#include "zombie.h"
#include "bullet.h"
#include "pickups.h"
#include "render.h"

int main(void){
    irqInit();
    irqEnable(IRQ_VBLANK);
    consoleDemoInit();

    REG_DISPCNT = MODE_0 | BG0_ON | OBJ_ON | OBJ_1D_MAP;

    // Load palette
    BG_PALETTE[0] = RGB5(0,0,0);       // black
    BG_PALETTE[1] = RGB5(31,0,0);      // red
    BG_PALETTE[2] = RGB5(0,31,0);      // green
    BG_PALETTE[3] = RGB5(31,31,0);     // yellow
    BG_PALETTE[4] = RGB5(0,0,31);      // blue

    // Load tiles into VRAM
    unsigned short* charBase = (unsigned short*)CHAR_BASE_BLOCK(0);
    for(int i=0;i<32;i++) charBase[i] = playerTile[i];
    for(int i=0;i<32;i++) charBase[32+i] = zombieTile[i];
    for(int i=0;i<32;i++) charBase[64+i] = bulletTile[i];
    for(int i=0;i<32;i++) charBase[96+i] = pickupTile[i];

    // Initialize everything
    initMap();
    initPlayer();
    initZombies();
    initBullets();
    initPickups();

    while(1){
        VBlankIntrWait();
        scanKeys();

        updatePlayer();
        updateBullets();
        updateZombies();
        updatePickups();

        updateMapScrolling(player.x, player.y);

        renderSprites();
        updateHUD();
    }

    return 0;
}