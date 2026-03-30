#ifndef PLAYER_H
#define PLAYER_H

typedef struct {
    int x, y;
    int hp;
    int ammo;
    int speed;
    int animFrame;
} Player;

extern Player player;

void initPlayer();
void updatePlayer();

#endif