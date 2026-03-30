#ifndef BULLET_H
#define BULLET_H

typedef struct{
    int x, y;
    int dx, dy;
    int active;
} Bullet;

#define MAX_BULLETS 20
extern Bullet bullets[MAX_BULLETS];

void initBullets();
void shootBullet(int x,int y,int dx,int dy);
void updateBullets();

#endif