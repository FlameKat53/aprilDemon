#include "player.h"
#include "bullet.h"
#include "sound.h"
#include <gba_input.h>
#include <gba_types.h>

Player player;

int frameCounter=0;

void initPlayer(){
    player.x = 120;
    player.y = 80;
    player.hp = 100;
    player.ammo = 50;
    player.speed = 2;
    player.animFrame = 0;
}

void updatePlayer(){
    int moving = 0;

    if(keysHeld() & KEY_UP){ player.y -= player.speed; moving=1; }
    if(keysHeld() & KEY_DOWN){ player.y += player.speed; moving=1; }
    if(keysHeld() & KEY_LEFT){ player.x -= player.speed; moving=1; }
    if(keysHeld() & KEY_RIGHT){ player.x += player.speed; moving=1; }

    if(player.x<0) player.x=0;
    if(player.y<0) player.y=0;
    if(player.x>224) player.x=224;
    if(player.y>144) player.y=144;

    if(keysDown() & KEY_A && player.ammo>0){
        shootBullet(player.x+8, player.y+8, 0, -3);
        player.ammo--;
        playShootSound();
    }

    if(moving){
        frameCounter++;
        if(frameCounter>5){
            player.animFrame = (player.animFrame+1)%4;
            frameCounter=0;
        }
    } else player.animFrame=0;
}