#include <gba_input.h>
#include "player.h"
#include "bullet.h"

Player player;

void initPlayer() {
    player.x = 120;
    player.y = 80;
    player.hp = 100;
    player.ammo = 50;
}

void updatePlayer() {
    scanKeys();
    u16 keys = keysHeld();

    if(keys & KEY_UP)    player.y -= PLAYER_SPEED;
    if(keys & KEY_DOWN)  player.y += PLAYER_SPEED;
    if(keys & KEY_LEFT)  player.x -= PLAYER_SPEED;
    if(keys & KEY_RIGHT) player.x += PLAYER_SPEED;

    if(keys & KEY_A && player.ammo > 0){
        shootBullet(player.x, player.y, 0, -4); // shoot upward
        player.ammo--;
    }

    if(player.x < 0) player.x = 0;
    if(player.x > 240) player.x = 240;
    if(player.y < 0) player.y = 0;
    if(player.y > 160) player.y = 160;
}