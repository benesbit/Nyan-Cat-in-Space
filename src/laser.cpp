// laser.cpp

#include "ofMain.h"
#include "laser.h"
#include "globals.h"
#include "ship.h"

struct laser {
	float x;
	float y;
	float v;
	float w;
	float h;
	bool onScreen;
	bool enemy;
	ofImage* laserImage;
	ofSoundPlayer* laserSound;
};

struct ship;

struct laser* laserConstruct(int v, bool enemy, ofImage* thisImage, ofSoundPlayer* thisSound) {
	// Allocate memory and get address of the memory
	struct laser* thisLaser = (struct laser*)malloc(sizeof(struct laser));
	thisLaser->laserImage = (ofImage*)malloc(sizeof(ofImage*));
	thisLaser->laserSound = (ofSoundPlayer*)malloc(sizeof(ofSoundPlayer*));
	// Prep the laser
	thisLaser->v = v;
	thisLaser->enemy = enemy;
	thisLaser->onScreen = false;
	thisLaser->w = 70;
	thisLaser->h = 15;
	thisLaser->laserImage = thisImage;
	thisLaser->laserSound = thisSound;
	return thisLaser;
}

struct laser** lasersConstruct(int v, bool enemy, ofImage* thisImage, ofSoundPlayer* thisSound) {
	// Allocate memore for the laser array
	struct laser** thisLasers = (struct laser**)malloc(MAX_NUMBER_OF_LASERS * sizeof(struct laser*));
	// Fill laser array with struct laser*
	for (int i = 0; i < MAX_NUMBER_OF_LASERS; ++i) {
		thisLasers[i] = laserConstruct(v, enemy, thisImage, thisSound);
	}
	return thisLasers;
}

int* laserCounterConstruct() {
	int* thisCounter = (int*)malloc(sizeof(thisCounter));
	*thisCounter = 0;
	return thisCounter;
}

void laserFire(struct laser* thisLaser, struct ship* thisShip) {
	thisLaser->x = shipGetX(thisShip) + 110;
	thisLaser->y = shipGetY(thisShip) + (75 / 2);
	thisLaser->onScreen = true;
	thisLaser->laserSound->play();
}

void laserFireEnemy(struct laser* thisLaser, struct ship* thisShip) {
	thisLaser->x = shipGetX(thisShip) - 70;
	thisLaser->y = shipGetY(thisShip) + (75 / 2);
	thisLaser->onScreen = true;
	thisLaser->laserSound->play();
}

void laserDrawLasers(struct laser* thisLasers[]) {
	for (int i = 0; i < MAX_NUMBER_OF_LASERS; ++i) {
		if (laserOnScreen(thisLasers[i])) {
			laserDraw(thisLasers[i]);
		}
		else {
			laserStore(thisLasers[i]);
		}
	}
}

void laserDraw(struct laser* thisLaser) {
	thisLaser->laserImage->draw(thisLaser->x, thisLaser->y, thisLaser->w, thisLaser->h);
}

void laserMoveLasers(struct laser* thisLasers[]) {
	for (int i = 0; i < MAX_NUMBER_OF_LASERS; ++i) {
		if (laserOnScreen(thisLasers[i])) {
			laserMove(thisLasers[i]);
		}
	}
}

void laserMove(struct laser* thisLaser) {
		thisLaser->x += thisLaser->v;
		if (thisLaser->x > ofGetWidth()) {
			thisLaser->onScreen = false;
		}
}
void laserStore(struct laser* thisLaser) {
	if (thisLaser->enemy) {
		thisLaser->x = ofGetWidth();
		thisLaser->y = ofGetWidth();
	}
	else {
		thisLaser->x = 0;
		thisLaser->y = ofGetHeight();
	}
	thisLaser->onScreen = false;
}

bool laserOnScreen(struct laser* thisLaser) {
	return thisLaser->onScreen;
}

bool laserEnemyShouldFire(int* thisTimer) {
	return ((*thisTimer % ENEMY_FIRE_RATE) == 0);
}

void laserDetermineEnemyShot(int* thisTimer, struct laser* thisLaser, struct ship* thisShip, int* thisCounter) {
	if (laserEnemyShouldFire(thisTimer)) {
		laserFireEnemy(thisLaser, thisShip);
		laserModifyCounter(thisCounter);
	}
}

void laserModifyCounter(int *thisCounter) {
	++*thisCounter;
	if (*thisCounter >= MAX_NUMBER_OF_LASERS) {
		*thisCounter = 0;
	}
}

bool laserLasersAreTouching(struct laser* playerLaser, struct laser* enemyLaser) {
	ofRectangle playerShot;
	ofRectangle enemyShot;
	playerShot.set(playerLaser->x, playerLaser->y, playerLaser->w, playerLaser->h);
	enemyShot.set(enemyLaser->x, enemyLaser->y, enemyLaser->w, enemyLaser->h);
	return playerShot.intersects(enemyShot);
}