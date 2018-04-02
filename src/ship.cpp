// ship.cpp

#include "ofMain.h"
#include "ofApp.h"
#include "ship.h"
#include "globals.h"

struct ship {
	float x;
	float y;
	float v;
	float a;
	float w;
	float h;
	float t;
	bool enemy;
	ofImage* shipImage;
};

struct ship * shipConstruct(float x, float y, float v, float a, float w, float h, bool enemy, ofImage* thisImage) {
	// Allocate memory and grab address
	struct ship* thisShip = (struct ship*)malloc(sizeof(struct ship));
	thisShip->shipImage = (ofImage*)malloc(sizeof(ofImage*));
	// Prep ship with params
	thisShip->x = x - (.5 * w);
	thisShip->y = y;
	thisShip->v = v;
	thisShip->a = a;
	thisShip->w = w;
	thisShip->h = h;
	thisShip->t = 0;
	thisShip->shipImage = thisImage;
	thisShip->enemy = enemy;
	
	return thisShip;
}

void shipMove(struct ship* thisShip) {
	thisShip->y += thisShip->v;
	thisShip->v *= .997;
	thisShip->x += 0.2 * cos(thisShip->t);
	thisShip->t += 0.01;
	if (shipIsAtEdge(thisShip)) {
		shipBounce(thisShip);
	}
}

void shipEnemyMove(struct ship* thisShip, int* thisTimer) {
	int directionChooser = (int)ofRandom(101);
	if (thisShip->y <= (ofGetHeight() / 4)) {
		// 1st Quad (top)
		if (directionChooser <= 25) {
			shipThrustUp(thisShip);
		}
		else if (directionChooser <= 50) {
			// No Thrust applied
		}
		else if (directionChooser <= 100) {
			shipThrustDown(thisShip);
		}
	}
	else if ((thisShip->y <= (ofGetHeight() / 2)) && (thisShip->y > (ofGetHeight() / 4))) {
		// 2nd Quad
		if (directionChooser <= 35) {
			shipThrustUp(thisShip);
		}
		else if (directionChooser <= 85) {
			shipThrustDown(thisShip);
		}
		else if (directionChooser <= 100) {
			// No Thrust applied
		}
	}
	else if ((thisShip->y <= (ofGetHeight() - (ofGetHeight() / 4))) && (thisShip->y > (ofGetHeight() / 2))) {
		// 3rd Quad
		if (directionChooser <= 35) {
			shipThrustDown(thisShip);
		}
		else if (directionChooser <= 85) {
			shipThrustUp(thisShip);
		}
		else if (directionChooser <= 100) {
			// No Thrust applied
		}
	}
	else if ((thisShip->y <= ofGetHeight()) && (thisShip->y > (ofGetHeight() - (ofGetHeight() / 4)))) {
		// 4th Quad (bottom)
		if (directionChooser <= 25) {
			shipThrustDown(thisShip);
		}
		else if (directionChooser <= 50) {
			// No Thrust applied
		}
		else if (directionChooser <= 100) {
			shipThrustUp(thisShip);
		}
	}
	++*thisTimer;
	if (*thisTimer > ENEMY_FIRE_RATE) {
		*thisTimer = 0;
	}
	shipMove(thisShip);
}

void shipThrustDown(struct ship* thisShip) {
	thisShip->v += thisShip->a;
}

void shipThrustUp(struct ship* thisShip) {
	thisShip->v -= thisShip->a;
}

void shipDraw(struct ship* thisShip) {
	ofSetColor(255);
	thisShip->shipImage->draw(thisShip->x, thisShip->y, thisShip->w, thisShip->h);
}

void shipBounce(struct ship* thisShip) {
	thisShip->v *= -0.6;
}

bool shipIsAtEdge(struct ship* thisShip) {
	if (((thisShip->y) <= 0)) {
		thisShip->y = 0;
		return true;
	}
	else if (((thisShip->y) + (thisShip->h)) >= ofGetHeight()) {
		thisShip->y = ofGetHeight() - thisShip->h;
		return true;
	}
	return false;
}

float shipGetX(struct ship* thisShip) {
	return thisShip->x;
}

float shipGetY(struct ship* thisShip) {
	return thisShip->y;
}

void shipPositionEnemyShip(struct ship* thisShip) {
	thisShip->x = ofGetWidth() - 150;
}