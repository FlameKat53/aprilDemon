#ifndef PLAYER_H
#define PLAYER_H

#define PLAYER_SPEED 2

typedef struct {
    int x, y;
    int hp;
    int ammo;
} Player;

extern Player player;

void initPlayer();
void updatePlayer();

#endif