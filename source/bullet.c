#include "bullet.h"

Bullet bullets[MAX_BULLETS];

void initBullets() {
    for(int i=0;i<MAX_BULLETS;i++) bullets[i].active = 0;
}

void updateBullets() {
    for(int i=0;i<MAX_BULLETS;i++){
        if(!bullets[i].active) continue;
        bullets[i].x += bullets[i].dx;
        bullets[i].y += bullets[i].dy;
        // Deactivate if offscreen
        if(bullets[i].x < 0 || bullets[i].x > 240 || bullets[i].y < 0 || bullets[i].y > 160)
            bullets[i].active = 0;
    }
}

void shootBullet(int x, int y, int dx, int dy){
    for(int i=0;i<MAX_BULLETS;i++){
        if(!bullets[i].active){
            bullets[i].x = x;
            bullets[i].y = y;
            bullets[i].dx = dx;
            bullets[i].dy = dy;
            bullets[i].active = 1;
            break;
        }
    }
}