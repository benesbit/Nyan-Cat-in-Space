#pragma once

#include "ofMain.h"
#include "ship.h"

struct laser* laserConstruct(int v, bool enemy, ofImage* thisImage, ofSoundPlayer* thisSound);

struct laser** lasersConstruct(int v, bool enemy, ofImage* thisImage, ofSoundPlayer* thisSound);

int* laserCounterConstruct();

void laserFire(struct laser* thisLaser, struct ship* thisShip);

void laserFireEnemy(struct laser* thisLaser, struct ship* thisShip);

void laserDraw(struct laser* thisLaser);

void laserMove(struct laser* thisLaser);

void laserMoveLasers(struct laser* thisLasers[]);

void laserStore(struct laser* thisLaser);

void laserModifyCounter(int *laserCounter);

bool laserOnScreen(struct laser* thisLaser);

void laserDrawLasers(struct laser* thisLasers[]);

bool laserEnemyShouldFire(int* thisTimer);

void laserDetermineEnemyShot(int* thisTimer, struct laser* thisLaser, struct ship* thisShip, int* thisCounter);

bool laserLasersAreTouching(struct laser* playerLaser, struct laser* enemyLaser);