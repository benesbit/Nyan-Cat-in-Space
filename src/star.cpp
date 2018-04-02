// stars.cpp

#include "ofMain.h"
#include "star.h"
#include "ofApp.h"
#include "globals.h"

struct star {
	int x;
	int y;
	int radius;
	float speed;
	ofColor color;
};

struct star * starConstruct() {
	// Allocate memory and get address of that memory
	struct star* thisStar = (struct star*)malloc(sizeof(struct star));
	// Prep the star, using params
	thisStar->x = (int)ofRandom(ofGetWidth());
	thisStar->y = (int)ofRandom(ofGetHeight());
	starSetRandomColor(thisStar);
	starSetRadius(thisStar);

	return thisStar;
}

struct star ** starsConstruct() {
	// Allocate memory for stars array
	struct star** thisStars = (struct star**)malloc(NUMBER_OF_STARS * sizeof(struct star *));
	for (int i = 0; i < NUMBER_OF_STARS; ++i) {
		thisStars[i] = starConstruct();
	}
	return thisStars;
}

void starDrawField(struct star* thisField[]) {
	for (int i = 0; i < NUMBER_OF_STARS; ++i) {
		starDraw(thisField[i]);
	}
}

void starDraw(struct star* thisStar) {
	ofSetColor(thisStar->color);
	ofDrawCircle(thisStar->x, thisStar->y, thisStar->radius);
}

void starMove(struct star* thisStar) {
	thisStar->x -= thisStar->speed;
}

void starMoveField(struct star* thisField[]) {
	for (int i = 0; i < NUMBER_OF_STARS; ++i) {
		starMove(thisField[i]);
		if ((thisField[i]->x) <= (-1 *(thisField[i]->radius))) {
			starStayInbounds(thisField[i]);
		}
	}
}

void starStayInbounds(struct star* thisStar) {
	thisStar->y = (int)ofRandom(ofGetHeight());
	thisStar->x = ofGetWidth();
	starSetRandomColor(thisStar);
	starSetRadius(thisStar);
}

void starSetRandomColor(struct star* thisStar) {
	int colorChooser = (int)ofRandom(101);
	if (colorChooser < 5) {
		thisStar->color = ofColor(144, 166, 255);
	}
	else if (colorChooser < 85) {
		thisStar->color = ofColor(255, 255, 255);
	}
	else if (colorChooser < 95) {
		thisStar->color = ofColor(255, 210, 120);
	}
	else {
		thisStar->color = ofColor(255, 157, 000);
	}
}

void starSetRadius(struct star* thisStar) {
	int sizeChooser = (int)ofRandom(101);
	if (sizeChooser <= 15) {
		thisStar->radius = 3;
	}
	else if (sizeChooser <= 25) {
		thisStar->radius = 2;
	}
	else {
		thisStar->radius = 1;
	}
	starSetSpeed(thisStar);
}

void starSetSpeed(struct star* thisStar) {
	if ((thisStar->radius) == 3) {
		thisStar->speed = 3;
	}
	else if ((thisStar->radius) == 2) {
		thisStar->speed = 2;
	}
	else if ((thisStar->radius) == 1) {
		thisStar->speed = 1;
	}
}