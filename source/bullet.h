#ifndef BULLET_H
#define BULLET_H

#define MAX_BULLETS 16
#define BULLET_SPEED 4

typedef struct {
    int x, y;
    int active;
    int dx, dy;
} Bullet;

extern Bullet bullets[MAX_BULLETS];

void initBullets();
void updateBullets();
void shootBullet(int x, int y, int dx, int dy);

#endif