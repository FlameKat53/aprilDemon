#include <gba.h>
#include <stdio.h>
#include <gba_console.h>  // for iprintf
#include <gba_sprites.h>  // for OBJATTR
#include "player.h"
#include "zombie.h"
#include "bullet.h"
#include "pickups.h"
#include "graphics.h"     // placeholder tiles

void renderSprites(){
    OBJATTR* oam = OAM;

    // Hide all sprites
    for(int i=0;i<128;i++){
        oam[i].attr0 = ATTR0_DISABLED;
        oam[i].attr1 = 0;
        oam[i].attr2 = 0;
    }

    int index = 0;

    // Player
    oam[index].attr0 = player.y | ATTR0_SQUARE;
    oam[index].attr1 = player.x;
    oam[index].attr2 = 0; // player tile
    index++;

    // Zombies
    for(int i=0;i<MAX_ZOMBIES;i++){
        if(zombies[i].active){
            oam[index].attr0 = zombies[i].y | ATTR0_SQUARE;
            oam[index].attr1 = zombies[i].x;
            oam[index].attr2 = 1; // zombie tile
            index++;
        }
    }

    // Bullets
    for(int i=0;i<MAX_BULLETS;i++){
        if(bullets[i].active){
            oam[index].attr0 = bullets[i].y | ATTR0_SQUARE;
            oam[index].attr1 = bullets[i].x;
            oam[index].attr2 = 2; // bullet tile
            index++;
        }
    }

    // Pickups
    for(int i=0;i<MAX_PICKUPS;i++){
        if(pickups[i].active){
            oam[index].attr0 = pickups[i].y | ATTR0_SQUARE;
            oam[index].attr1 = pickups[i].x;
            oam[index].attr2 = 3; // pickup tile
            index++;
        }
    }
}

void updateHUD(){
    iprintf("\x1b[0;0HHP:%03d Ammo:%03d", player.hp, player.ammo);
}