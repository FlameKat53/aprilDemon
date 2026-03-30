#include "bullet.h"
#include "zombie.h"
#include <stdlib.h>

Bullet bullets[MAX_BULLETS];

void initBullets(){
    for(int i=0;i<MAX_BULLETS;i++) bullets[i].active=0;
}

void shootBullet(int x,int y,int dx,int dy){
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

void updateBullets(){
    for(int i=0;i<MAX_BULLETS;i++){
        if(!bullets[i].active) continue;
        bullets[i].x += bullets[i].dx;
        bullets[i].y += bullets[i].dy;

        if(bullets[i].x<0 || bullets[i].y<0 || bullets[i].x>240 || bullets[i].y>160){
            bullets[i].active=0;
            continue;
        }

        for(int j=0;j<MAX_ZOMBIES;j++){
            if(!zombies[j].active) continue;
            if(abs(zombies[j].x-bullets[i].x)<12 && abs(zombies[j].y-bullets[i].y)<12){
                zombies[j].hp -= 5;
                bullets[i].active=0;
                if(zombies[j].hp<=0) zombies[j].active=0;
            }
        }
    }
}